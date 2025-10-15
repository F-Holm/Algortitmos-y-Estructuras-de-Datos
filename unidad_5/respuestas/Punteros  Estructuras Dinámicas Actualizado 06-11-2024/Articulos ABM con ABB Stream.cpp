/*
   Id.Programa: Articulos ABM con ABB Stream.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: 2018-OCT
   Comentario.: Actualizacion Articulos Indexado
                Novedades (sin orden).
                Estructura de datos Arbol Binario de busqueda
                con info con 3 campos:
                  codArt (ord. asc.), refArt, estado.
                2018-10-27 TP2 ArtIdx ABB.
*/

#include <iomanip>
#include <fstream>
using namespace std;

typedef char str5[6];
typedef char str20[21];
typedef char str30[31];

struct sArt {
  str5  codArt;
  str20 descrip;
  short rubro;
  float precio;
  short stkAct,
        stkMin,
        ptoRep;
};

struct sNov {
  sArt rArt;
  char codMov;
};

typedef struct sNodo * tTree;

struct sInfo {
  str5 codArt; //es la clave
  int  refArt;
  bool estado;
};

struct sNodo {
  tTree izq;
  sInfo rInfo;
  tTree der;
};

// ----< Inicio Modulos de Estructuras Dinamicas >----

tTree CrearArbol() {
  return NULL;
} // CrearAbrol

bool ArbolVacio(tTree &Tree) {
  return Tree == NULL;
} // ArbolVacio

void InsertarHoja(tTree &Tree, tTree pNvo) {
  if (ArbolVacio(Tree))
    Tree = pNvo;
  else
    if (strcmp(pNvo->rInfo.codArt,Tree->rInfo.codArt) < 0)
      InsertarHoja(Tree->izq,pNvo);
    else
      InsertarHoja(Tree->der,pNvo);
} // InsertaNodoHoja

void EliminarNodo(tTree &Tree, str5 valor) {
  tTree pAct,
        pAnt,
        pElim;

  if (!ArbolVacio(Tree))
    if (strcmp(valor,Tree->rInfo.codArt) < 0)
      EliminarNodo(Tree->izq,valor);
    else if (strcmp(valor,Tree->rInfo.codArt) > 0)
      EliminarNodo(Tree->der,valor);
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

void ListarInOrden(fstream &Art, fstream &ArtIdx, tTree &pRoot) {
  sInfo rInfo;
  sArt  rArt;

  if (!ArbolVacio(pRoot)) {
    ListarInOrden(Art,ArtIdx,pRoot->izq); // I
    if(pRoot->rInfo.estado) {             // R
      Art.seekg(pRoot->rInfo.refArt * sizeof rArt,ios::beg);
      Art.read((char *) &rArt,sizeof rArt);
      cout << setw(2) << ' ' << setw(5) << rArt.codArt << setw(2)
           << ' ' << left << setw(20) << rArt.descrip << right
           << setw(2) << ' ' << setw(4) << rArt.stkAct << setw(7)
           << ' ' << setw(4) << rArt.ptoRep << setw(7) << ' '
           << setw(4) << rArt.stkMin << setw(5) << ' ' << setw(8)
           << rArt.precio << endl;
    }
    ListarInOrden(Art,ArtIdx,pRoot->der);  // D
  }
} // ListarInOrden

tTree BuscarNodo(tTree &pRoot, str5 codArt) {
  if (ArbolVacio(pRoot))
    return NULL;
  else
    if (strcmp(codArt,pRoot->rInfo.codArt) == 0)
      return pRoot;
    else
      if (strcmp(codArt,pRoot->rInfo.codArt) < 0)
        return BuscarNodo(pRoot->izq,codArt);
      else
        return BuscarNodo(pRoot->der,codArt);
} // BuscarNodo

// ----< Fin Modulos de Estructuras Dinamicas >----

void VolcarIdx(fstream &ArtIdx, tTree &pRoot) {
  tTree pNodo;
  sInfo rIdx;

  while(ArtIdx.read((char *) &rIdx,sizeof rIdx)) {
    pNodo = new sNodo;
    pNodo->rInfo = rIdx;
    pNodo->izq = NULL;
    pNodo->der = NULL;
    InsertarHoja(pRoot,pNodo);
  }
  ArtIdx.clear();
} // VolcarIdx

void MsjError(short &nroErr, int refNov, str5 codArt, str30 titulo) {
  cout << setw(3) << setw(3) << ++nroErr << setw(5) << ' '
       << setw(6) << setw(5) << refNov << setw(6) << ' ' << setw(5)
       << codArt  << setw(3) << ' ' << left << setw(20) <<titulo
       << right <<endl;
} // MsjErr

void Alta(fstream &Art, sNov rNov, tTree &pRoot,
          tTree pAct, short &nroErr,int refNov) {
  tTree pNodo;
  sArt rArt;
  sInfo rInfo;
  bool  existe;

  existe = pAct && pAct->rInfo.estado;
  if(!pAct) { // NO se encontro
    rArt = rNov.rArt;
    Art.seekp(0L,ios::end);
    Art.write((const char *) &rArt,sizeof rArt);
    strcpy(rInfo.codArt,rNov.rArt.codArt);
    rInfo.refArt = Art.tellp() / sizeof rArt - 1;
    rInfo.estado = true;
    pNodo = new sNodo;
    pNodo->rInfo = rInfo;
    pNodo->izq = NULL;
    pNodo->der = NULL;
    InsertarHoja(pRoot,pNodo);
  }
  else
    if(!existe) { //se encontro pero estado es false.
      rArt = rNov.rArt;
      Art.seekp(pAct->rInfo.refArt * sizeof rArt,ios::beg);
      Art.write((const char *) &rArt,sizeof rArt);
      pAct->rInfo.estado = true;
    }
    else
      MsjError(nroErr,refNov,rNov.rArt.codArt,"Alta existente");
} // Alta

void Baja(str5 cArt, tTree &pNodoAct,
          short &nroErr, int refNov) {
  if(pNodoAct && pNodoAct->rInfo.estado)
    pNodoAct->rInfo.estado = false;
  else
    MsjError(nroErr,refNov,cArt,"Baja inexistente");
} // Baja

void Modif(fstream &Art, str5 codArt, tTree &pNodoArt,
           short &nroErr, int refNov, float precio, short ptoRep) {
  sArt rArt;

  if(pNodoArt && pNodoArt->rInfo.estado) {
    if(precio || ptoRep) {
      Art.seekg(pNodoArt->rInfo.refArt * sizeof rArt,ios::beg);
      Art.read((char *) &rArt,sizeof rArt);
      if(precio)
        rArt.precio = precio;
      if(ptoRep)
        rArt.ptoRep = ptoRep;
      Art.seekp(pNodoArt->rInfo.refArt * sizeof rArt,ios::beg);
      Art.write((const char *) &rArt,sizeof rArt);
    }
  }
  else
    MsjError(nroErr,refNov,codArt,"Modificacion inexistente");
} // Modif

void ProcNov(fstream &Art, ifstream &Nov, tTree &pRoot) {
  short  nroErr = 0;
  sNov  rNov;
  tTree pNodoAct;

  freopen("LstErroresActArt.Txt","w",stdout);
  cout << "Listado de Errores de Actualizacion Articulos" << endl;
  cout << "Nro.Ord. Nro.Reg. Cod.Art. Observacion" << endl;
  while(Nov.read((char *) &rNov,sizeof rNov)) {
    pNodoAct = BuscarNodo(pRoot,rNov.rArt.codArt);
    switch(rNov.codMov) {
      case 'A': Alta(Art,rNov,pRoot,pNodoAct,nroErr,
                     Nov.tellg() / sizeof rNov - 1);
                break;
      case 'B': Baja(rNov.rArt.codArt,pNodoAct,nroErr,
                     Nov.tellg() / sizeof rNov - 1);
                break;
      default : Modif(Art,rNov.rArt.codArt,pNodoAct,
                      nroErr,Nov.tellg() / sizeof rNov - 1,
                      rNov.rArt.precio, rNov.rArt.ptoRep);
    }
  }
} // ProcNov

void EliminarNodos(tTree &pRoot) {
  while(pRoot) {
    EliminarNodo(pRoot,pRoot->rInfo.codArt);
  }
} // EliminarNodos

void ListadoActIdx(fstream &Art, fstream &ArtIdx, tTree &pRoot) {
  sInfo rInfo;
  sArt rArt;

  cout.precision(2);
  cout << fixed;
  ArtIdx.seekg(0);
  cout << endl << "Listado de Articulos Actualizado" << endl;
  cout << "Cod.Art. Descripcion          Stk.Act.   Pto.Rep."
       <<  "   Stk.Min.    Precio" << endl;
  ListarInOrden(Art,ArtIdx,pRoot);
  EliminarNodos(pRoot);
  freopen("CON","w",stdout);
} // ListadoActIdx

void GrabarPreOrden(fstream &ArtIdx, tTree &pRoot) {
  sInfo rInfo;
  sArt rArt;

  if (!ArbolVacio(pRoot)) {
    ArtIdx.write((const char *) &pRoot->rInfo,sizeof rInfo); // R
    GrabarPreOrden(ArtIdx,pRoot->izq);                       // I
    GrabarPreOrden(ArtIdx,pRoot->der);                       // D
  }
} //GrabarPreOrden

void Cerrar(fstream &Art, fstream &ArtIdx, ifstream &Nov) {
  Art.close();
  ArtIdx.close();
  Nov.close();
} // Cerrar

main() {
  fstream Articulos("Articulos.Dat", ios::in | ios::out | ios::binary);
  fstream ArticIdx("Articulos.Idx", ios::in | ios::out | ios::binary);
  ifstream Novedades("Novedades.Dat",ios::binary);
  tTree ArbolBBIdx = CrearArbol();

  VolcarIdx(ArticIdx,ArbolBBIdx);
  ProcNov(Articulos,Novedades,ArbolBBIdx);
  ListadoActIdx(Articulos,ArticIdx,ArbolBBIdx);
  GrabarPreOrden(ArticIdx,ArbolBBIdx);
  Cerrar(Articulos,ArticIdx,Novedades);
  return 0;
} // main
