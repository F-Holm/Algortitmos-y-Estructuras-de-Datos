/*
	Id.Programa: G1Ej09.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dado un valor entero n > 0, generar la sumatoria
								 desde 1 hasta n.
*/

#include <fstream>
using namespace std;

main() {
	int n;
	long sum;

	cout << "Hallar la sumaroria desde 1 hasta n" << endl;
	do {
		cout << "Entero n: ";
		cin >> n;
	}
	while (!(n > 0));
	sum = n * (n + 1) / 2;
	cout << "Sumatoria desde 1 hasta " << n << " = " << sum;
	return 0;
}
