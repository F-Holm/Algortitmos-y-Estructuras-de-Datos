'''
    Id.Programa: G2_Ej03 LowCase.py
    Autor......: Lic. Hugo A. Cuello
    Fecha......: marzo-2024
    Comentario.: Funcion de usuario que convierte
                  un caracter a minuscula si corresponde.
    Lenguaje...: Python V.3.10.
'''

def LowCase(car):
    if ord(car) in range(ord('A'), ord('Z')):
        return chr(ord(car) + (ord('a') - ord('A')))
    else:
        return car
# LowCase
    
print ("Convertir caracter a minuscula si corresponde")
car = input("Ing. un caracter: ")
print (LowCase(car))
cad = input("Ing. una cadena de caracteres: ")
sarta = list(cad)  # Las cadenas son inmutables hay que cnv. a lista y luego cnv a str.
for i in range(0,len(cad)):
    sarta[i] = LowCase(cad[i])
cad = "".join(sarta)
print(cad)
print("Metodo de Python ","CAdena 45-&%$ de caRaCTeReS".lower())
# G2_Ej03 LowCase
