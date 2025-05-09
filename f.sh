#!/bin/bash

for n in {1..5}; do
    dir="Unidad $n"

    if [ -d "$dir" ]; then
        # Solo archivos .cpp directamente dentro del directorio (no subcarpetas)
        for file in "$dir"/*.cpp; do
            [ -f "$file" ] && clang-format -i "$file"
        done
    fi
done
