/*
	Id.Programa: G1-Ej random.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion primitiva random.
	Lenguaje...: Borland V.5.5
*/

#include <iostream>

#include "Borland.h"

using namespace std;

const double PI = 3.1415926;

int main() {
  short a = 12,
        b = 37; // [12, 37]

  cout << "Hola" << endl;
  randomize();
  for (short i = 1; i <= 15; i++)
    cout <<  random(b - a + 1) + 12 << endl;
  return 0;
}
