#!/bin/bash

# Leer unidad y ejercicio desde argumentos si están presentes
unidad="$1"
ejercicio="$2"

# Si no se pasaron, pedirlos al usuario
if [ -z "$ejercicio" ]; then
    read -p "Ingresá el número de la unidad: " unidad
    read -p "Ingresá el nombre del ejercicio: " ejercicio
    echo ""
fi

# Construir path al archivo fuente
archivo="Unidad ${unidad}/Ejercicio ${ejercicio}.cpp"

# Verificar si el archivo existe
if [ ! -f "$archivo" ]; then
    echo "El archivo '$archivo' no existe."
    exit 1
fi

# Crear nombre para el ejecutable (puede ir a ./bin por ejemplo)
salida="Unidad ${unidad}/Ejercicio ${ejercicio}"

# Compilar con clang++
clang++ "$archivo" -o "$salida"

# Verificar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación exitosa. Ejecutable: $salida"
    if [ $# -eq 0 ] || [ $# -eq 2 ]; then
        ./r.sh "${unidad}" "${ejercicio}"
    fi
else
    echo ""
    echo "Error al compilar el archivo."
fi
