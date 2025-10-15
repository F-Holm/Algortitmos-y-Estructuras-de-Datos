/*
   Id.Programa: CreaArtIdx.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: 2018-oct.
   Comentario.: Crea archivo de indices de Articulos.Dat
                utilizando un Arbol Binario ordenada y luego
                graba en el archivo Articulos.Idx
*/

#include <iomanip>
#include <conio>
#include <fstream>
using namespace std;

typedef char str5 [ 6];
typedef char str20[21];

struct sArt {
  str5  codArt;
  str20 descrip;
  short rubro;
  float precio;
  short stkAct,
        stkMin,
        ptoRep;
};

struct sIdx {
  str5 codArt;
  int  refArt;
  bool estado;
};

typedef struct sNodo * tTree;
typedef sIdx tInfo;

struct sNodo {
  tTree izq;
  tInfo rInfo;
  tTree der;
};

bool ArbolVacio(tTree &Tree) {
  return Tree == NULL;
} //ArbolVacio

void InsertarHoja(tTree &Tree, tTree pNvo) {
  if (ArbolVacio(Tree))
    Tree = pNvo;
  else
    if (strcmp(pNvo->rInfo.codArt,Tree->rInfo.codArt) < 0)
      InsertarHoja(Tree->izq,pNvo);
    else
      InsertarHoja(Tree->der,pNvo);
} //InsertaNodoHoja

void GrabarPreOrden(fstream &ArtIdx, tTree &pRoot) {
  tInfo rInfo;
  sArt rArt;

  if (!ArbolVacio(pRoot)) {
    ArtIdx.write((const char *) &pRoot->rInfo,sizeof rInfo); // R
    GrabarPreOrden(ArtIdx,pRoot->izq);                       // I
    GrabarPreOrden(ArtIdx,pRoot->der);                       // D
  }
} //GrabarPreOrden

void EliminarNodo(tTree &Tree, str5 codArt) {
  tTree pAct,
        pAnt,
        pElim;

  if (!ArbolVacio(Tree))
    if (strcmp(codArt,Tree->rInfo.codArt) < 0)
      EliminarNodo(Tree->izq,codArt);
    else if (strcmp(codArt,Tree->rInfo.codArt) > 0)
      EliminarNodo(Tree->der,codArt);
    else {
      pElim = Tree;
      if (!pElim->der)
        Tree = pElim->izq;
      else if (!pElim->izq)
        Tree = pElim->der;
      else {
        pAct = pElim->izq;
        pAnt = pAct;
        while (pAct->der) {
          pAnt = pAct;
          pAct = pAct->der;
        }
        if (pAct == pAnt)
          pElim->izq = pAct->izq;
        pElim->rInfo = pAct->rInfo;
        pElim = pAct;
        pAnt->der = pAct->izq;
      }
      delete pElim;
    }
} // EliminarNodo

void ListarInOrden(tTree &Tree, ifstream &Art) {
  sArt rArt;
  short static i = 0;

  if (!ArbolVacio(Tree)) {
    ListarInOrden(Tree->izq,Art);     // I
    Art.seekg(Tree->rInfo.refArt * sizeof(sArt),ios::beg);                  // R
    Art.read((char *) &rArt, sizeof rArt);
    cout << setw( 3) << i++ << ' ' << setw(3) << rArt.codArt << ' '
         << setw(20) <<rArt.descrip << ' '  << setw(3) << rArt.rubro
         << setw( 8) << rArt.precio << ' '  << setw(5) << rArt.stkAct << "  "
         << setw( 5) << rArt.stkMin << "  " << setw(5) << rArt.ptoRep
         << ' ' << endl;                                                    // R
    ListarInOrden(Tree->der,Art);     // D
  }
} //ListarInOrden

main() {
  ifstream Articulos("Articulos.Dat",ios::binary);
  fstream ArtIdx("Articulos.Idx",ios::in | ios::out | ios::binary);
  sArt rArt;
  sIdx rIdx;
  tInfo rInfo;
  tTree ArbolBB = NULL,
        pNodo;
  int   i = 0;

  while(Articulos.read((char *) &rArt,sizeof rArt)) {
    strcpy(rInfo.codArt,rArt.codArt);
    rInfo.refArt = i++;
    rInfo.estado = i % 7 != 0; //asigna falso si i es divis por 7, sino true.
    pNodo = new sNodo;
    pNodo->rInfo = rInfo;
    pNodo->izq = NULL;
    pNodo->der = NULL;
    InsertarHoja(ArbolBB,pNodo);
  }
  GrabarPreOrden(ArtIdx,ArbolBB);
  while (ArbolBB)
    EliminarNodo(ArbolBB, ArbolBB->rInfo.codArt);
  Articulos.clear();
  ArtIdx.seekg(0);
  i = 0;
  cout << "Listar Pre-Orden... " << endl;
  cout << "** Articulos.Idx y Articulos.Dat" << endl;
  cout << "Ord C.Art.Descripcion           Ru  Precio  StkAct StkMin PtoRep "
       << endl;
  //-----< Lee lo que Grabo y Muestra en Pantalla >-----
  while(ArtIdx.read((char *) &rIdx,sizeof rIdx)) {
    Articulos.seekg(rIdx.refArt * sizeof rArt,ios::beg);
    Articulos.read((char *) &rArt,sizeof rArt);
    cout << setw( 3) << i++ << ' ' << setw(3) << rArt.codArt << ' '
         << setw(20) <<rArt.descrip << ' '  << setw(3) << rArt.rubro
         << setw( 8) << rArt.precio << ' '  << setw(5) << rArt.stkAct << "  "
         << setw( 5) << rArt.stkMin << "  " << setw(5) << rArt.ptoRep << ' '
         << endl;
  }
  cout << "-------x-------x-------x-------x" << endl;
  ArtIdx.clear();
  ArtIdx.seekg(0);
  while (ArtIdx.read((char *) &rIdx, sizeof rIdx)) {
    pNodo = new sNodo;
    pNodo->rInfo = rIdx;
    pNodo->izq = NULL;
    pNodo->der = NULL;
    InsertarHoja(ArbolBB, pNodo);
  }
  cout << "Listar In-Orden... " << endl;
  cout << "Ord C.Art.Descripcion           Ru  Precio  StkAct StkMin PtoRep "
       << endl;
  ListarInOrden(ArbolBB,Articulos);
  Articulos.close();
  ArtIdx.close();
  return 0;
} // main



