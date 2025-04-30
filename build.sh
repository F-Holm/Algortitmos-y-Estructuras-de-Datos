#!/bin/bash

set -e

# 🔧 Variables configurables
compilador="clang++"         # Podés cambiar a g++ u otro
optimizaciones="-O3"         # Para sin optimización: usar "-O0"
debug=false                  # true para debug, false para release
estandar="c++23"             # Si no se especifica, clang++ usa c++98 como default

# 🧠 Ajustes según debug
extra_flags=""
if [ "$debug" = true ]; then
    extra_flags="-g"  # Genera información de depuración
    optimizaciones="-O0"  # Generalmente se combina -g con -O0
fi

ROOT_DIR=$(pwd)
FAILED=()

echo "🔍 Buscando archivos .cpp..."
mapfile -t CPP_FILES < <(find "$ROOT_DIR" -type f -name "*.cpp")

echo "🛠 Compilando con $compilador, estándar $estandar, optimización $optimizaciones..."

for SRC_FILE in "${CPP_FILES[@]}"; do
    REL_DIR=$(dirname "$SRC_FILE")
    EXEC_NAME=$(basename "$SRC_FILE" .cpp)
    OUT_PATH="$REL_DIR/$EXEC_NAME"

    echo "🔧 Compilando $SRC_FILE..."
    if "$compilador" -std="$estandar" $optimizaciones $extra_flags "$SRC_FILE" -o "$OUT_PATH"; then
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
find "$ROOT_DIR" -type f -name "*.o" -delete
echo "✅ Limpieza completada."
