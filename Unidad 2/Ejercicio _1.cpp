// Unidad 2 - Ejercicio _1
#include <iostream>

using namespace std;

char* FillBlank(char car, short n) {
  char* str = new char[n + 1];
  str[n] = '\0';
  for (n -= 1; n >= 0; n--) str[n] = car;
  return str;
}

int main() {
  char* str = FillBlank('-', 100);
  cout << str << endl;
  delete[] str;
  return 0;
}
