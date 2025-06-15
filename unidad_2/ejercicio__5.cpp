// Unidad 2 - Ejercicio _5
#include <cstring>
#include <iostream>

using namespace std;

void CmbCar(char* cad, char car1, char car2) {
  for (size_t i = 0; i < strlen(cad); i++)
    if (cad[i] == car1)
      cad[i] = car2;
}

int main() {
  char str[] = "Cambiar";
  cout << str << " -> 'a' -> 'K'";
  CmbCar(str, 'a', 'K');
  cout << str << endl;
  return 0;
}
