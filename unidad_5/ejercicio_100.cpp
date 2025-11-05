// Unidad 5 - Ejercicio 100

/*
2 listas con valores de coeficientes y exponentes que están en un archivo y otro
archivo que también contiene coefiientes y exponentes. archivo1: polinomioP |
archivo2: polinomioQ. Hay que sumar ambos polinomios. Cada término de cada
polinomio debe ordenarse por los exponentes antes de la suma. Cada archivo tiene
2 campos por bloque
*/

#include <conio.h>

#include <iostream>

using namespace std;

struct tsTermino {
  float coef;
  int exp;
};

typedef struct tsTermino tInfo;

struct sNodo {
  tInfo info;
  sNodo *ptr;
};

typedef struct sNodo *tPol;

void Menu(char &opcion);
void IngresarTermino(tPol &pol);
void Emitir(tPol &pol);
void Sumar(tPol &polP, tPol &polQ, tPol &polR);
void EliminarR(tPol &polR);
void InsertaNodo(tPol &pol, tInfo valor);
void InsertaInicio(tPol &pol, tInfo valor);
void InsertaEnMedio(tPol &pol, tInfo valor);
void SacarPrimerNodo(tPol &pol, tInfo &valor);

int main() {
  tPol polP, polQ, polR;
  polP = polQ = polR = NULL;
  char opcion;
  Menu(opcion);
  while (opcion != '0') {
    IngresarTermino(opcion == '1' ? polP : polQ);
    Menu(opcion);
  }
  cout << "\nP:    ";
  Emitir(polP);
  cout << "Q:    ";
  Emitir(polQ);
  Sumar(polP, polQ, polR);
  cout << "Suma: ";
  Emitir(polR);
  EliminarR(polR);
  return 0;
}  // main

void Menu(char &opcion) {
  cout << "0 = Sumar | 1 = Ingresar P | 2 = Ingresar Q: ";
  opcion = getch();
  cout << '\n';
}  // Menu

void IngresarTermino(tPol &pol) {
  tsTermino termino;
  cout << "Coeficiente: ";
  cin >> termino.coef;
  cout << "Exponente:   ";
  cin >> termino.exp;
  cin.ignore();
  InsertaNodo(pol, termino);
}  // IngresarTermino

void Emitir(tPol &pol) {
  bool primero = true;
  tPol aux = pol;
  while (aux != NULL) {
    if (primero)
      primero = false;
    else
      cout << (aux->info.coef < 0 ? " " : " +");
    cout << aux->info.coef << "*X^" << aux->info.exp;
    aux = aux->ptr;
  }
  cout << endl;
}  // Emitir

void Sumar(tPol &polP, tPol &polQ, tPol &polR) {
  tInfo info;
  if (polP == NULL && polQ == NULL)
    return;
  else if (polQ == NULL || polP->info.exp > polQ->info.exp) {
    InsertaNodo(polR, polP->info);
    SacarPrimerNodo(polP, info);
  } else if (polP == NULL || polQ->info.exp > polP->info.exp) {
    InsertaNodo(polR, polQ->info);
    SacarPrimerNodo(polQ, info);
  } else {
    tsTermino sTermino;
    sTermino.coef = polP->info.coef + polQ->info.coef;
    sTermino.exp = polP->info.exp;
    InsertaNodo(polR, sTermino);
    SacarPrimerNodo(polP, info);
    SacarPrimerNodo(polQ, info);
  }
  Sumar(polP, polQ, polR);
}  // Sumar

void EliminarR(tPol &polR) {
  if (polR != NULL) {
    tInfo info;
    SacarPrimerNodo(polR, info);
    EliminarR(polR);
  }
}  // EliminarR

void InsertaNodo(tPol &pol, tInfo valor) {
  if (pol == NULL || valor.exp > pol->info.exp)
    InsertaInicio(pol, valor);
  else
    InsertaEnMedio(pol, valor);
}  // InsertaNodo

void InsertaInicio(tPol &pol, tInfo valor) {
  sNodo *pNodo = new sNodo;
  pNodo->info = valor;
  pNodo->ptr = pol;
  pol = pNodo;
}  // InsertaInicio

void InsertaEnMedio(tPol &pol, tInfo valor) {
  tPol nodo = new sNodo;
  nodo->info = valor;
  tPol aux = pol;

  while (aux->ptr != NULL && valor.exp < aux->info.exp)
    aux = aux->ptr;

  nodo->ptr = aux->ptr;
  aux->ptr = nodo;
}  // InsertaEnMedio

void SacarPrimerNodo(tPol &pol, tInfo &valor) {
  sNodo *pElim = pol;
  valor = pol->info;
  pol = pol->ptr;
  delete pElim;
}  // SacarPrimerNodo