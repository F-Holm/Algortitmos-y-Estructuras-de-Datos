'''
    Id.Programa: G2-Ej05 Intercalar Vectores.py
    Autor......: Lic. Hugo A. Cuello
    Fecha......: marzo-2024
    Comentario.: Fusionar vectores previamente ordenados
                  para insertarlos ordenados en el vector
                  resultados, aplicando el metodo de
                  intercalacion (apareo entre vectores).
    Lenguaje...: Python V.3.10.
'''

import msvcrt
import random

global MAX_ELEM
MAX_ELEM = 90

def ObtCard(titulo):
    print(titulo,end='')
    card = int(input(' #: '))
    while not (card >= 1 and card <= MAX_ELEM):
        print(titulo,end='')
        card = int(input(' #: '))
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

def Asignar(elemR, elemX, indX, indR, cX, fdvX):
    elemR.append(elemX)
    indX += 1
    indR += 1
    fdvX = cX <= indX
    return [indX, indR, fdvX]
# Asignar

def Intercalar(vP, vQ, vR, cP, cQ):
    fdvP = False
    fdvQ = False
    i = j = 0
    k = -1
    while not fdvP or not fdvQ:
        if not fdvP and not fdvQ:
            if vP[i] <= vQ[j]:
                [i, k, fdvP] = Asignar(vR,vP[i],i,k,cP,fdvP)
            else:
                [j, k, fdvQ] = Asignar(vR,vQ[j],j,k,cQ,fdvQ)
        else:
            if not fdvP:
                [i, k, fdvP] = Asignar(vR,vP[i],i,k,cP,fdvP)
            else:
                [j, k, fdvQ] = Asignar(vR,vQ[j],j,k,cQ,fdvQ)
# Intercalar

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
    print("Hola... ",titulo)
    print("#",titulo,": ",card)
    for i in range(0, card):
        print(vE[i],end=' ')
    print()
    msvcrt.getche()
# EmiteVec

# -----> Bloque Ppal. <-----

p = []
q = []
r = []
m = ObtCard("Cjto. P")
n = ObtCard("Cjto. Q")
GenVecSinRepCaso1a(p,m)
GenVecSinRepCaso1a(q,n)
OrdxBur(p,m)
OrdxBur(q,n)
Intercalar(p,q,r,m,n)
EmiteVec(p,m,"Cjto. P")
EmiteVec(q,n,"Cjto. Q")
EmiteVec(r,m + n,"Cjto. R")
# G2_Ej10 Intercalar Vectores