/*************
*	Id.Programa: G5Anx02COLA-Tmpl.cpp
*	Autor      : Lic. Hugo Cuello
*	Fecha......: octubre-201
*	Comentario.: Plantillas Template.
*              Se definen 4 Template:
*					       1. de tipo int.
*					       2. de tipo float.
*                3. de tipo string.
*                4. de tipo sArt.
*              Ventaja del uso de Templates:
*					     Permite declarar tipos genericos de datos
*              Aplicacion: Se crean 4 Colas;
*                1. de sNodo<int>*    Pila = NULL;
*					       2. de sNodo<float>*  Pila2 = NULL;
*                3. de sNodo<string>* Pila3 = NULL;
*                4. de sNodo<sArt>*   Pila4 = NULL;
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
void Enqueue(PsNodoT &cFte, PsNodoT &cFin, T valor) {
	PsNodoT pNodo;

	pNodo = new sNodoT;
	pNodo->Info = valor;
	pNodo->Sgte = NULL;
	if (cFte == NULL)
		cFte = pNodo;
	else
		cFin->Sgte = pNodo;
	cFin = pNodo;
} // Enqueue - Agregar

template <class T>
void Dequeue(PsNodoT &cFte, PsNodoT &cFin, T &valor) {
	PsNodoT pElim;

	pElim = cFte;
	valor = cFte->Info;
	cFte = cFte->Sgte;
	if (cFte == NULL)
		cFin = NULL;
	delete pElim;
} // Dequeue - Suprimir

typedef char str20[21];
  struct sArt {
    unsigned codArt,
             cant;
    str20    descrip;
    float    preUni;
};

void ColaINT() {
  PsNodoINT ColaFte  = NULL;
  PsNodoINT ColaFin  = NULL;
  int       a;

  for (register i = 1; i <= 3; i++) {
    cout << "Ing. int: ";
    cin >> a;
    Enqueue<int>(ColaFte,ColaFin,a);
  }
  cout << "-----------x-----------" << endl;
  while (ColaFte) {
    Dequeue<int>(ColaFte,ColaFin,a);
    cout << a << endl;
  }
  cout << "-----------x-----------" << endl;
}//ColaINT

void ColaFLOAT() {
  PsNodoFLOAT ColaFte = NULL;
  PsNodoFLOAT ColaFin = NULL;
  float       r;

  for (register i = 1; i <= 3; i++) {
    cout << "Ing. float: ";
    cin >> r;
    Enqueue<float>(ColaFte,ColaFin,r);
  }
  cout << "----------x-----------" << endl;
  while (ColaFte) {
    Dequeue<float>(ColaFte,ColaFin,r);
    cout << r << endl;
  }
  cout << endl << "-------+-------" << endl << endl;
}//ColaFLOAT

void ColaSTRING() {
  PsNodoSTRING ColaFte = NULL;
  PsNodoSTRING ColaFin = NULL;
  string s;
  char   cad[81];

  for (register i = 1; i <= 3; i++) {
    cout << "Ing. cadena: ";
    gets(cad);
    s = cad;
    Enqueue<string>(ColaFte,ColaFin,s);
  }
  cout << "----------x-----------" << endl;
  while (ColaFte) {
    Dequeue<string>(ColaFte,ColaFin,s);
    cout << s << endl;
  }
  cout << "----------x-----------" << endl;
}//ColaSTRING

void ColaSTRUCT() {
  PsNodoSTRUCT ColaFte = NULL;
  PsNodoSTRUCT ColaFin = NULL;
  sArt         rArt;

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
    Enqueue<sArt>(ColaFte,ColaFin,rArt);
  }
  cout << "-----------x-----------" << endl;
  while (ColaFte) {
    Dequeue<sArt>(ColaFte,ColaFin,rArt);
    cout << rArt.codArt << " "
         << rArt.cant << " "
         << rArt.descrip << " "
         << rArt.preUni << endl;
  }
}//ColaSTRUCT

int main() {
  ColaINT();
  ColaFLOAT();
  ColaSTRING();
  ColaSTRUCT();

  return 0;
}
