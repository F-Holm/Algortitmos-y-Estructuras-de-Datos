/*
    Id.Programa: G2-Ej05 FusionArreglos.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: ago-2014
    Comentario.: Fusion o Mezcla (Merge) de arreglos
    Lenguaje...: Borland V. 5.5.
*/

#include <conio.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include "borland.h"
#include <windwos.h>
using namespace std;

#define and &&
#define or ||
#define not !

const int
  MAX_ELEM = 90;

typedef char str20[21];
typedef unsigned char byte_;
typedef unsigned short word;
typedef byte_ tvEnt[MAX_ELEM + 1]; //pos. cero no se va a usar.
typedef byte_ tvEntD[2 * MAX_ELEM + 1]; //pos. cero no se va a usar.

// Prototipos --------------------------------------------------
byte_ ObtCard(str20 );
void IntCmb(byte_ &, byte_ &);
void OrdxBur(tvEnt , byte_ );
void Asignar(byte_ &, byte_ , byte_ &, byte_ &, byte_ , bool &);
void Intercalar(tvEnt , tvEnt , tvEntD , byte_ , byte_ );
void GenVecSinRepCaso2(tvEnt , byte_ );
void EmiteVec(tvEnt , byte_ , str20 );
// Fin Prototipos ----------------------------------------------

byte_ ObtCard(str20 titulo) {
  word card;

  clrscr();
  do {
    gotoxy(10,3);
    cout << titulo << " #: ";
    clreol();
    cin >> card;
  } while (not (card >= 1 and card <= MAX_ELEM));
  return card;
} //ObtCard

void IntCmb(byte_ &elem1, byte_ &elem2) {
	byte_ aux = elem1;

	elem1 = elem2;
	elem2 = aux;
} // IntCmb

void OrdxBur(tvEnt vE, byte_ card) {
	bool ordenado;
	byte_ k = 0;

	do {
		ordenado = true;
		k++;
		for (byte_ i = 1; i <= card - k; i++)
			if (vE[i] > vE[i + 1]) {
				IntCmb(vE[i],vE[i + 1]);
				ordenado = false;
			}
	} while (not ordenado);
} // OrdxBur

void Asignar(byte_ &elemR, byte_ elemX, byte_ &indX, byte_ &indR, byte_ cX,
             bool &fdvX) {

  elemR = elemX;
  indX++;
  indR++;
  fdvX = indX > cX;
} //Asignar

void Intercalar(tvEnt vP, tvEnt vQ, tvEntD vR, byte_ cP, byte_ cQ) {
  byte_ i,
       j,
       k;
  bool fdvP = false,
       fdvQ = false;

  i = j = k = 1;
  while (not fdvP or not fdvQ) {
    if (not fdvP and not fdvQ)
      if (vP[i] <= vQ[j])
        Asignar(vR[k],vP[i],i,k,cP,fdvP);
      else
        Asignar(vR[k],vQ[j],j,k,cQ,fdvQ);
    else
      if (!fdvP)
        Asignar(vR[k],vP[i],i,k,cP,fdvP);
      else
        Asignar(vR[k],vQ[j],j,k,cQ,fdvQ);
  }
} //Intercalar

void GenVecSinRepCaso2(tvEnt vE, byte_ card) {
  byte_ x;

  for (byte_ i = 1; i <= MAX_ELEM; i++)
    vE[i] = i;
  for (byte_ i = 1; i <= card; i++) {
    x = random(MAX_ELEM - i + 1) + i;
    IntCmb(vE[i],vE[x]);
  }
} //GenVecSinRepCaso2

void EmiteVec(tvEnt vE, byte_ card, str20 titulo) {

  cout << titulo << endl;
  cout << "#" << titulo << ": " << setw(3) << (short) card << endl;
  for (byte_ i = 1; i <= card; i++)
    cout << setw(4) << (short) vE[i];
  cout << endl;
  cin.get();
} //EmiteVec

int main() {
  tvEnt  p,
         q;
  tvEntD r;
  byte_   m,
         n;

  m = ObtCard("Cjto. P");
  n = ObtCard("Cjto. Q");
  GenVecSinRepCaso2(p,m);
  GenVecSinRepCaso2(q,n);
  OrdxBur(p,m);
  OrdxBur(q,n);
  Intercalar(p,q,r,m,n);
  EmiteVec(p,m,"Cjto. P");
  EmiteVec(q,n,"Cjto. Q");
  EmiteVec(r,m + n,"Cjto. R");
  return 0;
}
