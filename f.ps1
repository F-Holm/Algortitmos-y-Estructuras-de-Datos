#!/usr/bin/env pwsh

foreach ($n in 1..5) {
    $dir = ".\Unidad $n"

    # Solo archivos .cpp directamente en la carpeta (no en subcarpetas)
    if (Test-Path $dir) {
        Get-ChildItem -Path $dir -File -Filter *.cpp | ForEach-Object {
            clang-format -i $_.FullName
        }
    }
}
