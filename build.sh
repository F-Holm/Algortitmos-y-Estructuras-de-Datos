#!/usr/bin/env bash

# Configuración
compiler="clang++"
cpp_standard="-std=c++23"
extra_info="-Wall -Wextra"

# debug flags:
#mode_flags="-g -O0 -DDEBUG"
# release flags:
mode_flags="-O3 -DNDEBUG"

# Ejecutar script de formateo f.sh
source ./f.sh

# Buscar archivos .cpp
mapfile -t cpp_files < <(find "." -type f -name "*.cpp")
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
max_jobs=100000
running_jobs=0

compile() {
  local file="$1"
  local exe_name="${file%.cpp}"
  local log_file="$tmp_dir/$(basename "$file").log"

  "$compiler" $cpp_standard $extra_info $mode_flags -o "$exe_name" "$file" &> "$log_file"
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
        echo "---------------"
        ;;
      error)
        ((count_error++))
        echo "Errores en $file:"
        cat "$log_file"
        echo "---------------"
        ;;
    esac
  done < "$tmp_dir/resultados"
fi

# Mostrar resumen
echo "Resumen final:"
echo "  Compilaciones exitosas         : $count_success"
echo "  Compilaciones con advertencias : $count_warning"
echo "  Compilaciones fallidas         : $count_error"
