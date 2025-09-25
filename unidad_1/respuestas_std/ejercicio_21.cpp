/*
	Id.Programa: G1_Ej21.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Crear una funcion que recibe dos valores enteros y retorne
                    un valor booleano de verdadero si el primero es divisible
					por el segundo, caso contrario retorne falso.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

bool EsDivis (int x, int y) {
  return x % y == 0;
} // EsDivis

int main () {
  int a,
      b;

  cout << "Funcion que retorna verdadero si el primer entero es divisible ";
  cout << "por el segundo o falso si no lo es" << endl;
  cout << "Entero a: ";
  cin >> a;
  cout << "Entero b: ";
  cin >> b;
  cout << boolalpha;
  cout << "EsDivis(" << a << " / " << b << ") = " << EsDivis(a,b);
  return 0;
}
