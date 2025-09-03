/*
    Id.Programa: G4Ej04OperacCjtoConArr.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: ago-2014
    Comentario.: Operaciones de Conjunto con arreglos:
                   a) Union
                   b) Interseccion
                   c) Diferencia
                   d) Diferencia Simetrica
                   e) Complemento de A U B
*/

#define pOperCjto tvEnt vP, tvEnt vQ, tvEnt vR, byte cP, byte cQ, byte &cR
#define pOperDifer tvEnt v1, tvEnt v2, tvEnt vR, byte c1, byte c2, byte &cR
#include <conio.h>

#include <iomanip>
#include <iostream>
using namespace std;

const MAX_ELEM = 90;

typedef char str20[21];
typedef unsigned char byte;
typedef byte tvEnt[MAX_ELEM + 1];  // pos. cero no se va a usar.

// Prototipos ------------------------------------------------
byte ObtCard(str20);
void IntCmb(byte &, byte &);
void OrdxBur(tvEnt, byte);
char Menu();
byte BusBin(tvEnt, byte, byte);
void Union(tvEnt, tvEnt, tvEnt, byte, byte, byte &);
void Intersec(tvEnt, tvEnt, tvEnt, byte, byte, byte &);
void Difer(tvEnt, tvEnt, tvEnt, byte, byte, byte &);
void DifSim(tvEnt, tvEnt, tvEnt, byte, byte, byte &);
void Cmplto(tvEnt, tvEnt, tvEnt, byte, byte, byte &);
void GenVecSinRepCaso2(tvEnt, byte);
void EmiteVec(tvEnt, byte, str20);
// Fin Prototipos --------------------------------------------

byte ObtCard(str20 titulo) {
  short card;

  clrscr();
  do {
    gotoxy(10, 3);
    cout << titulo << " # 1 y " << MAX_ELEM << ": ";
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

char Menu() {
  char opc;

  clrscr();
  gotoxy(10, 5);
  cout << endl;
  cout << setw(10) << " " << "A: Union" << endl;
  cout << setw(10) << " " << "B: Interseccion" << endl;
  cout << setw(10) << " " << "C: Diferencia" << endl;
  cout << setw(10) << " " << "D: Diferencia Simetrica" << endl;
  cout << setw(10) << " " << "E: Complemento" << endl;
  cout << setw(10) << " " << "F: Finalizar" << endl;
  cout << endl;
  cout << setw(10) << "Su opcion: ";
  do
    opc = toupper(getch());
  while (!(opc >= 'A' && opc <= 'F'));
  cout << endl;
  return opc;
}  // Menu

byte BusBin(tvEnt vX, byte clv, byte ult) {
  byte pri = 1, med;

  while (pri <= ult) {
    med = (pri + ult) / 2;
    if (vX[med] == clv)
      return med;
    else if (vX[med] < clv)
      pri = med + 1;
    else
      ult = med - 1;
  }
  return 0;
}  // BusBin

void Union(pOperCjto) {
  for (byte i = 1; i <= cP; i++)
    vR[i] = vP[i];
  cR = cP;
  for (byte i = 1; i <= cQ; i++)
    if (!BusBin(vP, vQ[i], cP)) {
      cR++;
      vR[cR] = vQ[i];
    }
}  // Union

void Intersec(pOperCjto) {
  for (byte i = 1; i <= cP; i++)
    if (BusBin(vQ, vP[i], cQ)) {
      cR++;
      vR[cR] = vP[i];
    }
}  // Intersec

void Difer(pOperDifer) {
  for (byte i = 1; i <= c1; i++)
    if (!BusBin(v2, v1[i], c2)) {
      cR++;
      vR[cR] = v1[i];
    }
}  // Difer

void DifSim(pOperCjto) {
  Difer(vP, vQ, vR, cP, cQ, cR);
  Difer(vQ, vP, vR, cQ, cP, cR);
}  // DifSim

void Cmplto(pOperCjto) {
  for (byte i = 1; i <= MAX_ELEM; i++)
    if (!BusBin(vP, i, cP) && !BusBin(vQ, i, cQ)) {
      cR++;
      vR[cR] = i;
    }
}  // Cmplto

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
  getche();
}  // EmiteVec

int main() {
  tvEnt p, q, r;
  byte m, n, k;
  char opc;

  m = ObtCard("Cjto. P");
  n = ObtCard("Cjto. Q");
  GenVecSinRepCaso2(p, m);
  GenVecSinRepCaso2(q, n);
  OrdxBur(p, m);
  OrdxBur(q, n);
  do {
    opc = Menu();
    k = 0;
    switch (opc) {
      case 'A':
        Union(p, q, r, m, n, k);
        break;
      case 'B':
        Intersec(p, q, r, m, n, k);
        break;
      case 'C':
        Difer(p, q, r, m, n, k);
        break;
      case 'D':
        DifSim(p, q, r, m, n, k);
        break;
      case 'E':
        Cmplto(p, q, r, m, n, k);
        break;
    }
    if (opc != 'F') {
      EmiteVec(p, m, "Cjto. P");
      EmiteVec(q, n, "Cjto. Q");
      EmiteVec(r, k, "Cjto. R");
    }
  } while (!(opc == 'F'));
  return 0;
}
