/*
  Id.Programa: Prototipos de EDD y desarrollo de alguanss funciones.cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: octubre-2024
  Comentario.: Se indican los prototipos de funciones para las
                 Estructuras Dinamicas de Datos y desarrollo de
                 algunas de ellas.
                 Las que no esten desarrolladas, es porque estan
                 desarrolladas en los ejercicios resueltos en las clases.
*/

typedef struct tInfo {
  word clv;
  long ref;
};

typedef struct tNodo * tLista; // ord. x clv
typedef struct tNodo {
	tInfo  Info;
	tLista Sgte;
};

// Prototipos para E.D.D.

void Push(tPila &Pila, tInfo valor);
void Pop(tPila &Pila, tInfo &valor);
void Enqueue(tCola &cFte, tCola &cFin, tInfo valor);
void Dequeue(tCola &cFte, tCola &cFin, tInfo &valor);
void InsertaInicio(tLista &Lista, tInfo valor);
void InsertaEnMedio(tLista &Lista, tInfo valor);
void InsertaNodo(tLista &Lista, tInfo valor);
void SuprimeNodo(tLista &Lista, tInfo valor);
void SuprimeNodo(tLista &Lista, tInfo &valor);  // tInfo es un registro
void SacarPrimerNodo(tLista &Lista, tInfo &valor);
tLista BuscarPosNodo(tLista &Lista, byte pos);
tLista BuscarClvNodo(tLista &Lista, byte clv); { // Lista desordenada
tLista ExisteNodo(tLista &Lista,tLista &pAnt, byte clv);
void CrearNodo(tLista &Lista, tLista &pAnt, tInfo valor);

void InsertaEnLugar(tLista &pNodo, tInfo valor);                          (*)
void AgregarUltimoNodo(tLista &Lista, tLista &ListaFin, tInfo valor);     (*)
void InsertaUltimoNodo(tLista &Lista, tInfo valor);                       (*)
void EnlazaInicio(tLista &Lista, tLista &pNodo);                          (*)
void EnlazaEnMedio(tLista &Lista, tLista &pNodo);                         (*)

void ReInsertaNodo(tLista &Lista, tLista &pNodo);
void ReOrdenar(tLista &Lista);
tLista iif(bool exprLog, tLista ptr1, tLista ptr2);
tLista BuscarClvNodo(tLista &Lista, byte clv); { // Lista ordenada

void SuprimeNodoEnLugar(tLista &Lista, tLista &pAnt, tInfo &valor);       (*)
void SacarNodoEnLugar(tLista &Lista, tInfo &valor);                       (*)


// Desarrollo de algunas funciones de EDD de las indicadas con  (*)

void InsertaEnLugar(tLista &pNodo, tInfo valor) {
  tLista pNvo = new tNodo;

  pNvo->rInfo = valor;
  pNvo->sgte = pNodo->sgte;
  pNodo->sgte = pNvo;
} //InsertaEnLugar

void AgregarUltimoNodo(tLista &Lista, tLista &ListaFin, tInfo valor) {
  tLista pNvo = new tNodo;

  pNvo->Info = valor;
  pNvo->sgte = NULL;
  if (!Lista)
    Lista = pNvo;
  else
    ListaFin->sgte = pNvo;
  ListaFin = pNvo;
} // AgregarUltimoNodo

void InsertaUltimoNodo(tLista &Lista, tInfo valor) {
  tLista pAct;
         pNvo = new tNodo;

  pNvo->Info = valor;
  pNvo->sgte = NULL;
  if (!Lista)
    Lista = pNvo;
  else {
    pAct = Lista;
    while (pAct->sgte)
      pAct = pAct->sgte;
    pAct->sgte = pNvo;
  }
} // InsertaUltimoNodo

void EnlazaInicio(tLista &Lista, tLista &pNodo) {
    pNodo->sgte = Lista;
    Lista = pNodo;
} // EnlazaInicio

void EnlazaEnMedio(tLista &Lista, tLista &pNodo) {
  tLista pAct = Lista;
  while (pAct->sgte && pNodo->Info.clv > pAct->sgte->Info.clv)
    pAct = pAct->sgte;
  pNodo->sgte = pAct->sgte;
  pAct->sgte = pNodo;
}  // EnlazaEnMedio

void SuprimeNodoEnLugar(tLista &Lista, tLista &pAnt, tInfo &valor) {
  if (!pAnt)
    SacarPrimerNodo(Lista,valor);
  else
    SacarNodoEnLugar(pAnt,valor);
} //SuprimeNodoEnLugar

void SacarNodoEnLugar(tLista &Lista, tInfo &valor) {
  tLista pElim = Lista->Sgte;

  valor = Lista->Sgte->rInfo;
  Lista->sgte = Lista->sgte->sgte;
  delete pElim;
} //SacarNodoEnLugar
