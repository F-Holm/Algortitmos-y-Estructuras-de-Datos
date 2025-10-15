/*************
*	Id.Programa: DG5E04GtOpc1.hpp
*	Autor......: Lic. Hugo Cuello
*	Fecha......: octubre-2014
*	Comentario.: Modulos de Listas dinamicas, con:
*							 ListaMes INFO:
*                tListaDia pSlstDia.
*							 ListaDia INFO:
*                float ImpAcum.
*							 Ambas estructuras Pre-Armadas.
*							 Polimorfismo en SobreCarga Funcional,
*              Programa: --> G5Ej04aListaSubLstOpc1.Cpp
**************/

typedef unsigned char byte;
typedef struct        sNodoMes *tListaMes;
typedef struct        sNodoDia *tListaDia;
typedef float         tInfoDia;
typedef tListaDia     tInfoMes;

struct sNodoMes {
	tInfoMes  pSlstDia;
	tListaMes Sgte;
};

struct sNodoDia {
	tInfoDia  ImpAcum;
	tListaDia Sgte;
};

tListaMes BuscarPosNodo(tListaMes &LstM, byte mes) {
  tListaMes pAct;

  pAct = LstM;
  for (register i = 1; i < mes; i++)
    pAct = pAct->Sgte;
  return pAct;
} // BuscarPosNodo

tListaDia BuscarPosNodo(tListaDia &LstD, byte dia) {
  tListaDia pAct;

  pAct = LstD;
  for (register i = 1; i < dia; i++)
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
	pNodo->ImpAcum = valor;
	pNodo->Sgte = LstD;
	LstD = pNodo;
} // InsertaInicio

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
	valor = LstD->ImpAcum;
	LstD = LstD->Sgte;
	delete pElim;
} // SacarPrimerNodo
