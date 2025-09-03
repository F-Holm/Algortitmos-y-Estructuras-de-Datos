/*
	Id.Programa: G1Ej20.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Crear una funcion que recibe dos valores enteros y retorne
								 el resto de la division entera.
*/

#include <fstream>
using namespace std;

int resto(int x, int y) {

	return x - x / y * y;
} // resto

void main() {
	int a,
        b;

	cout << "Funcion que retorna el resto de una division entre enteros" << endl;
	cout << "Entero a: ";
	cin >> a;
	cout << "Entero b: ";
	cin >> b;
	cout << "resto(" << a << ", " << b << ") = " << resto(a,b);
}
