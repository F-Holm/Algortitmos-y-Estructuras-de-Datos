'''
    Id.Programa: G2-Ej02 OperacArreglos.py
    Autor......: Lic. Hugo A. Cuello
    Fecha......: marzo-2024
    Comentario.: Operaciones con arreglos, opc. de Menu:
                   a) Promedio
                   b) Maximo
                   c) Minimo
                   d) Sumatoria
    Lenguaje....: Python V.3.10.
'''

import random
import msvcrt

global MIN
MIN = 35
global MAX 
MAX = 93

def ObtCard():
    cantElem = int(input("Ing.Cardinalidad del vector [1..100]: "))
    while cantElem < 1 or cantElem > 100:
        cantElem = int(input("Ing.Cardinalidad del vector [1..100]: "))
    return cantElem
# ObtenerCard

def GenVec(vE, card):
  random.seed()
  for i in range(0, card):
    vE.append(random.randrange(MIN, MAX))
# GenVec

def EmitirVec( vE, card):
  for i in range(0, card):
    print (vE[i])
  print ("Oprima Enter para continuar...")
  opc = msvcrt.getch()
# EmitirVec

def SumVec( vE,  card):
  sum = 0

  for i in range(0, card):
    sum += vE[i]
  return sum
# SumVec

def PromVec(vE, card):
  return SumVec(vE,card) / float(card)
# PromVec

def MaxVec(vE, card):
  maxElem = vE[0]
  for i in range(1, card):
    if vE[i] > maxElem:
      maxElem = vE[i]
  return maxElem
# MaxVec

def MinVec(vE, card):
  minElem = vE[0]
  for i in range(1, card):
    if vE[i] < minElem:
      minElem = vE[i]
  return minElem
# MinVec

def Menu (vE, card):
  LISTA_OPC = []
  LISTA_OPC.append('A'); LISTA_OPC.append('B'); LISTA_OPC.append('C')
  LISTA_OPC.append('D'); LISTA_OPC.append('E')
  opc = 'A'
  while opc in LISTA_OPC and opc != 'E':
    print ("Operaciones con Arreglos")
    print ("A: Promedio")
    print ("B: Maximo elemento")
    print ("C: Minimo elemento")
    print ("D: Sumatoria")
    print ("E: Salir")
    print ("Elija su opcion: ",end='')
    print()
    opc = msvcrt.getwch()
    opc = opc.upper()
    while opc not in LISTA_OPC:
      print ("Ing. nuevamente la opcion: ")
      opc = msvcrt.getwch()
      opc = opc.upper()
    if opc == 'A':
      print ("\nPromedio.: ", PromVec(vE,card))
    elif opc == 'B': 
      print ("\nMaximo...: ",MaxVec(vE,card))
    elif opc == 'C':
      print ("\nMinimo...: ",MinVec(vE,card))
    elif opc == 'D': 
      print ("\nSumatoria: ",SumVec(vE,card))
    else:
      continue
    msvcrt.getch()
# Menu

# -----> Bloque Ppal. <-----

vEnt = [] # Indica que es una lista, vector equiv. a otros lenguajes.
cantElem = ObtCard()
GenVec(vEnt, cantElem)
EmitirVec(vEnt, cantElem)
Menu(vEnt, cantElem)
# G2_Ej04