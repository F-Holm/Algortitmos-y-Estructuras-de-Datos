/*
	Id.Programa: Pila.Cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: Jul-2005 / Jun-2014
	Comentario.: Estructura dinamica de tipo Pila (=Stack) -L.I.F.O.-
                 Modulos:
                          Push - Meter
                          Pop  - Sacar
*/

#include <fstream>
using namespace std;

typedef int tInfo;
typedef struct sNodo *tPila;

struct sNodo {
  tInfo Info;
  tPila Ant;
};

void Push(tPila &Stack, tInfo valor) {
  tPila pNodo = new sNodo;

  pNodo->Info = valor;
  pNodo->Ant = Stack;
  Stack = pNodo;
} //Push

void Pop(tPila &Stack, tInfo &valor) {
  tPila pElim = Stack;

  valor = Stack->Info;
  Stack = Stack->Ant;
  delete pElim;
} //Pop

main () {
  tInfo num;
  tPila Pila = NULL;

  for(int i = 1; i <= 3; i++) {
    cout << "Ing.valor: ";
    cin >> num;
    Push(Pila,num);
  }
  cout << "-----------x----------" << endl;
  while(Pila) {
    Pop(Pila,num);
    cout << "valor: " << num << endl;
  }
  return 0;
}
