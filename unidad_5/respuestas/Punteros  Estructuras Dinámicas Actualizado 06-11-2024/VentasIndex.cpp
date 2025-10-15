/*
  Id.Programa: VentasIndex.cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: octubre-2013
  Comentario.: Archivo indexado de Ventas con Arbol Binario
               Compilador C++ Borland V.5.5
*/

#include <iomanip.h>
#include <fstream>
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
  int   codArt,
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

void ListarInOrden(ifstream &Vtas, tTree &Tree) {
  tsVta rVta;

  if (!ArbolVacio(Tree)) {
    ListarInOrden(Vtas,Tree->pIzq);
    Vtas.seekg(Tree->Info.refArt * sizeof(rVta));
    Vtas.read((char *) &rVta, sizeof rVta);
    cout << setw(4) << rVta.codArt << ' ' << setw(4) << rVta.cant << ' '
         << setw(8) << rVta.preUni << ' ' << left
         << rVta.descrip << right << endl;
    ListarInOrden(Vtas,Tree->pDer);
  }
} //ListarInOrden

void Abrir(ifstream &Vtas) {
  Vtas.open("Ventas.Dat",ios::binary);
} //Abrir

int main() {
  ifstream Ventas;
  tsVta    rVenta;
  tInfo    rInfo;
  tTree    ArbolBin = NULL,
           pNodoNew;

  Abrir(Ventas);
  while (Ventas.read((char *) &rVenta, sizeof rVenta)) {
    rInfo.codArt = rVenta.codArt;
    rInfo.refArt = Ventas.tellg() / sizeof (rVenta) - 1;
    pNodoNew = new tNodo;
    pNodoNew-> Info = rInfo;
    pNodoNew-> pIzq = pNodoNew->pDer = NULL;
    InsertarNodoHoja(ArbolBin,pNodoNew);
  }
  Ventas.clear();
  cout << "Listado de Ventas de Articulos" << endl;
  cout << "cArt cant   preUni Descripcion" << endl;
  ListarInOrden(Ventas,ArbolBin);
  Ventas.close();
  return 0;
} //main()
