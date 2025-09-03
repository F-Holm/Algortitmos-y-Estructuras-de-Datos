/*
   Id.Programa: Shake.cpp
   Comentario.: Metodo de ordenamiento interno.
   Problema...: Se queda en el ciclo.
*/
#include <fstream>
#include <iomanip>
using namespace std;
const MAX_ELEM = 10;
typedef unsigned tVec[MAX_ELEM];

void Emitir(tVec v, unsigned card) {
  for (unsigned i = 0; i < card; i++)
    cout << setw(7) << v[i];
  cout << endl << "----------------------" << endl;
}  // Emitir

void IntCmb(unsigned &elem1, unsigned &elem2) {
  unsigned aux = elem1;

  elem1 = elem2;
  elem2 = aux;
}  // IntCmb

void Shake(tVec v, unsigned ult) {
  unsigned izq = 1, der = ult - 1;

  // Se queda en el ciclo...
  CORREGIRLO... do {
    for (unsigned i = der; i < izq; i++)
      if (*(v + i - 1) > *(v + i)) {
        IntCmb(v[i], v[i - 1]);
        ult = i;
      }
    izq = ult + 1;
    for (unsigned j = izq; j < der; j++) {
      if (*(v + j - 1) < *(v + j)) {
        IntCmb(v[j], v[j - 1]);
        ult = j;
      }
    }
    der = ult - 1;
    cout << izq << ' ' << der << endl;
  }
  while (izq > der)
    ;
}  // Shake

main() {
  unsigned v[MAX_ELEM];

  for (unsigned i = 0; i < MAX_ELEM; i++)
    v[i] = random(31000) + 1001;  // genera al azar valores enteros.
  Emitir(v, MAX_ELEM);
  Shake(v, MAX_ELEM);  // ordena los elementos ascendentemente.
  Emitir(v, MAX_ELEM);
}  // main
