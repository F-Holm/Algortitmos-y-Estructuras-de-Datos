/*
	Id.Programa: SumaPoli.Cpp
	Autor......: Prof. Hugo Cuello
	Fecha......: nov-2013
	Comentario.: Genera en forma arbitraria y al azar terminos de
							 polinomios P y Q, ord. x expo descendente.
							 Se pide:
								 Realizar la suma de P + Q --> R
*/

#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include "h:\tc\prgsftes\dSumPoli.h"

#define LOW_VALUE -1

void ObTerPoli(tInfo &valor, char NomPoli) {
	clrscr();
	gotoxy(10,1);
	cout << "Datos de un termino del Polinomio " << NomPoli;
	gotoxy(15,5);
	cout << "expo: ";
	cin >> valor.expo;
	gotoxy(15,7);
	cout << "coef: ";
	cin >> valor.coef;
} // ObTerPoli

char Menu() {
	char opc;

	clrscr();
	gotoxy(10,1),
	cout << "Suma de Polinomios";
	gotoxy(15,5);
	cout << "1: Termino P";
	gotoxy(15,7);
	cout << "2: Termino Q";
	gotoxy(15,9);
	cout << "3: Salir";
	gotoxy(20,12);
	cout << "Su Opcion: ";
	do
		opc = getche();
	while (!(opc>='1' && opc<='3'));
	return opc;
} // Menu

void LecEspLst(tLista &Px, tInfo &valor) {
	if (Px != NULL)
		SacarPrimerNodo(Px,valor);
	else
		valor.expo = LOW_VALUE;
} // LecEspLst

void SumarPoli(tLista &P, tLista &Q, tLista &R) {
	tLista RFin;
	tInfo rInfoP,
				rInfoQ,
				rInfoR;

	RFin = NULL;
	LecEspLst(P,rInfoP);
	LecEspLst(Q,rInfoQ);
	while (rInfoP.expo != LOW_VALUE || rInfoQ.expo != LOW_VALUE)
		if (rInfoP.expo == rInfoQ.expo) {
			rInfoR.expo = rInfoP.expo;
			rInfoR.coef = rInfoP.coef + rInfoQ.coef;
			AgregarNodo(R,RFin,rInfoR);
			LecEspLst(P,rInfoP);
			LecEspLst(Q,rInfoQ);
		}
		else
			if (rInfoP.expo > rInfoQ.expo) {
				AgregarNodo(R,RFin,rInfoP);
				LecEspLst(P,rInfoP);
			}
			else {
				AgregarNodo(R,RFin,rInfoQ);
				LecEspLst(Q,rInfoQ);
			}
} // SumarPoli

void EmitirPoli(tLista &Px, char NomPoli) {
	tLista PxAux;

	cout << endl << NomPoli << " = ";
	PxAux = Px;
	while (PxAux != NULL) {
		cout << PxAux->Info.coef << " ";
		if (PxAux->Info.expo > 0)
			cout << "x^" << PxAux->Info.expo << " +";
		PxAux = PxAux->Sgte;
	}
	cout << '\b' << " Enter para continuar...";
	getch();
} // EmitirPoli

void LiberarNodos(tLista &Px) {
	tInfo valor;

	while (Px != NULL)
		SacarPrimerNodo(Px,valor);
} // LiberarNodos

void main() {
	tLista P,Q,R;
	tInfo  valor;
	char   opc;

	P = Q = R = NULL;
	do {
		opc = Menu();
		switch (opc) {
			case '1':
				ObTerPoli(valor,'P');
				InsertaNodo(P,valor);
				break;
			case '2':
				ObTerPoli(valor,'Q');
				InsertaNodo(Q,valor);
				break;
		}
	}
	while (opc != '3');
	EmitirPoli(P,'P');
	EmitirPoli(Q,'Q');
	SumarPoli(P,Q,R);
	EmitirPoli(R,'R');
	LiberarNodos(R);
} // main
