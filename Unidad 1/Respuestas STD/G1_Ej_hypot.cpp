/*
	Id.Programa: G1_Ej_hypot.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion primitiva hypot.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include<cmath>
#include <iostream>
using namespace std;

const double PI = 3.141592654;

int main() {
  double x = 4,
         y = 3;

  cout << hypot(x,y) << endl;
  return 0;
}


