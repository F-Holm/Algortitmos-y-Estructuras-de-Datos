/*
   Id.Programa: Insensata.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <iostream>
using namespace std;

typedef int tInfo;
typedef struct tNodo *tLista;
struct tNodo {
  tInfo  Info;
  tLista Sgte;
};

void InsertaInicio(tLista &Lista, tInfo valor) {
  tLista pNvo;

  pNvo = new tNodo;
  pNvo->Info = valor;
  pNvo->Sgte = Lista;
  Lista = pNvo;
} //InsertaInicio

bool Insensata(tLista &Lista) {
  if (!Lista)
    return false;
  else
    return (1 + 1 == 2) && Insensata(Lista->Sgte);
} //Insensata

void Insensata2(tLista &Lista) {
  tLista pElim;

  if (Lista) {
    pElim = Lista;
    cout << Lista->Info << ' ';
    Insensata2(Lista->Sgte);
    delete pElim;
  }
} //Insensata2

int main() {
  tLista Lista;

  for (register i = 1; i <=30; i++)
    InsertaInicio(Lista,random(100)),
    cout << Lista->Info << ' ';
  cout << endl << boolalpha << Insensata(Lista);
  cout << endl;
  Insensata2(Lista);
  return 0;
}
