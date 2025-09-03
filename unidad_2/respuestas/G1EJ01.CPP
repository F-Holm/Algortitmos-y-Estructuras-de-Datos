/*
	Id.Programa: G1Ej01.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dadas las medidas de los catetos de un triangulo
                 rectangulo, hallar la medida de su hipotenusa.
*/

#include <fstream>
using namespace std;

main() {
  float a,
        b,
        c;

  cout << "Calcular hipotenusa con datos de catetos a y b" << endl;
  cout << "Cateto a: ";
  cin >> a;

  cout << "Cateto b: ";
  cin >> b;
  c = sqrt(pow(a,2) + pow(b,2));
  cout << "Hipotenusa: " << c;
  return 0;
}
