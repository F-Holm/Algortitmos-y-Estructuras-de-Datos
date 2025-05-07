// Unidad 1 - Ejercicio 5
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  unsigned int a, b;
  do {
    cout << "Ingrese la base: ";
    cin >> a;
    cout << "Ingrese el exponente: ";
    cin >> b;
  } while (a == 0 && b == 0);

  cout << a << "^" << b << " = " << pow(a, b) << endl;
  return 0;
}
