/*
  Id.Programa: Template a EDD.cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: octubre-2023
  Comentario.: Template y funciones Criterios aplicadas
                 a Estructuras Dinamicas de Datos Lineales.
*/

#include <iomanip>
#include <fstream>
using namespace std;

const MAX_REGS = 12;

typedef char str20[21];

struct sArt {
  short codArt;
  str20 descrip;
  float preUni;
};

typedef sArt  tInfo;
typedef short tInfo2;

#define sNodoT      sNodo<T>
#define psNodoT     sNodo<T>*
#define psNodoInfo  sNodo<tInfo>*
#define psNodoInfo2 sNodo<tInfo2>*

template <typename T>
struct sNodo {
  T      info;
  psNodoT proxNodo;  // pNodo
};

// ----< Funciones para Criterios >----

bool fCodArtHigh(tInfo &elem1, tInfo &elem2) {
  return elem1.codArt > elem2.codArt;
}

bool fCodArtEqual(tInfo &elem1, tInfo &elem2) {
  return elem1.codArt == elem2.codArt;
}

bool fCodArtLess(tInfo &elem1, tInfo &elem2) {
  return elem1.codArt < elem2.codArt;
}

bool fDescripHigh(tInfo &elem1, tInfo &elem2) {
  return strcmp(elem1.descrip,elem2.descrip) > 0;
}

bool fDescripLess(tInfo &elem1, tInfo &elem2) {
  return strcmp(elem1.descrip,elem2.descrip) < 0;
}

bool fDescripNotEq(tInfo &elem1, tInfo &elem2) {
  return strcmp(elem1.descrip,elem2.descrip) != 0;
}

bool fDescripEqual(tInfo &elem1, tInfo &elem2) {
  return strcmp(elem1.descrip,elem2.descrip) == 0;
}

bool fPreUniHigh(tInfo &elem1, tInfo &elem2) {
  return elem1.preUni > elem2.preUni;
}

bool fPreUniEqual(tInfo &elem1, tInfo &elem2) {
  return elem1.preUni == elem2.preUni;
}

bool fPreUniLess(tInfo &elem1, tInfo &elem2) {
  return elem1.preUni < elem2.preUni;
}

//----< Modulos para Pila >----

template <typename T>
void Push(psNodoT &Stk, T valor) {
  psNodoT pNvo = new sNodoT;

  pNvo->info = valor;
  pNvo->proxNodo = Stk;
  Stk = pNvo;
} // Push

template <typename T>
void Pop(psNodoT &Stk, T &valor) {
  psNodoT pElim = Stk;

  valor = Stk->info;
  Stk = Stk->proxNodo;
  delete pElim;
} // Pop

//----< Modulos para Cola >----

template <typename T>
void Enqueue(psNodoT &cFte, psNodoT &cFin, T valor) {
  psNodoT pNvo = new sNodoT;

  pNvo->info = valor;
  pNvo->proxNodo = NULL;
  if (!cFte)
    cFte = pNvo;
  else
    cFin->proxNodo = pNvo;
  cFin = pNvo;
} // Enqueue

template <typename T>
void Dequeue(psNodoT &cFte, psNodoT &cFin, T &valor) {
  psNodoT pElim = cFte;

  valor = cFte->info;
  cFte = cFte->proxNodo;
  if (!cFte)
    cFin = NULL;
  delete pElim;
} // Dequeue

//----< Modulos para Lista >----

template <typename T>
void InsertaInicio(psNodoT &List, T valor) {
  psNodoT pNvo = new sNodoT;

  pNvo->info = valor;
  pNvo->proxNodo = List;
  List = pNvo;
} // InsertaInicio

template <typename T>
void InsertaEnMedio(psNodoT &List, T &valor,
                    bool (* criterio)  (void *, void *)) {
  psNodoT pNvo,
         *pAct = List;

  while(pAct->proxNodo && criterio(&valor,&pAct->proxNodo->info))
    pAct = pAct->proxNodo;
  pNvo = new sNodoT;
  pNvo->info = valor;
  pNvo->proxNodo = pAct->proxNodo;
  pAct->proxNodo = pNvo;
} // InsertaEnMedio

template <typename T>
void InsertaNodo(psNodoT &List, T valor,
                 bool (* criterio)  (void *, void *), void * fCrit) {
  if (!List || criterio(&valor,&List->info))
    InsertaInicio(List, valor);
  else
    InsertaEnMedio(List, valor,(bool (*) (void *, void * )) (fCrit));
} // InsertaNodo

template <typename T>
void SacarPrimerNodo(psNodoT &List, T &valor) {
  psNodoT pElim = List;

  valor = List->info;
  List = List->proxNodo;
  delete pElim;
} // SacarPrimerNodo

template <typename T>
void SuprimeNodo(psNodoT &List, T &valor,
                 bool (* criterio)  (void *, void *),
                 bool (* criterio2) (void *, void *)) {
  psNodoT pAct = List;
  psNodoT pAnt = NULL;

  while (pAct && criterio(&valor, &pAct->info) ) {
    pAnt = pAct;
    pAct = pAct->proxNodo;
  }
  if (pAct && criterio2(&valor, &pAct->info)) {
    if (!pAnt)
      List = List->proxNodo;
    else
      pAnt->proxNodo = pAct->proxNodo;
    delete pAct;
  }
} // SuprimeNodo

template <typename T>
void EmiteLst(psNodoT &List) {
  psNodoT pAct = List;

  cout << "  Cod.Art Descripcion             Pre.Uni." << endl;
  while (pAct) {
    cout << "--> " << setw(5) << pAct->info.codArt << ' '
         << left << setw(20) << pAct->info.descrip << ' '
         << right << setw(10) << pAct->info.preUni << endl;
    pAct = pAct->proxNodo;
  }
  cout << endl;
} // EmiteLst

template <typename T>
void EnlazaInicio(psNodoT &Lista, psNodoT &pNodo) {
    pNodo->proxNodo = Lista;
    Lista = pNodo;
} // EnlazaInicio

template <typename T>
void EnlazaEnMedio(psNodoT &Lista, psNodoT &pNodo,
                   bool (* criterio) (void *, void *)) {
  psNodoT pAct = Lista;
  while (pAct->proxNodo && criterio(&pNodo->info,&pAct->proxNodo->info))
    pAct = pAct->proxNodo;
  pNodo->proxNodo = pAct->proxNodo;
  pAct->proxNodo = pNodo;
}  // EnlazaEnMedio

template <typename T>
void ReInsertaNodo(psNodoT &ListaAux, psNodoT &pNodo,
                   bool (* criterio) (void *, void *) , void * fCritHigh) {

  if (!ListaAux || criterio(&pNodo->info,&ListaAux->info))
    EnlazaInicio(ListaAux,pNodo);
  else
    EnlazaEnMedio(ListaAux,pNodo,
                      (bool (*) (void *, void * )) (fCritHigh) );
} // ReInsertaNodo

template <typename T>
void ReOrdenarLst(psNodoT &Lista,void * fCritLess,void * fCritHigh) {
  psNodoT ListaAux = NULL;
  psNodoT pNodo;

  while (Lista) {
    pNodo = Lista;
    Lista = Lista->proxNodo;
    ReInsertaNodo(ListaAux,pNodo,
                       (bool (*) (void *, void * )) (fCritLess), fCritHigh);
  }
  Lista = ListaAux;
} // ReOrdenarLst

//----< Operaciones con Pila >----

template <typename T>
void OperarPila(psNodoT &Pila)  {
  tInfo2 x2;

  for (short i = 1; i <=3; i++) {
    cout << "Ing. valor: ";
    cin >> x2;
    Push(Pila,x2);
  }
  while (Pila) {
    Pop(Pila,x2);
    cout << x2 << ' ';
  }
  cout << endl;

} // OperarPila

//----< Operaciones con Cola >----

template <typename T>
void OperarCola(psNodoT &ColaFte, psNodoT &ColaFin) {
  tInfo2 x2;

  for (short i = 1; i <=3; i++) {
    cout << "Ing. valor: ";
    cin >> x2;
    Enqueue(ColaFte,ColaFin,x2);
  }
  while (ColaFte) {
    Dequeue(ColaFte,ColaFin,x2);
    cout << x2 << ' ';
  }
  cout << endl;
} // OperarCola

//----< Operaciones con Lista >----

template <typename T>
void OperarLista(psNodoT &Lista) {
  tInfo x;

  for (short i = 1; i <= MAX_REGS; i++) {
    cout << "Ing. CodArt.: ";
    cin >> x.codArt;
    cout << "Ing. Descrip: ";
    cin >> x.descrip;
    cout << "Ing. PreUni.: ";
    cin >> x.preUni;
    InsertaNodo(Lista,x,(bool (*) (void *, void * )) (fPreUniLess),&fPreUniHigh);
  }
  while (Lista) {
    SacarPrimerNodo(Lista,x);
    cout << setw( 5) << x.codArt << ' '
         << setw(20) << x.descrip << ' '
         << setw(10) << x.preUni << endl;
  }
  cout << endl;

  // Genera nuevamente Lista para reOrdenar segun criterio
  for (short i = 1; i <= MAX_REGS; i++) {
    cout << "*Ing. CodArt: ";
    cin >> x.codArt;
    cout << "Ing. Descrip: ";
    cin >> x.descrip;
    cout << "Ing. PreUni.: ";
    cin >> x.preUni;
    InsertaNodo(Lista,x,(bool (*) (void *, void * )) (fCodArtLess),&fCodArtHigh);
  }
  EmiteLst(Lista);
  ReOrdenarLst(Lista,&fDescripLess,&fDescripHigh);
  while (Lista) {
    EmiteLst(Lista);
    cout << "+Ing. Descrip: ";
    cin >> x.descrip;
    SuprimeNodo(Lista,x,(bool (*) (void *, void * )) (fDescripHigh),
                        (bool (*) (void *, void * )) (fDescripEqual));
  }

  for (short i = 1; i <= MAX_REGS; i++) {
    cout << "*Ing. CodArt: ";
    cin >> x.codArt;
    cout << "Ing. Descrip: ";
    cin >> x.descrip;
    cout << "Ing. PreUni.: ";
    cin >> x.preUni;
    InsertaNodo(Lista,x,(bool (*) (void *, void * )) (fPreUniLess),&fPreUniHigh);
  }
  EmiteLst(Lista);
  ReOrdenarLst(Lista,&fCodArtLess,&fCodArtHigh);
  while (Lista) {
    EmiteLst(Lista);
    cout << "+Ing. CodArt: ";
    cin >> x.codArt;
    SuprimeNodo(Lista,x,(bool (*) (void *, void * )) (fCodArtHigh),
                        (bool (*) (void *, void * )) (fCodArtEqual));
  }

  for (short i = 1; i <= MAX_REGS; i++) {
    cout << "*Ing. CodArt: ";
    cin >> x.codArt;
    cout << "Ing. Descrip: ";
    cin >> x.descrip;
    cout << "Ing. PreUni.: ";
    cin >> x.preUni;
    InsertaNodo(Lista,x,(bool (*) (void *, void * )) (fCodArtLess),&fCodArtHigh);
  }
  EmiteLst(Lista);
  ReOrdenarLst(Lista,&fPreUniLess,&fPreUniHigh);
  while (Lista) {
    EmiteLst(Lista);
    cout << "+Ing. PreUni: ";
    cin >> x.preUni;
    SuprimeNodo(Lista,x,(bool (*) (void *, void * )) (fPreUniHigh),
                        (bool (*) (void *, void * )) (fPreUniEqual));
  }

  for (short i = 1; i <= MAX_REGS; i++) {
    cout << "*Ing. CodArt: ";
    cin >> x.codArt;
    cout << "Ing. Descrip: ";
    cin >> x.descrip;
    cout << "Ing. PreUni.: ";
    cin >> x.preUni;
    InsertaNodo(Lista,x,(bool (*) (void *, void * )) (fCodArtLess),&fCodArtHigh);
  }
  while (Lista) {
    EmiteLst(Lista);
    cout << "+Ing. Descripcion: ";
    cin >> x.descrip;
    SuprimeNodo(Lista,x,(bool (*) (void *, void * )) (fDescripNotEq),
                        (bool (*) (void *, void * )) (fDescripEqual));
  }
} // OperarLista

main() {
  psNodoInfo2 Pila    = NULL;
  psNodoInfo2 ColaFte = NULL;
  psNodoInfo2 ColaFin = NULL;
  psNodoInfo  Lista   = NULL;

  //---------< PILA >----------------
  OperarPila(Pila);
  //---------< COLA >----------------
  OperarCola(ColaFte,ColaFin);
  //---------< LISTA >---------------
  OperarLista(Lista);
  return 0;
}
