#!/usr/bin/env python3

import os
import subprocess
from pathlib import Path
from dotenv import load_dotenv

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

if __name__ == "__main__":
    formatear()
