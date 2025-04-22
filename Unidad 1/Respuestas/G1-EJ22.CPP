/*
	Id.Programa: G1-Ej22.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Examen de Matematica, tema Triangulos, para responder por
                   cada alumno su perimetro y tipo de triangulo
                   (Isos,Escal,eQuil), conociendo las medidas de sus lados.
	Lenguaje...: Borland V.5.5
*/

#include <ctime>
#include <iostream>
#include <cstring>

#include "Borland.h"

using namespace std;

#define CENTINELA "*"

const short MIN = 6,
            MAX = 10;

typedef unsigned short ushort;
typedef char str20[21];

void EmiteInic (ushort &tRespC, ushort &tRespI) {
  cout << "Examen de Matematica, tema Triangulos perimetro y tipo de Triang."
       << endl;
  tRespC = tRespI = 0;
  srand(time(NULL));
} // EmiteInic

void ObtNomAlu (str20 nAlu) {
  cout << "Nombre Fin = *: ";
  cin.get(nAlu,21);
  cin.ignore(100,'\n');
} // ObtNomAlu

ushort iif(bool expLog, ushort ent1, ushort ent2) {
  if (expLog)
    return ent1;
  else
    return ent2;
} // iif

void ObtLados(ushort &x, ushort &y, ushort &z) {
  ushort mini,
         maxi;

  x = random(MAX - MIN + 1) + MIN;
  y = random(MAX - MIN + 1) + MIN;
  mini = iif (abs(x - y) <= MIN,MIN,abs(x - y) + 1);
  maxi = iif (x + y >= MAX,MAX,x + y - 1);
  z = random(maxi - mini + 1) + mini;
} // ObtLados

void RespAlu (ushort x, ushort y, ushort z, ushort &pAlu, char &tAlu) {
  char cjtoCar[] = "EIQ",
       unCar[2];

  cout << "Dados los lados de un triangulo con medidas: "
       << x << ", " << y << ", " << z;
  cout << " responder su perimetro y ";
  cout << "tipo de triangulo (Isos,Escal,eQuil)" << endl;
  cout << "Perimetro: ";
  cin >> pAlu;
  do {
    cout << "Tipo de triangulo (I,E,Q): ";
    cin >> tAlu;
    cin.ignore(100,'\n');
    tAlu = toupper(tAlu);
    unCar[0] = tAlu;
    unCar[1] = '\0';
    !strspn(unCar,cjtoCar);
  }
  while (!(tAlu == 'E' || tAlu == 'I' || tAlu == 'Q'));
} // RespAlu

void RespMaq (ushort x, ushort y, ushort z, ushort &pMaq, char &tMaq) {
  pMaq = x + y + z;
  if (x == y && y == z)
    tMaq = 'Q';
  else
    if (x == y || x == z || y == z)
      tMaq = 'I';
    else
      tMaq = 'E';
} // RespMaq

void CalcVerifEmite (const str20 nAlu, ushort pAlu, ushort pMaq,
                    char tAlu, char tMaq, ushort &tRespC, ushort &tRespI) {
  char Cartel[11];

  if (pAlu == pMaq && tAlu == tMaq) {
    tRespC++; // tRespC = tRespC + 1; tResp += 1;
    strcpy (Cartel,"O.K.");
  }
  else {
    tRespI++;
    strcpy (Cartel,"Estudie+++");
  }
  cout << nAlu << " " << Cartel << endl;
} // CalcVerifEmite

void EmiteTot (ushort tRespC, ushort tRespI) {
  cout << "Cantidad de respuestas correctas..: " << tRespC << endl;
  cout << "Cantidad de respuestas incorrectas: " << tRespI << endl;
} // EmiteTot

int main () {
  ushort totRespCor,
         totRespIncor,
         a,
         b,
         c,
         perAlu,
         perMaq;
  str20  NomAlu;
  char   triAlu,
         triMaq;

  EmiteInic(totRespCor,totRespIncor);
  ObtNomAlu(NomAlu);
  while (strcmp(NomAlu,CENTINELA)) {
    ObtLados(a,b,c);
    RespAlu(a,b,c,perAlu,triAlu);
    RespMaq(a,b,c,perMaq,triMaq);
    CalcVerifEmite (NomAlu,perAlu,perMaq,triAlu,triMaq,totRespCor,totRespIncor);
    ObtNomAlu(NomAlu);
  }
  EmiteTot(totRespCor,totRespIncor);
  return 0;
}
