#!/usr/bin/env python3

# Descripción:
#	Este script limpia el repositorio eliminando todos los archivos ignorados por Git
#	(usando `git clean -Xfd`) y luego aplica `clang-format` a los archivos fuente del proyecto,
#	excluyendo las carpetas definidas en `config.env`.
#
# Uso:
#	python3 g.py
#	./g.py

import subprocess
from f import formatear

def git_clean():
    subprocess.run(["git", "clean", "-Xfd"], check=True)

if __name__ == "__main__":
    git_clean()
    formatear()
