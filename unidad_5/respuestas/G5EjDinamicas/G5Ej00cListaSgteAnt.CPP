/*************
*	Id.Programa: G5Ej00cListaSgteAnt.Cpp
*	Autor......: Lic. Hugo Cuello
*	Fecha......: Jul-2005 / Jun-2014
*	Comentario.: Estructura dinamica de tipo Lista (=List) ordenada -Free-
*               Modulos:
*                 InsertaNodoSgte, InsertaNodoAnt
*                    "Modulo despachador"
*                 InsertaInicioSgte, InsertaInicioAnt
*                   "Si ListaFte es Vacia Inserta primero
*                      sino por el frente o inicio" o
*                   "Si ListaFin es Vacia Inserta ultimo
*                      sino por el fondo o final
*                 InsertaEnMedioSgte, InsertaEnMedioAnt
*                   "Inserta despues del primero, no antes,
*                      incluye por final" o
*                   "Inserta antes del ultimo, no despues,
*                      incluye por inicio"
*                 SuprimeNodoSgte, SuprimeNodoAnt
*                   "Elimina un nodo, en cualquier punto de la Lista,
*                      sino enc. no."
**************/

#include <conio.h>
#include <iostream>
using namespace std;

typedef int tInfo;
typedef struct sNodo *tLista;
struct sNodo {
  tLista Ant;
  tInfo  Info;
  tLista Sgte;
};

void InsertaInicioFte(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pNodo;

  pNodo = new sNodo;
  pNodo->Info = valor;
  pNodo->Sgte = ListFte;
  pNodo->Ant = NULL;
  if (!ListFte)
    ListFin = pNodo;
  else
    ListFte->Ant = pNodo;
  ListFte = pNodo;
} //InsertaInicioFte

void InsertaInicioFin(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pNodo;

  pNodo = new sNodo;
  pNodo->Info = valor;
  pNodo->Ant = ListFin;
  pNodo->Sgte = NULL;
  if (!ListFin)
    ListFte = pNodo;
  else
    ListFin->Sgte = pNodo;
  ListFin = pNodo;
} //InsertaInicioFin

void InsertaEnMedioSgte(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pNodo,
            pAct;

  pNodo = new sNodo;
  pNodo->Info = valor;
  pAct = ListFte;
  while (pAct->Sgte && valor > pAct->Sgte->Info)
	  pAct = pAct->Sgte;
  pNodo->Sgte = pAct->Sgte;
  pAct->Sgte = pNodo;
  pNodo->Ant = pAct;
  if (!pNodo->Sgte)
    ListFin = pNodo;
  else
    pNodo->Sgte->Ant = pNodo;
} //InsertaEnMedioSgte

void InsertaEnMedioAnt(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pNodo,
            pAct;

  pNodo = new sNodo;
  pNodo->Info = valor;
  pAct = ListFin;
  while (pAct->Ant && valor < pAct->Ant->Info)
	  pAct = pAct->Ant;
  pNodo->Ant = pAct->Ant;
  pAct->Ant = pNodo;
  pNodo->Sgte = pAct;
  if (!pNodo->Ant)
    ListFte = pNodo;
  else
    pNodo->Ant->Sgte = pNodo;
} //InsertaEnMedioAnt

void InsertaNodoFte(tLista &ListFte, tLista &ListFin, tInfo valor) {
  if (!ListFte || valor < ListFte->Info)
	  InsertaInicioFte(ListFte,ListFin, valor);
  else
	  InsertaEnMedioSgte(ListFte,ListFin,valor);
} //InsertaNodoFte

void InsertaNodoFin(tLista &ListFte, tLista &ListFin, tInfo valor) {
  if (!ListFin || valor > ListFin->Info)
	  InsertaInicioFin(ListFte,ListFin,valor);
  else
	  InsertaEnMedioAnt(ListFte,ListFin,valor);
} //InsertaNodoFin

void SuprimeNodoSgte(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pAct,
         pAnt;

  pAct = ListFte;
  pAnt = NULL;
  while (pAct && valor > pAct->Info) {
    pAnt = pAct;
	  pAct = pAct->Sgte;
  }
  if (pAct && valor == pAct->Info) {
	  if (!pAnt)
      ListFte = pAct->Sgte;
    else
      pAnt->Sgte = pAct->Sgte;
    if (!pAct->Sgte)
      ListFin = pAnt;
    else
      pAct->Sgte->Ant = pAnt;
    if (!ListFte)
      ListFin = NULL;
    delete pAct;
  }
} //SuprimeNodoSgte

void SuprimeNodoAnt(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pAct,
         pAnt;

  pAct = ListFin;
  pAnt = NULL;
  while (pAct && valor < pAct->Info) {
    pAnt = pAct;
	  pAct = pAct->Ant;
  }
  if (pAct && valor == pAct->Info) {
	  if (!pAnt)
      ListFin = pAct->Ant;
    else
      pAnt->Ant = pAct->Ant;
    if (!pAct->Ant)
      ListFte = pAnt;
    else
      pAct->Ant->Sgte = pAnt;
    if (!ListFin)
      ListFte = NULL;
    delete pAct;
  }
} //SuprimeNodoAnt

void EmiteListaSgte(tLista List) {
  tLista pAct = List;

  while (pAct) {
    cout << pAct->Info << " ";
    pAct = pAct->Sgte;
  }
  cout << endl;
} // EmiteListaSgte

void EmiteListaAnt(tLista List) {
  tLista pAct = List;

  while (pAct) {
    cout << pAct->Info << " ";
    pAct = pAct->Ant;
  }
  cout << endl;
} // EmiteListaAnt

int main () {
  int    num;
  tLista ListaFte = NULL,
         ListaFin = NULL;

  clrscr();
  cout << "Ing. valor: ";
  cin >> num;
  while ( num > 0) {
    InsertaNodoFte(ListaFte,ListaFin,num);
    cout << "Ing. valor: ";
    cin >> num;
    InsertaNodoFin(ListaFte,ListaFin,num);
    cout << "* Ing. valor: ";
    cin >> num;
  }
  cout << "-----------x----------" << endl;

  while (ListaFte) {
    EmiteListaSgte(ListaFte);
	  cout << "Ing. valor: ";
	  cin >> num;
	  SuprimeNodoSgte(ListaFte,ListaFin,num);
  }
  cout << "***********X***********" << endl;
  cout << "Ing. valor: ";
  cin >> num;
  while ( num > 0) {
    InsertaNodoFte(ListaFte,ListaFin,num);
    cout << "Ing. valor: ";
    cin >> num;
    InsertaNodoFin(ListaFte,ListaFin,num);
    cout << "+ Ing. valor: ";
    cin >> num;
  }
  cout << "-----------x----------" << endl;

  while (ListaFte) {
    EmiteListaAnt(ListaFin);
	  cout << "Ing. valor: ";
	  cin >> num;
	  SuprimeNodoAnt(ListaFte,ListaFin,num);
  }

  return 0;
}
