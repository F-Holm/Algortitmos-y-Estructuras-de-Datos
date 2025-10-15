/*
   Id.Programa: DolorCabeza.cpp
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

int main() {
  tLista Lista = NULL;

  for (register i = 1; i <=30; i++)
    InsertaInicio(Lista,random(100));
  cout << DolorCabeza(Lista); // jamás regresa de la recursividad, no hay casos base
  return 0;
}
