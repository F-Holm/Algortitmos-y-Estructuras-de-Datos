#!/usr/bin/env python3

import subprocess
from f import formatear

def git_clean():
    # Ejecuta: git clean -Xfd
    subprocess.run(["git", "clean", "-Xfd"], check=True)

if __name__ == "__main__":
    git_clean()
    formatear()
