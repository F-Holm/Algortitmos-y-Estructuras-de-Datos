// Unidad 1 - Ejercicio 15b
#include <iostream>

using namespace std;
// num perfecto = suma de sus partes alicuotas excepto el propio número es el
// número dado

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
    unsigned int sum = 2 * num + 1;

    if (EsPrimo(sum)) {
      k++;
      cout << k << ") " << sum * (num + 1) << " es un número perfecto\n";
    }
    num = sum;
  }
  return 0;
}