# Algoritmos y Estructuras de Datos
---
## Requisitos

- clang++
- clang-format

---

## Instalación

### Windows

```bash
winget install --id LLVM.LLVM --source winget
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

## Setup

### Windows

```bash
./setup.bat
```

### Linux (Ubuntu)

```bash
./setup.sh
```

---

## Scripts

<table style="width:100%; text-align:center;">
  <thead>
    <tr>
      <th style="text-align:center;">Acción</th>
      <th style="text-align:center;">Ejecutable</th>
      <th style="text-align:center;">Flags</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Crear archivo C++</td>
      <td><code>./n.exe</code></td>
      <td>-</td>
    </tr>
    <tr>
      <td>Compilar archivo C++</td>
      <td><code>./c.exe</code></td>
      <td>
        <code>-n</code> No ejecuta<br>
        <code>-d</code> compila en modo DEBUG</code>
      </td>
    </tr>
    <tr>
      <td>Ejecutar archivo</td>
      <td><code>./e.exe</code></td>
      <td>-</td>
    </tr>
    <tr>
      <td>Eliminar archivos temporales</td>
      <td><code>./l.exe</code></td>
      <td><code>-t</code> No vuelve a compilar los ejecutables</td>
    </tr>
    <tr>
      <td>Compilar todos los .cpp</td>
      <td><code>./build.exe</code></td>
      <td>
        <code>-e</code> Excluye <code>RESPUESTAS</code><br>
        <code>-d</code> compila en modo DEBUG</code>
      </td>
    </tr>
    <tr>
      <td>Formatear archivos</td>
      <td><code>./f.exe</code></td>
      <td>-</td>
    </tr>
    <tr>
      <td>Crear/compilar/ejecutar con parámetros</td>
      <td style="text-align:center;" colspan="2"><code>./{archivo_exe} {unidad} {ejercicio} {flag1}...</code></td>
    </tr>
  </tbody>
</table>

- `RESPUESTAS` en una variable del archivo `src/configuración.h` que contiene la lista de directorios con las respuestas subidas al aula virtual
- El ejecutable para dar formato a todos los archivos se ejecuta automáticamente cada vez que se utiliza otro ejecutable
- El ejecutable de formateo no afecta las `RESPUESTAS`

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