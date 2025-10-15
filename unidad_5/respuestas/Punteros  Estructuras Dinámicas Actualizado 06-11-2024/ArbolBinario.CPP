/*
   Id.Programa: ArbolBinario.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: junio-2015 Fecha original en Pascal junio-2002.
   Comentario.: Genera, Emite (In-Orden, Pre-Orden, Pos-Orden), Busca
                  y Elimina, de Estructura Dinamica Arbol Binario.
*/

typedef unsigned short word;
typedef word tInfo;
typedef struct sNodo * tTree;

struct sNodo {
  tTree pIzq;
  tInfo Info;
  tTree pDer;
};

#include <conio.h>
#include <iomanip.h>
#include <iostream>
using namespace std;

void CrearArbol(tTree &Tree) {
  Tree = NULL;
} //CrearAbrol

bool ArbolVacio(tTree &Tree) {
  return Tree == NULL;
} //ArbolVacio

bool ArbolLleno(word MagnitudNodo) {
  return MagnitudNodo > 10000;
} //ArbolLleno

void InsertarHoja(tTree &Tree, tTree pNvo) {
  if (ArbolVacio(Tree))
    Tree = pNvo;
  else
    if (pNvo->Info < Tree->Info)
      InsertarHoja(Tree->pIzq,pNvo);
    else
      InsertarHoja(Tree->pDer,pNvo);
} //InsertaNodoHoja

void ListarInOrden(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    ListarInOrden(Tree->pIzq);     // I
    cout << setw(3) << Tree->Info; // R
    ListarInOrden(Tree->pDer);     // D
  }
} //ListarInOrden

void ListarPreOrden(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    cout << setw(3) << Tree->Info;  // R
    ListarPreOrden(Tree->pIzq);     // I
    ListarPreOrden(Tree->pDer);     // D
  }
} //ListarPreOrden

void ListarPosOrden(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    ListarPosOrden(Tree->pIzq);     // I
    ListarPosOrden(Tree->pDer);     // D
    cout << setw(3) << Tree->Info;  // R
  }
} //ListarPosOrden

tTree BuscarNodo(tTree &Tree, tInfo valor) {
  if (ArbolVacio(Tree))
    return NULL;
  else
    if (valor == Tree->Info)
      return Tree;
    else
      if (valor < Tree->Info)
        return BuscarNodo(Tree->pIzq,valor);
      else
        return BuscarNodo(Tree->pDer,valor);
} //BuscarNodo

void EliminarNodo(tTree &Tree, tInfo valor) {
  tTree pAct,
        pAnt,
        pElim;

  if (!ArbolVacio(Tree))
    if (valor < Tree->Info)
      EliminarNodo(Tree->pIzq,valor);
    else if (valor > Tree->Info)
      EliminarNodo(Tree->pDer,valor);
    else {
      pElim = Tree;
      if (!pElim->pDer)
        Tree = pElim->pIzq;
      else if (!pElim->pIzq)
        Tree = pElim->pDer;
      else {
        pAct = pElim->pIzq;
        pAnt = pAct;
        while (pAct->pDer) {
          pAnt = pAct;
          pAct = pAct->pDer;
        }
        if (pAct == pAnt)
          pElim->pIzq = pAct->pIzq;
        pElim->Info = pAct->Info;
        pElim = pAct;
        pAnt->pDer = pAct->pIzq;
      }
      delete pElim;
      gotoxy(1,15); clreol();
      cout << "El elemento " << setw(3) << valor << " fue eliminado... ";
    }
    else {
      gotoxy(1,15); clreol();
      cout << "El elemento " << valor << " no existe... ";
  }
} //EliminarNodo

word IngElem(string mens) {
  word elem;

  gotoxy(20,8);
  cout << mens;
  gotoxy(10,15);
  cout << "Para finalizar ingresar un valor = 0...";
  gotoxy(10,9); clreol();
  cout << "Ing. valor: ";
  cin >> elem;
  return elem;
} //IngElem

main() {
  tTree pRoot,
        pNvo,
        pNodo;
  word  elem;
  char  opc;

  clrscr();
  CrearArbol(pRoot);
  do {
    clrscr();
    cout << "1: Insertar" << endl;
    cout << "2: Quitar" << endl;
    cout << "3: Listar In-Orden" << endl;
    cout << "4: Listar Pre-Orden" << endl;
    cout << "5: Listar Pos-Orden" << endl;
    cout << "6: Buscar elemento" << endl;
    cout << "0: Finalizar" << endl;
    cout << "Su opcion: ";
    opc = getche();
    switch(opc) {
      case '1':
        elem = IngElem("Insertar");
        while (elem) {
          pNvo = new sNodo;
          pNvo->Info = elem;
          pNvo->pIzq = NULL;
          pNvo->pDer = NULL;
          InsertarHoja(pRoot,pNvo);
          elem = IngElem("Insertar");
        }
        break;
      case '2':
        elem = IngElem("Quitar");
        while (elem) {
          EliminarNodo(pRoot,elem);
          system("pause");
          gotoxy(1,15); clreol();
          elem = IngElem("Quitar");
        }
        break;
      case '3':
        gotoxy(20,8); clreol();
        cout << "Listar In-Orden...";
        gotoxy(20,12);
        ListarInOrden(pRoot);
        gotoxy(1,15); clreol();
        system("pause");
        break;
      case '4':
        gotoxy(20,8); clreol();
        cout << "Listar Pre-Orden...";
        gotoxy(20,12);
        ListarPreOrden(pRoot);
        gotoxy(1,15); clreol();
        system("pause");
        break;
      case '5':
        gotoxy(20,8); clreol();
        cout << "Listar Pos-Orden...";
        gotoxy(20,12);
        ListarPosOrden(pRoot);
        gotoxy(1,15); clreol();
        system("pause");
        break;
      case '6':
        elem = IngElem("Buscar");
        while (elem) {
          pNodo = BuscarNodo(pRoot,elem);
          gotoxy(1,15); clreol();
          if (pNodo)
            cout << "El elemento " << pNodo->Info << " se encontro...";
          else
            cout << "El elemento " << elem << " no existe... ";
          system("pause");
          gotoxy(1,15); clreol();
          elem = IngElem("Buscar");
        }
    }
  }
  while (opc != '0');
} // main

