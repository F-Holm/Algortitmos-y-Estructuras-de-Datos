# Algoritmos y Estructuras de Datos
---
## Requisitos

- clang++
- clang-format
- python3

---

## Instalación

### Windows

```bash
winget install --id Microsoft.PowerShell --source winget
```
```bash
winget install --id BrechtSanders.WinLibs.POSIX.UCRT.LLVM --source winget
```
```bash
winget install --id Python.Python.3.13 --source winget
```

### Linux (Ubuntu)

```bash
sudo apt update
```
```bash
sudo apt install clang clang-format python3 python3-pip python3-venv
```

---

## Estilo de código

Este proyecto sigue la [Guía de Estilo de C++ de Google](https://google.github.io/styleguide/cppguide.html) para mantener la consistencia y legibilidad del código. El script de formateo utiliza `clang-format` configurado según esta guía.


---

## Scripts

<table style="width:100%; text-align:center;">
  <thead>
    <tr>
      <th style="text-align:center;">Acción</th>
      <th style="text-align:center;">Script</th>
      <th style="text-align:center;">Flags</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Crear archivo C++</td>
      <td><code>./n.py</code></td>
      <td>-</td>
    </tr>
    <tr>
      <td>Compilar archivo C++</td>
      <td><code>./c.py</code></td>
      <td><code>-r</code>  No ejecutar</td>
    </tr>
    <tr>
      <td>Ejecutar archivo</td>
      <td><code>./r.py</code></td>
      <td>-</td>
    </tr>
    <tr>
      <td>Eliminar archivos temporales</td>
      <td><code>./g.py</code></td>
      <td>-</td>
    </tr>
    <tr>
      <td>Compilar todos los .cpp</td>
      <td><code>./build.py</code></td>
      <td><code>-e</code> Excluye las respuestas</td>
    </tr>
    <tr>
      <td>Formatear archivos</td>
      <td><code>./f.py</code></td>
      <td>-</td>
    </tr>
    <tr>
      <td>Crear/compilar/ejecutar con parámetros</td>
      <td style="text-align:center;" colspan="2"><code>./${archivo_script} ${unidad} ${ejercicio} ${flags}</code></td>
    </tr>
  </tbody>
</table>

- El script para dar formato a todos los archivos se ejecuta automáticamente cada vez que se utiliza otro script
- El script de formateo no afecta los directorios de 'RESPUESTAS' del archivo config.env

---

## Leer PDFs

Se puede utilizar la siguiente extensión de VS Code para ver PDFs:

#### Windows
```bash
bashtomoki1207.pdf
```
#### Linux
```bash
tomoki1207.pdf
```