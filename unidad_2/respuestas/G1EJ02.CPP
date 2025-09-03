/*
	Id.Programa: G1Ej02.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dados 2 valores enteros y distintos emitir cartel apropiado
	               que informe el mayor entre ellos.
*/

#include <fstream>
using namespace std;

main() {
	int a,
	    b;

	cout << "Mostrar cartel que informe el mayor entre 2 enteros diferentes" << endl;
	cout << "Entero a: ";
	cin >> a;
	do {
	  cout << "Entero b: ";
	  cin >> b;
	}
	while (a == b);
	if (a > b)
		cout << "a > b";
	else
		cout << "b > a";
    return 0;
}
