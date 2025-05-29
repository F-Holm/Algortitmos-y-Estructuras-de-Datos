/*
    Id.Programa: G2-Ej04 OperacCjtoConArr.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: ago-2014
    Comentario.: Operaciones de Conjunto con arreglos:
                   a) Union
                   b) Interseccion
                   c) Diferencia
                   d) Diferencia Simetrica
                   e) Complemento de A U B
    Lenguaje...: Borland C++ V.5.5
*/

#include<conio.h>
#include<iomanip>
#include<fstream>
#include<iostream>
#include "borland.h"
#include<windows.h>
using namespace std;

#define pOperCjto tvEnt vP, tvEnt vQ, tvEnt vR, short cP, short cQ, short &cR
#define pOperDifer tvEnt v1, tvEnt v2, tvEnt vR, short c1, short c2, short &cR

const int
  MAX_ELEM = 90;

typedef char str20[21];
typedef short tvEnt[MAX_ELEM + 1]; //pos. cero no se va a usar.

// Prototipos ------------------------------------------------
short ObtCard(str20 );
void IntCmb(short &, short &);
void OrdxBur(tvEnt , short );
char Menu();
short BusBinVec(tvEnt , short , short );
void Union(tvEnt , tvEnt , tvEnt , short , short , short &);
void Intersec(tvEnt , tvEnt , tvEnt , short , short , short &);
void Difer(tvEnt , tvEnt , tvEnt , short , short , short &);
void DifSim(tvEnt , tvEnt , tvEnt , short , short , short &);
void Cmplto(tvEnt , tvEnt , tvEnt , short , short , short &);
void GenVecSinRepCaso2(tvEnt , short );
void EmiteVec(tvEnt , short , str20 );
// Fin Prototipos --------------------------------------------

short ObtCard(str20 titulo) {
  short card;

  clrscr();
  do {
    gotoxy(10,3);
    cout << titulo << " # 0 y " << MAX_ELEM << ": ";
    clreol();
    cin >> card;
  } while (!(card >= 0 && card <= MAX_ELEM));
  return card;
} //ObtCard

void IntCmb(short &elem1, short &elem2) {
	short aux = elem1;

	elem1 = elem2;
	elem2 = aux;
} // IntCmb

void OrdxBur(tvEnt vE, short card) {
	bool ordenado;
	short k = 0;

	do {
		ordenado = true;
		k++;
		for (short i = 1; i <= card - k; i++)
			if (vE[i] > vE[i + 1]) {
				IntCmb(vE[i],vE[i + 1]);
				ordenado = false;
			}
	} while (!ordenado);
} // OrdxBur

char Menu() {
  char opc;

  clrscr();
  gotoxy(10,5);
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
} //Menu

short BusBinVec(tvEnt vX, short clv, short ult) {
	short pri = 1,
          med;

	while (pri <= ult) {
		med = (pri + ult) / 2;
		if (vX[med] == clv)
			return med;
		else
			if (clv > vX[med])
				pri = med + 1;
			else
				ult = med - 1;
	}
	return 0;
} //BusBinVec

void Union(pOperCjto) {

  for (short i = 1; i <= cP; i++)
    vR[i] = vP[i];
  cR = cP;
  for (short i = 1; i <= cQ; i++)
    if (!BusBinVec(vP,vQ[i],cP)) {
      cR++;
      vR[cR] = vQ[i];
    }
} //Union

void Intersec(pOperCjto) {

  for (short i = 1; i <= cP; i++)
    if (BusBinVec(vQ,vP[i],cQ)) {
    cR++;
    vR[cR] = vP[i];
  }
} //Intersec

void Difer(pOperDifer) {

  for (short i = 1; i <= c1; i++)
    if (!BusBinVec(v2,v1[i],c2)) {
      cR++;
      vR[cR] = v1[i];
    }
} //Difer

void DifSim(pOperCjto) {

  Difer(vP,vQ,vR,cP,cQ,cR);
  Difer(vQ,vP,vR,cQ,cP,cR);
} //DifSim

void Cmplto(pOperCjto) {

  for (short i = 1; i <= MAX_ELEM; i++)
    if (!BusBinVec(vP,i,cP) && !BusBinVec(vQ,i,cQ)) {
      cR++;
      vR[cR] = i;
    }
} //Cmplto

void GenVecSinRepCaso2(tvEnt vE, short card) {
  short x;

  for (short i = 1; i <= MAX_ELEM; i++)
    vE[i] = i;
  for (short i = 1; i <= card; i++) {
    x = random(MAX_ELEM - i + 1) + i;
    IntCmb(vE[i],vE[x]);
  }
} //GenVecSinRepCaso2

void EmiteVec(tvEnt vE, short card, str20 titulo) {

  cout << titulo << endl;
  cout << "#" << titulo << ": " << setw(3) << (short) card << endl;
  for (short i = 1; i <= card; i++)
    cout << setw(4) << (short) vE[i];
  cout << endl;
  getche();
} //EmiteVec

int main() {
  tvEnt p,
        q,
        r;
  short  m,
        n,
        k;
  char  opc;

  m = ObtCard("Cjto. P");
  n = ObtCard("Cjto. Q");
  GenVecSinRepCaso2(p,m);
  GenVecSinRepCaso2(q,n);
  OrdxBur(p,m);
  OrdxBur(q,n);
  do {
    opc = Menu();
    k = 0;
    switch (opc) {
      case 'A': Union(p,q,r,m,n,k);
                break;
      case 'B': Intersec(p,q,r,m,n,k);
                break;
      case 'C': Difer(p,q,r,m,n,k);
                break;
      case 'D': DifSim(p,q,r,m,n,k);
                break;
      case 'E': Cmplto(p,q,r,m,n,k);
                break;
    }
    if (opc != 'F') {
     EmiteVec(p,m,"Cjto. P");
     EmiteVec(q,n,"Cjto. Q");
     EmiteVec(r,k,"Cjto. R");
    }
  } while (!(opc == 'F'));
  return 0;
}
