/*
	Id.Programa: G1-Ej01.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dadas las medidas de los catetos de un triángulo
                   rectángulo, hallar la medida de su hipotenusa.
    Lenguaje...: Borland V.5.5
*/

#include <iostream>
#include <cmath>

using namespace std;

int main () {
  float a,
        b,
        c;

  cout << "Calcular hipotenusa con datos de catetos a y b" << endl;
  do {
    cout << "Cateto a: ";
    cin >> a;
    cout << "Cateto b: ";
    cin >> b;
  }
  while ( a + b == 0);
  c = sqrt(pow(a,2) + pow(b,2)); // comentario de una linea
  cout << "Hipotenusa: " << c;
  return 0;
} // main()
