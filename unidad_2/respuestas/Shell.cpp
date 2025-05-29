/*
  Id.Programa: Shell.cpp
  Fecha......: ago-1992
  Autor......: Lic. Hugo Cuello
  Comentario.: M�todo logar�tmico de ordenamiento interno.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include "borland.h"
using namespace std;
const int MAX_ELEM = 1000;
typedef short tVec[MAX_ELEM];

void Emitir(tVec v, short card) {
  for(short i = 0; i < card; i++)
    cout << setw(8) << v[i] << ' ';
  cout << endl << "--------------------------" << endl;
} //Emitir

void Shell(tVec v, short card) {
  short j,
        intrvl,
        aux;

  intrvl = card / 2;
  while(intrvl > 0) {
    for(short i = intrvl; i < card; i++) {
      j = i;
      aux = v[i]; //o tmb. *(v + i);
      while(j >= intrvl && *(v + j - intrvl) > aux) {
        *(v + j) = *(v + j - intrvl);
        j -= intrvl;
      }
      v[j] = aux; // o tmb. *(v + j) = aux;
    }
    intrvl /= 2;
  }
} //Shell

int main() {
  short v[MAX_ELEM];

  for(short i = 0; i < MAX_ELEM; i++)
    v[i] = random(31000) + 1001; //genera al azar valores enteros.
  Emitir(v,MAX_ELEM);
  Shell(v,MAX_ELEM);             //ordena los elementos ascendentemente.
  Emitir(v,MAX_ELEM);
} //main
