/*
	Id.Programa: G1-Ej07.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dado un valor n, generar el valor irracional e.
	Lenguaje...: Borland V.5.5
*/

#include <iomanip>
#include <iostream>

using namespace std;

int main () {
  short n;
  long double e = 1,
              fact;

  cout << setprecision(20);
  cout << "Hallar el numero irracional e" << endl;
  cout << "Entero n: ";
  cin >> n;
  for (short i = 1; i <= n; i++) {
    fact = 1;
    for (short j = i; j >= 1; j--)
      fact *= j;
    e += 1.0 / fact;
  }
  cout << "e~= " << e << endl;
  return 0;
}
