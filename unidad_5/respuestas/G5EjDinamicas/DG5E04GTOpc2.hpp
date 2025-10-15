/*************
*	Id.Programa: DG5E04GtOpc2.hpp
*	Autor......: Lic. Hugo Cuello
*	Fecha......: octubre-2014
*	Comentario.: Modulos de Listas dinamicas, con:
*							 ListaMes pre-Armada.
*                INFO:
*                      tListaDia pSlstDia.
*							 ListaDia sin pre-Armar.
*                INFO:
*                      byte  Dia
*                      float ImpAcum.
*							 Polimorfismo en SobreCarga Funcional,
*              Programa: --> G5Ej04bListaSubLstOpc2.Cpp
**************/

typedef unsigned char byte;
typedef struct        sNodoMes *tListaMes;
typedef struct        sNodoDia *tListaDia;
typedef tListaDia     tInfoMes;

struct tInfoDia {
  byte  Dia;
  float ImpAcum;
};

struct sNodoMes {
	tInfoMes  pSlstDia;
	tListaMes Sgte;
};

struct sNodoDia {
	tInfoDia  Info;
	tListaDia Sgte;
};

tListaMes BuscarPosNodo(tListaMes &LstM, byte mes) {
  tListaMes pAct;

  pAct = LstM;
  for (register i = 1; i < mes; i++)
    pAct = pAct->Sgte;
  return pAct;
} // BuscarPosNodo

void InsertaInicio(tListaMes &LstM, tListaDia valor) {
	tListaMes pNodo;

	pNodo = new sNodoMes;
	pNodo->pSlstDia = valor;
	pNodo->Sgte = LstM;
	LstM = pNodo;
} // InsertaInicio

void InsertaInicio(tListaDia &LstD, tInfoDia valor) {
	tListaDia pNodo;

	pNodo = new sNodoDia;
	pNodo->Info = valor;
	pNodo->Sgte = LstD;
	LstD = pNodo;
} // InsertaInicio

tListaDia iif(bool exprLog, tListaDia ptr1, tListaDia ptr2) {
	if (exprLog)
		return ptr1;
	else
		return ptr2;
} // iif

tListaDia ExisteNodo(tListaDia &LstD,tListaDia &pAnt,byte dia) {
	tListaDia pAct;

	pAnt = NULL;
	pAct = LstD;
	while (pAct != NULL && dia > pAct->Info.Dia) {
		pAnt = pAct;
		pAct = pAct->Sgte;
	}
	return iif(pAct && dia == pAct->Info.Dia,pAct,NULL);
} // ExisteNodo

void CrearNodo(tListaDia &LstD, tListaDia &pAnt, tInfoDia valor) {
	tListaDia pNodo;

	if (!pAnt)
		InsertaInicio(LstD,valor);
	else {
		pNodo = new sNodoDia;
		pNodo->Info = valor;
		pNodo->Sgte = pAnt->Sgte;
		pAnt->Sgte = pNodo;
	}
} // CrearNodo

void SacarPrimerNodo(tListaMes &LstM, tInfoMes &valor) {
	tListaMes pElim;

	pElim = LstM;
	valor = LstM->pSlstDia;
	LstM = LstM->Sgte;
	delete pElim;
} // SacarPrimerNodo

void SacarPrimerNodo(tListaDia &LstD, tInfoDia &valor) {
	tListaDia pElim;

	pElim = LstD;
	valor = LstD->Info;
	LstD = LstD->Sgte;
	delete pElim;
} // SacarPrimerNodo
