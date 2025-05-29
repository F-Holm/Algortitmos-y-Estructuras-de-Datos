/*
    Id.Programa: G2-Ej InsertarOrdenado.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: agosto-2014
    Comentario.: Insertar elementos en el arreglo ordenado.
    Lenguaje...: Borland V. 5.5.
*/

#include <fstream>
#include <iostream>
using namespace std;

const int
  MAX_ELEM = 5;

typedef unsigned char byte_;
typedef unsigned short word;
typedef byte_ tvEnt[MAX_ELEM];

// Prototipos -------------------------
void InsertarEnOrden(tvEnt , byte_ , byte_ );
// Fin Prototipos ---------------------

void InsertarEnOrden(tvEnt vE, byte_ elem, byte_ card) {

	while (card > 0 && elem < vE[card - 1]) {
		vE[card] = vE[card - 1];
		card--;
	}
	vE[card] = elem;
} // InsertarEnOrden

int main() {
	tvEnt vEnt;
    word valor;

	for(byte_ i = 0; i < MAX_ELEM; i++) {
		cout << "Ing. valor del elemento: ";
		cin >> valor;
		InsertarEnOrden(vEnt,valor,i);
	}
	for(byte_ i = 0; i < MAX_ELEM; i++)
		cout << (short) i << ": " << (short) vEnt[i] << endl;
	return 0;
} // main
