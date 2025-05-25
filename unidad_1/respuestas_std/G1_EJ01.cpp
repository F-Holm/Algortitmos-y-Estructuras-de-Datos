/*
	Id.Programa: G1_Ej01.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Dadas las medidas de los catetos de un triángulo
                   rectángulo, hallar la medida de su hipotenusa.
    Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <cmath>
#include <iostream>
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
