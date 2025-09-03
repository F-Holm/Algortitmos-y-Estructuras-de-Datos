/*
	Id.Programa: G1Ej19.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Crear una funcion que recibe un valor entero x, y retorne
								 el signo de x. A diferencia de la funcion matematica,
								 se acepta el cero y en este caso se debe retornar cero.
*/

#include <fstream>
using namespace std;

short sgn(float x) {
	if(x == 0)
		return 0;
	else
		return x / fabs(x);
} // sgn

void main() {
	float a;

	cout << "Funcion que retorna el signo de x" << endl;
	cout << "Real a: ";
	cin >> a;
	cout << "sgn x: " << sgn(a);
}
