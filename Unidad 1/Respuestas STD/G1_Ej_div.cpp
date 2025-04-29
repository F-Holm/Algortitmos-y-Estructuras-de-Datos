/*
	Id.Programa: G1_Ej_div.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion primitiva poly de una variable.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <cmath>
#include <iostream>
using namespace std;

int main() {
  div_t x;

  x = div(7, 3);
  cout << "Division entre enteros; 7 / 3:" << endl;
  cout << "Cociente: " << x.quot << endl;
  cout << "Resto: " << x.rem << endl;
  return 0;
}

