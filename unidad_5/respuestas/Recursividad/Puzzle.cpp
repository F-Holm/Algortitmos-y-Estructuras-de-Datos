/*
   Id.Programa: Ahijuna.cpp
   Fecha......: junio-2015
   Autor......: Lic. Hugo Cuello
   Comentar...: Tecnicas recursivas.
*/

#include <fstream>
using namespace std;

typedef short tInfo;
typedef struct tNodo *tLista;
struct tNodo {
  tInfo  Info;
  tLista Sgte;
};

void InsertaInicio(tLista &Lista, tInfo valor) {
  tLista pNvo = new tNodo;

  pNvo->Info = valor;
  pNvo->Sgte = Lista;
  Lista = pNvo;
} //InsertaInicio

long Puzzle(tLista &Lista) {
  if (!Lista)
    return 1;
  else
    if (Lista->Info > 0)
      return Lista->Info * Puzzle(Lista->Sgte);
    else
      return Puzzle(Lista->Sgte);
} //Puzzle

void Puzzle2(tLista &Lista) {
  tLista pElim;

  if (Lista) {
    pElim = Lista;
    cout << Lista->Info << endl;
    Puzzle2(Lista->Sgte);
    cout << pElim->Info << endl;
    delete pElim;
  }
} //Puzzle2

int main() {
  tLista Lista = NULL;
  short n;

  for (register i = 1; i <=6; i++) {
    cout << i << " Ing. un entero: ";
    cin >> n;
    InsertaInicio(Lista,n);
  }
  cout << Puzzle(Lista);
  Puzzle2(Lista);
  return 0;
}
