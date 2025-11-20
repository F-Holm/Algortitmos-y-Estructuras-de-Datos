// Unidad 5 - Ejercicio 2024-11-11
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

const short CANT_FIGS = 20;

typedef char str20;
typedef char str10;
typedef short tInfo;

struct sFig {
  str20 nomFG;
  tInfo *info;
};

struct sResp {
  str10 nomAlum;
  bool rtaCorrecta;
  str20 nomFG;
};

struct sNodo {
  tInfo info;
  sNodo *sgte;
};

typedef struct sNodo *tListaNomFG;
typedef sFig tvrCalc[CANT_FIGS];

int main() {
  ;
  return 0;
}

void ProcNomFig(ifstream &NomFG, tvrCalc vrCalc, tListaNomFG &ListaFG) {
  str20 figura;
  while (NomFG.read(&figura, sizeof(str20))) {
  }
}

void ProcRespAlum(ifstream &RespAlu, tListaNomFG &ListaFG, tvrCalc vrCalculos,
                  ofstream &ExaAlu) {
}

void EmitirResulta2(tListaNomFG &ListaFG, tvrCalc vrCalc, ofstream &ExaAlu) {
}
