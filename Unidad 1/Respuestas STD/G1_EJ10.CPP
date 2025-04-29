/*
	Id.Programa: G1_Ej10.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Dado un valor entero n, hallar la sucesion de Fibonacci.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

main () {
  int  i,
       n;
  long anteult,
       ult,
       sum;

  cout << "Hallar la sucesion de Fibonacci desde 0 hasta n" << endl;
  cout << "Entero n: ";
  cin >> n;
  switch (n) {
    case 0:
      cout << 0 << endl;
      break;
    case 1:
      cout << 0 << ", " << 1;
      break;
    default:
      anteult = 0;
      ult = 1;
      cout << anteult << ", " << ult << ", ";
      for (i = 2; i <= n; i++) {
        sum = ult + anteult;
        anteult = ult;
        ult = sum;
        cout << sum << ", ";
      }
    cout << '\b' << '\b' << '.' << endl;
  }
  return 0;
}
