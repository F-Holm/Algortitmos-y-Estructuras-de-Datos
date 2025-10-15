/*
   Id.Programa: fibonacci.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <iostream>
using namespace std;
typedef unsigned short ushort;

long fibonacci(ushort x) {
  if (x == 0 || x == 1)
    return x;
  else
    return fibonacci(x - 1) + fibonacci(x - 2);
} // fibonacci

int main() {
  //int n;

  cout << "Ing. valor n para calcular los n + 1 terminos de la suc. de Fibonacci: ";
  //cin >> n;
  cout << "Sucesion de Fibonacci hasta " << 46 << "= " << fibonacci(46);
  return 0;
}
