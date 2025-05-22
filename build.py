#!/usr/bin/env python3

# Descripción:
#	Este script busca y compila todos los archivos `.cpp` del proyecto, aplicando
#	los flags definidos en el archivo `config.env`. La compilación se realiza en paralelo
#	y se detectan advertencias y errores de compilación.
#
#	Antes de compilar, se aplica `clang-format` a los archivos fuente.
#	Después de compilar, se eliminan carpetas `__pycache__`.
#
# Funcionalidades:
#	- Lectura de configuración desde `config.env`:
#		- COMPILADOR, ESTANDAR, EXTRA_INFO, MODO_BUILD (R/D), RELEASE_FLAGS/DEBUG_FLAGS, RESPUESTAS
#	- Compilación concurrente de archivos `.cpp`.
#	- Detección de errores y advertencias por archivo.
#	- Reporte de progreso en tiempo real.
#	- Resultados detallados y resumen final de compilación.
#
# Flags (opcionales):
#	-e          Excluye las carpetas listadas en RESPUESTAS del archivo `config.env`.
#
# Uso:
#	python3 build.py [-e]
#	./build.py [-e]

import subprocess
import tempfile
import sys
from pathlib import Path
from dotenv import dotenv_values # type: ignore
import concurrent.futures
import threading
from f import formatear, eliminar_pycache

# Para imprimir el progreso sin que se interrumpa con los hilos
print_lock = threading.Lock()
file_lock = threading.Lock()


def cargar_config(env_path="config.env"):
    config = dotenv_values(env_path)
    
    modo_build = config.get("MODO_BUILD", "").strip('"')
    if modo_build == "R":
        mode_flags = config.get("RELEASE_FLAGS", "")
    elif modo_build == "D":
        mode_flags = config.get("DEBUG_FLAGS", "")
    else:
        raise ValueError(f'MODO_BUILD inválido: "{modo_build}"')
    
    return {
        "COMPILADOR": config.get("COMPILADOR", ""),
        "ESTANDAR": config.get("ESTANDAR", ""),
        "EXTRA_INFO": config.get("EXTRA_INFO", ""),
        "MODE_FLAGS": mode_flags,
        "RESPUESTAS": config.get("RESPUESTAS", ""),
    }

def cargar_configuracion(path="config.env"):
    config = dotenv_values(path)

    modo_build = config.get("MODO_BUILD", "").strip('"')

    resultado = {
        k: v for k, v in config.items()
        if k not in ("MODO_BUILD", "MODO_COMPILACION", "DEBUG_FLAGS", "RELEASE_FLAGS")
    }

    if modo_build == "R":
        resultado["MODO"] = config.get("RELEASE_FLAGS", "")
    elif modo_build == "D":
        resultado["FLAGS"] = config.get("DEBUG_FLAGS", "")
    else:
        raise ValueError(f'MODO_BUILD inválido: "{modo_build}"')

    return resultado

def parsear_respuestas(resp_str):
    # Separa por | y limpia espacios
    paths = [p.strip() for p in resp_str.split("|") if p.strip()]
    # Pasar a Path absolutos para comparar
    return [Path(p).resolve() for p in paths]

def es_excluido(archivo: Path, carpetas_excluidas):
    for carpeta in carpetas_excluidas:
        try:
            if carpeta in archivo.resolve().parents:
                return True
        except Exception:
            continue
    return False

def buscar_cpp_files(root_dir=".", carpetas_excluidas=None):
    root_path = Path(root_dir).resolve()
    archivos = []
    for f in root_path.rglob("*.cpp"):
        if carpetas_excluidas and es_excluido(f, carpetas_excluidas):
            continue
        archivos.append(f)
    return archivos

def compilar(file: Path, compiler, cpp_standard, extra_info, mode_flags, tmp_dir: Path):
    exe_name = file.with_suffix("")  # sin .cpp
    log_file = tmp_dir / f"{file.name}.log"
    
    # Construir comando
    cmd = [
        compiler,
        cpp_standard,
        *extra_info.split(),
        *mode_flags.split(),
        "-o",
        str(exe_name),
        str(file)
    ]

    with open(log_file, "w") as logf:
        proceso = subprocess.run(cmd, stdout=logf, stderr=subprocess.STDOUT)
        code = proceso.returncode

    # Analizar log para warnings
    with open(log_file, "r") as logf:
        contenido = logf.read()

    if code != 0:
        estado = "error"
    elif "warning:" in contenido.lower():
        estado = "warning"
    else:
        estado = "success"

    return estado, file, log_file

def build():
    # Leer flag -e
    excluir = False
    if "-e" in sys.argv:
        excluir = True

    config = cargar_config()
    compiler = config["COMPILADOR"]
    cpp_standard = config["ESTANDAR"]
    extra_info = config["EXTRA_INFO"]
    mode_flags = config["MODE_FLAGS"]
    respuestas_raw = config["RESPUESTAS"]
    carpetas_excluidas = parsear_respuestas(respuestas_raw) if excluir else []

    print(f"🔧 Compilando con {compiler} {cpp_standard} {mode_flags} {extra_info}...")
    
    # Buscar archivos
    cpp_files = buscar_cpp_files(".", carpetas_excluidas)
    total = len(cpp_files)

    count = 0
    count_success = 0
    count_warning = 0
    count_error = 0

    with tempfile.TemporaryDirectory() as tmpdirname:
        tmp_dir = Path(tmpdirname)

        resultados_path = tmp_dir / "resultados"
        resultados_path.write_text("")  # archivo vacío

        max_workers = 8  # limitamos la concurrencia para no saturar CPU/disk

        def tarea(file):
            nonlocal count
            estado, f, log = compilar(file, compiler, cpp_standard, extra_info, mode_flags, tmp_dir)

            with print_lock:
                count += 1
                percent = int(count * 100 / total) if total > 0 else 100
                print(f"Compilando... {count}/{total} ({percent}%)\r", end="", flush=True)

            # Guardar resultado
            with file_lock:
                with resultados_path.open("a") as resf:
                    resf.write(f"{estado};{str(f)}\n")

            return estado, f, log

        with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
            futures = [executor.submit(tarea, f) for f in cpp_files]
            concurrent.futures.wait(futures)

        print("\n\nResultados de compilación:\n")

        # Leer y analizar resultados
        if resultados_path.exists():
            with resultados_path.open() as resf:
                for linea in resf:
                    linea = linea.strip()
                    if not linea:
                        continue
                    status, file_str = linea.split(";", 1)
                    log_file = tmp_dir / f"{Path(file_str).name}.log"

                    if status == "success":
                        count_success += 1
                    elif status == "warning":
                        count_warning += 1
                        print(f"Advertencias en {file_str}:")
                        print(log_file.read_text())
                        print("---------------")
                    elif status == "error":
                        count_error += 1
                        print(f"Errores en {file_str}:")
                        print(log_file.read_text())
                        print("---------------")

        print("Resumen final:")
        print(f"  Compilaciones exitosas         : {count_success}")
        print(f"  Compilaciones con advertencias : {count_warning}")
        print(f"  Compilaciones fallidas         : {count_error}")

if __name__ == "__main__":
    formatear()
    build()
    eliminar_pycache()
