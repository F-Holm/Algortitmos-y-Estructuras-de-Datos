// Unidad 1 - Ejercicio 20
#include <iostream>

using namespace std;

int Resto(int dividendo, int divisor) {
  return dividendo % divisor;
}

int main() {
  cout << "Resto de 234/5464: " << Resto(234, 5464) << endl;
  return 0;
}
