#!/usr/bin/env pwsh

$Compilador       = "clang++"
$ExtraInfo        = @("-Wall", "-Wextra")
$CppStandard      = "-std=c++23"

# debug flags:
#$ModeFlags = @("-g", "-O0", "-DDEBUG")
# release flags:
$ModeFlags = @("-O3", "-DNDEBUG")

# Llamar al script f.ps1 después de los parámetros iniciales
. ./f.ps1

# Obtener la lista de archivos .cpp
$archivos = Get-ChildItem -Path "." -Recurse -Filter *.cpp

# Crear un job para compilar cada archivo
$jobs = @()
foreach ($archivo in $archivos) {
    $rutaCpp = $archivo.FullName

    $jobs += Start-Job -ScriptBlock {
        param ($ruta, $comp, $extraInfo, $std, $modo)
        # Construir la ruta de salida .exe en la misma carpeta que el .cpp
        #$exeSalida = [System.IO.Path]::ChangeExtension($ruta, ".exe")

        if ($IsWindows) {
            $exeSalida = [System.IO.Path]::ChangeExtension($ruta, ".exe")
        } else {
            $nombreSinExtension = [System.IO.Path]::GetFileNameWithoutExtension($ruta)
            $directorio = [System.IO.Path]::GetDirectoryName($ruta)
            $exeSalida = Join-Path $directorio $nombreSinExtension
        }

        # Ejecutar clang++ y capturar salida y código de error
        $salida = & $comp $std $opt $extraInfo $modo  "-o" $exeSalida $ruta 2>&1
        $codigo = $LASTEXITCODE

        # Devolver un objeto con la información
        [PSCustomObject]@{
            Archivo   = $ruta
            Salida    = $salida -join "`n"
            ExitCode  = $codigo
        }
    } -ArgumentList $rutaCpp, $Compilador, $ExtraInfo, $CppStandard, $ModeFlags
}

# Barra de progreso global mientras los jobs están en ejecución
$total = $jobs.Count
while ($true) {
    $hechos = ($jobs | Where-Object { $_.State -eq 'Completed' -or $_.State -eq 'Failed' }).Count
    $porcentaje = [int]($hechos * 100 / $total)
    Write-Progress -Activity "Compilando archivos C++" `
                   -Status "Procesados $hechos de $total archivos" `
                   -PercentComplete $porcentaje

    if ($hechos -ge $total) { break }
    Start-Sleep -Milliseconds 200
}

# Recibir salida de cada job y eliminar el job
$results = foreach ($job in $jobs) {
    $res = Receive-Job $job
    Remove-Job $job -Force
    $res
}

# Procesar cada resultado
$sinAdvertencias = 0
$conAdvertencias = 0
$conErrores     = 0

foreach ($res in $results) {
    $ruta   = $res.Archivo
    $salida = $res.Salida
    $exit   = $res.ExitCode

    if ($salida) {
        Write-Host "Archivo: $ruta"
        Write-Host $salida
        Write-Host "---------------"
    } else {
        # Write-Host "Compilado exitosamente sin advertencias."
    }

    if ($exit -ne 0) {
        $conErrores++
    } elseif ($salida -match "(?i)warning") {
        $conAdvertencias++
    } else {
        $sinAdvertencias++
    }
}

# Resumen final
Write-Host "Resumen:"
Write-Host "  Exitosos         : $sinAdvertencias"
Write-Host "  Con advertencias : $conAdvertencias"
Write-Host "  Fallidos         : $conErrores"
