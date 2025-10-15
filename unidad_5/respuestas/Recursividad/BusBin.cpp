/*
   Id.Programa: BusBin.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <windows>
#include <iomanip>
#include <iostream>
using namespace std;

typedef int tv[200000];

int BusBin(tv v, int clv, int pri, int ult) {
  int med;

  if (pri > ult)
    return 0;
  else {
    med = (pri + ult) / 2;
    if (v[med] == clv)
      return med;
    else
      if (v[med] < clv)
        return BusBin(v,clv,med + 1,ult);
      else
        return BusBin(v,clv,pri,med - 1);
  }
} //BusBin

int main() {
  tv  vec;
  int elem,
      pos;

 for (register i = 1; i <= 10000; i++)
    vec[i] = i * 2;
  cout << "Ing. elemento: ";
  cin >> elem;
  cout << "El elemento " << elem;
  if (pos = BusBin(vec,elem,1,10000))
    cout << " se encontro en el vector..." << pos;
  else
    cout << " no se encontro en el vector...";
  return 0;
}
