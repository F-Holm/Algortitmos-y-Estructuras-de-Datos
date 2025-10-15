
#include <conio.h>
#include <iomanip>
#include <iostream>
using namespace std;

typedef unsigned short ushort;
typedef char str20[21];
typedef int t1;
typedef t1   t2;
typedef float          t3;
typedef char           t4[21];
typedef unsigned int   t5;

struct trf {
  t1 cmp1;
  t2 cmp2;
  t3 cmp3;
  t4 cmp4;
};

struct tInfo {
  t1 cmp1;
  t5 reff;
};

typedef struct tNodo* tLista;
struct tNodo {
   tInfo  rInfo;
   tLista Sgte;
};

void InsertaInicio(tLista &Lista, tInfo valor) {
	tLista pNodo;

	pNodo = new tNodo;
	pNodo->rInfo = valor;
	pNodo->Sgte = Lista;
	Lista = pNodo;
} // InsertaInicio


void InsertaEnMedio(tLista &List, tInfo valor) {
  tLista pNodo,
         pAct;

  pNodo = new tNodo;
  pNodo->rInfo = valor;
  pAct = List;
  while (pAct->Sgte && valor.cmp1 > pAct->Sgte->rInfo.cmp1)
	  pAct = pAct->Sgte;
  pNodo->Sgte = pAct->Sgte;
  pAct->Sgte = pNodo;
} //InsertaEnMedio

void InsertaNodo(tLista &List, tInfo valor) {
  if (!List || valor.cmp1 < List->rInfo.cmp1)
	  InsertaInicio(List,valor);
  else
	  InsertaEnMedio(List,valor);
} //InsertaNodo

void SacarPrimerNodo(tLista &Lista, tInfo &valor) {
	tLista pElim;

	pElim = Lista;
	valor = Lista->rInfo;
	Lista = Lista->Sgte;
	delete pElim;
} //SacarPrimerNodo

 main() {
  FILE *f,*g;
  tLista L = NULL;
  char opc;
  t1 clv;
  trf rf;
  tInfo rI;

  f = fopen("ventas.dat","rb");
  //g = fopen("ventas.idx","rb");

  g = fopen("ventas.idx","wb");
  while (fread(&rf,sizeof rf,1,f)) {
    rI.cmp1 = rf.cmp1;
    rI.reff = (ftell(f) - sizeof rf) / sizeof rf;
    InsertaNodo(L,rI);
  }
  while(L) {
    SacarPrimerNodo(L,rI);
    fwrite(&rI,sizeof rI,1,g);
  }
  fclose(f);
  fclose(g);
  return 0;
}

