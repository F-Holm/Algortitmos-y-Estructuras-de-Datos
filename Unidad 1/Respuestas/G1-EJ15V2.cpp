/*
	Id.Programa: G1-Ej15V2.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Generar los 3 primeros numeros perfectos
	               utilizando una expresi�n aritmetica,
	                1 +  2 =  3;  3 *  2 =   6 es nro.perfecto.
	                3 +  4 =  7;  7 *  4 =  28 es nro.perfecto.
	                7 +  8 = 15.
	               15 + 16 = 31; 31 * 16 = 496 es nro.perfecto.
                   ...
    Lenguaje...: Borland V.5.5
*/

#include <iomanip>
#include <fstream>
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
} //EsPrimo

main () {
  double ultTer = 2,
      num = 1,
   nroPerf;
  short k = 0;

  cout.precision(0);
  cout << fixed;
  cout << "Generar los 7 primeros numeros perfectos" << endl;
  while ( k < 8) {
    num += ultTer;
    if (EsPrimo(num)) {
      nroPerf = num * ultTer;
      ++k;
      cout << setw(2) << k << "-: " << setw(20) << nroPerf << endl;
    }
    ultTer *= 2;
  }
  return 0;
}
