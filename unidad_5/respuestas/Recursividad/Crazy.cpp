/*
   Id.Programa: Crazy.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Tecnicas recursivas.
*/

#include <fstream>
using namespace std;

long Crazy(int x, int y) {
  if (x == y)
    return 1;
  else
    if (x > y)
      return 0;
    else
      return x + Crazy(x + 1, y);
} //Crazy

int main() {
  int a,
      b;

  cout << "Ing. entero: ";
  cin >> a;
  cout << "Ing. entero: ";
  cin >> b;
  cout << "Crazy(" << a << ", " << b << ")= " << Crazy(a,b);
  return 0;
}
