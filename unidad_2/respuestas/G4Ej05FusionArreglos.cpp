/*
    Id.Programa: G4Ej05FusionArreglos.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: ago-2014
    Comentario.: Fusion o Mezcla (Merge) de arreglos
*/

#include <conio.h>

#include <iomanip>
#include <iostream>
using namespace std;

const MAX_ELEM = 90;

typedef char str20[21];
typedef unsigned char byte;
typedef unsigned short word;
typedef byte tvEnt[MAX_ELEM + 1];       // pos. cero no se va a usar.
typedef byte tvEntD[2 * MAX_ELEM + 1];  // pos. cero no se va a usar.

// Prototipos --------------------------------------------------
byte ObtCard(str20);
void IntCmb(byte &, byte &);
void OrdxBur(tvEnt, byte);
void Asignar(byte &, byte, byte &, byte &, byte, bool &);
void Intercalar(tvEnt, tvEnt, tvEntD, byte, byte);
void GenVecSinRepCaso2(tvEnt, byte);
void EmiteVec(tvEnt, byte, str20);
// Fin Prototipos ----------------------------------------------

byte ObtCard(str20 titulo) {
  word card;

  clrscr();
  do {
    gotoxy(10, 3);
    cout << titulo << " #: ";
    clreol();
    cin >> card;
  } while (!(card >= 1 && card <= MAX_ELEM));
  return card;
}  // ObtCard

void IntCmb(byte &elem1, byte &elem2) {
  byte aux = elem1;

  elem1 = elem2;
  elem2 = aux;
}  // IntCmb

void OrdxBur(tvEnt vE, byte card) {
  bool ordenado;
  byte k = 0;

  do {
    ordenado = true;
    k++;
    for (byte i = 1; i <= card - k; i++)
      if (vE[i] > vE[i + 1]) {
        IntCmb(vE[i], vE[i + 1]);
        ordenado = false;
      }
  } while (!ordenado);
}  // OrdxBur

void Asignar(byte &elemR, byte elemX, byte &indX, byte &indR, byte cX,
             bool &fdvX) {
  elemR = elemX;
  indX++;
  indR++;
  fdvX = indX > cX;
}  // Asignar

void Intercalar(tvEnt vP, tvEnt vQ, tvEntD vR, byte cP, byte cQ) {
  byte i, j, k;
  bool fdvP = false, fdvQ = false;

  i = j = k = 1;
  while (!fdvP || !fdvQ) {
    if (!fdvP && !fdvQ)
      if (vP[i] <= vQ[j])
        Asignar(vR[k], vP[i], i, k, cP, fdvP);
      else
        Asignar(vR[k], vQ[j], j, k, cQ, fdvQ);
    else if (!fdvP)
      Asignar(vR[k], vP[i], i, k, cP, fdvP);
    else
      Asignar(vR[k], vQ[j], j, k, cQ, fdvQ);
  }
}  // Intercalar

void GenVecSinRepCaso2(tvEnt vE, byte card) {
  byte x;

  for (byte i = 1; i <= MAX_ELEM; i++)
    vE[i] = i;
  for (byte i = 1; i <= card; i++) {
    x = random(MAX_ELEM - i + 1) + i;
    IntCmb(vE[i], vE[x]);
  }
}  // GenVecSinRepCaso2

void EmiteVec(tvEnt vE, byte card, str20 titulo) {
  cout << titulo << endl;
  cout << "#" << titulo << ": " << setw(3) << (short)card << endl;
  for (byte i = 1; i <= card; i++)
    cout << setw(4) << (short)vE[i];
  cout << endl;
  cin.get();
}  // EmiteVec

int main() {
  tvEnt p, q;
  tvEntD r;
  byte m, n;

  m = ObtCard("Cjto. P");
  n = ObtCard("Cjto. Q");
  GenVecSinRepCaso2(p, m);
  GenVecSinRepCaso2(q, n);
  OrdxBur(p, m);
  OrdxBur(q, n);
  Intercalar(p, q, r, m, n);
  EmiteVec(p, m, "Cjto. P");
  EmiteVec(q, n, "Cjto. Q");
  EmiteVec(r, m + n, "Cjto. R");

  return 0;
}
