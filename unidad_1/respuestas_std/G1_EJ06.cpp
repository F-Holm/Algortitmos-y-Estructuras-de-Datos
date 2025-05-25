/*
	Id.Programa: G1_Ej06.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Dado un valor entero n, hallar su factorial.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

int main () {
  short  n;
  long double fact = 1;

  cout << "Hallar el factorial de n" << endl;
  cout << "Entero n: ";
  cin >> n;
  for (short i = n; i >= 1; i--)
    fact *= i;
  cout << n << "! = " << fact;
  return 0;
}
