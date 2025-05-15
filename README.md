# Algoritmos y Estructuras de Datos
---
## Requisitos

- Linux (Ubuntu) o Windows
- clang++ (pueden usarse otros compiladores pero se debe cambiar la variable "compilador" en los scripts)
- clang-format
- Bash o PowerShell 7.0.0+

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

<table style="width:100%; text-align:center;">
  <thead>
    <tr>
      <th style="text-align:center;">Acción</th>
      <th style="text-align:center;">PowerShell</th>
      <th style="text-align:center;">Bash</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Crear archivo C++</td>
      <td><code>./n.ps1</code></td>
      <td><code>./n.sh</code></td>
    </tr>
    <tr>
      <td>Compilar archivo C++</td>
      <td><code>./c.ps1</code></td>
      <td><code>./c.sh</code></td>
    </tr>
    <tr>
      <td>Ejecutar archivo</td>
      <td><code>./r.ps1</code></td>
      <td><code>./r.sh</code></td>
    </tr>
    <tr>
      <td>Eliminar archivos temporales</td>
      <td><code>./g.ps1</code></td>
      <td><code>./g.sh</code></td>
    </tr>
    <tr>
      <td>Compilar todos los .cpp</td>
      <td><code>./build.ps1</code></td>
      <td><code>./build.sh</code></td>
    </tr>
    <tr>
      <td>Formatear archivos</td>
      <td><code>./f.ps1</code></td>
      <td><code>./f.sh</code></td>
    </tr>
    <tr>
      <td>Crear/compilar/ejecutar con parámetros</td>
      <td style="text-align:center;" colspan="2"><code>./${archivo_script} ${unidad} ${ejercicio}</code></td>
    </tr>
    <tr>
      <td>Compilar con ejecución deshabilitada</td>
      <td><code>./c.ps1 -r</code></td>
      <td><code>./c.sh -r</code></td>
    </tr>
    <tr>
      <td>Compilar con parámetros y ejecución deshabilitada</td>
      <td><code>./c.ps1 ${unidad} ${ejercicio} -r</code></td>
      <td><code>./c.sh ${unidad} ${ejercicio} -r</code></td>
    </tr>
  </tbody>
</table>

- El script para dar formato a todos los archivos se ejecuta automáticamente cada vez que se utiliza otro script
- El script de formateo no afecta subdirectorios para evitar alterar las respuestas

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