# Detener ejecución en caso de error
$ErrorActionPreference = "Stop"

# 🔧 Configuración
$compilador = "clang++"       # También podés usar g++
$optimizaciones = "-O3"       # -O0 para desactivar optimización
$debug = $true                # $true para debug, $false para release
$estandar = "c++23"           # Clang++ defaulta a C++98 si no se especifica

# ⚙️ Ajustes según modo debug
$extra_flags = ""
if ($debug) {
    $extra_flags = "-g"
    $optimizaciones = "-O0"
}

# 📥 Leer argumentos
#param (
#    [string]$unidad,
#    [string]$ejercicio
#)
# En vez de usar 'param', usa $args directamente
$unidad = $args[0]
$ejercicio = $args[1]


if (-not $ejercicio) {
    $unidad = Read-Host "Ingresá el número de la unidad"
    $ejercicio = Read-Host "Ingresá el nombre del ejercicio"
    Write-Host ""
}

# Construir paths
$archivo = "Unidad $unidad\Ejercicio $ejercicio.cpp"
$salida = "Unidad $unidad\Ejercicio $ejercicio.exe"

# 📁 Verificar existencia del archivo
if (-not (Test-Path $archivo)) {
    Write-Host "❌ El archivo '$archivo' no existe."
    exit 1
}

# 🛠 Compilar
Write-Host "🔧 Compilando con $compilador -std=$estandar $optimizaciones $extra_flags..."
& $compilador "-std=$estandar" $optimizaciones $extra_flags "$archivo" -o "$salida"

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
