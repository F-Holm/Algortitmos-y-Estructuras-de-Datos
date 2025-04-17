#!/bin/bash

# Leer unidad y ejercicio desde argumentos si están presentes
unidad="$1"
ejercicio="$2"

# Si no se pasaron, pedirlos al usuario
if [ -z "$unidad" ]; then
    read -p "Ingresá el número de la unidad: " unidad
    echo ""
fi

if [ -z "$ejercicio" ]; then
    read -p "Ingresá el nombre del ejercicio: " ejercicio
    echo ""
fi

# Construir path del ejecutable
ejecutable="Unidad ${unidad}/Ejercicio ${ejercicio}"

# Verificar si el ejecutable existe
if [ ! -f "$ejecutable" ]; then
    echo "El ejecutable '$ejecutable' no existe."
    exit 1
fi

# Dar permisos de ejecución por si acaso
#chmod +x "$ejecutable"

# Ejecutar el binario
echo "Ejecutando: $ejecutable"
echo ""

"$ejecutable"
