/*
	Id.Programa: G1-Ej fmod.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion primitiva fmod obtiene el resto entero.
	Lenguaje...: Borland V.5.5
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int x;

  x = fmod(7, 3);
  cout << "Resto   7 / 3: " << x << endl;
  return 0;
}

