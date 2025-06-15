// Unidad 1 - Ejercicio 19
#include <iostream>

using namespace std;

int Sgn(double x) {
  if (x == 0)
    return 0;
  return x > 0 ? 1 : -1;
}

int main() {
  cout << "Signo de: -123.123 | 0 | 132123.123\n";
  cout << Sgn(-123.123) << " | " << Sgn(0) << " | " << Sgn(132123.123) << endl;
  return 0;
}
