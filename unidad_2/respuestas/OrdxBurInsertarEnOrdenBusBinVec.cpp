/*
    Id.Programa: OrdxBurInsertarEnOrdenBusBinVec.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: ago-2014
    Comentario.: Genera un vector con valores short sin repetir,
                   para luego ordenarlo asc. OrdxBur y finalmente
                   buscar un elemento con BusBinVec.
    Lenguaje...: Borland C++ V.5.5.
*/

#include <fstream>
#include <iomanip>
using namespace std;
const MAX_ELEM = 100;

void IntCmb(short &elem1, short &elem2) {
  short aux = elem1;

  elem1 = elem2;
  elem2 = aux;
} // IntCmb

void GenVecSinRepCaso1a(short vCI[], short card) {
  short j;

  for (short i = 1; i <= card; i++) {
    vCI[i] = random(500 ) + 200;
    j = 1;
    while (j < i)
      if (vCI[i] == vCI[j]) {
        vCI[i] = random(500) + 200;
        j = 1;
      }
    else
      j++;
  }
} //GenVecSinRepCaso1a

short BusBinVec(short vCI[ ], short clv, short ult) {
  short pri = 1,
        med;

  while (pri <= ult) {
    med = (pri + ult) / 2;
	if (vCI[med] == clv)
	  return med;
    else
	  if (vCI[med] < clv)
		pri = med + 1;
      else
		ult = med - 1;
  }
  return 0;
} // BusBinVec

void OrdxBur (short v [ ], short card) {
  short k = 0;
  bool  ordenado;

  do {
    k++;
    ordenado = true;
    for (short i = 1; i <= card - k; i++) {
      if (v [ i ] > v [ i + 1 ]) {
        IntCmb (v [ i ], v [ i + 1 ]);
        ordenado = false;
      }
    }
  }
  while (!ordenado);
} // OrdxBur

void InsertarEnOrden(short vE[], short elem, short card) {
  while (card > 1 && elem < vE[card - 1]) {
    vE[card] = vE[card - 1];
    card--;
  }
  vE[card] = elem;
} // InsertarEnOrden

main() {
  short vec[MAX_ELEM + 1],
        elem,
        pos;

  for (short i = 1; i <= MAX_ELEM; i++)
    GenVecSinRepCaso1a(vec,MAX_ELEM); // entre 200 y 699
  OrdxBur(vec,100);
  for (short i = 1; i <= 100; i++)
    cout << setw(3) << i << ' ' << setw(3) << vec[i] << ' ' << endl;
  cout << endl;
  cout << "Elemento entre 200 y 700: ";
  cin >> elem;
  pos = BusBinVec(vec,elem,100);
  if (pos > 0)
    cout << "El valor " <<  elem << " se encontro en la pos.: " << pos << endl;
  else
    cout << "El valor " << elem << " NO se encontro..." << endl;
  return 0;
}
