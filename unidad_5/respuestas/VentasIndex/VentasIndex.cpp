
// Id.Programa: VentasIndex.cpp
// Archivo indexado de Ventas con Arbol Binario


#include <iomanip.h>
#include <iostream>
using namespace std;

struct tInfo {
  int codArt,
      refArt;
};

typedef struct tNodo *tTree;
struct tNodo {
  tTree pIzq;
  tInfo Info;
  tTree pDer;
};

typedef char str20[21];
struct tsVta {
  int codArt,
      cant;
  float preUni;
  str20 descrip;
};

bool ArbolVacio(tTree &Tree) {
  return Tree == NULL;
} //ArbolVacio

void InsertarNodoHoja(tTree &Tree, tTree pNvo) {
  if (ArbolVacio(Tree))
    Tree = pNvo;
  else
    if (pNvo->Info.codArt < Tree->Info.codArt)
      InsertarNodoHoja(Tree->pIzq,pNvo);
    else
      InsertarNodoHoja(Tree->pDer,pNvo);
} //InsertarNodoHoja

void ListarInOrden(FILE **Vtas, tTree &Tree) {
  tsVta rVta;

  if (!ArbolVacio(Tree)) {
    ListarInOrden(Vtas,Tree->pIzq);
    fseek(*Vtas,Tree->Info.refArt * sizeof(rVta),SEEK_SET);
    fread(&rVta,sizeof rVta,1,*Vtas);
    cout << setw(3) << rVta.codArt << " " << rVta.cant << " " << rVta.preUni << " " << rVta.descrip << endl;
    ListarInOrden(Vtas,Tree->pDer);
  }
} //ListarInOrden


void Abrir(FILE **Vtas) {
  *Vtas = fopen("Ventas.Dat","rb");
} //Abrir

int main() {
  FILE *Ventas;
  tsVta rVenta;
  tInfo rInfo;
  tTree ArbolBin = NULL,
        pNodoNew;

  Abrir(&Ventas);
  while (fread(&rVenta,sizeof rVenta,1,Ventas)) {
    rInfo.codArt = rVenta.codArt;
    rInfo.refArt = ftell(Ventas) / sizeof (rVenta) - 1;
    pNodoNew = new tNodo;
    pNodoNew-> Info = rInfo;
    pNodoNew-> pIzq = pNodoNew->pDer = NULL;
    InsertarNodoHoja(ArbolBin,pNodoNew);
  }
  ListarInOrden(&Ventas,ArbolBin);
  fclose(Ventas);
  return 0;
} //main()
