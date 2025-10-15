/*
   Id.Programa: maxComDiv.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <iostream>
using namespace std;

long mcd(int x, int y) {
  if (y == 0)
    return x;
  else {
    //cout << x << ':' << y << ':' << x % y << endl;
    return mcd(y, x % y);
  }
} //mcd

int main() {
  int a,
      b;

  cout << "Ing. dividendo: ";
  cin >> a;
  cout << "Ing. divisor: ";
  cin >> b;
  cout << "mcd(" << a << ", " << b << ")= " << mcd(a,b) << endl;
  cout << "mcd(" << b << ", " << a << ")= " << mcd(b,a);
  return 0;
}
