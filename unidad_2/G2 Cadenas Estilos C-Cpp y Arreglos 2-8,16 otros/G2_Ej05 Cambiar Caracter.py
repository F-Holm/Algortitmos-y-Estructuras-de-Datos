'''
    Id.Programa: G2_Ej05 Cambiar Caracter.py
    Autor......: Lic. Hugo A. Cuello
    Fecha......: marzo-2024
    Comentario.: Funcion de usuario que convierte
                  un caracter a minuscula si corresponde.
    Lenguaje...: Python V.3.10.
'''

def CamCar(cad,car1,car2):
    sarta = list(cad)
    for i in range(0, len(sarta)):
        if sarta[i] == car1:
            sarta[i] = car2
    return ''.join(sarta)
# CamCar

print ("Cambiar en una cadena un caracter por otro")
cad = input("Ing. una cadena: ")
car1 = input("Ing. 1er. caracter: ")
car2 = input("Ing. 2do. caracter: ")
cadCmb = CamCar(cad,car1,car2)
print("Cadena original: ",cad)
print("Cadena cambiada: ",cadCmb)
cadModif = cad.replace('e','u') # Metodo definido por el lenguaje
print("Cadena cambiada: ",cadModif)
# G2_Ej05 Cambiar Caracter
