/*************
*	Id.Programa: G5Anx03LISTA-Tmpl.cpp
*	Autor      : Lic. Hugo Cuello
*	Fecha......: octubre-2013
*	Comentario.: Plantillas Template.
*              Se definen 4 Template:
*					       1. de tipo int.
*					       2. de tipo float.
*                3. de tipo string.
*                4. de tipo sArt.
*              Ventaja del uso de Templates:
*					     Permite declarar tipos genericos de datos
*              Aplicacion: Se crean 4 Listas;
*                1. de sNodo<int>*    Lista = NULL;
*					       2. de sNodo<float>*  Lista2 = NULL;
*                3. de sNodo<string>* Lista3 = NULL;
*                4. de sNodo<sArt>*   Lista4 = NULL;
**************/

#include <iostream>
using namespace std;
#define sNodoT       sNodo<T>
#define PsNodoT      sNodoT*
#define PsNodoINT    sNodo<int>*
#define PsNodoFLOAT  sNodo<float>*
#define PsNodoSTRING sNodo<string>*
#define PsNodoSTRUCT sNodo<sArt>*

template <class T>
  struct sNodo {
    T       Info;
    PsNodoT Sgte;
  };

template <class T>
  void InsertaInicio(PsNodoT &Lista, T valor) {
    PsNodoT pNodo;

    pNodo = new sNodoT;
    pNodo->Info = valor;
    pNodo->Sgte = Lista;
    Lista = pNodo;
} //InsertaInicio

template <class T>
  void InsertaEnMedio(PsNodoT &Lista, T valor) {
	  PsNodoT pAct;
	  PsNodoT pNodo;

	  pNodo = new sNodoT;
	  pNodo->Info = valor;
	  pAct = Lista;
	  while (pAct->Sgte != NULL && valor > pAct->Sgte->Info)
		  pAct = pAct->Sgte;
	  pNodo->Sgte = pAct->Sgte;
	  pAct->Sgte = pNodo;
} // InsertaEnMedio

template <class T>
  void InsertaNodo(PsNodoT &Lista, T valor) {
	  if (!Lista || valor < Lista->Info)
		  InsertaInicio(Lista,valor);
  	else
	  	InsertaEnMedio(Lista,valor);
} // InsertaNodo

//-------------------------------------

template <class T>
  void InsertaEnMedioClv(PsNodoT &Lista, T valor) {
	  PsNodoT pAct;
	  PsNodoT pNodo;

	  pNodo = new sNodoT;
	  pNodo->Info = valor;
	  pAct = Lista;
	  while (pAct->Sgte != NULL && valor.codArt > pAct->Sgte->Info.codArt)
		  pAct = pAct->Sgte;
	  pNodo->Sgte = pAct->Sgte;
	  pAct->Sgte = pNodo;
} // InsertaEnMedio

template <class T>
  void InsertaNodoClv(PsNodoT &Lista, T valor) {
	  if (!Lista || valor.codArt < Lista->Info.codArt)
		  InsertaInicio(Lista,valor);
  	else
	  	InsertaEnMedioClv(Lista,valor);
} // InsertaNodo


//------------------------------------




template <class T>
  void SacarPrimerNodo(PsNodoT &Lista, T &valor) {
    PsNodoT pElim;

    pElim = Lista;
    valor = Lista->Info;
    Lista = Lista->Sgte;
    delete pElim;
} // SacarPrimerNodo

typedef char str20[21];
  struct sArt {
    unsigned codArt,
             cant;
    str20    descrip;
    float    preUni;
};

void ListaINT() {
  PsNodoINT    Lista  = NULL;
  int    a;

  for (register i = 1; i <= 3; i++) {
    cout << "Ing. int: ";
    cin >> a;
    InsertaNodo<int>(Lista,a);
  }
  cout << "-----------x-----------" << endl;
  while (Lista) {
    SacarPrimerNodo<int>(Lista,a);
    cout << a << endl;
  }
  cout << "-----------x-----------" << endl;
}// ListaINT

void ListaFLOAT() {
  PsNodoFLOAT Lista = NULL;
  float  r;

  for (register i = 1; i <= 3; i++) {
    cout << "Ing. float: ";
    cin >> r;
    InsertaNodo<float>(Lista,r);
  }
  cout << "----------x-----------" << endl;
  while (Lista) {
    SacarPrimerNodo<float>(Lista,r);
    cout << r << endl;
  }
  cout << endl << "-------+-------" << endl << endl;
}// ListaFLOAT

void ListaSTRING() {
  PsNodoSTRING Lista3 = NULL;
  string s;
  char   cad[81];

  for (register i = 1; i <= 3; i++) {
    cout << "Ing. cadena: ";
    gets(cad);
    s = cad;
    InsertaNodo<string>(Lista3,s);
  }
  cout << "----------x-----------" << endl;
  while (Lista3) {
    SacarPrimerNodo<string>(Lista3,s);
    cout << s << endl;
  }
  cout << "----------x-----------" << endl;
}// ListaSTRING

void ListaSTRUCT() {
  PsNodoSTRUCT Lista4 = NULL;
  sArt   rArt;

  for (register i = 1; i <= 3; i++) {
    cout << "Ing. Cod.Art: ";
    cin >> rArt.codArt;
    cout << endl << "     Cant....: ";
    cin >> rArt.cant;
    cout << endl << "     Descrip.: ";
    gets(rArt.descrip);
    cin.clear();
    cout << endl << "     Pre.Uni.: ";
    cin >> rArt.preUni;
    InsertaNodoClv<sArt>(Lista4,rArt);
  }
  cout << "-----------x-----------" << endl;
  while (Lista4) {
    SacarPrimerNodo<sArt>(Lista4,rArt);
    cout << rArt.codArt << " "
         << rArt.cant << " "
         << rArt.descrip << " "
         << rArt.preUni << endl;
  }
}// ListaSTRUCT

int main() {
  ListaINT();
  ListaFLOAT();
  ListaSTRING();
  ListaSTRUCT();

  return 0;
}
