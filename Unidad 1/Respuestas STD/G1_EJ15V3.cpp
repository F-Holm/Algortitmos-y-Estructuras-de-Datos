/*
	Id.Programa: G1_Ej15V3.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Generar los 3 primeros numeros perfectos,
	               utilizando una expreson aritmetica:
	               n^(n-1) * (2^n - 1) con n >= 2,
	               si n y (2^n-1) ambos son primos,
	               entonces el resultado del producto
	               es nro.perfecto. �obtiene esta expresión
	               todos los nro. perfectos o saltea algunos?
    Lenguaje...: cygwin64 gcc 64bits for windows
*/

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

typedef unsigned long ulong;

bool EsPrimo (double x) {
  if (x == 2)
    return true;
  else
    if (ulong(x) % 2 == 0 || ulong(x) == 1)
      return false;
  for (ulong i = 3; i <= x / 2; i += 2)
    if (ulong(x) % i == 0)
      return false;
  return true;
}
//EsPrimo

int main () {
  short  n = 1,
         k = 0;
  double nroPerfecto;

  cout.precision(0);
  cout << fixed;
  cout << "Metodo para determinar numero perfecto" << endl;
  while (k < 7) {
    n++;
    if (EsPrimo(n) && EsPrimo(pow(2,n)-1)) {
      k++;
      nroPerfecto = pow(2,n-1) * (pow(2,n)-1);
      cout << setw(15) << nroPerfecto << " es nro.Perfecto." << endl;
    }
  }
  return 0;
}
