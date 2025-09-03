/*
	Id.Programa: G1Ej3.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Conociendo sus catetos a y b, hallar la superficie de
                un cuadrado con lado igual a la medida de la
                hipotenusa de un triangulo rectangulo si es > 100,
                sino el doble de su valor.
*/

#include <fstream>
using namespace std;

main() {
	float a,
				b,
				c,
				SupCuad;

	cout << "Emitir Sup.Cuad con hip.>100 o 2*hip si es <= 100" << endl;
	cout << "Cateto a: ";
	cin >> a;
	cout << "Cateto b: ";
	cin >> b;
	c = sqrt(pow(a,2) + pow(b,2));
	if (c > 100)
		SupCuad = pow(c,2);
	else
		SupCuad = pow(2*c,2);
	cout << "Sup.Cuad.= " << SupCuad << " c/Hipot. = " << c;
	return 0;
}
