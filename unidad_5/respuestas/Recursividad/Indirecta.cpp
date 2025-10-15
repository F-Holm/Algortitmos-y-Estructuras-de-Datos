/*
   Id.Programa: Indirecta.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <conio.h>
#include <iostream>
using namespace std;

typedef unsigned char byte;
typedef char str20[21];

void Basc(char car);

void Aasc(char car) {
  if (car > 'A')
    Basc(car);
  cout << car << ' ';
} //Aasc

void Basc(char car) {
  Aasc(--car);
} //Basc

int main() {
  char car;

  cout << "Ing. caracter: ";
  car = getche();
  Aasc(car);
  return 0;
}
