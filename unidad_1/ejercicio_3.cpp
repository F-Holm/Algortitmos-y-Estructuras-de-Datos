// Unidad 1 - Ejercicio 3
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double a, b, h;
  cout << "Ingrese los valores de los catetos:" << endl;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;

  h = hypot(a, b);
  if (h <= 100) h *= 2;

  cout << "La superficie del cuadrado es: " << h << endl;
  return 0;
}
