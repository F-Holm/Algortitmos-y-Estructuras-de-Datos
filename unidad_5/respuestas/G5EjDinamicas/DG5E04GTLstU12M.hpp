/*************
*	Id.Programa: DG5E04GtLstU12M.hpp
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
*              Programa: --> G5Ej04iLista12MesesArr.Cpp
**************/

const
  DIAS = 31;

typedef unsigned char byte;
typedef unsigned short word;
typedef float tInfoMD[DIAS + 1];
typedef struct sNodoMD *tListaMD;

struct sNodoMD {
	tInfoMD  vImpAcum;
	tListaMD Sgte;
};

tListaMD BuscarPosNodo(tListaMD LstMD, byte mes) {
  tListaMD pAct;

  pAct = LstMD;
  for (register i = 1; i < mes; i++)
    pAct = pAct->Sgte;
  return pAct;
} // BuscarPosNodo

void InsertaInicio(tListaMD &LstMD, tInfoMD valor) {
	tListaMD pNodo;

	pNodo = new sNodoMD;
	for (register i = 0; i <= DIAS; i++)
	  pNodo->vImpAcum[i] = valor[i];
	pNodo->Sgte = LstMD;
	LstMD = pNodo;
} // InsertaInicio

void SacarPrimerNodo(tListaMD &LstMD, tInfoMD &valor) {
	tListaMD pElim;

	pElim = LstMD;
	for (register i = 0; i <= DIAS; i++)
	  valor[i] = LstMD->vImpAcum[i];
	LstMD = LstMD->Sgte;
	delete pElim;
} // SacarPrimerNodo
