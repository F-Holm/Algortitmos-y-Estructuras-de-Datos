'''
    Id.Programa: G2-Ej03 GeneraAzarSinRep.py
    Autor......: Lic. Hugo A. Cuello
    Fecha......: marzo-2024
    Comentario.: Generar arreglo con enteros al azar:
                   Caso 1a) Sacar, cantar y meter en la misma bolsa.
                   Caso 1b) Idem anterior, pero optimizando tiempo.
                   Caso 2)  Sacar, cantar y apartar de la bolsa.
                   Caso 2b) Idem anterior pero generando de abajo hacia arriba
    Lenguaje....: Python V.3.10.
'''

import random

global MAX_ELEM
MAX_ELEM = 90

def ObtCard():
  random.seed()
  card = int(input("Cardinalidad entre 0 y {:5d}: ".format(MAX_ELEM)))
  while not (card >= 1 and card <= MAX_ELEM):
    card = int(input("Cardinalidad entre 0 y {:5d}: ".format(MAX_ELEM)))
  return card
# ObtCard

def GenVecSinRepCaso1a(vE, card):
  for i in range(0,card):
    elem = random.randrange(1,MAX_ELEM+1)
    j = 0
    while j < i:
      if elem == vE[j]:
        elem = random.randrange(1,MAX_ELEM+1)
        j = 0
      else:
        j += 1
    vE.append(elem)
#  GenVecSinRepCaso1a

def GenVecSinRepCaso1b(vE, card):
  vBool = []
  for i in range(0,MAX_ELEM+1):
    vBool.append(False)
  for i in range(0,card):
      x = random.randrange(1,MAX_ELEM+1)
      while vBool[x]:
        x = random.randrange(1,MAX_ELEM+1)  
      vBool[x] = True
      vE.append(x)
# GenVecSinRepCaso1b

def IntCmb(elem1,  elem2):
  aux = elem1
  elem1 = elem2
  elem2 = aux
  return [elem1, elem2]
# IntCmb

def GenVecSinRepCaso2(vE, card):
  for i in range(1,MAX_ELEM+1):
    vE.append(i)
  for i in range(0,card):
    x = random.randrange(i,MAX_ELEM)
    [vE[i],vE[x]] = IntCmb(vE[i],vE[x])
# GenVecSinRepCaso2

def GenVecSinRepCaso2Inv(vE, card):
  for i in range(1,MAX_ELEM+1):
    vE.append(i)
  for i in range(0,card):
    x = random.randrange(1,MAX_ELEM - i + 1)
    [vE[i], vE[x]] = IntCmb(vE[i], vE[x])
# GenVecSinRepCaso2Inv

def OrdxBur(vE, card):
  k = 0
  ordenado = False
  while not ordenado:
    ordenado = True
    k += 1
    for i in range(card - k):
      if vE[i] > vE[i + 1]:
        ordenado = False
        [vE[i], vE[i + 1]] = IntCmb(vE[i], vE[i + 1])
# OrdxBur

def EmiteVec(vE, card):
  print('<<< >>> ')
  for i in range(0, card):
    print(vE[i],end=' ')
  print('\n')
# EmiteVec

def EmiteVecInv(vE, card):
  for i in range(card-1, -1, -1):
    print(vE[i],end=' ')
  print('\n')
# EmiteVecInv

# -----> Bloque Ppal. <-----

vEnt = []

cantElem = ObtCard()
GenVecSinRepCaso1a(vEnt,cantElem)
print('Antes de ordenar ')
EmiteVec(vEnt,cantElem)
OrdxBur(vEnt,cantElem)
print('Despues de ordenar ')
EmiteVec(vEnt,cantElem)
print("Caso 1a-------------------------------")
vEnt.clear()
GenVecSinRepCaso1b(vEnt,cantElem)
print('Antes de ordenar ')
EmiteVec(vEnt,cantElem)
OrdxBur(vEnt,cantElem)
print('Despues de ordenar ')
EmiteVec(vEnt,cantElem)
print("Caso 1b--------------------------------")
vEnt.clear()
GenVecSinRepCaso2(vEnt,cantElem)
print('Antes de ordenar ')
EmiteVec(vEnt,cantElem)
OrdxBur(vEnt,cantElem)
print('Despues de ordenar ')
EmiteVec(vEnt,cantElem)
print("Caso2---------------------------------")
vEnt.clear()
GenVecSinRepCaso2Inv(vEnt,cantElem)
EmiteVec(vEnt,cantElem)
OrdxBur(vEnt,cantElem)
EmiteVecInv(vEnt,cantElem)
print("Caso2 invertido-----------------------")
# GeneraAzarSinRep