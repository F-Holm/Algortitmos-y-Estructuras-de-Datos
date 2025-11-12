/*
  Id.Programa: 2025-02-24 R2-P2 IdxArticulos.cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: febrero-2025
  Comentario.: Indexar archivo binario de Articulos por:
                 1) Cod.Art.
                 2) Descrip.
                 en listas uno por cada indice.
               Listar ambos indices:
                 1) Ord. x Cod. Art.
                 2) Ord. x Descrip.
               Grabar ambos archivos de indices en archivos binarios.
  Compilador.: Borland V 5.5 C++
*/

#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

const float PORCTJE = 1.5;

typedef char str20[21];

struct sArt {
  short codArt,
        cant;
  str20 descrip;
  float preUni;
};

typedef struct sNodoCA * tListaCA;
typedef struct sNodoD * tListaD;

struct tInfoCA {
  short codArt,
        refArt;
};

struct tInfoD {
  str20 descrip;
  short refArt;
};

struct sNodoCA {
  tInfoCA  rInfo;
  tListaCA sgte;
};

struct sNodoD {
  tInfoD  rInfo;
  tListaD sgte;
};

void InsertaEnLugar(tListaCA &pNodo, tInfoCA valor) {
  tListaCA pNvo = new sNodoCA;

  pNvo->rInfo = valor;
  pNvo->sgte = pNodo->sgte;
  pNodo->sgte = pNvo;
} //InsertaEnLugar

void InsertaEnLugar(tListaD &pNodo, tInfoD valor) {
  tListaD pNvo = new sNodoD;

  pNvo->rInfo = valor;
  pNvo->sgte = pNodo->sgte;
  pNodo->sgte = pNvo;
} //InsertaEnLugar

void InsertaInicio(tListaCA &Lista, tInfoCA valor) {
  tListaCA pNvo = new sNodoCA;

  pNvo->rInfo = valor;
  pNvo->sgte = Lista;
  Lista = pNvo;
} // InsertaInicio

void InsertaEnMedio(tListaCA &Lista, tInfoCA valor) {
  tListaCA pAct = Lista;

  while (pAct->sgte && valor.codArt > pAct->sgte->rInfo.codArt)
    pAct = pAct->sgte;
  InsertaEnLugar(pAct,valor);
} // InsertaEnMedio

void InsertaNodo(tListaCA &Lista, tInfoCA valor) {
  if (!Lista || valor.codArt < Lista->rInfo.codArt)
    InsertaInicio(Lista,valor);
  else
    InsertaEnMedio(Lista,valor);
} // InsertaNodo

void InsertaInicio(tListaD &Lista, tInfoD valor) {
  tListaD pNvo = new sNodoD;

  pNvo->rInfo = valor;
  pNvo->sgte = Lista;
  Lista = pNvo;
} // InsertaInicio

void InsertaEnMedio(tListaD &Lista, tInfoD valor) {
  tListaD pAct = Lista;

  while (pAct->sgte && strcmp(valor.descrip,pAct->sgte->rInfo.descrip) > 0)
    pAct = pAct->sgte;
  InsertaEnLugar(pAct,valor);
} // InsertaEnMedio

void InsertaNodo(tListaD &Lista, tInfoD valor) {
  if (!Lista || strcmp(valor.descrip,Lista->rInfo.descrip) < 0)
    InsertaInicio(Lista,valor);
  else
    InsertaEnMedio(Lista,valor);
} // InsertaNodo

void SacarPrimerNodo(tListaCA &Lista, tInfoCA &valor) {
  tListaCA pElim = Lista;

  valor = Lista->rInfo;
  Lista = Lista->sgte;
  delete pElim;
} // SacarPrimerNodo

void SacarPrimerNodo(tListaD &Lista, tInfoD &valor) {
  tListaD pElim = Lista;

  valor = Lista->rInfo;
  Lista = Lista->sgte;
  delete pElim;
} // SacarPrimerNodo

void Abrir(fstream &Art, ofstream &IdxCodArt, ofstream &IdxDescrip) {
  Art.open("Articulos.Dat", ios::binary | ios::in | ios::out);
  IdxCodArt.open("IdxCodArt.Idx", ios::binary);
  IdxDescrip.open("IdxDescrip.Idx", ios::binary);
} // Abrir

void ActReg(fstream &Art, sArt rArt) {
  Art.seekg(-1 * sizeof rArt, ios::cur);
  Art.write((char *) &rArt, sizeof rArt);
} // ActReg

void ActualizarArt(fstream &Art) {
  sArt rArt;

  while (Art.read((char *) &rArt, sizeof rArt)) {
    rArt.preUni *= (1 + PORCTJE / 100);
    ActReg(Art,rArt);
  }
  Art.clear();  //Limpia el flag de error por haber llegado al fin del archivo.
} // ActualizarArt

void ProcIdxArt(fstream &Art, tListaCA &ListaCA, tListaD &ListaD) {
  sArt    rArt;
  tInfoCA rCodArt;
  tInfoD  rDescrip;
  short   cArt = 0;

  Art.seekg(0);
  while (Art.read((char *) &rArt, sizeof rArt)) {
    rCodArt.codArt = rArt.codArt;
    rCodArt.refArt = cArt;
    strcpy(rDescrip.descrip,rArt.descrip);
    rDescrip.refArt = cArt;
    InsertaNodo(ListaCA,rCodArt);
    InsertaNodo(ListaD,rDescrip);
    cArt++;
  }
  Art.clear();
} // ProcIdxArt

void ListarOrdCodArt(fstream &Art, tListaCA &ListaCA) {
  sArt     rArt;
  tListaCA pAct = ListaCA;

  freopen("Listados.Txt","w",stdout);
  cout.precision(2);
  cout << fixed;
  cout << "Listado de Articulos ordenado por Cod.Art."  << endl;
  cout << "C.Art. Cant. Descripcion           Pre.Unit." << endl;
  while (pAct) {
    Art.seekg(pAct->rInfo.refArt * sizeof rArt);
    //Art.seekp(Art.tellp() - (int) sizeof rArt);
    Art.read((char *) &rArt, sizeof rArt);
    cout << setw(6) << rArt.codArt << ' ' << setw(5) << rArt.cant << ' '
         << setw(20) << rArt.descrip << ' ' << setw(8)  << rArt.preUni << endl;
    pAct = pAct->sgte;
  }
} // ListarOrdCodArt

void ListarOrdDescrip(fstream &Art, tListaD &ListaD) {
  sArt    rArt;
  tListaD pAct = ListaD;

  cout << endl << "Listado de Articulos ordenado por Descripcion"  << endl;
  cout << "C.Art. Cant. Descripcion           Pre.Unit." << endl;
  while (pAct) {
    Art.seekg(pAct->rInfo.refArt * sizeof rArt);
    Art.read((char *) &rArt, sizeof rArt);
    cout << setw(6) << rArt.codArt << ' ' << setw(5) << rArt.cant << ' '
         << setw(20) << rArt.descrip << ' ' << setw(8) << rArt.preUni << endl;
    pAct = pAct->sgte;
  }
  freopen("CON","w",stdout);
} // ListarOrdDescrip

void GrabarIdxCodArt(ofstream &IdxArtCodArt, tListaCA &ListaCA) {
  tInfoCA rIdx;

  while (ListaCA) {
    SacarPrimerNodo(ListaCA, rIdx);
    IdxArtCodArt.write((char *) &rIdx, sizeof rIdx);
  }
} // GrabarIdxCodArt

void GrabarIdxDescrip(ofstream &IdxArtDescrip, tListaD &ListaD) {
  tInfoD rIdx;

  while (ListaD) {
    SacarPrimerNodo(ListaD, rIdx);
    IdxArtDescrip.write((char *) &rIdx, sizeof rIdx);
  }
} // GrabarIdxDescrip

void Cerrar(fstream &Art, ofstream &IdxCodArt, ofstream &IdxDescrip) {
  Art.close();
  IdxCodArt.close();
  IdxDescrip.close();
} // Cerrar

main () {
  fstream  Articulos;
  ofstream IdxArtCodArt,
           IdxArtDescrip;
  tListaCA ListaIdxCodArt = NULL;
  tListaD  ListaIdxDescrip = NULL;

  Abrir(Articulos,IdxArtCodArt,IdxArtDescrip);
  ActualizarArt(Articulos);
  ProcIdxArt(Articulos,ListaIdxCodArt,ListaIdxDescrip);
  ListarOrdCodArt(Articulos,ListaIdxCodArt);
  ListarOrdDescrip(Articulos,ListaIdxDescrip);
  GrabarIdxCodArt(IdxArtCodArt,ListaIdxCodArt);
  GrabarIdxDescrip(IdxArtDescrip,ListaIdxDescrip);
  Cerrar(Articulos,IdxArtCodArt,IdxArtDescrip);
  return 0;
} // main
