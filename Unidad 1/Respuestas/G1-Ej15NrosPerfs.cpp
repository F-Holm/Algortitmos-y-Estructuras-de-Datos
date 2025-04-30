/*
	Id.Programa: G1-Ej15NrosPerfs.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Generar los 3 primeros numeros perfectos,
	               aplicando el algoritmo de la definicion
	               de nro.perfecto, que dice:
	               x es nro.perfecto si la suma de sus
	               partes alicuotas (sus divisores) excepto
	               el propio valor x, suma x.
  Lenguaje...: Borland V.5.5
*/

#include <iomanip>
#include <iostream>

using namespace std;

int main () {
  int sum,
      num = 0,
      k = 0;

  cout << "Generar los 3 primeros numeros perfectos" << endl;
  while ( k < 3 ) {
    num += 2;
    sum = 1;
    for (int i = 2; i <= num / 2; i++)
      if ( num % i == 0 )
        sum += i;
    if ( num == sum) {
      k++;
      cout << setw(2) << k << "-: " << setw(5) << num << endl;
    }
  }
  return 0;
}
