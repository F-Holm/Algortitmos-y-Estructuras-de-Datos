/*
	Id.Programa: G1_Ej19.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Crear una funcion que recibe un valor entero x, y retorne
					el signo de x. A diferencia de la funcion matematica,
					se acepta el cero y en este caso se debe retornar cero.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

float vabs (float x) {
  if (x >= 0)
    return x;
  else
    return -x;
} // vabs

short sgn (float x) {
  if (x == 0)
    return 0;
  else
    return x / vabs (x);
} // sgn

int main () {
  float a;

  cout << "Funcion que retorna el signo de x: ";
  cin >> a;
  cout << "sgn x: " << sgn(a);
  return 0;
}
