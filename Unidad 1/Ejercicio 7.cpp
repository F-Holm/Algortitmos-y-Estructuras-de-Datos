// Unidad 1 - Ejercicio 7
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  short n = 0;
  long double fact = 1, e = 1;

  cout << "Ingrese un numero natural (incluido el 0) y se calculará esa "
          "cantidad de términos del numero irracional e." << endl;

  do {
    cin >> n;
  } while (n < 0);

  for (unsigned short int i = 1; i <= n; i++) {
    fact *= i;
    e += 1.0 / fact;
  }

  cout << "La aproximación de e con " << n
       << " términos es: " << setprecision(30) << e << endl;
  return 0;
}