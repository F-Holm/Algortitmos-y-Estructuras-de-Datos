// Unidad 2 - Ejercicio 4
#include <cstring>
#include <iostream>

using namespace std;

char* InvCad(char* cad) {
  size_t len = strlen(cad);
  for (unsigned int i = 0; i < len / 2; i++) {
    char temp = cad[i];
    cad[i] = cad[len - i - 1];
    cad[len - i - 1] = temp;
  }
  return cad;
}

int main() {
  char str[] = "Reinventar";
  cout << str << " -> " << InvCad(str) << endl;
  return 0;
}
