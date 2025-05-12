#!/usr/bin/env pwsh

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

# Construir path del ejecutable
$ejecutable = "Unidad $unidad\Ejercicio $ejercicio.exe"

# Verificar si el ejecutable existe
if (-not (Test-Path $ejecutable)) {
    Write-Host "El ejecutable '$ejecutable' no existe."
    exit 1
}

# Dar permisos de ejecución por si acaso
# En Windows no es necesario dar permisos explícitos como en Linux, pero se puede verificar el atributo de sólo lectura
if ((Get-Item $ejecutable).IsReadOnly) {
    Write-Host "El archivo es de solo lectura. Quitando atributo..."
    (Get-Item $ejecutable).IsReadOnly = $false
}

# Ejecutar el binario
Write-Host "Ejecutando: $ejecutable"
Write-Host ""

# Ejecutar el archivo
& "$ejecutable"
