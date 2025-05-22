#!/usr/bin/env python3

# Descripción:
#   Este script aplica automáticamente el formateador `clang-format` a archivos fuente de C/C++
#   dentro del directorio actual y sus subdirectorios, excluyendo aquellos que se especifiquen
#   en un archivo de entorno `.env` (por defecto, `config.env`). Además, elimina carpetas
#   `__pycache__` encontradas durante el recorrido del árbol de directorios.
#
#   El archivo `.env` debe contener una variable `RESPUESTAS` con una lista de carpetas a excluir,
#   separadas por el carácter "|", por ejemplo:
#       RESPUESTAS=build|third_party|external
#
# Uso:
#   ./f.py
#   python3 f.py
#
# Comportamiento:
#   1. Lee las carpetas a excluir desde `config.env`.
#   2. Aplica `clang-format` a todos los archivos con extensiones fuente C/C++ (.cpp, .hpp, .c, .h, etc.).
#   3. Elimina todas las carpetas `__pycache__` encontradas.

import os
import subprocess
from pathlib import Path
from dotenv import load_dotenv # type: ignore

def cargar_exclusiones(env_path="config.env"):
    load_dotenv(env_path)
    respuestas = os.getenv("RESPUESTAS", "")
    carpetas_excluidas = [Path(p.strip()) for p in respuestas.split("|") if p.strip()]
    return set(carpetas_excluidas)

def es_excluido(archivo, carpetas_excluidas):
    for carpeta in carpetas_excluidas:
        try:
            if carpeta.resolve() in archivo.resolve().parents:
                return True
        except FileNotFoundError:
            continue  # Por si el archivo es un symlink roto
    return False

def aplicar_clang_format(root_dir=".", carpetas_excluidas=None):
    extensiones = {".cpp", ".hpp", ".h", ".cc", ".cxx", ".c", ".hxx"}
    root_path = Path(root_dir).resolve()

    for archivo in root_path.rglob("*"):
        if archivo.suffix.lower() in extensiones and archivo.is_file():
            if not es_excluido(archivo, carpetas_excluidas):
                subprocess.run(["clang-format", "-i", str(archivo)], check=False)
                #print(f"Formateado: {archivo}")

def formatear():
    carpetas_excluidas = cargar_exclusiones()
    aplicar_clang_format(carpetas_excluidas=carpetas_excluidas)

def eliminar_pycache(directorio="."):
    for root, dirs, _ in os.walk(directorio):
        if "__pycache__" in dirs:
            path = os.path.join(root, "__pycache__")
            os.system(f'rmdir /S /Q "{path}"' if os.name == "nt" else f'rm -rf "{path}"')
            print(f"🗑️  Eliminado: {path}")

if __name__ == "__main__":
    formatear()
    eliminar_pycache()