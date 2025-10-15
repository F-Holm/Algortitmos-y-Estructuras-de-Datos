/*
*	Id.Programa: Lista Doblemente Enlazada.cpp
*	Autor......: Lic. Hugo Cuello
*	Fecha......: Jul-2005 / Jun-2014
*	Comentario.: Estructura dinamica de tipo Lista (=List) ordenada -Freedom-
*               Modulos:
*                 InsertaNodoSgte, InsertaNodoant
*                    "Modulo despachador"
*                 InsertaInicioSgte, InsertaInicioant
*                   "Si ListaFte es Vacia Inserta primero
*                      sino por el frente o inicio" o
*                   "Si ListaFin es Vacia Inserta ultimo
*                      sino por el fondo o final
*                 InsertaEnMedioSgte, InsertaEnMedioant
*                   "Inserta despues del primero, no antes,
*                      incluye por final" o
*                   "Inserta antes del ultimo, no despues,
*                      incluye por inicio"
*                 SuprimeNodoSgte, SuprimeNodoant
*                   "Elimina un nodo, en cualquier punto de la Lista,
*                      sino enc. no."
*/

#include <conio.h>
#include <fstream>
using namespace std;

typedef int tInfo;
typedef struct sNodo * tLista;
struct sNodo {
  tLista ant;
  tInfo  info;
  tLista sgte;
};

void InsertaInicioFte(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pNodo;

  pNodo = new sNodo;
  pNodo->info = valor;
  pNodo->sgte = ListFte;
  pNodo->ant = NULL;
  if (!ListFte)
    ListFin = pNodo;
  else
    ListFte->ant = pNodo;
  ListFte = pNodo;
} //InsertaInicioFte

void InsertaInicioFin(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pNodo;

  pNodo = new sNodo;
  pNodo->info = valor;
  pNodo->ant = ListFin;
  pNodo->sgte = NULL;
  if (!ListFin)
    ListFte = pNodo;
  else
    ListFin->sgte = pNodo;
  ListFin = pNodo;
} //InsertaInicioFin

void InsertaEnMedioSgte(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pNodo,
         pAct;

  pNodo = new sNodo;
  pNodo->info = valor;
  pAct = ListFte;
  while (pAct->sgte && valor > pAct->sgte->info)
	  pAct = pAct->sgte;
  pNodo->sgte = pAct->sgte;
  pAct->sgte = pNodo;
  pNodo->ant = pAct;
  if (!pNodo->sgte)
    ListFin = pNodo;
  else
    pNodo->sgte->ant = pNodo;
} //InsertaEnMedioSgte

void InsertaEnMedioAnt(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pNodo,
         pAct;

  pNodo = new sNodo;
  pNodo->info = valor;
  pAct = ListFin;
  while (pAct->ant && valor < pAct->ant->info)
	  pAct = pAct->ant;
  pNodo->ant = pAct->ant;
  pAct->ant = pNodo;
  pNodo->sgte = pAct;
  if (!pNodo->ant)
    ListFte = pNodo;
  else
    pNodo->ant->sgte = pNodo;
} //InsertaEnMedioAnt

void InsertaNodoFte(tLista &ListFte, tLista &ListFin, tInfo valor) {
  if (!ListFte || valor < ListFte->info)
	  InsertaInicioFte(ListFte,ListFin, valor);
  else
	  InsertaEnMedioSgte(ListFte,ListFin,valor);
} //InsertaNodoFte

void InsertaNodoFin(tLista &ListFte, tLista &ListFin, tInfo valor) {
  if (!ListFin || valor > ListFin->info)
	  InsertaInicioFin(ListFte,ListFin,valor);
  else
	  InsertaEnMedioAnt(ListFte,ListFin,valor);
} //InsertaNodoFin

void SuprimeNodoSgte(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pAct,
         pant;

  pAct = ListFte;
  pant = NULL;
  while (pAct && valor > pAct->info) {
    pant = pAct;
    pAct = pAct->sgte;
  }
  if (pAct && valor == pAct->info) {
	  if (!pant)
      ListFte = pAct->sgte;
    else
      pant->sgte = pAct->sgte;
    if (!pAct->sgte)
      ListFin = pant;
    else
      pAct->sgte->ant = pant;
    if (!ListFte)
      ListFin = NULL;
    delete pAct;
  }
} //SuprimeNodoSgte

void SuprimeNodoAnt(tLista &ListFte, tLista &ListFin, tInfo valor) {
  tLista pAct,
         pant;

  pAct = ListFin;
  pant = NULL;
  while (pAct && valor < pAct->info) {
    pant = pAct;
    pAct = pAct->ant;
  }
  if (pAct && valor == pAct->info) {
	  if (!pant)
      ListFin = pAct->ant;
    else
      pant->ant = pAct->ant;
    if (!pAct->ant)
      ListFte = pant;
    else
      pAct->ant->sgte = pant;
    if (!ListFin)
      ListFte = NULL;
    delete pAct;
  }
} //SuprimeNodoAnt

void EmiteListaSgte(tLista &List) {
  tLista pAct = List;

  while (pAct) {
    cout << pAct->info << " ";
    pAct = pAct->sgte;
  }
  cout << endl;
} // EmiteListaSgte

void EmiteListaAnt(tLista &List) {
  tLista pAct = List;

  while (pAct) {
    cout << pAct->info << " ";
    pAct = pAct->ant;
  }
  cout << endl;
} // EmiteListaAnt

void IngDatos(tLista &ListaFte, tLista &ListaFin, char titulo[]) {
  int num;

  cout << "Tanda de " << titulo << endl;
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
} // IngDatos

tLista iif(bool expLog, tLista &Lst1, tLista &Lst2) {
  if (expLog)
    return Lst1;
  else
    return Lst2;
} // iif

void EmiteSuprime(tLista &ListaX, tLista &Lista1, tLista &Lista2,
                  void (*fEmite) (tLista &), void (*fSuprime) (tLista &,tLista &,tInfo)) {
  short num;

  while (ListaX) {
    fEmite(ListaX);
    cout << "Ing. valor: ";
    cin >> num;
    fSuprime(Lista1,Lista2,num);
  }
} // EmiteSuprime

main () {
  int    num;
  tLista ListaFte = NULL,
         ListaFin = NULL;

  IngDatos(ListaFte,ListaFin,"Izq. a Der.");
  EmiteSuprime(ListaFte,ListaFte,ListaFin,EmiteListaSgte,SuprimeNodoSgte);
  IngDatos(ListaFte,ListaFin,"Der. a Izq.");
  EmiteSuprime(ListaFin,ListaFte,ListaFin,EmiteListaAnt,SuprimeNodoAnt);
  return 0;
} // main
