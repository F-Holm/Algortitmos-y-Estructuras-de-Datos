/*
	Id.Programa: G1_Ej07Ef.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Dado un valor n, generar el valor irracional e.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iomanip>
#include <iostream>
using namespace std;

int main () {
  short n;
  long  double fact = 1;
  long double e = 1;

  cout << setprecision(20);
  cout << "Hallar el numero irracional e" << endl;
  cout << "Entero n: ";
  cin >> n;
  for (short i = 1; i <= n; i++) {
    fact *= i;
    e += 1.0 / fact;
  }
  cout << "e~= " << e;
  return 0;
}
