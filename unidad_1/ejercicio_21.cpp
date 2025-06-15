// Unidad 1 - Ejercicio 21
#include <iostream>

using namespace std;

bool Divisible(int dividendo, int divisor) {
  return !(dividendo % divisor);
}

int main() {
  cout << "100 es divisible por 10: " << Divisible(100, 10) << endl;
  return 0;
}
