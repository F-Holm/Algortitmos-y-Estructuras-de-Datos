/*
	Id.Programa: G1-Ej poly.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion primitiva poly de una variable.
	Lenguaje...: Borland V.5.5
*/

#include <fstream>
using namespace std;

main() {
  double vCoef[4],
         x = 2;

  vCoef[0] =  3;
  vCoef[1] = -2;
  vCoef[2] =  5;
  vCoef[3] = 4;
  cout << poly(x,3,vCoef) << endl; // 4*2^3+5*2^2+-2*2+3 = 32+20+-4+3 = 51
  vCoef[0] = 3;
  vCoef[1] = 1;
  vCoef[2] = 5;
  vCoef[3] = 2;
  cout << poly(x,3,vCoef); // 4*2^3+5*2^2+-2*2+3 = 32+20+-4+3 = 16+20+2+3 = 41
  return 0;
}

