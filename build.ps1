# Configuración de variables
$compilador = "clang++"         # Puedes cambiar a g++ u otro
$optimizaciones = "-O3"         # Para sin optimización: usar "-O0"
$debug = $false                 # $true para debug, $false para release
$estandar = "c++23"             # Si no se especifica, clang++ usa c++98 por defecto

# Ajustes según modo debug
$extra_flags = ""
if ($debug) {
    $extra_flags = "-g"  # Genera información de depuración
    $optimizaciones = "-O0"  # Generalmente se combina -g con -O0
}

$ROOT_DIR = Get-Location
$FAILED = @()

Write-Host "🔍 Buscando archivos .cpp..."

# Buscar todos los archivos .cpp
$CPP_FILES = Get-ChildItem -Path $ROOT_DIR -Recurse -Filter "*.cpp" | Select-Object -ExpandProperty FullName

Write-Host "🛠 Compilando con $compilador, estándar $estandar, optimización $optimizaciones..."

foreach ($SRC_FILE in $CPP_FILES) {
    $REL_DIR = [System.IO.Path]::GetDirectoryName($SRC_FILE)
    $EXEC_NAME = [System.IO.Path]::GetFileNameWithoutExtension($SRC_FILE)
    $OUT_PATH = "$REL_DIR\$EXEC_NAME.exe"

    Write-Host "🔧 Compilando $SRC_FILE..."
    try {
        & $compilador "-std=$estandar" $optimizaciones $extra_flags $SRC_FILE "-o" $OUT_PATH
        Write-Host "✅ Compilado: $OUT_PATH"
    } catch {
        Write-Host "❌ Error al compilar: $SRC_FILE"
        $FAILED += $SRC_FILE
    }
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

# Eliminar archivos intermedios (.o)
Get-ChildItem -Path $ROOT_DIR -Recurse -Filter "*.o" | Remove-Item

Write-Host "✅ Limpieza completada."
