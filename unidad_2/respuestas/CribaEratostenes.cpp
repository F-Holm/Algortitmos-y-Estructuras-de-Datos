

// Numeros primos

#include <iostream>
using namespace std;

int main() {
  int criba[101];
  int num = 0;

  for (int i = 1; i <= 100; i++)
    criba[i] = i;
  num += 1;
  while (pow(num, 2) < 100) {
    num += 1;
    for (int k = num; k < 100 / num; k++)
      criba[num * k] = 0;
  }
  for (int i = 2; i <= 100; i++)
    if (criba[i] > 0)
      cout << criba[i] << ' ';
  return 0;
}
