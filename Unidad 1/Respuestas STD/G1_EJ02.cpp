/*
	Id.Programa: G1_Ej02.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Dados 2 valores enteros y distintos emitir cartel apropiado
	               que informe el mayor entre ellos.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

int main () {
  int a,
      b;

  cout << "Mostrar cartel que informe el mayor de 2 enteros distintos" << endl;
  cout << "Entero a: ";
  cin >> a;
  do {
    cout << "Entero b: ";
    cin >> b;
  }
  while (a == b);
  if (a > b)
    cout << "a > b" << endl;
  else
    cout << "b > a" << endl;
  return 0;
}
