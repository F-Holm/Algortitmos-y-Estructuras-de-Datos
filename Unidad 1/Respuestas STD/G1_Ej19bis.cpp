/*
	Id.Programa: G1_Ej19bis.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Crear una funcion que recibe un valor entero x, y retorne
								 el signo de x. A diferencia de la funcion
								 matematica, se acepta el cero y en este
								 caso se debe retornar cero.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <cmath>
#include <iostream>
using namespace std;

string iif (bool expLog, string x, string y) {
  if (expLog)
    return x;
  else
    return y;
} // iif

short sgn (float x) {
  if (!x)
    return x;
  else
    return x / fabs (x);
} // sgn

int main () {
  float a;

  cout << "Valor real: ";
  cin >> a;
  cout << "sgn x: " << iif(a==0,"cero",iif(sgn(a) == 1,"Positivo","Negativo"));
  return 0;
}
