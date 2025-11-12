/*
   Id.Programa: 2024-11-25 Recup1-Parc2 RespSuperficiesFiguras.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: octubre-2024
   Comentario.: Archivos Binarios de Datos:
                  NomFiguras.Dat desordenado con nombres de figuras geometricas.
                  RespAlumnos.Dat con nomAlum, EsRespCor, nomFig.
                Se pide:
                  1: Emitir por cada alumno/a la cantidad de resp.Cor. e Incor.
                       y mensaje de acuerdo al resultado evaluado.
                  2: Emitir por cada Figura Geometrica las cant. totales
                       resp.Cor e Incor. ord. x Nombre Figura Geometrica.
                Estructuras de Datos:
                     sFig vrCalculos[20] con campos de sFig:
                       nomFG, Lista de nomAlum.
                     en donde el rInfo de Lista contiene los campos:
                       nomAlu, resp.(0: mal, 1: bien).
    Compilador: C++ de Borland V. 5.5.
*/

#define record struct
#include <iomanip>
#include <fstream>
using namespace std;

const CANT_FIG = 20;

typedef char str20[21];
typedef char str10[11];

typedef record sNodo * tLista;

record tInfo {
  str10 nomAlu;
  short resp;
};

record sNodo {
  tInfo  rInfo;
  tLista sgte;
};

record sFig {
  str20  nomFig;
  tLista Lista;
};

typedef sFig tvrCalc[CANT_FIG];

record sResp {
  str10 nomAlu;
  bool  EsRespCor; // Si EsRespCor es true (valor 1) sino es false (valor 0).
  str20 nomFig;
};

void Abrir(ifstream &NomFigs, ifstream &RespAlu, ofstream &ExaAlu) {
  NomFigs.open("NombresFiguras.Dat");
  RespAlu.open("RespuestasAlumnos.Dat");
  ExaAlu.open("ExamenAlumnos.Txt");
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

void InsertarEnOrden(tvrCalc vrCalc, sFig rFig, short card) {

	while (card > 0 && strcmp(rFig.nomFig, vrCalc[card - 1].nomFig) < 0) {
		vrCalc[card] = vrCalc[card - 1];
		card--;
	}
	vrCalc[card] = rFig;
} // InsertarEnOrden

void InsertaInicio(tLista &Lista, tInfo valor) {
  tLista pNvo = new sNodo;

  pNvo->rInfo = valor;
  pNvo->sgte = Lista;
  Lista = pNvo;
} // InsertaInicio

void EnlazaInicio(tLista &Lista, tLista &pNodo) {
    pNodo->sgte = Lista;
    Lista = pNodo;
} // EnlazaInicio

void EnlazaEnMedio(tLista &Lista, tLista &pNodo) {
  tLista pAct = Lista;
  while (pAct->sgte && strcmp(pNodo->rInfo.nomAlu,pAct->sgte->rInfo.nomAlu) > 0)
    pAct = pAct->sgte;
  pNodo->sgte = pAct->sgte;
  pAct->sgte = pNodo;
}  // EnlazaEnMedio

void ReInsertaNodo(tLista &Lista, tLista &pNodo) {
  if (!Lista || strcmp(pNodo->rInfo.nomAlu,Lista->rInfo.nomAlu) < 0)
    EnlazaInicio(Lista,pNodo);
  else
    EnlazaEnMedio(Lista,pNodo);
} // ReInsertaNodo

void ReOrdenar(tLista &Lista) {
  tLista ListaAux = NULL,
         pNodo;

  while (Lista) {
    pNodo = Lista;
    Lista = Lista->sgte;
    ReInsertaNodo(ListaAux,pNodo);
  }
  Lista = ListaAux;
} // ReOrdenar

short BusBinVec(tvrCalc vrCalc, str20 nomFig, short ult) {
  short pri = 0,
        med;

  ult--;
  while (pri <= ult) {
    med = (pri + ult) / 2;
	if (strcmp(vrCalc[med].nomFig,nomFig) == 0)
	  return med;
    else
	  if (strcmp(vrCalc[med].nomFig,nomFig) < 0)
		pri = med + 1;
      else
		ult = med - 1;
  }
  return -1;
} // BusBinVec

void SacarPrimerNodo(tLista &Lista, tInfo &valor) {
  tLista pElim = Lista;

  valor = Lista->rInfo;
  Lista = Lista->sgte;
  delete pElim;
} // SacarPrimerNodo

void ProcNomFig(ifstream &NomFG, tvrCalc vrCalc) {
  sFig  rFig;
  short i = 0;

  while (NomFG.read(rFig.nomFig, sizeof rFig.nomFig)) {
    rFig.Lista = NULL;
    InsertarEnOrden(vrCalc,rFig,i);
    i++;
  }
} // ProcNomFig

void ProcRespAlum(ifstream &RespAlu, tvrCalc vrCalc, ofstream &ExaAlu) {
  sResp  rResp;
  str20  nomAluAnt;
  short  cRespC,
         cRespI,
         posV;
  tInfo  rInfo;

  ExaAlu << "Examenes de Superficies de Figuras Geometricas" << endl;
  ExaAlu << "Alumno/a   cResp.Cor. cResp.InCor. Evaluacion" << endl;
  RespAlu.read((char *) &rResp, sizeof rResp);
  while (!RespAlu.eof()) {
    cRespC = cRespI = 0;
    strcpy(nomAluAnt,rResp.nomAlu);
    while (!RespAlu.eof() && strcmp(rResp.nomAlu,nomAluAnt) == 0) {
      posV = BusBinVec(vrCalc,rResp.nomFig,CANT_FIG);
      strcpy(rInfo.nomAlu,rResp.nomAlu);
      if (rResp.EsRespCor)
        cRespC++;
      else
        cRespI++;
      rInfo.resp = rResp.EsRespCor;
      InsertaInicio(vrCalc[posV].Lista,rInfo);
      RespAlu.read((char *) &rResp, sizeof rResp);
    }
    ExaAlu << setw(10) << nomAluAnt << setw(7) << cRespC << setw(11) << cRespI;
    if (cRespI < cRespC)
      ExaAlu << setw(7) << ' ' << "Excelente" << endl;
    else
      ExaAlu << setw(7) << ' ' << "Lo lamento" << endl;
  }
} // ProcRespAlum

void EmitirResulta2(tvrCalc vrCalc, ofstream &ExaAlu) {
  tInfo rInfo;
  short cRespC,
        cRespI,
        totRespC = 0,
        totRespI = 0;

  ExaAlu << endl;
  ExaAlu << "Listado cant. Resp.Cor. e Incor. por Figuras Geometricas" << endl;
  for(short i = 0; i < CANT_FIG; i++) {
    ExaAlu << left << vrCalc[i].nomFig << endl;
    cRespC = cRespI = 0;
    ReOrdenar(vrCalc[i].Lista);
    ExaAlu << "Nombre Alumno Respuesta" << endl;
    while (vrCalc[i].Lista) {
      SacarPrimerNodo(vrCalc[i].Lista, rInfo);
      ExaAlu << setw(10) << rInfo.nomAlu << ' ' << setw(3) << ' ' << rInfo.resp;
      if (rInfo.resp) {
        ExaAlu << " bien" << endl;
        cRespC++;
      }
      else {
        ExaAlu << " mal" << endl;
        cRespI++;
      }
    }
    totRespC += cRespC;
    totRespI += cRespI;
    ExaAlu << "Total Figura: " << setw(20) << vrCalc[i].nomFig << ' ';
    ExaAlu << "bien: " << setw(2) << cRespC
           << "mal.: " << setw(2) << cRespI << endl << endl;
  }
  ExaAlu << endl;
  ExaAlu << "Tot.Resp.Correctas  : " << totRespC << endl;
  ExaAlu << "Tot.Resp.InCorrectas: " << totRespI << endl;
} // EmitirResulta2

main() {
  ifstream NombresFiguras,
           RespAlu;
  ofstream ExaAlumnos;
  tvrCalc  vrCalculos;

  Abrir(NombresFiguras,RespAlu,ExaAlumnos);
  ProcNomFig(NombresFiguras,vrCalculos);
  ProcRespAlum(RespAlu,vrCalculos,ExaAlumnos);
  EmitirResulta2(vrCalculos,ExaAlumnos);
  Cerrar(NombresFiguras,RespAlu,ExaAlumnos);
  system("ExamenAlumnos.Txt"); // Asume x defecto la app. Bloc de Notas notepad.
  return 0;
} // main
