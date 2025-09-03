/*
	Id.Programa: G1Ej08.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dado un valor entero n > 0, generar la sumatoria
                    desde 1 hasta n.
*/

#include <fstream>
using namespace std;

void main() {
	short n;
	long  sum = 0;

	cout << "Hallar la sumaroria desde 1 hasta n" << endl;
	do {
		cout << "Entero n: ";
		cin >> n;
	}
	while (n <= 0);
	for (short i = 1; i <= n; i++)
		sum += i;
	cout << "Sumatoria desde 1 hasta " << n << " = " << sum;
}
