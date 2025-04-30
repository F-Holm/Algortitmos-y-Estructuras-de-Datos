# Leer unidad y ejercicio desde los argumentos si están presentes
param (
    [string]$unidad,
    [string]$ejercicio
)

# Si no se pasaron, pedirlos al usuario
if (-not $unidad) {
    $unidad = Read-Host "Ingresá el número de la unidad"
    Write-Host ""
}

if (-not $ejercicio) {
    $ejercicio = Read-Host "Ingresá el nombre del ejercicio"
    Write-Host ""
}

# Crear carpeta de la unidad si no existe
$directorio = "Unidad $unidad"
if (-not (Test-Path $directorio)) {
    New-Item -ItemType Directory -Force -Path $directorio
}

# Crear archivo del ejercicio
$archivo = "$directorio\Ejercicio $ejercicio.cpp"

# Verificar si el archivo ya existe
if (Test-Path $archivo) {
    Write-Host "El archivo '$archivo' ya existe."
} else {
    # Crear archivo y escribir contenido
    New-Item -ItemType File -Force -Path $archivo
    $contenido = @"
        // Unidad $unidad - Ejercicio $ejercicio
        #include <iostream>

        using namespace std;

        int main() {
            
            return 0;
        }
"@
    Set-Content -Path $archivo -Value $contenido
    Write-Host "Archivo '$archivo' creado con éxito."
}
