/*************
*	Id.Programa: DG5E04GtLstU.hpp
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
*              Programa: --> G5Ej04gListaMesDia.Cpp
**************/

typedef unsigned short word;
typedef float tInfoMD;
typedef struct sNodoMD *tListaMD;
struct sNodoMD {
	tInfoMD  ImpAcum;
	tListaMD Sgte;
};

tListaMD BuscarPosNodo(tListaMD LstMD, word diaAcum) {
  tListaMD pAct;

  pAct = LstMD;
  for (register i = 1; i < diaAcum; i++)
    pAct = pAct->Sgte;
  return pAct;
} // BuscarPosNodo

void InsertaInicio(tListaMD &LstMD, tInfoMD valor) {
	tListaMD pNodo;

	pNodo = new sNodoMD;
	pNodo->ImpAcum = valor;
	pNodo->Sgte = LstMD;
	LstMD = pNodo;
} // InsertaInicio

void SacarPrimerNodo(tListaMD &LstMD, tInfoMD &valor) {
	tListaMD pElim;

	pElim = LstMD;
	valor = LstMD->ImpAcum;
	LstMD = LstMD->Sgte;
	delete pElim;
} // SacarPrimerNodo
