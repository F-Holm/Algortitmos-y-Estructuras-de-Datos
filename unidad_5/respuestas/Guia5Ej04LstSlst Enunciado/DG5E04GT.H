/*
	Id.Programa: DG5E04Gt.Cpp
	Autor......: Prof. Hugo Cuello
	Fecha......: oct-2013
	Comentario.: Modulos de Listas dinamicas, con:
							 ListaMes INFO: byte Mes, tListaDia SlstDia.
							 ListaDia INFO: byte Dia, float ImpAcu.
							 Ambas estructuras sin Pre-Armar.
							 Polimorfismo en SobreCarga Funcional.
*/

typedef unsigned short byte;
typedef unsigned short bool;

typedef struct tInfoDia {
	byte  Dia;
	float ImpAcu;
};

typedef struct tNodoDia *tListaDia;
typedef struct tNodoDia {
	tInfoDia  Info;
	tListaDia Sgte;
};

typedef struct tInfoMes {
	byte      Mes;
	tListaDia SlstDia;
};

typedef struct tNodoMes* tListaMes;
typedef struct tNodoMes {
	tInfoMes  Info;
	tListaMes Sgte;
};

tListaMes iif(bool exprLog, tListaMes ptr1, tListaMes ptr2) {
	if (exprLog)
		return ptr1;
	else
		return ptr2;
} //iif

tListaDia iif(bool exprLog, tListaDia ptr1, tListaDia ptr2) {
	if (exprLog)
		return ptr1;
	else
		return ptr2;
} //iif

tListaMes ExisteNodo(tListaMes &Lista,tListaMes &pAnt,byte mes) {
	tListaMes pAct;

	pAnt = NULL;
	pAct = Lista;
	while (pAct != NULL && mes > pAct->Info.Mes) {
		pAnt = pAct;
		pAct = pAct->Sgte;
	}
	return iif(pAct != NULL && mes == pAct->Info.Mes,pAct,NULL);
} //ExisteNodo

tListaDia ExisteNodo(tListaDia &Lista,tListaDia &pAnt,byte dia) {
	tListaDia pAct;

	pAnt = NULL;
	pAct = Lista;
	while (pAct != NULL && dia > pAct->Info.Dia) {
		pAnt = pAct;
		pAct = pAct->Sgte;
	}
	return iif(pAct != NULL && dia == pAct->Info.Dia,pAct,NULL);
} //ExisteNodo

void InsertaInicio(tListaMes &Lista, tInfoMes valor) {
	tListaMes pNodo;

	pNodo = new tNodoMes;
	pNodo->Info = valor;
	pNodo->Sgte = Lista;
	Lista = pNodo;
} //InsertaInicio

void InsertaInicio(tListaDia &Lista, tInfoDia valor) {
	tListaDia pNodo;

	pNodo = new tNodoDia;
	pNodo->Info = valor;
	pNodo->Sgte = Lista;
	Lista = pNodo;
} //InsertaInicio

void CrearNodo(tListaMes &Lista, tListaMes &pAnt, tInfoMes valor) {
	tListaMes pNodo;

	if (pAnt == NULL)
		InsertaInicio(Lista,valor);
	else {
		pNodo = new tNodoMes;
		pNodo->Info = valor;
		pNodo->Sgte = pAnt->Sgte;
		pAnt->Sgte = pNodo;
	}
} //CrearNodo

void CrearNodo(tListaDia &Lista, tListaDia &pAnt, tInfoDia valor) {
	tListaDia pNodo;

	if (pAnt == NULL)
		InsertaInicio(Lista,valor);
	else {
		pNodo = new tNodoDia;
		pNodo->Info = valor;
		pNodo->Sgte = pAnt->Sgte;
		pAnt->Sgte = pNodo;
	}
} //CrearNodo

void SacarPrimerNodo(tListaMes &Lista, tInfoMes &valor) {
	tListaMes pElim;

	pElim = Lista;
	valor = Lista->Info;
	Lista = Lista->Sgte;
	delete pElim;
} //SacarPrimerNodo

void SacarPrimerNodo(tListaDia &Lista, tInfoDia &valor) {
	tListaDia pElim;

	pElim = Lista;
	valor = Lista->Info;
	Lista = Lista->Sgte;
	delete pElim;
} //SacarPrimerNodo
