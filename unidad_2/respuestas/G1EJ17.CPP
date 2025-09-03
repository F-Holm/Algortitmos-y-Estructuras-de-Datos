/*
	Id.Programa: G1Ej17.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Crear una funcion que recibe un valor logico y 2 enteros y
                    retorne el primer entero si el valor logico es verdadero,
					caso contrario, retorne el segundo entero.
*/

#include <fstream>
using namespace std;

int iif(bool expLog, int ent1, int ent2) {

	if (expLog)
		return ent1;
	else
		return ent2;
} // iif

main() {
	int a,
        b;

	cout << "Funcion que retorna un entero u otro segun el resultado " <<
						 "de una expLog" << endl;
	cout << "Entero a: ";
	cin >> a;
	do {
	  cout << "Entero b: ";
	  cin >> b;
	}
	while (a == b);
	cout << iif(a > b,a,b);
	return 0;
}
