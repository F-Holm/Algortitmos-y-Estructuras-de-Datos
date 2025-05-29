/*
    Id.Programa: G2-Ej OrdenarArreglo.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: agosto-2014
    Comentario.: Ordena elementos en el arreglo.
    Lenguaje...: Borland V. 5.5.
*/

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

const int MAX_ELEM = 100;

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


int main() {
    int vec[MAX_ELEM];
    short n = 7;
    ifstream ValEnt("Enteros.Txt");

    for (short i = 0; i < n; i++)
        ValEnt >> vec[i];
    OrdxBur ( vec, n);
    cout << "Pos. Elem.   Valor"   << endl;
    for ( short i = 0; i < n; i++)
        cout << setw(2) << i << "    "
             << setw(2) << i + 1 << "      "
             << setw(3) << vec [i] << endl;

    ValEnt.close();
}
