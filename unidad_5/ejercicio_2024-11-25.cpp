// Unidad 5 - Ejercicio 2024-11-25
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

const short CANT_FIGS = 20;
typedef char str20[21];
typedef char str10[11];

struct sResp {
  str10 nomAlum;
  bool rtaCorrecta;
  str20 nomFG;
};

struct tInfo {
  str10 nomAlum;
  bool rtaCorrecta;
};

struct sNodo {
  tInfo info;
  sNodo *sgte;
};

typedef struct sNodo *tLista;

struct sFig {
  str20 nomFG;
  tLista nomAlum;
};

typedef struct sFig tvrCalc[CANT_FIGS];

void ProcNomFig(ifstream &NomFG, tvrCalc vrCalc);
void ProcRespAlum(ifstream &RespAlu, tvrCalc vrCalc, ofstream &ExaAlu);
void EmitirResulta2(tvrCalc vrCalc, ofstream &ExaAlu);
void ReInsertaNodo(tLista &Lista, tLista Nodo);
void ReOrdenar(tLista &Lista);

int main() {
  ;
  return 0;
}  // main

void ProcNomFig(ifstream &NomFG, tvrCalc vrCalc) {
  sFig rFig;
  rFig.nomAlum = NULL;
  while (NomFG.read(rFig.nomFG, sizeof(rFig.nomFG))) {
    InsertarEnOrden(vrCalc, rFig.nomFG, CANT_FIGS);
  }
}  // ProcNomFig

void ProcRespAlum(ifstream &RespAlu, tvrCalc vrCalc, ofstream &ExaAlu) {
  sResp rResp;
  str10 nomAlum;
  tInfo info;
  RespAlu.read((char *)&rResp, sizeof(sResp));
  cout << "Alumno/a             cResp.Cor. cResp.InCor. Evaluacion\n" while (
      RespAlu.eof()) {
    int cantCorrectas = 0, cantIncorrectas = 0;
    strcpy(info.nomAlum, rResp.nomAlum);
    do {
      if (rResp.rtaCorrecta)
        cantCorrectas++;
      else
        cantIncorrectas++;
      info.rtaCorrecta = rResp.rtaCorrecta;
      InsertaInicio(vrCalc[BusBinVec(vrCalc, rResp.nomFG, CANT_FIGS)].nomAlum,
                    info);

    } while (RespAlu.read((char *)&rResp, sizeof(sResp)) &&
             strcmp(info.nomAlum, rResp.nomAlum) == 0);

    cout << setw(20) << rResp.nomAlum << "     " << setw(2) << cantCorrectas
         << "         " << setw(2) << cantIncorrectas << "     "
         << (cantCorrectas > cantIncorrectas ? "Excelente" : "Lo lamento")
         << '\n';
  }
}  // ProcRespAlum

void EmitirResulta2(tvrCalc vrCalc, ofstream &ExaAlu) {
  for (int i = 0; i < CANT_FIGS; i++) {
    ReOrdenar(vrCalc[i].nomAlum);
    cout << "Nombre Figura: " << vrCalc[i].nomFG
         << "\nNombre del alumno/a  Respuesta\n";
    tLista aux = vrCalc[i].nomAlum;
    while (aux != NULL) {
      cout << setw(20) << aux->info.nomAlum << "  " << aux->info.rtaCorrecta
           << ' ' << (aux->info.rtaCorrecta ? "bien" : "mal") << '\n';
      aux = aux->sgte;
    }
  }
}  // EmitirResulta2

void ReInsertaNodo(tLista &Lista, tLista Nodo) {
  if (Lista == NULL || strcmp(Lista->info.nomAlum, Nodo->info.nomAlum) > 0)
    EnlazaInicio(Lista, Nodo);
  else
    EnlazaEnMedio(Lista, Nodo);
}  // ReInsertaNodo

void ReOrdenar(tLista &Lista) {
  tLista pNodo, aux = NULL;
  while (Lista != NULL) {
    pNodo = Lista;
    Lista = Lista->sgte;
    ReInsertaNodo(aux, pNodo);
  }
  Lista = aux;
}  // ReOrdenar
