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

# Crear carpeta de la unidad si no existe
directorio="Unidad ${unidad}"
mkdir -p "$directorio"

# Crear archivo del ejercicio
archivo="${directorio}/Ejercicio ${ejercicio}.cpp"

# Verificar si el archivo ya existe
if [ -e "$archivo" ]; then
    echo "El archivo '$archivo' ya existe."
else
    touch "$archivo"
    echo "// Unidad ${unidad} - Ejercicio ${ejercicio}" > "$archivo"
    echo "#include <iostream>" >> "$archivo"
    echo "" >> "$archivo"
    echo "using namespace std;" >> "$archivo"
    echo "" >> "$archivo"
    echo "int main() {" >> "$archivo"
    echo "    " >> "$archivo"
    echo "    return 0;" >> "$archivo"
    echo "}" >> "$archivo"
    echo "Archivo '$archivo' creado con éxito."
fi