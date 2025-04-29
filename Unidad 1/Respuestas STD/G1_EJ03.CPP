/*
	Id.Programa: G1_Ej3.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Conociendo sus catetos a y b, hallar la superficie de
                un cuadrado con lado igual a la medida de la
                hipotenusa de un triangulo rectangulo si es > 100,
                sino el doble de su valor.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <cmath>
#include <iostream>
using namespace std;

int main () {
  float a,
        b,
        c,
        SupCuad;

  cout << "Emitir Sup.Cuad con hipotenúsa >100 o 2*hip si es <= 100" << endl;
  cout << "Cateto a: ";
  cin >> a;
  cout << "Cateto b: ";
  cin >> b;
  c = sqrt(pow(a,2) + pow(b,2));
  if (c > 100)
    SupCuad = pow(c,2);
  else
    SupCuad = pow(2*c,2);
  cout << "Sup.Cuad.= " << SupCuad << " c/Hipot. = " << c << endl;
  return 0;
}
