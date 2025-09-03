/*
	Id.Programa: G1Ej23.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dado un valor n y a continuacion n ternas de valores enteros,
                   emitir c/u. de las ternas ordenadas descendente y por fin
				   de proceso el valor minimo y maximo de todas las ternas.
*/

#include <iostream>
using namespace std;
typedef unsigned short ushort;
const short MAX_INT = 32767;
const short MIN_INT = -MAX_INT - 1;


void EmiteInic(short &vMin, short &vMax) {

	cout << "Ternas de valores enteros ordenar descendente" << endl;
	cout << "Val.Min. y Val.Max" << endl;
	vMin = MAX_INT;
	vMax = MIN_INT;
} // EmiteInic

ushort ObtDato() {
	short cTer;

	do {
	  cout << "*Cantidad de ternas: ";
	  cin >> cTer;
	}
	while (cTer <= 0);
	return cTer;
} // ObtDato

void ObtTerna(short &x, short &y, short &z) {
static short orden = 0;

    cout << ++orden << ' ';
	cout << "Valores enteros de una terna" << endl;
	cout << "Entero 1: ";
	cin >> x;
	cout << "Entero 2: ";
	cin >> y;
	cout << "Entero 3: ";
	cin >> z;
} // ObtTerna

void IntCmb(short &elem1, short &elem2) {
	short aux = elem1;

	elem1 = elem2;
	elem2 = aux;
} // IntCmb

void OrdTerna(short &x, short &y, short &z) {

	if(y > x)
		IntCmb(x,y);
	if(z > x)
		IntCmb(x,z);
	if(z > y)
		IntCmb(y,z);
} // OrdTerna

void VerifMinMax(short x, short z, short &vMin, short &vMax) {

	if(x > vMax)
		vMax = x;
	if(z < vMin)
		vMin = z;
} // VerifMinMax

void EmiteTerna(short x, short y, short z) {

	cout << "Terna(" << x << ',' << y << ',' << z << ')' << endl;
} // EmiteTerna

void EmiteMinMax(short vMin, short vMax) {

	cout << endl << "Valor minimo de ternas: " << vMin << endl;
	cout << "Valor maximo de ternas: " << vMax << endl;
} // EmiteTot

int main() {
    ushort n;
	short  a,
           b,
    	   c,
	   	   valMin,
		   valMax;

	EmiteInic(valMin,valMax);
	n = ObtDato();
	for (ushort i = 1; i <= n; i++) {
		ObtTerna(a,b,c);
		OrdTerna(a,b,c);
		VerifMinMax(a,c,valMin,valMax);
		EmiteTerna(a,b,c);
	}
	EmiteMinMax(valMin,valMax);
	return 0;
}
