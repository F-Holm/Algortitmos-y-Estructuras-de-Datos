#!/usr/bin/env python3

import os
import sys
from pathlib import Path
from f import formatear

def pedir_input_si_falta(unidad, ejercicio):
    if not unidad:
        unidad = input("Ingresá el número de la unidad: ").strip()
    if not ejercicio:
        ejercicio = input("Ingresá el nombre del ejercicio: ").strip()
    print()
    return unidad, ejercicio

def crear_archivo(unidad, ejercicio):
    directorio = Path(f"Unidad {unidad}")
    directorio.mkdir(parents=True, exist_ok=True)

    archivo = directorio / f"Ejercicio {ejercicio}.cpp"

    if archivo.exists():
        print(f"El archivo '{archivo}' ya existe.")
    else:
        with archivo.open("w", encoding="utf-8") as f:
            f.write(f"// Unidad {unidad} - Ejercicio {ejercicio}\n")
            f.write("#include <iostream>\n\n")
            f.write("using namespace std;\n\n")
            f.write("int main() {\n")
            f.write("    ;\n")
            f.write("    return 0;\n")
            f.write("}\n")
        print(f"Archivo '{archivo}' creado con éxito.")

def nuevo_archivo():
    unidad = sys.argv[1] if len(sys.argv) > 2 else None
    ejercicio = sys.argv[2] if len(sys.argv) > 2 else None

    unidad, ejercicio = pedir_input_si_falta(unidad, ejercicio)
    crear_archivo(unidad, ejercicio)

def eliminar_pycache(directorio="."):
    for root, dirs, _ in os.walk(directorio):
        if "__pycache__" in dirs:
            path = os.path.join(root, "__pycache__")
            os.system(f'rmdir /S /Q "{path}"' if os.name == "nt" else f'rm -rf "{path}"')
            print(f"🗑️  Eliminado: {path}")

if __name__ == "__main__":
    nuevo_archivo()
    formatear()
    eliminar_pycache()
