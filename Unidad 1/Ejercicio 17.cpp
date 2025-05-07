// Unidad 1 - Ejercicio 17
#include <iostream>

using namespace std;

int Iif(bool condicion, int a, int b) {
  if (condicion) return a;
  return b;
}

int main() {  // iif(a, b, c) == a ? b : c
  cout << Iif(1 > 2, 1, 2) << endl;
  return 0;
}
