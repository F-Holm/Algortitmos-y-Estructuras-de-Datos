$compilador = "clang++"
$optimizaciones = "-O3"
$debug = $false
$estandar = "c++23"

$extra_flags = ""
if ($debug) {
    $extra_flags = "-g"
    $optimizaciones = "-O0"
}

$ROOT_DIR = Get-Location
$FAILED = @()
$JOBS = @()

Write-Host "🔍 Buscando archivos .cpp..."
$CPP_FILES = Get-ChildItem -Path $ROOT_DIR -Recurse -Filter "*.cpp" | Select-Object -ExpandProperty FullName

Write-Host "🛠 Compilando con $compilador, estándar $estandar, optimización $optimizaciones..."

foreach ($SRC_FILE in $CPP_FILES) {
    $JOBS += Start-Job -ScriptBlock {
        param($SRC_FILE, $compilador, $estandar, $optimizaciones, $extra_flags)

        $REL_DIR = [System.IO.Path]::GetDirectoryName($SRC_FILE)
        $EXEC_NAME = [System.IO.Path]::GetFileNameWithoutExtension($SRC_FILE)
        $OUT_PATH = "$REL_DIR\$EXEC_NAME.exe"

        try {
            & $compilador "-std=$estandar" $optimizaciones $extra_flags $SRC_FILE "-o" $OUT_PATH
            return "OK: $OUT_PATH"
        } catch {
            return "FAIL: $SRC_FILE"
        }
    } -ArgumentList $SRC_FILE, $compilador, $estandar, $optimizaciones, $extra_flags
}

# Esperar a que todos los trabajos terminen
$JOBS | ForEach-Object { $_ | Wait-Job }

# Recolectar resultados
foreach ($job in $JOBS) {
    $result = Receive-Job $job
    if ($result -like "FAIL:*") {
        $FAILED += $result.Substring(6)
        Write-Host "❌ Error al compilar: $($result.Substring(6))"
    } else {
        Write-Host "✅ Compilado: $($result.Substring(4))"
    }
    Remove-Job $job
}

Write-Host ""
if ($FAILED.Count -ne 0) {
    Write-Host "⚠️ Fallaron los siguientes archivos:"
    foreach ($F in $FAILED) {
        Write-Host "   - $F"
    }
} else {
    Write-Host "🎉 Todos los archivos se compilaron correctamente."
}

Write-Host "🧹 Limpiando archivos intermedios..."
Get-ChildItem -Path $ROOT_DIR -Recurse -Filter "*.o" | Remove-Item
Write-Host "✅ Limpieza completada."
