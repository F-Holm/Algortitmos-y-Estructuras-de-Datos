#!/bin/bash

# Formatear todos los archivos
source ./f.sh

set -e

# Configuración
compilador="clang++"
estandar="-std=c++23"
extra_info="-Wall -Wextra"

# debug flags:
mode_flags="-g -O0 -DDEBUG"
# release flags:
#mode_flags="-O3 -DNDEBUG"

# Detectar si se pasó la flag -r
no_ejecutar=false
args_filtrados=()

for arg in "$@"; do
    if [ "$arg" = "-r" ]; then
        no_ejecutar=true
    else
        args_filtrados+=("$arg")
    fi
done

# 📥 Leer unidad y ejercicio
unidad="${args_filtrados[0]}"
ejercicio="${args_filtrados[1]}"

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

    # ▶️ Ejecutar solo si no se pasó la flag -r
    if [ "$no_ejecutar" = false ]; then
        ./r.sh "${unidad}" "${ejercicio}"
    else
        echo "⏩ Ejecución omitida por flag -r."
    fi
else
    echo "❌ Error al compilar el archivo."
fi
