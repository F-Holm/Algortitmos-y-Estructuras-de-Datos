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
winget install --id LLVM.LLVM --source winget
```
```bash
winget install --id Python.Python.3.13 --source winget
```
```bash
pip install dotenv
```

### Linux (Ubuntu)

```bash
sudo apt update
```
```bash
sudo apt install clang clang-format python3 python3-pip python3-venv python3-dotenv
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
      <td><code>-e</code> Excluye <code>RESPUESTAS</code></td>
    </tr>
    <tr>
      <td>Formatear archivos</td>
      <td><code>./f.py</code></td>
      <td>-</td>
    </tr>
    <tr>
      <td>Crear/compilar/ejecutar con parámetros</td>
      <td style="text-align:center;" colspan="2"><code>./{archivo_script} {unidad} {ejercicio} {flag1}...</code></td>
    </tr>
  </tbody>
</table>

- `RESPUESTAS` en una variable del archivo config.env que contiene la lista de directorios con las respuestas subidas al aula virtual
- El script para dar formato a todos los archivos se ejecuta automáticamente cada vez que se utiliza otro script
- El script de formateo no afecta las `RESPUESTAS`

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