/*
 *****************
 *    Id.Programa: ColaCircular.cpp
 *    Autor......: Lic.Hugo Cuello
 *    Fecha......: sep-2014
 *    Comentario.: Cola Circular
 * ***************
                                              *--------------*
                  *--------*    *--------*    |  int   |tCola|       *---*
                  |    | *-|--->|    | *-|--->|nroVuelo|sgte |<------|-* |
                  *--^-----*    *--------*    |  4 b.  |4 b. |       *---*
                    |                        *-----------|--*        cFin
                   *------------------------------------*
*/

#include <conio.h>
#include <fstream>
using namespace std;

typedef int tInfo;
typedef struct sNodo *tCola;
struct sNodo {
  tInfo info;
  tCola sgte;
};

// ------------< prototipos >-----------------
void Enqueue(tCola &, tInfo );
void Dequeue(tCola &, tInfo & );
// ------------< Fin prototipos >-------------

// ------------< funciones >------------------
void Enqueue(tCola &qFin, tInfo valor) {
  tCola pNodo;

  pNodo = new sNodo;
  pNodo->info = valor;
  if (!qFin) // qFin = NULL
    pNodo->sgte = pNodo; // primer nodo en la cola circular
  else { // qFin <> NULL
    pNodo->sgte = qFin->sgte;
    qFin->sgte = pNodo;
  }
  qFin = pNodo;
} //Enqueue

void Dequeue(tCola &qFin, tInfo &valor) {
  tCola pElim;

  pElim = qFin->sgte;
  valor = qFin->sgte->info;
  if (qFin != qFin->sgte)
    qFin->sgte = qFin->sgte->sgte;
  else
    qFin = NULL; // ultimo nodo en la cola circular
  delete pElim;
} //Dequeue
// -------------< Fin funciones >-------------

int main() {
  tCola colaFin = NULL;
  int   valor;

  cout << 5 << endl;
  Enqueue(colaFin,5);
  cout << 3 << endl;
  Enqueue(colaFin,3);
  cout << 7 << endl;
  Enqueue(colaFin,7);
  cout << "------------------" << endl;
  while (colaFin) {
    Dequeue(colaFin,valor);
    cout << valor << endl;
  }
  return 0;
} // main

