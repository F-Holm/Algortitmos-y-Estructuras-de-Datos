// Unidad 5 - Ejercicio merge
#include <fstream>
#include <iostream>

using namespace std;

#define HIGH_VALUE 2147483647
typedef int tInfo;

struct sNodo {
  tInfo info;
  sNodo *sgte;
};

typedef struct sNodo *tLista;

int GetPos(int bloque, int pos);
void Leer10(ifstream &Arch, tLista &lista);
void Escribir10(fstream &Aux, tLista &lista);
void InsertaNodo(tLista &lista, tInfo valor);
void InsertaEnMedio(tLista &lista, tInfo valor);
void InsertaInicio(tLista &lista, tInfo valor);
void SacarPrimerNodo(tLista &lista, tInfo &valor);

int main() {
  tLista listaA, listaB;
  listaA = listaB = NULL;
  ifstream Arch("archivo.dat", ios::binary);
  fstream Aux("aux.dat", ios::binary | ios::in | ios::out);
  ofstream Salida("aux.dat", ios::binary);
  int cant = 0;

  while (Arch.good()) {
    cant++;
    Leer10(Arch, listaA);
    InsertaNodo(listaB, listaA->info);
    Escribir10(Aux, listaA);
  }
  Arch.clear();

  int *pos = new int[cant];
  for (int i = 0; i < cant; i++)
    pos[i] = i * 10;

  bool salir = false;
  while (!salir) {
    int minimo = HIGH_VALUE;
    int elem = 0;
    listaB = listaA;
    while (listaB != NULL) {
    }
  }

  Arch.close();
  Aux.close();
  return 0;
}  // main

int GetPos(int bloque, int pos) {
  return (bloque * 10 + pos) * sizeof(tInfo);
}  // GetPos

void Leer10(ifstream &Arch, tLista &lista) {
  tInfo info;
  for (int i = 0; i < 10 && Arch.read((char *)&info, sizeof(tInfo)); i++) {
    InsertaNodo(lista, info);
  }
}  // Leer10

void Escribir10(fstream &Aux, tLista &lista) {
  tInfo valor;
  while (lista != NULL) {
    Aux.write((char *)&lista->info, sizeof(tInfo));
    SacarPrimerNodo(lista, valor);
  }
}  // Escribir10

void InsertaNodo(tLista &lista, tInfo valor) {
  if (lista == NULL || lista->info > valor)
    InsertaInicio(lista, valor);
  else
    InsertaEnMedio(lista, valor);
}  // InsertaNodo

void InsertaEnMedio(tLista &lista, tInfo valor) {
  sNodo *nodo = new sNodo;
  nodo->info = valor;
  tLista aux = lista;

  while (aux->sgte != NULL && valor > aux->info)
    aux = aux->sgte;

  nodo->sgte = aux->sgte;
  aux->sgte = nodo;
}  // InsertaEnMedio

void InsertaInicio(tLista &lista, tInfo valor) {
  sNodo *pNodo = new sNodo;
  pNodo->info = valor;
  pNodo->sgte = lista;
  lista = pNodo;
}  // InsertaInicio

void SacarPrimerNodo(tLista &lista, tInfo &valor) {
  sNodo *pElim = lista;
  valor = lista->info;
  lista = lista->sgte;
  delete pElim;
}  // SacarPrimerNodo
