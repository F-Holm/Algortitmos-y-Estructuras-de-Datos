#!/bin/bash

set -e

ROOT_DIR=$(pwd)
FAILED=()

echo "🔍 Buscando archivos .cpp..."
mapfile -t CPP_FILES < <(find "$ROOT_DIR" -type f -name "*.cpp")

echo "🛠 Compilando con Clang++, optimización -O3..."

for SRC_FILE in "${CPP_FILES[@]}"; do
    REL_DIR=$(dirname "$SRC_FILE")
    EXEC_NAME=$(basename "$SRC_FILE" .cpp)
    OUT_PATH="$REL_DIR/$EXEC_NAME"

    echo "🔧 Compilando $SRC_FILE..."
    if clang++ -std=c++17 -O3 "$SRC_FILE" -o "$OUT_PATH"; then
        echo "✅ Compilado: $OUT_PATH"
    else
        echo "❌ Error al compilar: $SRC_FILE"
        FAILED+=("$SRC_FILE")
    fi
done

echo ""
if [ ${#FAILED[@]} -ne 0 ]; then
    echo "⚠️ Fallaron los siguientes archivos:"
    for F in "${FAILED[@]}"; do
        echo "   - $F"
    done
else
    echo "🎉 Todos los archivos se compilaron correctamente."
fi

echo "🧹 Limpiando archivos intermedios..."
# No hay archivos intermedios si no usás CMake, pero podés limpiar .o si existiera
find "$ROOT_DIR" -type f -name "*.o" -delete
echo "✅ Limpieza completada."
