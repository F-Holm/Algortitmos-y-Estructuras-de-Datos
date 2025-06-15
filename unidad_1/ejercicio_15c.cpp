// Unidad 1 - Ejercicio 15c
#include <cmath>
#include <iostream>

using namespace std;
// num perfecto = suma de sus partes alicuotas excepto el propio número es el
// número dado 2^(n-1) * (2^n -1)

bool EsPrimo(unsigned int num) {
  if (num < 2)
    return false;
  for (unsigned int i = 2; i < num / 2; i++)
    if (num % i == 0)
      return false;
  return true;
}

int main() {
  unsigned int k = 0, num = 1;
  while (k < 3) {  // puede llegar hasta 8
    num++;
    unsigned int der = pow(2, num) - 1;

    if (EsPrimo(num) && EsPrimo(der)) {
      k++;
      cout << k << ") " << pow(2, num - 1) * der << " es un número perfecto\n";
    }
  }
  return 0;
}