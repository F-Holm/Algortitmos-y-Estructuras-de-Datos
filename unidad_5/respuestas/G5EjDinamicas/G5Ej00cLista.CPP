/*************
*	Id.Programa: G5Ej00cLista.Cpp
*	Autor......: Lic. Hugo Cuello
*	Fecha......: Jul-2005 / Jun-2014
*	Comentario.: Estructura dinamica de tipo Lista (=List) ordenada -Freedom-.
*               Modulos:
*                 InsertaNodo    "Modulo despachador"
*                 InsertaInicio  "Si Lista es Vacia Inserta primero sino por el frente o inicio"
*                 InsertaEnMedio "Inserta despues del primero, no antes, incluye por final"
*                 SuprimeNodo    "Elimina un nodo, en cualquier punto de la Lista, sino enc. no."
**************/

#include <conio.h>
#include <iostream>
using namespace std;

typedef int tInfo;
typedef struct sNodo *tLista;
struct sNodo {
  tInfo Info;
  tLista Sgte;
};

void InsertaInicio(tLista &List, tInfo valor) {
  tLista pNodo;

  pNodo = new sNodo;
  pNodo->Info = valor;
  pNodo->Sgte = List;
  List = pNodo;
} //InsertaInicio

void InsertaEnMedio(tLista &List, tInfo valor) {
  tLista pNodo,
        pAct;

  pNodo = new sNodo;
  pNodo->Info = valor;
  pAct = List;
  while (pAct->Sgte && valor > pAct->Sgte->Info)
	  pAct = pAct->Sgte;
  pNodo->Sgte = pAct->Sgte;
  pAct->Sgte = pNodo;
} //InsertaEnMedio

void InsertaNodo(tLista &List, tInfo valor) {
  if (!List || valor < List->Info)
	  InsertaInicio(List,valor);
  else
	  InsertaEnMedio(List,valor);
} //InsertaNodo

void SuprimeNodo(tLista &List, tInfo valor) {
  tLista pAct,
         pAnt;

  pAct = List;
  pAnt = NULL;
  while (pAct && valor > pAct->Info) {
    pAnt = pAct;
	  pAct = pAct->Sgte;
  }
  if (pAct && valor == pAct->Info) {
	  if (pAnt)
	    pAnt->Sgte = pAct->Sgte;
    else
	    List = pAct->Sgte;
    delete pAct;
  }
} //SuprimeNodo

void EmiteLista(tLista &List) {
  tLista pAct = List;

  while (pAct) {
    cout << pAct->Info << " ";
    pAct = pAct->Sgte;
  }
  cout << endl;
} // EmiteLista

int main () {
  int    num;
  tLista Lista = NULL;

  clrscr();
  for(int i = 1; i <= 7; i++) {
  	cout << "Ing. valor: ";
	  cin >> num;
  	InsertaNodo(Lista,num);
  }
  cout << "-----------x----------" << endl;
  while (Lista) {
    EmiteLista(Lista);
	  cout << "Ing. valor: ";
	  cin >> num;
	  SuprimeNodo(Lista,num);
  }

  return 0;
}
