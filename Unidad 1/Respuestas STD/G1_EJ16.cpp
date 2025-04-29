/*
	Id.Programa: G1_Ej16.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Manejo apropiado con variables booleanas.
    Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

int main () {
  bool a,
       b;

  cout << "Muestra de manejo vars. booleanas o logicas" << endl;
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
