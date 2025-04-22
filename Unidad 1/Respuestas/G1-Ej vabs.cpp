/*
	Id.Programa: G1-Ej vabs.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion de usuario vabs.
	Lenguaje...: Borland V.5.5
*/

#include <iostream>

using namespace std;

float vabs(float x) {
  if (x >= 0)
    return x;
  else
    return -x;
} // vabs

int main() {
  float a,
        b;
  int   c,
        d;

  cout << "Ing. valor real: ";
  cin >> a;
  cout << "| " << a << " | = " << vabs(a) << endl;
  return 0;
}
