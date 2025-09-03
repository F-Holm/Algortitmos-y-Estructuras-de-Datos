/*
	Id.Programa: G1Ej18.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Crear una funcion que recibe un valor logico y 2 enteros y
								 retorne el primer entero si el valor logico es verdadero,
								 caso contrario, retorne el segundo entero.
*/

#include <fstream>
using namespace std;

int mcd(int x, int y) {
	int res;

	while(y) {
		res = x % y;
		//cout << "D: " << x << "  d: " << y << "  C: "  << x / y << "  r: " << res << endl;
		x = y;
		y = res;
	}
	return x;
} // mcd

main() {
	int a,
        b,
		maxComDiv;

	cout << "Funcion que retorna el m.c.d. entre 2 valores enteros" << endl;
	cout << "Entero a: ";
	cin >> a;
	cout << "Entero b: ";
	cin >> b;
	maxComDiv = mcd(a,b);
	cout << "m.c.d.: " << maxComDiv << endl;
	cout << "Aplicacion del m.c.d.: " << endl;
	cout << a << "/" << b << " = " << a / maxComDiv << "/" << b / maxComDiv;
	cout << " que es la fraccion irreducible al dividir " << endl;
	cout << "numerador y denominador por el m.c.d. = " << maxComDiv;
	return 0;
}
