/**************
*	Id. Programa: G5Ej04iLista12MesesArr.Cpp
*	Autor.......: Lic. Hugo Cuello
*	Fecha.......: octubre-2014
*	Comentario..: Archivo de Gastos con:
*                 Mes, Dia, Importe  (desordenado).
*               Se pide:
*                 Emitir un listado ord. x Mes y Dia  con
*                 importes acumulados por dia de cada
*                 mes.
*               Estructuras de Datos:
*                 Lista unica pre-Armada con 12 nodos por
*                 cada mes con Info vector Dias[32].
***************/

#include <iomanip>
#include <iostream>
#include "h:\tc\prgsFtes\Include\DG5E04GtLstU12M.hpp"
using namespace std;

const
  MESES = 12;

// Se define la macro readf con 2 argumentos-parametros
// f : Nombre Logico del archivo
// r : Buffer de almacenamiento
#define readf(f,r) fread(&(r),sizeof((r)),1,(f))

typedef unsigned char byte;
typedef char *pChar;

struct sGasto{
  float Impo;
  byte  Mes,
        Dia;
};

void Abrir(FILE **Gtos) {
	*Gtos = fopen("GastosMD.Dat","rb");
} // Abrir

void ArmarED(tListaMD &LstM) {
  tInfoMD vImpo = {0.0};

  for (register i = 1; i <= MESES; i++)
    InsertaInicio(LstM,vImpo);
} // ArmarEd

byte CantDiasMes(byte mes) {
  switch(mes) {
    case  4:
    case  6:
    case  9:
    case 11:
      return 30;
    case  2:
      return 28;
    default:
      return 31;
  }
} // CantDiasMes

word CantDias(byte mes) {
  word sumDias = 0;

  for (register i = 1; i < mes; i++)
    switch (i) {
      case  4:
      case  6:
      case  9:
      case 11:
        sumDias += 30;
        break;
      case  2:
        sumDias += 28;
        break;
      default:
        sumDias += 31;
    }
  return sumDias;
} //CantDias

void AcumGto(tListaMD &LstM, sGasto rGto) {
  tListaMD pNodoMD;

  pNodoMD = BuscarPosNodo(LstM, rGto.Mes);
  pNodoMD->vImpAcum[rGto.Dia] += rGto.Impo;
}  // AcumGto

void Listado(tListaMD &LstMD) {
	float totAnu = 0.0,
        totMes,
        vImpAcum[DIAS + 1];
        pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL","MAYO",
                             "JUNIO","JULIO","AGOSTO","SEPTIEMBRE",
                             "OCTUBRE","NOVIEMBRE","DICIEMBRE"
                         };

	freopen("LstGtosMDi.Lst","w",stdout);
	cout << "(i) Listado de Gastos por Mes y Dia Acumulado (i)" << endl << endl;
	cout.setf(ios::fixed);
	cout.precision(2);
	for (register i = 1; i <= MESES; i++) {
    SacarPrimerNodo(LstMD,vImpAcum);
    totMes = 0.0;
    cout << "Mes: " << setw(2) << i << " ";
    cout.setf(ios::left);
    cout << mesCad[i] << endl;
    cout.unsetf(ios::left);
    cout << "         Dia           Imp.Acum." << endl;
    for (register j = 1; j <= CantDiasMes(i); j++) {
		  if (vImpAcum[j] > 0.0) {
		    totMes += vImpAcum[j];
		    cout << setw(9) << "";
		    cout << setw(2) << j;
		    cout << setw(9) << "";
		    cout << "$ ";
		    cout << setw(10) << vImpAcum[j] << endl;
		  }
    }
    totAnu += totMes;
    cout << endl << "Total del Mes:      $";
    cout.fill('*');
    cout << setw(11) << totMes << endl << endl;
    cout.fill(' ');
  }
	cout << "Total Anual:        $";
	cout.fill('*');
	cout << setw(11) << totAnu << endl;
	freopen("CON","w",stdout);
} // Listado

int main() {
	FILE      *Gastos;
	sGasto    rGasto;
	tListaMD ListaMD = NULL;

	Abrir(&Gastos);
	ArmarED(ListaMD);
	while (readf(Gastos,rGasto))
    AcumGto(ListaMD,rGasto);
  Listado(ListaMD);
	fclose(Gastos);

	return 0;
} // main
