#pragma once

#include <conio.h>
#include <iomanip.h>

#include <iostream>

using namespace std;

typedef unsigned short word;
typedef word tInfo;
typedef struct tNodo *tTree;

struct tNodo {
  tTree pIzq;
  tInfo Info;
  tTree pDer;
};

template <typename T>
struct sNodo {
  T info;
  sNodo<T> *ptrEmpo;
};

// Pilas
template <typename T>
void Push(sNodo<T> *&pila, T valor) {
  sNodo<T> *pNodo = new sNodo<T>;
  pNodo->info = valor;
  pNodo->ptrEmpo = pila;
  pila = pNodo;
}  // Push

template <typename T>
void Pop(sNodo<T> *&pila, T &valor) {
  sNodo<T> *pElim = pila;
  valor = pila->info;
  pila = pila->ptrEmpo;
  delete pElim;
}  // Pop

// Colas
template <typename T>
void Enqueue(sNodo<T> *&cFte, sNodo<T> *&cFin, T valor) {
  sNodo<T> *pNodo = new sNodo<T>;
  pNodo->ptrEmpo = cFin->ptrEmpo;
  pNodo->info = valor;
  cFin->ptrEmpo = pNodo;
}  // Enqueue

template <typename T>
void Denqueue(sNodo<T> *&cFte, sNodo<T> *&cFin, T &valor) {
  sNodo<T> *pElim = cFte;
  valor = cFte->info;
  cFte = cFte->ptrEmpo;
  delete cFte;
}  // Denqueue

// Listas
template <typename T>
void InsertaInicio(sNodo<T> *&lista, T valor) {
  sNodo<T> *pNodo = new sNodo<T>;
  pNodo->info = valor;
  pNodo->ptrEmpo = lista;
  lista = pNodo;
}  // InsertaInicio

template <typename T>
void SacarPrimerNodo(sNodo<T> *&lista, T &valor) {
  sNodo<T> *pElim = lista;
  valor = lista->info;
  lista = lista->ptrEmpo;
  delete pElim;
}  // SacarPrimerNodo

void CrearArbol(tTree &Tree) {
  Tree = NULL;
}  // CrearAbrol

bool ArbolVacio(tTree &Tree) {
  return Tree == NULL;
}  // ArbolVacio

bool ArbolLleno(word MagnitudNodo) {
  return MagnitudNodo > 10000;
}  // ArbolLleno

void InsertarHoja(tTree &Tree, tTree pNvo) {
  if (ArbolVacio(Tree))
    Tree = pNvo;
  else if (pNvo->Info < Tree->Info)
    InsertarHoja(Tree->pIzq, pNvo);
  else
    InsertarHoja(Tree->pDer, pNvo);
}  // InsertaNodoHoja

void ListarInOrden(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    ListarInOrden(Tree->pIzq);
    cout << setw(3) << Tree->Info;
    ListarInOrden(Tree->pDer);
  }
}  // ListarInOrden

void ListarPreOrden(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    cout << setw(3) << Tree->Info;
    ListarPreOrden(Tree->pIzq);
    ListarPreOrden(Tree->pDer);
  }
}  // ListarPreOrden

void ListarPosOrden(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    ListarPosOrden(Tree->pIzq);
    ListarPosOrden(Tree->pDer);
    cout << setw(3) << Tree->Info;
  }
}  // ListarPosOrden

// Falta desarrollar este modulo
void ListarEnAnchura(tTree &Tree) {  // ListarPorNivel
  if (!ArbolVacio(Tree)) {
    cout << setw(3) << Tree->Info;
    ListarPosOrden(Tree->pIzq);
    ListarPosOrden(Tree->pDer);
  }
}  // ListarEnAnchura

tTree BuscarNodo(tTree &Tree, tInfo valor) {
  if (ArbolVacio(Tree))
    return NULL;
  else if (valor == Tree->Info)
    return Tree;
  else if (valor < Tree->Info)
    return BuscarNodo(Tree->pIzq, valor);
  else
    return BuscarNodo(Tree->pDer, valor);
}  // BuscarNodo

void EliminarNodo(tTree &Tree, tInfo valor) {
  tTree pAct, pAnt, pElim;

  if (!ArbolVacio(Tree))
    if (valor < Tree->Info)
      EliminarNodo(Tree->pIzq, valor);
    else if (valor > Tree->Info)
      EliminarNodo(Tree->pDer, valor);
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
      gotoxy(1, 24);
      clreol();
      cout << "El elemento " << setw(3) << valor << " fue eliminado... ";
    }
  else {
    gotoxy(1, 24);
    clreol();
    cout << "El elemento " << valor << " no existe... ";
  }
}  // EliminarNodo

void EliminarPosOrden(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    EliminarPosOrden(Tree->pIzq);
    EliminarPosOrden(Tree->pDer);
    delete Tree;
  }
  // Tree = NULL; luego de llamar a esta funcion;
}  // EliminarPosOrden