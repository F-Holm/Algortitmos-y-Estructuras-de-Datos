// Unidad 1 - Ejercicio 15a
#include <iostream>

using namespace std;
// num perfecto = suma de sus partes alicuotas excepto el propio número es el
// número dado
int main() {
  unsigned int k = 0, num = 0;
  while (k < 3) {  // puede llegar hasta 4
    num += 2;
    unsigned int sum_div = 1;

    for (unsigned int i = 2; i <= num / 2; i++)
      if (num % i == 0)
        sum_div += i;

    if (num == sum_div) {
      k++;
      cout << k << ") " << num << " es un número perfecto\n";
    }
  }
  return 0;
}