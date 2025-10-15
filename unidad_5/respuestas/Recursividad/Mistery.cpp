/*
   Id.Programa: Mistery.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Calculo factorial recursivo
*/

#include <iostream>
using namespace std;

typedef unsigned short word;
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

word Mistery(tLista &Lista) {
  if (!Lista)
    return 0;
  else
    return Lista->Info + Mistery(Lista->Sgte);
} //Mistery

word Mistery2(tLista &Lista, tLista &pTemp) {

  pTemp = Lista;
  if (!pTemp)
    return 0;
  else
    return pTemp->Info + Mistery2(Lista,pTemp->Sgte);
} //Mistery2

void Mistery3(tLista &Lista) {
  tLista pElim;

  if (Lista) {
    pElim = Lista;
    Mistery3(Lista->Sgte);
    delete pElim;
  }
} //Mistery3

int main() {
  tLista Lista,
         pCopia;

  for (register i = 1; i <=30; i++)
    InsertaInicio(Lista,random(100));
  cout << Mistery(Lista);
  cout << Mistery2(Lista,pCopia);
  Mistery3(Lista);
  return 0;
}
