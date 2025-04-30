#!/bin/bash

set -e

# 🔧 Variables configurables
compilador="clang++"         # Podés usar g++ si preferís
optimizaciones="-O3"         # Sin optimización: -O0
debug=true                   # true para debug (símbolos de depuración), false para release
estandar="c++23"             # Clang++ defaulta a c++98 si no se especifica

# ⚙️ Configuración según modo debug
extra_flags=""
if [ "$debug" = true ]; then
    extra_flags="-g"
    optimizaciones="-O0"
fi

# 📥 Leer argumentos si están presentes
unidad="$1"
ejercicio="$2"

if [ -z "$ejercicio" ]; then
    read -p "Ingresá el número de la unidad: " unidad
    read -p "Ingresá el nombre del ejercicio: " ejercicio
    echo ""
fi

archivo="Unidad ${unidad}/Ejercicio ${ejercicio}.cpp"
salida="Unidad ${unidad}/Ejercicio ${ejercicio}"

# 📁 Verificar existencia del archivo fuente
if [ ! -f "$archivo" ]; then
    echo "❌ El archivo '$archivo' no existe."
    exit 1
fi

# 🛠 Compilar
echo "🔧 Compilando con $compilador -std=$estandar $optimizaciones $extra_flags..."
if "$compilador" -std="$estandar" $optimizaciones $extra_flags "$archivo" -o "$salida"; then
    echo "✅ Compilación exitosa. Ejecutable: $salida"

    # ▶️ Ejecutar si no se pasó ningún argumento o ambos
    if [ $# -eq 0 ] || [ $# -eq 2 ]; then
        ./r.sh "${unidad}" "${ejercicio}"
    fi
else
    echo "❌ Error al compilar el archivo."
fi
