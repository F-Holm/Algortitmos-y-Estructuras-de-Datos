'''
    Id.Programa: G2_Ej01 Replicate.py
    Autor......: Lic. Hugo A. Cuello
    Fecha......: marzo-2024
    Comentario.: Funcion de usuario que convierte
                  un caracter a minuscula si corresponde.
    Lenguaje...: Python V.3.10.
'''

def Replicate(car, n):
    cad = ""
    for i in range(0, n):
        cad += car   # cad = cad + car;   cad = car + cad;
    return cad
# Replicate

car = input("Ing. un caracter: ")
n = int(input("Ing. un entero: "))
print(Replicate(car,n))
# G1_Ej01 Replicate
