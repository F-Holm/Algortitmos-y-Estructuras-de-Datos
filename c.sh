#!/bin/bash

# Formatear todos los archivos
source ./f.sh

set -e

# Configuración
compilador="clang++"
estandar="-std=c++23"
extra_info="-Wextra"

# debug flags:
mode_flags="-g -O0 -DDEBUG"
# release flags:
#mode_flags="-O3 -DNDEBUG"

# 📥 Leer argumentos si están presentes
unidad="$1"
ejercicio="$2"

if [ -z "$ejercicio" ]; then
    read -p "Ingresá el número de la unidad: " unidad
    read -p "Ingresá el nombre del ejercicio: " ejercicio
    echo ""
fi

archivo="./Unidad ${unidad}/Ejercicio ${ejercicio}.cpp"
salida="./Unidad ${unidad}/Ejercicio ${ejercicio}"

# 📁 Verificar existencia del archivo fuente
if [ ! -f "$archivo" ]; then
    echo "❌ El archivo '$archivo' no existe."
    exit 1
fi

# 🛠 Compilar
echo "🔧 Compilando con $compilador $estandar $mode_flags $extra_info..."
# "-finput-charset=utf-8" "-DUNICODE" "-fexec-charset=utf-8"
if "$compilador" $estandar $mode_flags $extra_info "$archivo" -o "$salida"; then
    echo "✅ Compilación exitosa. Ejecutable: $salida"

    # ▶️ Ejecutar si no se pasó ningún argumento o ambos
    if [ $# -eq 0 ] || [ $# -eq 2 ]; then
        ./r.sh "${unidad}" "${ejercicio}"
    fi
else
    echo "❌ Error al compilar el archivo."
fi
