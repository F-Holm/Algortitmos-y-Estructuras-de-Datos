/*
	Id.Programa: G1_Ej17.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Manejo apropiado con variables booleanas.
    Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

int iif (bool expLog, int x, int y) {
  if (expLog)
    return x;
  else
    return y;
} // iif

int main() {
  int a,
      b;

  cout << "Determinar el mayor entre 2 enteros" << endl;
  cout << "Entero 1: ";
  cin >> a;
  do {
    cout << "Entero 2: ";
    cin >> b;
  }
  while (a == b);
  cout << "El mayor valor entre " << a << " y " << b << " es: "
           << iif(a > b, a, b) << endl;
  return 0;
}
