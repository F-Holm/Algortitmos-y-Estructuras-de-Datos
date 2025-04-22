/*
	Id.Programa: G1-Ej07Ef.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dado un valor n, generar el valor irracional e.
	Lenguaje...: Borland V.5.5
*/

#include <iomanip>
#include <fstream>
using namespace std;

main () {
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
