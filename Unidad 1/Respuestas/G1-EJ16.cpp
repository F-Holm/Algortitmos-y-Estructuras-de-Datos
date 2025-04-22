/*
	Id.Programa: G1-Ej16.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Manejo apropiado con variables booleanas.
    Lenguaje...: Borland V.5.5
*/

#include <iostream>

using namespace std;

int main () {
  bool a,
       b;

  cout << "Muestra el manejo vars. booleanas o logicas" << endl;
  cout << boolalpha;
  a = b = true;
  while ( a ) {
    cout << a << ' ' << b << ' ' << (a && b) << endl;
    cout << noboolalpha;
    if ( !b )
      a = !a;
    else
      b = !b;
  }
  return 0;
}
