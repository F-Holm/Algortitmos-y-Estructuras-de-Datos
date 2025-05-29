'''
    Id.Programa: G2-Ej04 OperacCjtos con Arreglos.py
    Autor......: Lic. Hugo A. Cuello
    Fecha......: marzo-2024
    Comentario.: Operaciones de Conjunto con arreglos:
                   a) Union
                   b) Interseccion
                   c) Diferencia
                   d) Diferencia Simetrica
                   e) Complemento de A U B
    Lenguaje...: Python V.3.10.
'''

import msvcrt
import random

global MAX_ELEM
MAX_ELEM = 90

def ObtCard(titulo):
    print (titulo," # 0 y ",MAX_ELEM,end=': ')
    card = int(input())
    while not (card >= 0 and card <= MAX_ELEM):
        print (titulo," # 0 y ",MAX_ELEM,": ")
        card = int(input())
    return card
# ObtCard

def IntCmb(elem1, elem2):
    aux = elem1
    elem1 = elem2
    elem2 = aux
    return [elem1, elem2]
# IntCmb

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

def Menu():
    print("A: Union")
    print("B: Interseccion")
    print("C: Diferencia")
    print("D: Diferencia Simetrica")
    print("E: Complemento")
    print("F: Finalizar")
    print("Su opcion: ")
    opc = msvcrt.getwch()
    opc = opc.upper()
    while not (opc >= 'A' and opc <= 'F'):
        opc = msvcrt.getwch()
        opc = opc.upper()
    return opc
# Menu

def BusBinVec(vX, clv, ult):
    pri = 0
    ult -= 1
    while pri <= ult:
        med = int((pri + ult) / 2)
        if vX[med] == clv:
            return True
        else:
            if clv > vX[med]:
                pri = med + 1
            else:
                ult = med - 1
    return False
# BusBinVec

def Union(vP, vQ, vR, cP, cQ, cR):
    for i in range( 0, cP):
        vR.append(vP[i])
    cR = cP
    for i in range(0, cQ):
        if not BusBinVec(vP,vQ[i],cP):
            cR += 1
            vR.append(vQ[i])
    return cR
# Union

def Intersec(vP, vQ, vR, cP, cQ, cR):
    for i in range(0, cP):
        if BusBinVec(vQ,vP[i],cQ):
            cR += 1
            vR.append(vP[i])
    return cR
# Intersec

def Difer(v1, v2, vR, c1, c2, cR):
    for i in range(0, c1):
        if not BusBinVec(v2,v1[i],c2):
            cR += 1
            vR.append(v1[i])
    return cR
# Difer

def DifSim(vP, vQ, vR, cP, cQ, cR):
  cR = Difer(vP,vQ,vR,cP,cQ,cR)
  cR = Difer(vQ,vP,vR,cQ,cP,cR)
  return cR
# DifSim

def Cmplto(vP, vQ, vR, cP, cQ, cR):
    for i in range(1, MAX_ELEM):
        if not BusBinVec(vP,i,cP) and not BusBinVec(vQ,i,cQ):
            cR += 1
            vR.append(i)
    return cR
# Cmplto

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

def EmiteVec(vE, card, titulo):
    print('\n',titulo,end=' ')
    print("#",titulo,": ",card)
    for i in range(0, card):
        print(vE[i],end=' ')
    print()
    msvcrt.getche()
# EmiteVec

# -----> Bloque Ppal. <-----

p = []
q = []

LISTA_OPC = []
LISTA_OPC.append('A'); LISTA_OPC.append('B'); LISTA_OPC.append('C')
LISTA_OPC.append('D'); LISTA_OPC.append('E')
m = ObtCard("Cjto. P")
n = ObtCard("Cjto. Q")
GenVecSinRepCaso1a(p,m)
GenVecSinRepCaso1a(q,n)
OrdxBur(p,m)
# OrdxBur(q,n)
q.sort() # Utiliza metodo sort de Python. q.sort(reverse=True) ord. decreciente.
opc = 'A'
while opc != 'F':
    opc = Menu()
    r = []
    k = 0
    if opc == 'A':
        k = Union(p[:],q[:],r,m,n,k) # [:] hace que sea inmutable dentro del modulo.
    elif opc == 'B': 
        k = Intersec(p[:],q[:],r,m,n,k)
    elif opc == 'C':
        k = Difer(p[:],q[:],r,m,n,k)
    elif opc == 'D':
        k = DifSim(p[:],q[:],r,m,n,k)
    elif opc == 'E':
        k = Cmplto(p[:],q[:],r,m,n,k)
    if opc != 'F':
        EmiteVec(p,m,"Cjto. P")
        EmiteVec(q,n,"Cjto. Q")
        EmiteVec(r,k,"Cjto. R")
# G2_Ej09 OpercCjtos con Arreglos
