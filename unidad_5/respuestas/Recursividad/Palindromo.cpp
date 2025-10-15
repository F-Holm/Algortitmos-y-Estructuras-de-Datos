/*
   Id.Programa: Palindromo.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <iostream>
using namespace std;

typedef unsigned char byte;
typedef char str20[21];

void Palindromo(str20 sarta, byte n) {
  if (n == 0)
    cout << sarta[0];
  else {
    cout << sarta[n];
    Palindromo(sarta, n - 1);
  }
} //Palindromo

int main() {
  str20 cad;

  cout << "Ing. cadena: ";
  gets(cad);
  Palindromo(cad,strlen(cad) - 1);
  return 0;
}
