/*
        Id.Programa: G1Ej15.cpp
        Autor......: Lic. Hugo Cuello
        Fecha......: julio-2013
        Comentario.: Generar los 3 primeros numeros perfectos.
*/

#include <fstream>
#include <iomanip>
using namespace std;
typedef unsigned long ulong;

bool EsPrimo(double x) {
  if (x == 2)
    return true;
  else if (ulong(x) % 2 == 0 || ulong(x) == 1)
    return false;
  for (ulong i = 3; i <= x / 2; i += 2)
    if (ulong(x) % i == 0)
      return false;
  return true;
}  // EsPrimo

main() {
  short n;
  double nroPerfecto;

  cout << "Metodo para determinar numero perfecto" << endl;
  do {
    cout << "Ing.valor n >=2: ";
    cin >> n;
  } while (n < 2);
  if (EsPrimo(n) && EsPrimo(pow(2, n) - 1)) {
    nroPerfecto = pow(2, n - 1) * (pow(2, n) - 1);
    cout << setw(7) << ' ' << "n: " << n << endl
         << " 2^n - 1: " << pow(2, n) - 1
         << " nro.Perfecto: " << setprecision(37) << nroPerfecto;
  } else
    cout << "n: " << n << " o 2^n -1: " << (pow(2, n) - 1)
         << " no es o no son primos"
         << " no es perfecto: " << pow(2, n - 1) * (pow(2, n) - 1);
  return 0;
}
