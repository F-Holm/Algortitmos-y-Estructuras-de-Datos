/*
   Id.Programa: Shell.cpp
   Comentario.: Método logarítmico de ordenamiento interno.
*/

#include <fstream>
#include <iomanip>
using namespace std;
const MAX_ELEM = 1000;
typedef unsigned tVec[MAX_ELEM];

void Emitir(tVec v, unsigned card) {
  for (unsigned i = 0; i < card; i++)
    cout << setw(7) << v[i] << ' ';
  cout << endl << "--------------------------" << endl;
}  // Emitir

void Shell(tVec v, unsigned card) {
  unsigned j, intrvl, aux;

  intrvl = card / 2;
  while (intrvl > 0) {
    for (unsigned i = intrvl; i < card; i++) {
      j = i;
      aux = v[i];  // o tmb. *(v + i);
      while (j >= intrvl && *(v + j - intrvl) > aux) {
        *(v + j) = *(v + j - intrvl);
        j -= intrvl;
      }
      v[j] = aux;  // o tmb. *(v + j) = aux;
    }
    intrvl /= 2;
  }
}  // Shell

main() {
  unsigned v[MAX_ELEM];

  for (unsigned i = 0; i < MAX_ELEM; i++)
    v[i] = random(31000) + 1001;  // genera al azar valores enteros.
  Emitir(v, MAX_ELEM);
  Shell(v, MAX_ELEM);  // ordena los elementos ascendentemente.
  Emitir(v, MAX_ELEM);
}  // main
