/*
    Id.Programa: G4Ej03GeneraAzarSinRep.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: ago-2014
    Comentario.: Generar arreglo con enteros al azar:
                   Caso 1a) Sacar, cantar y meter en la misma bolsa.
                   Caso 1b) Idem anterior, pero optimizando tiempo.
                   Caso 2)  Sacar, cantar y apartar de la bolsa.
                   Caso 2b) Idem anterior pero generando de abajo hacia arriba
*/

#include <conio.h>

#include <fstream>
#include <iomanip>
using namespace std;

const MAX_ELEM = 90;

typedef unsigned short byte;
typedef unsigned int word;
typedef byte tvEnt[MAX_ELEM + 1];   // pos. cero no se va a usar.
typedef bool tvBool[MAX_ELEM + 1];  // pos. cero no se va a usar.

// Prototipos ------------------------------
byte ObtCard();
void GenVecSinRepCaso1a(tvEnt, byte);
void GenVecSinRepCaso1b(tvEnt, byte);
void IntCmb(byte &, byte &);
void GenVecSinRepCaso2(tvEnt, byte);
void GenVecSinRepCaso2Inv(tvEnt, byte);
void OrdxBur(tvEnt, byte);
void EmiteVec(tvEnt, byte);
void EmiteVecInv(tvEnt, byte);
// Fin Prototipos --------------------------

byte ObtCard() {
  byte card;

  clrscr();
  gotoxy(10, 5);
  cout << "Cardinalidad entre 0 y " << MAX_ELEM << ": ";
  do {
    gotoxy(42, 5);
    clreol();
    cin >> card;
  } while (!(card >= 0 && card <= MAX_ELEM));
  return card;
}  // ObtCard

void GenVecSinRepCaso1a(tvEnt vE, byte card) {
  byte j;

  for (byte i = 1; i <= card; i++) {
    vE[i] = random(MAX_ELEM) + 1;
    j = 1;
    while (j < i)
      if (vE[i] == vE[j]) {
        vE[i] = random(MAX_ELEM) + 1;
        j = 1;
      } else
        j++;
  }
}  // GenVecSinRepCaso1a

void GenVecSinRepCaso1b(tvEnt vE, byte card) {
  byte x;
  tvBool vBool;

  for (byte i = 1; i <= MAX_ELEM; i++)
    vBool[i] = false;
  for (byte i = 1; i <= card; i++) {
    do
      x = random(MAX_ELEM) + 1;
    while (vBool[x]);
    vBool[x] = true;
    vE[i] = x;
  }
}  // GenVecSinRepCaso1b

void IntCmb(byte &elem1, byte &elem2) {
  byte aux = elem1;

  elem1 = elem2;
  elem2 = aux;
}  // IntCmb

void GenVecSinRepCaso2(tvEnt vE, byte card) {
  byte x;

  for (byte i = 1; i <= MAX_ELEM; i++)
    vE[i] = i;
  for (byte i = 1; i <= card; i++) {
    x = random(MAX_ELEM - i + 1) + i;
    IntCmb(vE[i], vE[x]);
  }
}  // GenVecSinRepCaso2

void GenVecSinRepCaso2Inv(tvEnt vE, byte card) {
  byte x;

  for (byte i = 1; i <= MAX_ELEM; i++)
    vE[i] = i;
  for (byte i = 1; i <= card; i++) {
    x = random(MAX_ELEM - i + 1) + 1;
    IntCmb(vE[MAX_ELEM - i + 1], vE[x]);
  }
}  // GenVecSinRepCaso2Inv

void OrdxBur(tvEnt vE, byte card) {
  byte k = 0;
  bool ordenado;

  do {
    ordenado = true;
    k++;
    for (byte i = 1; i <= card - k; i++)
      if (vE[i] > vE[i + 1]) {
        ordenado = false;
        IntCmb(vE[i], vE[i + 1]);
      }
  } while (!ordenado);
}  // OrdxBur

void EmiteVec(tvEnt vE, byte card) {
  for (byte i = 1; i <= card; i++)
    cout << setw(6) << vE[i];
  cout << endl << endl;
}  // EmiteVec

void EmiteVecInv(tvEnt vE, byte card) {
  for (byte i = card; i >= 1; i--)
    cout << setw(6) << vE[i];
  cout << endl << endl;
}  // EmiteVecInv

int main() {
  tvEnt vEnt;
  byte cantElem;

  cantElem = ObtCard();
  GenVecSinRepCaso1a(vEnt, cantElem);
  EmiteVec(vEnt, cantElem);
  OrdxBur(vEnt, cantElem);
  EmiteVec(vEnt, cantElem);
  cout << "-------------------------------" << endl;
  GenVecSinRepCaso1b(vEnt, cantElem);
  EmiteVec(vEnt, cantElem);
  OrdxBur(vEnt, cantElem);
  EmiteVec(vEnt, cantElem);
  cout << "--------------------------------" << endl;
  GenVecSinRepCaso2(vEnt, cantElem);
  EmiteVec(vEnt, cantElem);
  OrdxBur(vEnt, cantElem);
  EmiteVec(vEnt, cantElem);
  cout << "---------------------------------" << endl;
  GenVecSinRepCaso2Inv(vEnt, cantElem);
  EmiteVec(vEnt, cantElem);
  OrdxBur(vEnt, cantElem);
  EmiteVecInv(vEnt, cantElem);
  return 0;
}
