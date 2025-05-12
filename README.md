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

### Borrar ejecutables y otros archivos del .gitignore

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

### Tanto en la creación, compilación y ejecución de archivos se puede usar el siguiente script:

#### Windows
```bash
./c.ps1 ${unidad} ${ejercicio}
```
#### Linux
```bash
./c.sh ${unidad} ${ejercicio}
```

#### Por ejemplo, para crear el ejercicio 1 de la unidad 1 hacés lo siguiente:

#### Windows
```bash
./n.ps1 1 1
```
#### Linux
```bash
./n.sh 1 1
```

### Cuando compilás, se ejecuta automáticamente. Si no querés esto le tenés que pasar cualquier valor extra sin espacios:

#### Windows
```bash
./n.ps1 k
```
#### Linux
```bash
./n.sh k
```

#### También se puede hacer así:

#### Windows
```bash
./n.ps1 1 1 k
```
#### Linux
```bash
./n.sh 1 1 k
```

---

## Leer PDFs

### Se puede utilizar la extensión de VS Code:
#### Windows
```bash
bashtomoki1207.pdf
```
#### Linux
```bash
tomoki1207.pdf
```