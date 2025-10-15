/*************
*	Id.Programa: DG5E04GtArcAuxMesLstDias.hpp
*	Autor......: Lic. Hugo Cuello
*	Fecha......: octubre-2013
*	Comentario.: Modulos de Listas dinamicas, con:
*							 Archivo Auxiliar de Meses de punteros a
*              Lista de días sin pre-Armar.
*							 ListaDia INFO:
*                 byte Dia,
*                 float ImpAcum.
*              Programas: --> G5Ej04lArcAuxMes&12Lst.Cpp
*                         --> G5Ej04mVectorAuxMes&12lst.Cpp
**************/

typedef unsigned char byte;
typedef struct sNodoDia *tListaDia;

struct sInfoDia {
	byte  Dia;
	float ImpAcum;
};

struct sNodoDia {
	sInfoDia  Info;
	tListaDia Sgte;
};

tListaDia iif(bool exprLog, tListaDia ptr1, tListaDia ptr2) {
	if (exprLog)
		return ptr1;
	else
		return ptr2;
} // iif

tListaDia ExisteNodo(tListaDia &Lista,tListaDia &pAnt,byte dia) {
	tListaDia pAct;

	pAnt = NULL;
	pAct = Lista;
	while (pAct != NULL && dia > pAct->Info.Dia) {
		pAnt = pAct;
		pAct = pAct->Sgte;
	}
	return iif(pAct && dia == pAct->Info.Dia,pAct,NULL);
} // ExisteNodo

void InsertaInicio(tListaDia &Lista, sInfoDia valor) {
	tListaDia pNodo;

	pNodo = new sNodoDia;
	pNodo->Info = valor;
	pNodo->Sgte = Lista;
	Lista = pNodo;
} // InsertaInicio

void CrearNodo(tListaDia &Lista, tListaDia &pAnt, sInfoDia valor) {
	tListaDia pNodo;

	if (!pAnt)
		InsertaInicio(Lista,valor);
	else {
		pNodo = new sNodoDia;
		pNodo->Info = valor;
		pNodo->Sgte = pAnt->Sgte;
		pAnt->Sgte = pNodo;
	}
} // CrearNodo

void SacarPrimerNodo(tListaDia &Lista, sInfoDia &valor) {
	tListaDia pElim;

	pElim = Lista;
	valor = Lista->Info;
	Lista = Lista->Sgte;
	delete pElim;
} // SacarPrimerNodo
