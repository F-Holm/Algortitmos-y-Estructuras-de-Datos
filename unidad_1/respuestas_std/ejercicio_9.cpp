/*
	Id.Programa: G1_Ej09.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Dado un valor entero n > 0, generar la sumatoria
								 desde 1 hasta n.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

int main () {
  int n;
  long sum;

  cout << "Hallar la sumatoria desde 1 hasta n" << endl;
  do {
    cout << "Entero n: ";
    cin >> n;
  }
  while (!(n > 0));
  sum = n * (n + 1) / 2;
  cout << "Sumatoria desde 1 hasta " << n << " = " << sum;
  return 0;
}
