/*
	Id.Programa: Cola.Cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: Jul-2005 / Jun-2014
	Comentario.: Estructura dinamica de tipo Cola (=Queue) -F.I.F.O.-
                 Modulos:
                          Enqueue - Agregar
                          Dequeue - Suprimir
*/

#include <fstream>
using namespace std;

typedef int tInfo;
typedef struct sNodo *tCola;
struct sNodo {
  tInfo Info;
  tCola Sgte;
};

void Enqueue(tCola &qFte, tCola &qFin, tInfo valor) {
  tCola pNodo = new sNodo;

  pNodo->Info = valor;
  pNodo->Sgte = NULL;
  if (!qFte)
    qFte = pNodo;
  else
    qFin->Sgte = pNodo;
  qFin = pNodo;
} //Enqueue

void Dequeue(tCola &qFte, tCola &qFin, tInfo &valor) {
  tCola pElim = qFte;

  valor = qFte->Info;
  qFte = qFte->Sgte;
  if (!qFte)
    qFin = NULL;
  delete pElim;
} //Dequeue

main () {
  tInfo   num;
  tCola ColaFte = NULL,
        ColaFin = NULL;

  for(int i = 1; i <= 3; i++) {
    cout << "Ing.valor: ";
    cin >> num;
    Enqueue(ColaFte,ColaFin,num);
  }
  cout << "-----------x----------" << endl;
  while(ColaFte) {
    Dequeue(ColaFte,ColaFin,num);
    cout << "valor: " << num << endl;
  }
  return 0;
}
