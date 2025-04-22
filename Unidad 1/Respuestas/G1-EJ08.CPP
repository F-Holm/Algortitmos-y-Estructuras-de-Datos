/*
	Id.Programa: G1-Ej08.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dado un valor entero n > 0, generar la sumatoria
                    desde 1 hasta n.
	Lenguaje...: Borland V.5.5
*/

#include <fstream>
using namespace std;

main () {
  short n;
  long  sum = 0;

  cout << "Hallar la sumaroria desde 1 hasta n" << endl;
  do {
    cout << "Entero n: ";
    cin >> n;
  }
  while (n <= 0);
  for (short i = 1; i <= n; i++)
    sum += i;
  cout << "Sumatoria desde 1 hasta " << n << " = " << sum;
  return 0;
}
