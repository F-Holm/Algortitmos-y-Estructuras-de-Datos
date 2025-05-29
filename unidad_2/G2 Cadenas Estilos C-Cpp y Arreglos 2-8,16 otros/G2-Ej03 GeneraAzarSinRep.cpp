/*
    Id.Programa: G2-Ej03 GeneraAzarSinRep.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: ago-2014
    Comentario.: Generar arreglo con enteros al azar:
                   Caso 1a) Sacar, cantar y meter en la misma bolsa.
                   Caso 1b) Idem anterior, pero optimizando tiempo.
                   Caso 2)  Sacar, cantar y apartar de la bolsa.
                   Caso 2b) Idem anterior pero generando de abajo hacia arriba.
    Lenguaje...: Borland C++ V.5.5.
*/

#include<conio.h>
#include<iomanip>
#include<fstream>
using namespace std;

const
  MAX_ELEM = 90;

typedef unsigned int   word;
typedef short tvEnt[MAX_ELEM + 1]; //pos. cero no se va a usar.
typedef bool tvBool[MAX_ELEM + 1]; //pos. cero no se va a usar.

// Prototipos ------------------------------
short ObtCard();
void GenVecSinRepCaso1a(tvEnt , short );
void GenVecSinRepCaso1b(tvEnt , short );
void IntCmb(short &, short &);
void GenVecSinRepCaso2(tvEnt , short );
void GenVecSinRepCaso2Inv(tvEnt , short );
void OrdxBur(tvEnt , short );
void EmiteVec(tvEnt , short );
void EmiteVecInv(tvEnt , short );
// Fin Prototipos --------------------------

short ObtCard() {
  short card;

  clrscr();
  gotoxy(10,5);
  cout << "Cardinalidad entre 0 y " << MAX_ELEM << ": ";
  do {
    gotoxy(42,5); clreol();
    cin >> card;
  } while (!(card >= 0 && card <= MAX_ELEM));
  return card;
} //ObtCard

void GenVecSinRepCaso1a(tvEnt vE, short card) {
  short j;

  for (short i = 1; i <= card; i++) {
    vE[i] = random(MAX_ELEM ) + 1;
    j = 1;
    while (j < i)
      if (vE[i] == vE[j]) {
        vE[i] = random(MAX_ELEM) + 1;
        j = 1;
      }
    else
      j++;
  }
} //GenVecSinRepCaso1a

void GenVecSinRepCaso1b(tvEnt vE, short card) {
  short   x;
  tvBool vBool;

  for (short i = 1; i <= MAX_ELEM; i++)
    vBool[i] = false;
  for (short i = 1; i <= card; i++) {
    do
      x = random(MAX_ELEM) + 1;
    while (vBool[x]);
    vBool[x] = true;
    vE[i] = x;
  }
} //GenVecSinRepCaso1b

void IntCmb(short &elem1, short &elem2) {
  short aux = elem1;

  elem1 = elem2;
  elem2 = aux;
} //IntCmb

void GenVecSinRepCaso2(tvEnt vE, short card) {
  short x;

  for (short i = 1; i <= MAX_ELEM; i++)
    vE[i] = i;
  for (short i = 1; i <= card; i++) {
    x = random(MAX_ELEM - i + 1) + i;
    IntCmb(vE[i],vE[x]);
  }
} //GenVecSinRepCaso2

void GenVecSinRepCaso2Inv(tvEnt vE, short card) {
  short x;

  for (short i = 1; i <= MAX_ELEM; i++)
    vE[i] = i;
  for (short i = 1; i <= card; i++) {
    x = random(MAX_ELEM - i + 1) + 1;
    IntCmb(vE[i],vE[x]);
  }
} //GenVecSinRepCaso2Inv

void OrdxBur(tvEnt vE, short card) {
  short k = 0;
  bool ordenado;

  do {
    ordenado = true;
    k++;
    for (short i = 1; i <= card - k; i++)
      if (vE[i] > vE[i + 1]) {
        ordenado = false;
        IntCmb(vE[i], vE[i + 1]);
      }
  } while (!ordenado);
} //OrdxBur

void EmiteVec(tvEnt vE, short card) {

  for (short i = 1; i <= card; i++)
    cout << setw(6) << vE[i];
  cout << endl << endl;
} //EmiteVec

void EmiteVecInv(tvEnt vE, short card) {

  for (short i = card; i >= 1; i--)
    cout << setw(6) << vE[i];
  cout << endl << endl;
} //EmiteVecInv

main() {
  tvEnt vEnt;
  short  cantElem;

  cantElem = ObtCard();
  GenVecSinRepCaso1a(vEnt,cantElem);
  EmiteVec(vEnt,cantElem);
  OrdxBur(vEnt,cantElem);
  EmiteVec(vEnt,cantElem);
  cout << "Caso 1a-------------------------------" << endl;
  GenVecSinRepCaso1b(vEnt,cantElem);
  EmiteVec(vEnt,cantElem);
  OrdxBur(vEnt,cantElem);
  EmiteVec(vEnt,cantElem);
  cout << "Caso 1b--------------------------------" << endl;
  GenVecSinRepCaso2(vEnt,cantElem);
  EmiteVec(vEnt,cantElem);
  OrdxBur(vEnt,cantElem);
  EmiteVec(vEnt,cantElem);
  cout << "Caso2---------------------------------" << endl;
  GenVecSinRepCaso2Inv(vEnt,cantElem);
  EmiteVec(vEnt,cantElem);
  OrdxBur(vEnt,cantElem);
  EmiteVecInv(vEnt,cantElem);
  cout << "Caso2 invertido-----------------------" << endl;
  return 0;
}
