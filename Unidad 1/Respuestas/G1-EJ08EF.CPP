/*
	Id.Programa: G1-Ej08Ef.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dado un valor entero n > 0, generar la sumatoria
								 desde 1 hasta n.
	Lenguaje...: Borland V.5.5
*/

#include <iostream>

using namespace std;

int main () {
  short n;
  long sum;

  cout << "Hallar la sumaroria desde 1 hasta n" << endl;
  do {
    cout << "Entero n: ";
    cin >> n;
  }
  while (n <= 0);
  sum = n * (n + 1) / 2;
	cout << "Sumatoria desde 1 hasta " << n << " = " << sum;
	return 0;
}
