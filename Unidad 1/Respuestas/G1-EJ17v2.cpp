/*
	Id.Programa: G1-Ej17.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion de usuario iif.
    Lenguaje...: Borland V.5.5
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
