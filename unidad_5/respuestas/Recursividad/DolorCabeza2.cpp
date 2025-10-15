/*
   Id.Programa: DolorCabeza2.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <iostream>
using namespace std;

typedef int tInfo;
typedef struct tNodo *tLista;
struct tNodo {
  tInfo  Info;
  tLista Sgte;
};

void InsertaInicio(tLista &Lista, tInfo valor) {
  tLista pNvo;

  pNvo = new tNodo;
  pNvo->Info = valor;
  pNvo->Sgte = Lista;
  Lista = pNvo;
} //InsertaInicio

long DolorCabeza(tLista &Lista) {
  if (Lista)
    return 1 + DolorCabeza(Lista->Sgte);
  else
    return DolorCabeza(Lista);
} //DolorCabeza

void DolorCabeza2(tLista &Lista) {
  tLista pElim;

  if (Lista) {
    pElim = Lista;
    DolorCabeza2(Lista->Sgte);
    delete pElim;
  }
} //DolorCabeza2

int main() {
  tLista Lista;

  for (register i = 1; i <=30; i++)
    InsertaInicio(Lista,random(100));
  cout << DolorCabeza(Lista); // jamás regresa de la recursividad, no hay casos base
  DolorCabeza2(Lista);
  return 0;
}
