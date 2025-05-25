// Unidad 1 - Ejercicio 16
#include <iostream>

using namespace std;

int main() {
  bool a, b;

  cout << "Muestra el manejo vars. booleanas o logicas" << endl;
  cout << boolalpha;
  a = b = true;

  while (a) {
    cout << a << ' ' << b << ' ' << (a && b) << endl;
    cout << noboolalpha;
    if (!b)
      a = !a;
    else
      b = !b;
  }
  return 0;
}