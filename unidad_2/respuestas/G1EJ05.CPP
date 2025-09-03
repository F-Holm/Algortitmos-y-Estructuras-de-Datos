/*
	Id.Programa: G1Ej05.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dados 2 valores enteros >= 0, hallar la potencia de a ^ b.
                    Ambos simultaneamente distintos de cero.
*/

#include <fstream>
using namespace std;

main() {
	short  a,
		   b;
	long pot = 1;

	cout << "Hallar la potencia de a ^ b" << endl;
	do {
		cout << "Entero a: ";
		cin >> a;
		cout << "Entero b: ";
		cin >> b;
    } while (!(a + b)); // (a+b == 0)
	for (short i = 1; i <= b; i++)
		pot *= a;  // pot = pot * a;
	cout << a << " ^ " << b << " = " << pot;
	return 0;
}
