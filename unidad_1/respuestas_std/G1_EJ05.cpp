/*
	Id.Programa: G1_Ej05.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Dados 2 valores enteros >= 0, hallar la potencia de a ^ b.
                    Ambos simultaneamente distintos de cero.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

int main () {
  short  a,
         b;
  long   pot = 1;

  cout << "Hallar la potencia de a ^ b" << endl;
  do {
    do {
      cout << "Entero a: ";
      cin >> a;
    }
    while (a < 0);
    do {
      cout << "Entero b: ";
      cin >> b;
    }
    while (b < 0);
  } while (!(a + b)); // (a+b == 0)
  for (short i = 1; i <= b; i++)
    pot *= a;  // pot = pot * a;
  cout << a << " ^ " << b << " = " << pot;
  return 0;
}
