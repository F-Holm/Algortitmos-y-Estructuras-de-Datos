# Algoritmos y Estructuras de Datos
---
## Requisitos

- Linux (Ubuntu) | Windows
- clang++ (pueden usarse otros compiladores pero se debe cambiar la variable "compilador" en los scripts)
- Bash | Powershell 7.0.0+
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

```bash
./c.ps1
```
#### Linux
```bash
./c.sh
```

### Ejecutar

```bash
./r.ps1
```
#### Linux
```bash
./r.sh
```

### Borrar ejecutables y otros archivos del .gitignore

```bash
./g.ps1
```
#### Linux
```bash
./g.sh
```
---
## Más Scripts

### Tanto en la creación, compilación y ejecución de archivos se puede usar el siguiente script:

```bash
./n.ps1 ${unidad} ${ejercicio}
```
#### Linux
```bash
./n.sh ${unidad} ${ejercicio}
```

#### Por ejemplo, para crear el ejercicio 1 de la unidad 1 hacés lo siguiente:

```bash
./n.ps1 1 1
```
#### Linux
```bash
./n.sh 1 1
```

### Cuando compilás, se ejecuta automáticamente. Si no querés esto le tenés que pasar cualquier valor extra sin espacios:

```bash
./n.sh K
```
#### También se puede hacer así:
```bash
./n.sh 1 1 K
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