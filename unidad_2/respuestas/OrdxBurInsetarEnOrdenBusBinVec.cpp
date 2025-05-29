

#include <iostream>
#include <iomanip>
using namespace std;

int BusBinVec(int vCI[ ], int clv, short ult) {
  short pri = 0,
        med;

  ult--;
  while (pri < ult) {
    med = (pri + ult) / 2;
	if (vCI[med] == clv)
	  return med;
    else
	  if (vCI[med] < clv)
		pri = med + 1;
      else
		ult = med - 1;
  }
  return -1;
} // BusBinVec

void IntCmb ( int &elem1, int &elem2) {
    int aux = elem1;

    elem1 = elem2;
    elem2 = aux;
} // IntCmb

void OrdxBur (int v [ ], short card) {
    short k = 0;
    bool  ordenado;

    do {
        k++;
        ordenado = true;
        for (short i = 0; i < card - k; i++) {
            if (v [ i ] > v [ i + 1 ]) {
                IntCmb (v [ i ], v [ i + 1 ]);
                ordenado = false;
            }
        }
    }
    while (!ordenado);
} // OrdxBur

void InsertarEnOrden(int vE[], short elem, short card) {

	while (card > 0 && elem < vE[card - 1]) {
		vE[card] = vE[card - 1];
		card--;
	}
	vE[card] = elem;
} // InsertarEnOrden

int main() {
    int vec[100],
        elem;
    short pos;

    for (short i = 0; i < 100; i++) {
        vec[i] = random(501) + 200; // entre 200 y 700
        //InsertarEnOrden(vec,elem,i);
    }
    cout << endl << endl;
    OrdxBur(vec,100);
    for (short i = 0; i < 100; i++)
        cout << setw(5) << vec[i] << ' ';
    cout << endl;
    cout << "Elemento entre 200 y 700: ";
    cin >> elem;
    pos = BusBinVec(vec,elem,100);
    if (pos >= 0)
        cout << "El valor " <<  elem << " se encontro en la pos.: "
             << pos << endl;
    else
        cout << "El valor " << elem << " NO se encontro..." << endl;
    return 0;
}
