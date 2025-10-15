/*
   Id.Programa: axb.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <fstream>
using namespace std;

long axb(int x, int y) {
  cout << x << ':' << y << endl;
  if (y == 1)
    return x;
  else
    return x + axb(x,y - 1);
} //axb

int iif(bool expLog,int x, int y) {
  if(expLog)
    return x;
  else
    return y;
} //iif

int main() {
  int a,
      b;

  cout << "Ing. valor a: ";
  //cin >> a;
  cout << "Ing. valor b: ";
  //cin >> b;
  cout << "a * b= " << axb(iif(a>b,a,b),iif(a>b,b,a));
  //cout << "a * b= " << axb(a,b);
  return 0;
}
