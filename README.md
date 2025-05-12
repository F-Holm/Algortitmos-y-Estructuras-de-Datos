# Algoritmos y Estructuras de Datos

Repositorio para practicar y automatizar tareas relacionadas con algoritmos y estructuras de datos en C++, utilizando scripts compatibles con Linux y Windows.

---

## Requisitos

- Linux (Ubuntu) o Windows
- `clang++` (puede usarse otro compilador cambiando la variable `compilador` en los scripts)
- `clang-format`
- Bash o PowerShell 7.0.0+

---

## Instalación

### Windows

```bash
winget install --id Microsoft.PowerShell --source winget
winget install --id BrechtSanders.WinLibs.POSIX.UCRT.LLVM --source winget
```

### Linux (Ubuntu)

```bash
sudo apt update
sudo apt install clang clang-format
```

---

## Uso de Scripts

### Crear archivo C++

Crea un archivo `.cpp` en una carpeta correspondiente a una unidad y ejercicio.

```bash
./n.ps1 <unidad> <ejercicio> [k]
./n.sh  <unidad> <ejercicio> [k]
```

Parámetros:
- `<unidad>`: número de unidad (ej. 1)
- `<ejercicio>`: número de ejercicio (ej. 2)
- `[k]`: valor opcional para evitar la ejecución automática luego de compilar

| Sistema | Script |
|--------|--------|
| Windows | `./n.ps1` |
| Linux   | `./n.sh`  |

---

### Compilar archivo C++

Compila el archivo `.cpp` del ejercicio seleccionado.

```bash
./c.ps1 <unidad> <ejercicio> [k]
./c.sh  <unidad> <ejercicio> [k]
```

> Si se omiten los parámetros, se compila el archivo actual.

---

### Ejecutar programa compilado

```bash
./r.ps1
./r.sh
```

---

### Borrar archivos del `.gitignore`

Elimina ejecutables y archivos temporales listados en `.gitignore`.

```bash
./g.ps1
./g.sh
```

---

### Compilar todos los archivos `.cpp`

Compila todos los archivos `.cpp` del proyecto.

```bash
./build.ps1
./build.sh
```

---

### Formatear archivos `.cpp`

Formatea todos los archivos `.cpp` del directorio actual (no incluye subdirectorios).

```bash
./f.ps1
./f.sh
```

---

## Visualizar PDFs de apoyo

Este proyecto utiliza archivos PDF accesibles desde el explorador de archivos o el editor de texto.

| Sistema | Archivo sugerido |
|--------|-------------------|
| Windows | `bashtomoki1207.pdf` |
| Linux   | `tomoki1207.pdf`     |

---

## Ejemplos de uso

Crear el ejercicio 1 de la unidad 1:

```bash
./n.ps1 1 1      # Windows
./n.sh 1 1       # Linux
```

Compilar y ejecutar automáticamente:

```bash
./c.ps1 1 1      # Windows
./c.sh 1 1       # Linux
```

Evitar la ejecución automática:

```bash
./n.ps1 1 1 k    # Windows
./n.sh 1 1 k     # Linux
```

---
