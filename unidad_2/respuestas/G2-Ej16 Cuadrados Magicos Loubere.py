'''
   Id.Programa: G2-Ej16 CuadradosMagicos Loubere.py
   Autor......: Lic. Hugo Cuello
   Fecha......: marzo-2024
   Comentario.: Matriz de n x n con elementos entero
                 desde 1 hasta n^2, en donde, la suma
                 de cada fila, de cada columna y de
                 ambas diagonales (principal y secundaria)
                 dan el mismo valor x.
                 El método aplicado es el de
                 Simón de la Loubere o también llamado
                 método siamés.
            https://es.wikipedia.org/wiki/cuadrado_mágico
    Lenguaje...: Python V.3.10.
'''
import math

global MAX_CF
MAX_CF = 12

def CantFilasImpar():
    cant = int(input("Ing. cantidad de filas o cols. impar: "))
    while not cant % 2 and cant > 2 and cant < MAX_CF:
        cant = int(input("Ing. cantidad de filas o cols. impar: "))
    return cant
# CantFilasImpar

def InicMatVec(matC,vCol):
    for i in range(0, MAX_CF):
        ceros = []
        vCol.append(0)
        for j in range(0,MAX_CF):
            ceros.append(0)
        matC.append(ceros)
# InicMatVec

def CuadradoMagico(mat, max_cf):
    i = 0
    maxElemCuad = pow(max_cf,2);
    j = math.trunc((max_cf) / 2)
    for num in range(1, maxElemCuad + 1):
        mat[i][j] = num
        i -= 1
        j += 1
        if i == -1 and j == max_cf:
            i += 2
            j -= 1
        else:
            if i == -1:
                i = max_cf - 1
            else:
                if j == max_cf:
                    j = 0
                else:
                    if mat[i][j]:
                        i += 2
                        j -= 1
# CuadradosMagicos

def EmiteSumasCuadradoMagico(mat, max_cf, vCol):
    sumaDiagPpal = 0
    sumaDiagSec = 0
    maxElemCuad = pow(max_cf,2)
    elemCtrl = int((maxElemCuad + 1) / 2)
    print("*Elemento central: ",elemCtrl)
    print("*Suma de c/F,C,DP,DS: ",(elemCtrl * max_cf))
    for i in range(0, max_cf):
        sumaFila = 0
        for j in range(0, max_cf):
            print('{:4d}'.format(mat[i][j]),end='')
            sumaFila += mat[i][j]
            vCol[j] += mat[i][j]
            if i == j:
                sumaDiagPpal += mat[i][j]
            if max_cf - i - 1 == j:
                sumaDiagSec += mat[max_cf - i - 1][j]
        print()
    print(" = ",sumaFila)
    print("------------------------------------")

    vCol[max_cf] = sumaDiagPpal
    print("Suma Diag. Ppal.: ",vCol[max_cf])
    print("Suma Diag. Sec..: ",sumaDiagSec)
# EmiteSumasCuadradoMagico

# ----------> Bloque Ppal. <----------

matCuad = []
vCol = []
n = CantFilasImpar()
InicMatVec(matCuad, vCol)
CuadradoMagico(matCuad, n)
EmiteSumasCuadradoMagico(matCuad, n, vCol)
# G2_Ej17 CuadradosMagicos