/*
	Id.Programa: G1-Ej hypot.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion primitiva hypot.
	Lenguaje...: Borland V.5.5
*/

#include <fstream>
using namespace std;

const double PI = 3.141592654;

main() {
  double x = 4,
         y = 3;

  cout << hypot(x,y) << endl;
  return 0;
}


