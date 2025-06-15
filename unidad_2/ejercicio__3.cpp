// Unidad 2 - Ejercicio _3
#include <iostream>

using namespace std;

char LowCase(char car) {
  if (car >= 'A' && car <= 'Z')
    car += 'a' - 'A';
  return car;
}

int main() {
  cout << "'A' -> " << LowCase('A') << endl;
  return 0;
}
