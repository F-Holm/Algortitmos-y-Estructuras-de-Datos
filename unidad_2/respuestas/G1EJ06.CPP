/*
	Id.Programa: G1Ej06.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dado un valor entero n, hallar su factorial.
*/

#include <fstream>
using namespace std;

main() {
	short  n;
	long double fact = 1;

	cout << "Hallar el factorial de n" << endl;
	cout << "Entero n: ";
	cin >> n;
	for (short i = n; i >= 1; i--)
		fact *= i;
	cout << n << "! = " << fact;
	return 0;
}
