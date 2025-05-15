#!/usr/bin/env python3

import os
import sys
import subprocess
from pathlib import Path
import platform
from f import formatear

def pedir_entrada_si_falta(unidad, ejercicio):
    if not unidad:
        unidad = input("Ingresá el número de la unidad: ").strip()
    if not ejercicio:
        ejercicio = input("Ingresá el nombre del ejercicio: ").strip()
    print()
    return unidad, ejercicio

def construir_path_ejecutable(unidad, ejercicio):
    base = Path(f"Unidad {unidad}")
    nombre = f"Ejercicio {ejercicio}"
    if platform.system() == "Windows":
        archivo = base / f"{nombre}.exe"
    else:
        archivo = base / nombre
    return archivo

def quitar_solo_lectura(path: Path):
    try:
        if path.stat().st_file_attributes & 0x01:  # ATRIB_READONLY en Windows
            print("El archivo es de solo lectura. Quitando atributo...")
            os.chmod(path, path.stat().st_mode | 0o222)  # Agrega permiso de escritura
    except AttributeError:
        # En sistemas Unix no aplica
        pass

def ejecutar():
    unidad = sys.argv[1] if len(sys.argv) > 2 else None
    ejercicio = sys.argv[2] if len(sys.argv) > 2 else None

    unidad, ejercicio = pedir_entrada_si_falta(unidad, ejercicio)
    ejecutable = construir_path_ejecutable(unidad, ejercicio)

    if not ejecutable.exists():
        print(f"El ejecutable '{ejecutable}' no existe.")
        sys.exit(1)

    quitar_solo_lectura(ejecutable)

    print(f"Ejecutando: {ejecutable}\n")
    # Ejecutar el binario
    try:
        subprocess.run([str(ejecutable)], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error ejecutando el archivo: {e}")
        sys.exit(e.returncode)

if __name__ == "__main__":
    ejecutar()
    formatear()
