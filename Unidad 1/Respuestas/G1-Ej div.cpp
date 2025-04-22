/*
	Id.Programa: G1-Ej div.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion primitiva poly de una variable.
	Lenguaje...: Borland V.5.5
*/

#include <fstream>
using namespace std;

main() {
  div_t x;

  x = div(7, 3);
  cout << "Division entre enteros; 7 / 3:" << endl;
  cout << "Cociente: " << x.quot << endl;
  cout << "Resto: " << x.rem << endl;
  return 0;
}

