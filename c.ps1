#!/usr/bin/env pwsh

# Detener ejecución en caso de error
$ErrorActionPreference = "Stop"

# 🔧 Configuración
$compilador = "clang++"       # También podés usar g++
$estandar = "-std=c++23"      # Clang++ defaulta a C++98 si no se especifica
$extra_info = @("-Wall", "-Wextra")

# ⚙️ Ajustes según modo debug
# debug flags:
$ModeFlags = @("-g", "-O0", "-DDEBUG")
# release flags:
# $ModeFlags = @("-O3", "-DNDEBUG")

# Verificar si se pasó la flag -r
$noEjecutar = $args -contains "-r"

# Filtrar la flag -r de los argumentos reales
$argsFiltrados = $args | Where-Object { $_ -ne "-r" }
$unidad = $argsFiltrados[0]
$ejercicio = $argsFiltrados[1]

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
& $compilador $estandar $extra_info $ModeFlags "$archivo" -o "$salida"

# ✅ Verificar si la compilación fue exitosa
if ($LASTEXITCODE -eq 0) {
    Write-Host "✅ Compilación exitosa. Ejecutable: $salida"

    # ▶️ Ejecutar solo si NO se pidió omitir con -r
    if (-not $noEjecutar) {
        & ".\r.ps1" $unidad $ejercicio
    } else {
        Write-Host "⏩ Ejecución omitida por flag -r."
    }
} else {
    Write-Host "❌ Error al compilar el archivo."
}
