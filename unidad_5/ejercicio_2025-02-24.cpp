// Unidad 5 - Ejercicio 2025-02-24
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

const float PORCTJE = 1.5;
typedef char str20[21];

struct sArt {
  short codArt;
  short cant;
  str20 descrip;
  float preUni;
};

struct tInfoCA {
  int pos;
  short codArt;
};

struct tInfoD {
  int pos;
  str20 descrip;
};

struct sNodoCA {
  tInfoCA info;
  sNodoCA *sgte;
};

struct sNodoD {
  tInfoD info;
  sNodoD *sgte;
};

typedef struct sNodoCA *tListaCA;
typedef struct sNodoD *tListaD;

void Abrir(fstream &Art, ofstream &IndArtCA, ofstream &IndArtD);
void ActualizarArt(fstream &Art);
void ProcIdxArt(fstream &Art, tListaCA &ListaCodArt, tListaD &ListaDescrip);
void ListarOrdCodArt();
void ListarOrdDescrip(fstream &Art, tListaD &ListaDescrip);
void GrabarIdxCodArt(ofstream &ldxCodArt, tListaCA &ListaCodArt);
void GrabarIdxDescrip();
void Cerrar();
void ActReg(fstream &Art, sArt rArt);
void SacarPrimerNodo(tListaCA &LístaCodArt, tInfoCA &valor);
void InsertaNodo(tListaCA &ListaCodArt, tInfoCA valor);
void InsertaNodo(tListaD &ListaDescrip, tInfoD valor);
void ListarOrdCodArt(fstream &Art, tListaCA &ListaCodArt);
void GrabarldxDescrip(ofstream &IdxDescrip, tListaD &ListaDescrip);

int main() {
  tListaCA ListaCodArt, ListaDescrip;
  fstream Art;
  ofstream IndArtCA, IndArtD;
  ListaCodArt = ListaDescrip = NULL;

  Abrir();
  ActualizarArt();
  ProcIdxArt();
  ListarOrdCodArt();
  ListarOrdDescrip();
  GrabarIdxCodArt();
  GrabarIdxDescrip();
  Cerrar();
  return 0;
}  // main

void Abrir(fstream &Art, ofstream &IndArtCA, ofstream &IndArtD) {
  Art.open("gvfduikyagsfyiod", ios::in | ios::out | ios::binary);
  IndArtCA.open("uyagdf", ios::binary);
  IndArtD.open("dsa", ios::binary);
}

void ActualizarArt(fstream &Art) {
  sArt rArt;
  while (Art.read((char *)&rArt, sizeof(sArt))) {
    rArt.preUni *= (1 - PORCTJE / 100.0);
    ActReg(Art, rArt);
  }
}  // ActualizarArt

void ProcIdxArt(fstream &Art, tListaCA &ListaCodArt, tListaD &ListaDescrip) {
  sArt rArt;
  tInfoCA infoCA;
  tInfoD infoD;
  Art.clear();
  Art.seekp(0);

  for (int i = 0; Art.read((char *)&rArt, sizeof(sArt)); i++) {
    infoCA.codArt = rArt.codArt;
    strcpy(infoD.descrip, rArt.descrip);
    infoCA.pos = infoD.pos = i;

    InsertaNodo(ListaCodArt, infoCA);
    InsertaNodo(ListaDescrip, infoD);
  }
}  // ProcIdxArt

void ListarOrdDescrip(fstream &Art, tListaD &ListaDescrip) {
  tListaD aux = ListaDescrip;
  sArt rArt;
  Art.clear();
  cout << setprecision(2) << fixed;

  cout << "Listado de Articulos ordenado por Descripcion\nCod.Art Cant. "
          "Descripcion          Pre.Unit.\n";
  while (aux != NULL) {
    Art.read((char *)&rArt, sizeof(sArt));
    cout << ' ' << setw(4) << rArt.codArt << "    " << setw(3) << rArt.cant
         << "  " << setw(20) << rArt.descrip << ' ' << setw(8) << rArt.preUni
         << '\n';
    aux = aux->sgte;
  }
}  // ListarOrdDescrip

void GrabarIdxCodArt(ofstream &ldxCodArt, tListaCA &ListaCodArt) {
  tInfoCA info;
  while (ListaCodArt != NULL) {
    ldxCodArt.write((char *)&ListaCodArt->info, sizeof(tInfoCA));
    SacarPrimerNodo(ListaCodArt, info);
  }
}  // GrabarIdxCodArt
