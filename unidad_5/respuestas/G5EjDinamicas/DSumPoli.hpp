/*************
*	Id.Programa: dSumPoli.h
*	Autor......: Lic. Hugo Cuello
*	Fecha......: nov-2013
*	Comentario.: Modulos de Dinamica para usar con el
*							 programa G5Ej08SumaPoli.Cpp
**************/

struct tInfo {
	short  expo;
	double coef;
};

typedef struct sNodo* tLista;
struct sNodo {
	tInfo  Info;
	tLista Sgte;
};

void InsertaInicio(tLista &Lista, tInfo valor) {
	tLista pNodo;

	pNodo = new sNodo;
	pNodo->Info = valor;
	pNodo->Sgte = Lista;
	Lista = pNodo;
} // InsertaInicio

void InsertaEnMedio(tLista &Lista, tInfo valor) {
	tLista pAct,
			   pNodo;

	pNodo = new sNodo;
	pNodo->Info = valor;
	pAct = Lista;
	while (pAct->Sgte && valor.expo < pAct->Sgte->Info.expo)
		pAct = pAct->Sgte;
	pNodo->Sgte = pAct->Sgte;
	pAct->Sgte = pNodo;
} // InsertaEnMedio

void InsertaNodo(tLista &Lista, tInfo valor) {
	if (!Lista || valor.expo > Lista->Info.expo)
		InsertaInicio(Lista,valor);
	else
		InsertaEnMedio(Lista,valor);
} // InsertaNodo

void SacarPrimerNodo(tLista &Lista, tInfo &valor) {
	tLista pElim;

	pElim = Lista;
	valor = Lista->Info;
	Lista = Lista->Sgte;
	delete pElim;
} // SuprimePrimerNodo

void AgregarNodo(tLista &Lista, tLista &ListaFin, tInfo valor) {
	tLista pNodo;

	pNodo = new sNodo;
	pNodo->Info = valor;
	pNodo->Sgte = NULL;
	if (!Lista)
		Lista = pNodo;
	else
		ListaFin->Sgte = pNodo;
	ListaFin = pNodo;
} // AgregarNodo
