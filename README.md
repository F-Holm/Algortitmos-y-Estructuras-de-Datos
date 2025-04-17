# Algoritmos y Estructuras de Datos
---
## Requisitos

- Linux (Ubuntu)
- clang++
- Bash
---
## Scripts

### Crear archivo C++

```bash
./n.sh
```

### Compilar archivo C++

```bash
./c.sh
```

### Ejecutar

```bash
./e.sh
```

### Borrar ejecutables y otros archivos del .gitignore

```bash
./g.sh
```
---
## Más Scripts

#### Tanto en la creación, compilación y ejecución de archivos se puede usar el siguiente script:

```bash
./n.sh ${unidad} ${ejercicio}
```

##### Por ejemplo, para crear el ejercicio 1 de la unidad 1 hacés lo siguiente:

```bash
./n.sh 1 1
```

#### Cuando compilás, se ejecuta automáticamente. Si no querés esto le tenés que pasar cualquier valor extra sin espacios:

```bash
./n.sh k
```
##### También se puede hacer así:
```bash
./n.sh 1 1 i
```