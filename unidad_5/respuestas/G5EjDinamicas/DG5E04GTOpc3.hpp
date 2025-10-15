/*************
*	Id.Programa: DG5E04GtOpc3.hpp
*	Autor......: Lic. Hugo Cuello
*	Fecha......: octubre-2013
*	Comentario.: Modulos de Listas dinamicas, con:
*							 ListaMes INFO: byte Mes, tListaDia pSlstDia.
*							 ListaDia INFO: byte Dia, float ImpAcum.
*							 Ambas estructuras sin Pre-Armar.
*							 Polimorfismo en SobreCarga Funcional,
*              Programa: --> G5Ej04cListaSubLstOpc3.Cpp
**************/

typedef unsigned char byte;
typedef struct sNodoMes *tListaMes;
typedef struct sNodoDia *tListaDia;

struct sInfoMes {
	byte      Mes;
	tListaDia pSlstDia;
};

struct sNodoMes {
	sInfoMes  Info;
	tListaMes Sgte;
};

struct sInfoDia {
	byte  Dia;
	float ImpAcu;
};

struct sNodoDia {
	sInfoDia  Info;
	tListaDia Sgte;
};

tListaMes iif(bool exprLog, tListaMes ptr1, tListaMes ptr2) {
	if (exprLog)
		return ptr1;
	else
		return ptr2;
} // iif

tListaDia iif(bool exprLog, tListaDia ptr1, tListaDia ptr2) {
	if (exprLog)
		return ptr1;
	else
		return ptr2;
} // iif

tListaMes ExisteNodo(tListaMes &Lista,tListaMes &pAnt,byte mes) {
	tListaMes pAct;

	pAnt = NULL;
	pAct = Lista;
	while (pAct && mes > pAct->Info.Mes) {
		pAnt = pAct;
		pAct = pAct->Sgte;
	}
	return iif(pAct && mes == pAct->Info.Mes,pAct,NULL);
} // ExisteNodo

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

void InsertaInicio(tListaMes &Lista, sInfoMes valor) {
	tListaMes pNodo;

	pNodo = new sNodoMes;
	pNodo->Info = valor;
	pNodo->Sgte = Lista;
	Lista = pNodo;
} // InsertaInicio

void InsertaInicio(tListaDia &Lista, sInfoDia valor) {
	tListaDia pNodo;

	pNodo = new sNodoDia;
	pNodo->Info = valor;
	pNodo->Sgte = Lista;
	Lista = pNodo;
} // InsertaInicio

void CrearNodo(tListaMes &Lista, tListaMes &pAnt, sInfoMes valor) {
	tListaMes pNodo;

	if (!pAnt)
		InsertaInicio(Lista,valor);
	else {
		pNodo = new sNodoMes;
		pNodo->Info = valor;
		pNodo->Sgte = pAnt->Sgte;
		pAnt->Sgte = pNodo;
	}
} // CrearNodo

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

void SacarPrimerNodo(tListaMes &Lista, sInfoMes &valor) {
	tListaMes pElim;

	pElim = Lista;
	valor = Lista->Info;
	Lista = Lista->Sgte;
	delete pElim;
} // SacarPrimerNodo

void SacarPrimerNodo(tListaDia &Lista, sInfoDia &valor) {
	tListaDia pElim;

	pElim = Lista;
	valor = Lista->Info;
	Lista = Lista->Sgte;
	delete pElim;
} // SacarPrimerNodo
