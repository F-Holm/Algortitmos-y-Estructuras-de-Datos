# Algoritmos y Estructuras de Datos
---
## Requisitos

- Linux (Ubuntu) o Windows
- clang++ (pueden usarse otros compiladores pero se debe cambiar la variable "compilador" en los scripts)
- clang-format
- Bash o Powershell 7.0.0+

---

## Instalación

### Windows

```bash
winget install --id Microsoft.PowerShell --source winget
```
```bash
winget install --id BrechtSanders.WinLibs.POSIX.UCRT.LLVM --source winget
```

### Linux (Ubuntu)

```bash
sudo apt update
```
```bash
sudo apt install clang clang-format
```

---

## Estilo de código

Este proyecto sigue la [Guía de Estilo de C++ de Google](https://google.github.io/styleguide/cppguide.html) para mantener la consistencia y legibilidad del código. El script de formateo utiliza `clang-format` configurado según esta guía.


---

## Scripts

### Crear archivo C++

#### Windows
```bash
./n.ps1
```
#### Linux
```bash
./n.sh
```

### Compilar archivo C++

#### Windows
```bash
./c.ps1
```
#### Linux
```bash
./c.sh
```

### Ejecutar

#### Windows
```bash
./r.ps1
```
#### Linux
```bash
./r.sh
```

### Borrar ejecutables y otros archivos nombrados en .gitignore

#### Windows
```bash
./g.ps1
```
#### Linux
```bash
./g.sh
```

### Compilar todos los archivos ".cpp"

#### Windows
```bash
./build.ps1
```
#### Linux
```bash
./build.sh
```

### Formatear todos los archivos (no incluye subdirectorios)
Este script se ejecuta automáticamente cada vez que utilizas otro script

#### Windows
```bash
./f.ps1
```
#### Linux
```bash
./f.sh
```
---
## Más Scripts

Tanto en la creación, compilación y ejecución de archivos se puede usar el siguiente script:

#### Windows
```bash
./${archivo_script} ${unidad} ${ejercicio}
```
#### Linux
```bash
./${archivo_script} ${unidad} ${ejercicio}
```

Por ejemplo, para crear el ejercicio 1 de la unidad 1 podés hacer lo siguiente:

#### Windows
```bash
./n.ps1 1 1
```
#### Linux
```bash
./n.sh 1 1
```

Cuando se utiliza el script de compilación, se ejecuta automáticamente. Si no querés que esto suceda, se debe pasar cualquier valor extra sin espacios:

#### Windows
```bash
./c.ps1 k
```
#### Linux
```bash
./c.sh k
```

También se puede hacer así:
(En este caso compilaría el ejercico 1 de la unidad 1)

#### Windows
```bash
./c.ps1 1 1 k
```
#### Linux
```bash
./c.sh 1 1 k
```

---

## Leer PDFs

Se puede utilizar la siguiente extensión de VS Code ára ver PDFs:

#### Windows
```bash
bashtomoki1207.pdf
```
#### Linux
```bash
tomoki1207.pdf
```