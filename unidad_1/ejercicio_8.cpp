// Unidad 1 - Ejercicio 8
#include <iostream>

using namespace std;

int main() {
  unsigned int n, sum = 0;
  cout << "Ingrese un número natural: ";
  cin >> n;
  for (unsigned int i = 1; i <= n; i++)
    sum += i;
  cout << "La sumatoria de todos los números naturales hasta " << n
       << " es: " << sum << endl;
  return 0;
}
