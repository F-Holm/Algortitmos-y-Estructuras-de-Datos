/*
    Id.Program: G1_Ej_ConjeturaDeCollatz.cpp
    Fecha.....: marzo-2022
    Autor.....: Lic. Hugo Cuello
    Comentario: Problema matematico: Conjetura de Collatz.
                  Presenta 2 reglas simples:
                  Regla 1: Si el nro. es impar, se lo
                          multiplica por 3 y se suma 1.
                  Regla 2: Si el nro. es par, se lo
                          divide por 2.
                  Todo nro. positivo si se aplican estas
                  2 reglas terminará en el ciclo 4,2,1.
                  El nro. más bajo conseguido es 1.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

bool EsPar(unsigned short x) {
  return !(x % 2);
} // EsPar

int main() {
  unsigned short num,
                 cant = 0;

  cout << "Ing. un numero entero positivo: ";
  cin >> num;
  while (num > 1) {
    cant++;
    cout << num << ' ';
    if (!EsPar(num))
      num = num * 3 + 1;
    else
      num = num / 2;
  }
  cout << num << endl << "Cant.: " << cant;
  return 0;
}
