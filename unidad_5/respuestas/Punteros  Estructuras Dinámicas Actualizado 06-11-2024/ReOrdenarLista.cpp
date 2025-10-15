/*************
*	Id.Programa: G5Ej00ReOrdenarLista.Cpp
*	Autor......: Lic. Hugo Cuello
*	Fecha......: noviembre/2014
*	Comentario.: Re ordena una Lista no ordenada u ordenada
*                por otro criterio.
**************/

#include <conio.h>
#include <iostream>
using namespace std;

typedef int tInfo;
typedef struct sNodo *tLista;
struct sNodo {
  tInfo  Info;
  tLista Sgte;
};

void InsertaInicio(tLista &List, tInfo valor) {
  tLista pNodo;

  pNodo = new sNodo;
  pNodo->Info = valor;
  pNodo->Sgte = List;
  List = pNodo;
} //InsertaInicio

void EnlazaInicio(tLista &Lista, tLista &pNodo) {
    pNodo->Sgte = Lista;
    Lista = pNodo;
} // EnlazaInicio

void EnlazaEnMedio(tLista &Lista, tLista &pNodo) {
  tLista pAct = Lista;

  while (pAct->Sgte && pNodo->Info > pAct->Sgte->Info)
    pAct = pAct->Sgte;
  pNodo->Sgte = pAct->Sgte;
  pAct->Sgte = pNodo;
}  // EnlazaEnMedio

void ReInsertaNodo(tLista &ListaAux, tLista &pNodo) {

	if (!ListaAux || pNodo->Info < ListaAux->Info)
		EnlazaInicio(ListaAux,pNodo);
	else
        EnlazaEnMedio(ListaAux,pNodo);
} // ReInsertaNodo

void ReOrdenarLst(tLista &Lista) {
	tLista ListaAux = NULL,
			   pNodo;

	 while (Lista) {
		 pNodo = Lista;
		 Lista = Lista->Sgte;
		 ReInsertaNodo(ListaAux,pNodo);
	 }
	 Lista = ListaAux;
} // ReOrdenarLst

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
		if (!pAnt)
			List = pAct->Sgte;
		else
			pAnt->Sgte = pAct->Sgte;
		delete pAct;
	}
} // SuprimeNodo

void EmiteLista(tLista List) {
  tLista pAct = List;

  while (pAct) {
    cout << pAct->Info << " ";
    pAct = pAct->Sgte;
  }
  cout << endl;
} // EmiteLista

int main() {
  int    num;
  tLista Lista = NULL;

  clrscr();
  cout << "Ing. valor: ";
  cin >> num;
  while ( num > 0) {   //   34 21 76 41 16 53 9 0
    InsertaInicio(Lista,num);
    cout << "Ing. valor: ";
    cin >> num;
  }
  cout << "-----------x----------" << endl;
  cout <<  "Lista antes de Re Ordenar..." << endl;
  EmiteLista(Lista); // 9 53 16 41 76 21 34
  getche();
  ReOrdenarLst(Lista);
  cout << endl << "Lista luego de Re Ordenar..." << endl;
  while (Lista) {
      EmiteLista(Lista);   // 9 16 21 34 41 53 76
	  cout << "Ing. valor: ";
	  cin >> num;
	  SuprimeNodo(Lista,num);
  }
  return 0;
}
