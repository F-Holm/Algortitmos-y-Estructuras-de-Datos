'''
    Id.Programa: G2-Ej08 Viajes Camioneros csv.py
    Autor......: Lic. Hugo A. Cuello
    Fecha......: marzo-2024
    Comentario.: Viajes de Camioneros con material fragil (1..Max.100).
                    1. Listado de Camioneros ord. x Cant.Unid.Rotas asc.
    Lenguaje...: Python V.3.10.
'''

import csv

codLeg = 0
codPcia = cantViajes = 1
cantRotas = 2

def LeeUnReg(lista):
    if lista != []:
        rVia = lista.pop(0)
        CodLeg = rVia[codLeg]
        CodPcia = int(rVia[codPcia])
        CantURotas = int(rVia[cantRotas])
        rVia.clear()
        return [CodLeg,CodPcia,CantURotas]
    else:
        return ["",0,0]
# LeeUnReg

def BusLinVec(vrCam, nLeg, card):
    i = 0
    while i < card and nLeg != vrCam[i][codLeg]:
        i += 1
    return i
# BusLinVec

def AcumViajes(vrCam, rVia, cCam):
    posCam = BusLinVec(vrCam,rVia[codLeg],cCam)
    if posCam >= cCam:
        cCam += 1
        vrCam.append([rVia[codLeg],0,0])
    vrCam[posCam][cantViajes] += 1
    vrCam[posCam][cantRotas] += rVia[cantRotas]
    return cCam
# AcumViajes

def OrdListado(vrCam, cCam):
  #OrdxBur(vrCam,cCam) metodo por el usuario o
  vrCam.sort(key=lambda x : x[cantRotas])
  Salida.write ("       Listado de Camioneros ordenado por Cant. Unid. rotas\n")
  Salida.write ("    Nro.Ord.    Cod. Leg.     Cant. Viajes       Cant.Uni.Rotas\n")
  for i in range(0,cCam):
    Salida.write ("""      {:3d}       {:5}            {:4d}                  {:4d}\n"""
                  .format(i+1,vrCam[i][codLeg],vrCam[i][cantViajes],vrCam[i][cantRotas]))
# Listado

# -----> Bloque Ppal. <-----

with open("Viajes.csv","r",encoding="utf-8") as Viajes:
    reader = csv.reader(Viajes, delimiter=",")
    lista = list(reader)
with open("SalidaViajes.Txt","w") as Salida:
    canCam = 0
    rViaje = []
    vrCamioneros = []

    rViaje = LeeUnReg(lista)
    while rViaje[0] != '':
        canCam = AcumViajes(vrCamioneros,rViaje,canCam)
        rViaje = LeeUnReg(lista)
    OrdListado(vrCamioneros,canCam)
# G2_Ej13 Viajes Camioneros Archivo