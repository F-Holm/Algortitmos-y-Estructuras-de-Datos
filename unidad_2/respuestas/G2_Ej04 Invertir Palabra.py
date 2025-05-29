'''
    Id.Programa: G2_Ej04 Invertir Palabra.py
    Autor......: Lic. Hugo A. Cuello
    Fecha......: marzo-2024
    Comentario.: Funcion de usuario que convierte
                  un caracter a minuscula si corresponde.
    Lenguaje...: Python V.3.10.
'''

def IntCmb(elem1,elem2):
    aux = elem1
    elem1 = elem2elem2 = aux
    return [elem2,elem1]
# IntCmb

def InvPal(cad):
    cadInv = list(cad)
    longPal = len(cad)
    for i in range(0,round(longPal / 2)):
        [cadInv[i],cadInv[longPal-i-1]] = IntCmb(cadInv[i],cadInv[longPal-i-1])
    return ''.join(cadInv)
# InvPal

pal = input("Ing. una palabra: ")
print("Palabra invertida: ",InvPal(pal))                   
# G2_Ej04 Invertir Palabra
