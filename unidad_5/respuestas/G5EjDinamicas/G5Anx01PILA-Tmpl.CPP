/*************
*	Id.Programa: G5Anx01PILA-Tmpl.cpp
*	Autor      : Lic. Hugo Cuello
*	Fecha......: oct-2013
*	Comentario.: Plantillas Template.
*              Se definen 4 Template:
*					       1. de tipo int.
*					       2. de tipo float.
*                3. de tipo string.
*                4. de tipo sArt.
*              Ventaja del uso de Templates:
*					     Permite declarar tipos genericos de datos
*              Aplicacion: Se crean 4 Pilas;
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
#define PsNodoSArt   sNodo<sArt>*

template <class T>
  struct sNodo {
    T       Info;
    PsNodoT Sgte;
  };

template <class T>
  void Push(PsNodoT &Pila, T valor) {
    PsNodoT pNodo;

    pNodo = new sNodoT;
    pNodo->Info = valor;
    pNodo->Sgte = Pila;
    Pila = pNodo;
} //Push - Meter

template <class T>
  void Pop(PsNodoT &Pila, T &valor) {
    PsNodoT pElim;

    pElim = Pila;
    valor = Pila->Info;
    Pila = Pila->Sgte;
    delete pElim;
} //Pop - Sacar

typedef char str20[21];
  struct sArt {
    unsigned codArt,
             cant;
    str20    descrip;
    float    preUni;
};

void PilaINT() {
  PsNodoINT Pila  = NULL;
  int       a;

  for (register i = 1; i <= 3; i++) {
    cout << "Ing. int: ";
    cin >> a;
    Push<int>(Pila,a);
  }
  cout << "-----------x-----------" << endl;
  while (Pila) {
    Pop<int>(Pila,a);
    cout << a << endl;
  }
  cout << "-----------x-----------" << endl;
} // PilaINT

void PilaFLOAT() {
  PsNodoFLOAT  Pila = NULL;
  float  r;

  for (register i = 1; i <= 3; i++) {
    cout << "Ing. float: ";
    cin >> r;
    Push<float>(Pila,r);
  }
  cout << "----------x-----------" << endl;
  while (Pila) {
    Pop<float>(Pila,r);
    cout << r << endl;
  }
  cout << endl << "-------+-------" << endl << endl;
} //PilaFLOAT

void PilaSTRING() {
  PsNodoSTRING Pila = NULL;
  string s;
  char   cad[81];

  for (register i = 1; i <= 3; i++) {
    cout << "Ing. cadena: ";
    gets(cad);
    s = cad;
    Push<string>(Pila,s);
  }
  cout << "----------x-----------" << endl;
  while (Pila) {
    Pop<string>(Pila,s);
    cout << s << endl;
  }
  cout << "----------x-----------" << endl;
} //PilaSTRING

void PilaSTRUCT() {
  PsNodoSArt Pila = NULL;
  sArt       rArt;

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
    Push<sArt>(Pila,rArt);
  }
  cout << "-----------x-----------" << endl;
  while (Pila) {
    Pop<sArt>(Pila,rArt);
    cout << rArt.codArt << " "
         << rArt.cant << " "
         << rArt.descrip << " "
         << rArt.preUni << endl;
  }
} //PilaSTRUCT

int main() {
  PilaINT();
  PilaFLOAT();
  PilaSTRING();
  PilaSTRUCT();

  return 0;
}
