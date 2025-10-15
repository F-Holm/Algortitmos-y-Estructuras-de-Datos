/*
   Id.Programa: Pot2.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <iostream>
using namespace std;

long Pot(int y) {
  if (y == 0)
    return 1;
  else
    return Pot(y - 1) * 2;
} //Pot

bool EsPot(int x) {
  int y = 0;
  while (Pot(y) < x)
    y++;
  if (Pot(y) <= x)
    return true;
  else
    return false;
} //EsPot

int main() {
  int a,
      b;

  cout << "Ing. valor entero: ";
  cin >> a;
  cout << "Ing. valor entero: ";
  cin >> b;
  cout << boolalpha;
  cout << "EsPot(" << a << "): " << EsPot(a) << endl;
  cout << "EsPot(" << b << "): " << EsPot(b) << endl;
  return 0;
}
