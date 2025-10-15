/*
	Id. Programa: G5-E04.Cpp
	Autor.......: Prof. Hugo Cuello
	Fecha.......: oct-2013
	Comentario..: Archivo de Gastos con Mes, Dia, Importe desordenado.
								Se pide: Emitir un listado ord. x Mes y Dia con
									Importes acumulados por dia de cada mes.
								Estructuras de Datos: Lista y SubLista:
								Info de la Lista con: byte Mes, tListaDia LstD
								Info de la SubLista con: byte Dia, float ImpAcu.
*/

#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include "i:\MultiM~1\Unidad~1\Tc\HeadDin\DG5E04Gt.h"
#include <iomanip.h>

#define SPACE "                                                  "

typedef struct RegGto {
	byte  Mes,
				Dia;
	float Impo;
};

void Abrir(FILE **Gtos) {
	*Gtos = fopen("Gastos.Dat","rb");
} //Abrir

void AcumGto(tListaMes &ListaMes, RegGto rGto) {
	tListaMes pMes,
						pAntMes;
	tListaDia pDia,
						pAntDia;
	tInfoMes  rInfoM;
	tInfoDia  rInfoD;

	pMes = ExisteNodo(ListaMes,pAntMes,rGto.Mes);
	if (pMes == NULL) {
		rInfoD.Dia = rGto.Dia;
		rInfoD.ImpAcu = rGto.Impo;
		rInfoM.Mes = rGto.Mes;
		rInfoM.SlstDia = NULL;
		InsertaInicio(rInfoM.SlstDia,rInfoD);
		CrearNodo(ListaMes,pAntMes,rInfoM);
	}
	else {
		pDia = ExisteNodo(pMes->Info.SlstDia,pAntDia,rGto.Dia);
		if (pDia == NULL) {
			rInfoD.Dia = rGto.Dia;
			rInfoD.ImpAcu = rGto.Impo;
			CrearNodo(pMes->Info.SlstDia,pAntDia,rInfoD);
		}
		else
			pDia->Info.ImpAcu += rGto.Impo;
	}
}  //AcumGto

void Listado(tListaMes &ListaMes) {
	float    totAnu = 0.0,
					 totMes;
	tInfoMes rInfoM;
	tInfoDia rInfoD;

	cout << "Listado de Gastos por Mes y Dia" << endl << endl;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	while (ListaMes) {
		SacarPrimerNodo(ListaMes,rInfoM);
		totMes = 0.0;
		cout << "Mes: ";
		cout.width(2);
		cout << rInfoM.Mes << endl;
		cout << "         Dia           Imp.Acum." << endl;
		cout.precision(2);
		while (rInfoM.SlstDia) {
			SacarPrimerNodo(rInfoM.SlstDia,rInfoD);
			totMes += rInfoD.ImpAcu;
			cout.write(SPACE,9);
			cout.width(2);
			cout << rInfoD.Dia;
			cout.write(SPACE,9);
			cout << "$";
			cout.width(11);
			cout << rInfoD.ImpAcu << endl;
		}
		totAnu += totMes;
		cout << endl << "Total del Mes:      ";
		cout << "$";
		cout.fill('*');
		cout.width(11);
		cout << totMes << endl << endl;
		cout.fill(' ');
		getch();
	}
	cout << "Total Anual:        ";
	cout << "$";
	cout.fill('*');
	cout.width(11);
	cout << totAnu << endl;
	getch();
} //Listado

void main() {
	FILE     *Gastos;
	RegGto    rGasto;
	tListaMes ListaMes = NULL;

	Abrir(&Gastos);
	fread(&rGasto,sizeof rGasto,1,Gastos);
	while (!feof(Gastos)) {
		AcumGto(ListaMes,rGasto);
		fread(&rGasto,sizeof rGasto,1,Gastos);
	}
	Listado(ListaMes);
	fclose(Gastos);
} //main
