#!/usr/bin/env python3

import os
import sys
import subprocess
from pathlib import Path
from dotenv import dotenv_values # type: ignore
from f import formatear
from r import ejecutar

def cargar_config(env_path="config.env"):
    config = dotenv_values(env_path)
    
    modo_build = config.get("MODO_COMPILACION", "").strip('"')
    if modo_build == "R":
        mode_flags = config.get("RELEASE_FLAGS", "")
    elif modo_build == "D":
        mode_flags = config.get("DEBUG_FLAGS", "")
    else:
        raise ValueError(f'MODO_COMPILACION inválido: "{modo_build}"')
    
    return {
        "COMPILADOR": config.get("COMPILADOR", ""),
        "ESTANDAR": config.get("ESTANDAR", ""),
        "EXTRA_INFO": config.get("EXTRA_INFO", ""),
        "MODE_FLAGS": mode_flags,
        "RESPUESTAS": config.get("RESPUESTAS", ""),
    }

def parsear_args(args):
    no_ejecutar = False
    args_filtrados = []

    for arg in args:
        if arg == "-r":
            no_ejecutar = True
        else:
            args_filtrados.append(arg)

    return no_ejecutar, args_filtrados

def pedir_unidad_ejercicio(args_filtrados):
    unidad = args_filtrados[0] if len(args_filtrados) > 1 else None
    ejercicio = args_filtrados[1] if len(args_filtrados) > 1 else None

    if not ejercicio:
        unidad = input("Ingresá el número de la unidad: ").strip()
        ejercicio = input("Ingresá el nombre del ejercicio: ").strip()
        print()
    return unidad, ejercicio

def compilar(config, unidad, ejercicio):
    archivo = Path(f"./Unidad {unidad}/Ejercicio {ejercicio}.cpp")
    salida = Path(f"./Unidad {unidad}/Ejercicio {ejercicio}")

    if not archivo.is_file():
        print(f"❌ El archivo '{archivo}' no existe.")
        sys.exit(1)

    compilador = config["COMPILADOR"]
    estandar = config["ESTANDAR"]
    extra_info = config["EXTRA_INFO"]
    mode_flags = config["MODE_FLAGS"]

    print(f"🔧 Compilando con {compilador} {estandar} {mode_flags} {extra_info}...")

    cmd = [
        compilador,
        *estandar.split(),
        *mode_flags.split(),
        *extra_info.split(),
        str(archivo),
        "-o",
        str(salida)
    ]

    try:
        subprocess.run(cmd, check=True)
        print(f"✅ Compilación exitosa. Ejecutable: {salida}")
        return salida
    except subprocess.CalledProcessError:
        print("❌ Error al compilar el archivo.")
        return None

def comp():
    config = cargar_config()

    no_ejecutar, args_filtrados = parsear_args(sys.argv[1:])
    unidad, ejercicio = pedir_unidad_ejercicio(args_filtrados)

    ejecutable = compilar(config, unidad, ejercicio)

    if ejecutable and not no_ejecutar:
        print(f"▶️ Ejecutando {ejecutable}:\n")
        ejecutar()
    elif no_ejecutar:
        print("⏩ Ejecución omitida por flag -r.")

if __name__ == "__main__":
    formatear()
    comp()
