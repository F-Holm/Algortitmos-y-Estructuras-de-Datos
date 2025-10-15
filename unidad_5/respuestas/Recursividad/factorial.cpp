/*
   Id.Programa: factorial.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <iostream>
using namespace std;

long double factorial(short x) {
  if (x == 0 || x == 1)
    return 1;
  else
    return x * factorial(x - 1);
} //factorial

int main() {
  short n;

  cout << "Ing. valor n para calcular su factorial: ";
  cin >> n;
  cout << n << "!= " << factorial(n);
  return 0;
}
