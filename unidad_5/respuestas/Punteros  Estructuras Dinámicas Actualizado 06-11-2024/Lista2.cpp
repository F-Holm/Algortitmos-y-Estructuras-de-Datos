/*
	Id.Programa: Lista2.Cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: Jul-2005 / Jun-2014
	Comentario.: Estructura dinamica de tipo Lista (=List) ordenada -Freedom-.
                 Modulos:
                   InsertaNodo    "Modulo despachador"
                   InsertaInicio  "Si Lista es Vacia Inserta primero sino por el
                                   frente o inicio"
                   InsertaEnMedio "Inserta despues del primero, no antes,
                                   incluye por final"
                   SacarPrimerNodo "Elimina cada vez que se lo invoque el primer
                                    nodo de la Lista."
*/

#include <iostream>
using namespace std;

typedef int tInfo;
typedef struct sNodo *tLista;

struct sNodo {
  tInfo Info;
  tLista Sgte;
};

void InsertaInicio(tLista &List, tInfo valor) {
  tLista pNodo = new sNodo;

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

void SacarPrimerNodo(tLista &Lista, tInfo &valor) {
  tLista pElim = Lista;

  valor = Lista->Info;
  Lista = Lista->Sgte;
  delete pElim;
} // SacarPrimerNodo

main () {
  int   num;
  tLista Lista = NULL,
         lAct;

  for(int i = 1; i <= 7; i++) {
  	cout << "Ing. valor: ";
	  cin >> num;
  	InsertaNodo(Lista,num);
  }
  cout << "-----------x----------" << endl;
  while (Lista) {
    SacarPrimerNodo(Lista,num);
    cout << "Valor eliminado: " << num << endl;
    lAct = Lista;
    while (lAct) {
      cout << lAct->Info << endl;
      lAct = lAct->Sgte;
    }
  }
  return 0;
}
