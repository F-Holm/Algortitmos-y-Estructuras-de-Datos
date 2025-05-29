'''
    Id.Programa: G2-Ej07 Encuesta Discografica csv.py
    Autor......: Lic. Hugo Cuello
    Fecha......: jun-2014
    Comentario.: Ranking de temas musicales (1..30).
                    1. Listado de Ranking.
                    2. Nro.Tema +Votado por Hom30+.
                    3. Nros. de Temas no votados por las Mujeres.
    Lenguaje...: Python V.3.10.
'''

import csv

MAX_TEMAS = 30

def IniTbl(vrRank):
    for i in range(1, MAX_TEMAS + 1):
      vrRank.append([i,0,0,False])
    print('vrRank ',vrRank)
# IniTbl

def LeerDatos(lista):
  if lista != []:
    rEnc = lista.pop(0)
    Sexo = rEnc[sexo]
    Edad = int(rEnc[edad])
    Temas = []
    for i in range(0,3):
      Temas.append(int(rEnc[temas+i]))
    rEnc.clear()
    return [Sexo,Edad,Temas]
  else:
    return ["",0,0,0,0]
# leerDatos

def AcumVotos(vrRank, rEnc):
  for i in range(0, 3):
    nTema = int(rEnc[temas][i]) - 1 # estamos haciendo una copia
    vrRank[nTema][votos] += 1
    if rEnc[sexo] == 'F':
      vrRank[nTema][mujer] = True
    else:
      if int(rEnc[edad]) >= 30:
        vrRank[nTema][hom30] += 1
# AcumVotos

def IntCmb(elem1,elem2):
  aux = elem1

  elem1 = elem2
  elem2 = aux
  return [elem1, elem2]
# IntCmb

def OrdxBur(vrRank, card):
  k = 0
  ordenado = False
  while not ordenado:
    k += 1
    ordenado = True
    for i in range(0, card - k):
      if vrRank[i][votos] < vrRank[i + 1][votos]:
        ordenado = False
        [vrRank[i], vrRank[i+1]] = IntCmb(vrRank[i],vrRank[i + 1])
# OrdxBur

def MayNroTemaHom30 (vrRank):
  nTema = 0
  for i in range(1, MAX_TEMAS):
    if vrRank[i][hom30] > vrRank[nTema][hom30]:
      nTema = i
  return nTema + 1
# MayNroTemaHom30

def EmitePtoB(nTema):
  print ("Por ahora sale en la Pantalla\n")
  Salida.write (f"El nro. de tema + votado por los Hom30+: {nTema}\n")
# EmitePtoB

def EmitePtoC(vrRank):
  Salida.write ("Nros. de temas no votados por Mujeres\n")
  Salida.write ("   Nro.Tema\n")
  for i in range(0, MAX_TEMAS):
    if not vrRank[i][mujer]:
      Salida.write ("     {:2d}\n".format(i+1))
# EmitePtoC

def EmitePtoA(vrRank):
  Salida.write ("Listado de Ranking de Temas Musicales\n")
  Salida.write ("  Nro.Ord.  Nro.Tema Cant.Votos\n")
  for i in range(0, MAX_TEMAS):
    Salida.write ("     {:2d}         {:2d}      {:3d}\n".format(i+1,vrRank[i][nTema],
                                                                 vrRank[i][votos]))
  # freopen("CON","w",stdout);
  print ("Vuelvo a la pantalla")
# EmitePtoA

# -----> Bloque Ppal. <-----

with open("Encuestas.csv", "r", encoding="utf-8") as Encuestas:
  reader = csv.reader(Encuestas, delimiter=",")
  lista = list(reader)
with open("Salida.Txt","w") as Salida:
  nTema = 0
  votos = 1
  hom30 = 2
  mujer = 3

  sexo  = 0
  edad  = 1
  temas = 2

  rEncuesta = []
  vrRanking = []

  IniTbl(vrRanking) # NroTema: Pos: i, Votos: 0, Hom30: 0, Mujer: False.
  rEncuesta = LeerDatos(lista)
  while rEncuesta[0] != "":
    AcumVotos(vrRanking,rEncuesta)
    rEncuesta = LeerDatos(lista)
  EmitePtoB(MayNroTemaHom30(vrRanking))
  EmitePtoC(vrRanking)
  #OrdxBur(vrRanking,MAX_TEMAS) reemplazado por el metodo sort()
  vrRanking.sort(key=lambda x : -x[votos])
  EmitePtoA(vrRanking)
  # G4Ej12 Encuesta Discografica Text