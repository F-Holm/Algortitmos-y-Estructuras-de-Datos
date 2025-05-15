#!/usr/bin/env pwsh

# Detener ejecución en caso de error
$ErrorActionPreference = "Stop"

# Formatear todos los archivos
#& "./f.ps1"

# 🔧 Configuración
$compilador = "clang++"       # También podés usar g++
$estandar = "-std=c++23"           # Clang++ defaulta a C++98 si no se especifica
$extra_info=@("-Wall", "-Wextra")

# ⚙️ Ajustes según modo debug
# debug flags:
$ModeFlags = @("-g", "-O0", "-DDEBUG")
# release flags:
#$ModeFlags = @("-O3", "-DNDEBUG")

$unidad = $args[0]
$ejercicio = $args[1]


if (-not $ejercicio) {
    $unidad = Read-Host "Ingresá el número de la unidad"
    $ejercicio = Read-Host "Ingresá el nombre del ejercicio"
    Write-Host ""
}

# Construir paths
$archivo = "./Unidad $unidad/Ejercicio $ejercicio.cpp"
if ($IsWindows) {
    $salida = "./Unidad $unidad/Ejercicio $ejercicio.exe"
} else {
    $salida = "./Unidad $unidad/Ejercicio $ejercicio"
}

# 📁 Verificar existencia del archivo
if (-not (Test-Path $archivo)) {
    Write-Host "❌ El archivo '$archivo' no existe."
    exit 1
}

# 🛠 Compilar
Write-Host "🔧 Compilando con $compilador -std=$estandar $optimizaciones..."
# "-finput-charset=utf-8" "-DUNICODE" "-fexec-charset=utf-8"
& $compilador $estandar $extra_info $ModeFlags "$archivo" -o "$salida"

# ✅ Verificar si la compilación fue exitosa
if ($LASTEXITCODE -eq 0) {
    Write-Host "✅ Compilación exitosa. Ejecutable: $salida"

    # ▶️ Ejecutar si no se pasaron argumentos o se pasaron dos
    if ($args.Count -eq 0 -or $args.Count -eq 2) {
        & ".\r.ps1" $unidad $ejercicio
    }
} else {
    Write-Host "❌ Error al compilar el archivo."
}