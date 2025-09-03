// Numeros primos

#include <fstream>
using namespace std;

bool EsPrimo(long x) {
  x = abs(x);
  switch (x) {
    case 1:
      return false;
    case 2:
      return true;
    default:
      if (x % 2 == 0)
        return false;
      for (long i = 3; i <= x / 2; i += 2)
        if (x % i == 0)
          return false;
      return true;
  }
}  // EsPrimo

int main() {
  long num;

  cout << "Determina si un entero es o no Primo" << endl;
  cout << "Entero - Fin = 0: ";
  cin >> num;
  while (num) {
    if (EsPrimo(num))
      cout << num << " es numero primo" << endl;
    else
      cout << num << " No es numero primo" << endl;
    cout << "Entero - Fin = 0: ";
    cin >> num;
  }
  return 0;
}
