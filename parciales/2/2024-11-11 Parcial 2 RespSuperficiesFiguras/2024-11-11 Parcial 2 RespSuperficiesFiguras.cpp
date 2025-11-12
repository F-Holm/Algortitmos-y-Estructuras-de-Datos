/*
   Id.Programa: 2024-11-11 Parcial 2 RespSuperficiesFiguras.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: agosto-2024
   Comentario.: Archivos Binarios de Datos:
                  NomFiguras.Dat
                  RespAlumnos.Dat
                Se pide:
                  1: Emitir por cada alumno/a la cantidad de resp.Cor. e Incor.
                  2: Emitir por cada Figura Geometrica las cant. totales
                       resp.Cor e Incor. ord. x Nombre Figura Geometrica.
                Estructuras de Datos:
                  1: Vector de Registro[20] (nomFG, ptr. a var.dinam.
                                             para contar cant. resp.Cor.)
                  2: Lista de Fig.Geom. con info para contar cant. resp.Incor.
                       Para localizar el nodo que se corresp. con el nombre
                       de la fig. geom. la posicion en el vector de ese nombre
                       sera la posicion en la lista.
    Compilador: Borland V. 5.5
*/

#define record struct
#include <iomanip>
#include <fstream>
using namespace std;

const CANT_FIG = 20;

typedef char str20[21];
typedef char str10[11];
typedef short tInfo;

record sFig {
  str20  nomFig;
  tInfo* pVarDin;
};

typedef sFig tvrCalc[CANT_FIG];

typedef record sNodo * tListaNomFG;

record sNodo {
  tInfo       cantResp;
  tListaNomFG sgte;
};

record sResp {
  str10 nomAlu;
  bool  EsRespCor; // Si EsRespCor es true (valor 1) sino es false (valor 0).
  str20 nomFig;
};

void Abrir(ifstream &NomFigs, ifstream &RespAlu, ofstream &ExaAlu) {
  NomFigs.open("NombresFiguras.Dat");
  RespAlu.open("RespuestasAlumnos.Dat");
  ExaAlu.open ("ExamenAlumnos.Txt");
} // Abrir

void Cerrar(ifstream &NomFigs, ifstream &RespAlu, ofstream &ExaAlu) {
  NomFigs.close();
  RespAlu.close();
  ExaAlu.close();
} // Cerrar

void IntCmb(sFig &elem1, sFig &elem2) {
	sFig aux = elem1;

	elem1 = elem2;
	elem2 = aux;
} // IntCmb

void OrdxBur(tvrCalc vrCalc, short Card) {
  bool  ordenado;
  short k = 0;

  do {
    ordenado = true;
    k++;
    for (short i = 0; i < Card - k; i++)
	  if (strcmp(vrCalc[i].nomFig,vrCalc[i+1].nomFig) > 0) {
		IntCmb(vrCalc[i],vrCalc[i+1]);
        ordenado = false;
      }
  } while (!ordenado);
} // OrdxBur

void InsertaInicio(tListaNomFG &Lista, tInfo valor) {
  tListaNomFG pNvo = new sNodo;

  pNvo->cantResp = valor;
  pNvo->sgte = Lista;
  Lista = pNvo;
} // InsertaInicio

short BusBinVec(tvrCalc vCI, str20 nomFig, short ult) {
  short pri = 0,
        med;

  ult--;
  while (pri <= ult) {
    med = (pri + ult) / 2;
	if (strcmp(vCI[med].nomFig,nomFig) == 0)
	  return med;
    else
	  if (strcmp(vCI[med].nomFig,nomFig) < 0)
		pri = med + 1;
      else
		ult = med - 1;
  }
  return -1;
} // BusBinVec

tListaNomFG BuscarPosNodo(tListaNomFG &Lista, short pos) {
	tListaNomFG pAct = Lista;

	for (short i = 1; i <= pos; i++)
      pAct = pAct->sgte;
	return pAct;
} // BuscarPosNodo

void SacarPrimerNodo(tListaNomFG &Lista, tInfo &valor) {
  tListaNomFG pElim = Lista;

  valor = Lista->cantResp;
  Lista = Lista->sgte;
  delete pElim;
} // SacarPrimerNodo

void ProcNomFig(ifstream &NomFG, tvrCalc vrCalc, tListaNomFG &ListaFG) {
  sFig  rFig;
  short i = 0;

  while (NomFG.read(rFig.nomFig, sizeof rFig.nomFig)) {
    rFig.pVarDin = new tInfo;
    *rFig.pVarDin = 0;
    vrCalc[i++] = rFig;
    InsertaInicio(ListaFG,0);
  }
  OrdxBur(vrCalc,i);
} // PocNomFig

void ProcRespAlum(ifstream &RespAlu, tListaNomFG &ListaFG, tvrCalc vrCalculos,
                  ofstream &ExaAlu) {
  sResp       rResp;
  str20       nomAluAnt;
  short       cRespC,
              cRespI,
              posV;
  tListaNomFG pNodoFig;

  ExaAlu << "Examenes de Superficies de Figuras Geometricas" << endl;
  ExaAlu << "Alumno/a   cResp.Cor. cResp.InCor. Evaluacion" << endl;
  RespAlu.read((char *) &rResp, sizeof rResp);
  while (!RespAlu.eof()) {
    cRespC = cRespI = 0;
    strcpy(nomAluAnt,rResp.nomAlu);
    while (!RespAlu.eof() && strcmp(rResp.nomAlu,nomAluAnt) == 0) {
      posV = BusBinVec(vrCalculos,rResp.nomFig,CANT_FIG);
      if (rResp.EsRespCor) {
        cRespC++;
        (*vrCalculos[posV].pVarDin)++;
      }
      else {
        cRespI++;
        pNodoFig = BuscarPosNodo(ListaFG,posV);
        pNodoFig->cantResp++;
      }
      RespAlu.read((char *) &rResp, sizeof rResp);
    }
    ExaAlu << setw(10) << nomAluAnt << setw(7) << cRespC << setw(11) << cRespI;
    if (cRespC > cRespI)
      ExaAlu << setw(7) << ' ' << "Excelente" << endl;
    else
      ExaAlu << setw(7) << ' ' << "Lo lamento" << endl;
  } // fin while not eof
} // ProcRespAlum

void EmitirResulta2(tListaNomFG &ListaFG, tvrCalc vrCalc, ofstream &ExaAlu) {
  tInfo cantResp;

  ExaAlu << endl;
  ExaAlu << "Listado cant. Resp.Cor. e Incor. por Figuras Geometricas" << endl;
  ExaAlu << "Nombre Figura          cResp.Cor. cResp.Incor" << endl;
  for(short i = 0; i < CANT_FIG; i++) {
    SacarPrimerNodo(ListaFG, cantResp);
    ExaAlu << setw(20) << vrCalc[i].nomFig << ' ';
    ExaAlu << setw( 8) << *vrCalc[i].pVarDin << ' ';
    ExaAlu << setw(10) << cantResp << endl;
    delete vrCalc[i].pVarDin;
  }
} // EmitirResulta2

main() {
  ifstream    NombresFiguras,
              RespAlu;
  ofstream    ExaAlumnos;
  tvrCalc     vrCalculos;
  tListaNomFG ListaNomFG = NULL;

  Abrir(NombresFiguras,RespAlu,ExaAlumnos);
  ProcNomFig(NombresFiguras,vrCalculos,ListaNomFG);
  ProcRespAlum(RespAlu,ListaNomFG,vrCalculos,ExaAlumnos);
  EmitirResulta2(ListaNomFG,vrCalculos,ExaAlumnos);
  Cerrar(NombresFiguras,RespAlu,ExaAlumnos);
  system("notepad ExamenAlumnos.Txt");
  return 0;
}
