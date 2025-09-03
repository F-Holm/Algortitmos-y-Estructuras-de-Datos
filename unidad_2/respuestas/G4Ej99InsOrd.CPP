/*
    Id.Programa: G4Ej99InsertarOrdenado.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: agosto-2014
    Comentario.: Insertar elementos en el arreglo ordenado.
*/

#include <iostream.h>
using namespace std;

const
  MAX_ELEM = 5;

typedef unsigned char byte;
typedef unsigned short word;
typedef byte tvEnt[MAX_ELEM];

// Prototipos -------------------------
void InsertarEnOrden(tvEnt , byte , byte );
// Fin Prototipos ---------------------

void InsertarEnOrden(tvEnt vE, byte elem, byte card) {

	while (card > 0 && elem < vE[card - 1]) {
		vE[card] = vE[card - 1];
		card--;
	}
	vE[card] = elem;
} // InsertarEnOrden

int main() {
	tvEnt vEnt;
    word valor;

	for(byte i = 0; i < MAX_ELEM; i++) {
		cout << "Ing. valor del elemento: ";
		cin >> valor;
		InsertarEnOrden(vEnt,valor,i);
	}
	for(byte i = 0; i < MAX_ELEM; i++)
		cout << (short) i << ": " << (short) vEnt[i] << endl;
	return 0;
} // main
