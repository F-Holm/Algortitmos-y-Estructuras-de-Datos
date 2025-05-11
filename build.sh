#!/usr/bin/env bash

# Valores por defecto
root_dir="."                  # Directorio raíz de búsqueda
output_dir="./build"          # Directorio de salida (no usado actualmente)
compiler="clang++"            # Compilador por defecto
flags="-Wextra"               # Flags de compilación por defecto

# Parseo de argumentos
while getopts ":r:o:c:f:" opt; do
  case $opt in
    r) root_dir="$OPTARG" ;;
    o) output_dir="$OPTARG" ;;
    c) compiler="$OPTARG" ;;
    f) flags="$OPTARG" ;;
    \?) echo "Opcion invalida: -$OPTARG" >&2; exit 1 ;;
    :) echo "La opcion -$OPTARG requiere un argumento." >&2; exit 1 ;;
  esac
done
shift $((OPTIND -1))

# Ejecutar script auxiliar f.sh
if [[ -f "./f.sh" ]]; then
  source ./f.sh
else
  echo "Advertencia: f.sh no encontrado, se omite." >&2
fi

#mkdir -p "$output_dir"

# Buscar archivos .cpp
mapfile -t cpp_files < <(find "$root_dir" -type f -name "*.cpp")
total=${#cpp_files[@]}
count=0

# Resultados
count_success=0
count_warning=0
count_error=0

# Archivos temporales para almacenar salida
tmp_dir=$(mktemp -d)
trap 'rm -rf "$tmp_dir"' EXIT

# Compilar archivos en paralelo sin "parallel"
max_jobs=4  # Cambiar esto para ajustar el número de procesos simultáneos
running_jobs=0

compile() {
  local file="$1"
  local exe_name="${file%.cpp}"
  local log_file="$tmp_dir/$(basename "$file").log"

  "$compiler" $flags -o "$exe_name" "$file" &> "$log_file"
  local code=$?

  if (( code != 0 )); then
    echo "error;$file" >> "$tmp_dir/resultados"
  elif grep -qi "warning:" "$log_file"; then
    echo "warning;$file" >> "$tmp_dir/resultados"
  else
    echo "success;$file" >> "$tmp_dir/resultados"
  fi
}

for file in "${cpp_files[@]}"; do
  compile "$file" &
  ((running_jobs+=1))

  if (( running_jobs >= max_jobs )); then
    wait -n
    ((running_jobs-=1))
  fi

  ((count++))
  percent=$(( count * 100 / total ))
  echo -ne "Compilando... $count/$total ($percent%)\r"
done

wait

echo -e "\n\nResultados de compilación:"

# Analizar resultados
if [[ -f "$tmp_dir/resultados" ]]; then
  while IFS=';' read -r status file; do
    log_file="$tmp_dir/$(basename "$file").log"
    case $status in
      success)
        ((count_success++))
        ;;
      warning)
        ((count_warning++))
        echo "Advertencias en $file:"
        cat "$log_file"
        echo "-----"
        ;;
      error)
        ((count_error++))
        echo "Errores en $file:"
        cat "$log_file"
        echo "-----"
        ;;
    esac
  done < "$tmp_dir/resultados"
fi

# Mostrar resumen
echo "Resumen final:"
echo "  Compilaciones exitosas (sin advertencias): $count_success"
echo "  Compilaciones con advertencias           : $count_warning"
echo "  Compilaciones fallidas (errores)         : $count_error"
