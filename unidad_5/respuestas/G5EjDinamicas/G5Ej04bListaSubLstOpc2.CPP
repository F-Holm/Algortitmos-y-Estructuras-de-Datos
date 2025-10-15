/**************
*	Id. Programa: G5Ej04bListaSubLstOpc2.Cpp
*	Autor.......: Lic. Hugo Cuello
*	Fecha.......: octubre-2014
*	Comentario..: Archivo de Gastos con:
*                 Mes, Dia, Importe  (desordenado).
*               Se pide:
*                 Emitir un listado ord. x Mes y Dia  con
*                 importes acumulados por dia de cada
*                 mes.
*               Estructuras de Datos: Lista pre-Armada
*                 y SubLista, sin pre-armar:
*                   Info de la Lista con:
*                     tListaDia pSlstDia
*                   Info de la SubLista con:
*                     byte  Dia
*                     float ImpAcum.
***************/

#include <iomanip>
#include <iostream>
#include "h:\tc\prgsFtes\Include\DG5E04GtOpc2.hpp"
using namespace std;

const
  MESES = 12;

// Se define la macro readf con 2 argumentos-parametros
// f : Nombre Logico del archivo
// r : Buffer de almacenamiento
#define readf(f,r) fread(&(r),sizeof((r)),1,(f))

typedef char *pChar;

struct sGasto{
  float Impo;
  byte  Mes,
        Dia;
};

void Abrir(FILE **Gtos) {
	*Gtos = fopen("GastosMD.Dat","rb");
} // Abrir

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

void ArmarED(tListaMes &LstM) {
  for (register i = 1; i <= MESES; i++)
    InsertaInicio(LstM,NULL);
} // ArmarEd

void AcumGto(tListaMes &LstM, sGasto rGto) {
  tListaMes pNodoMes;
  tListaDia pNodoDia,
            pAntDia;
  tInfoDia  rInfoD;

  pNodoMes = BuscarPosNodo(LstM, rGto.Mes);
  pNodoDia = ExisteNodo(pNodoMes->pSlstDia,pAntDia,rGto.Dia);
  if (!pNodoDia) {
    rInfoD.Dia = rGto.Dia;
		rInfoD.ImpAcum = rGto.Impo;
		CrearNodo(pNodoMes->pSlstDia,pAntDia,rInfoD);
  }
  else
    pNodoDia->Info.ImpAcum += rGto.Impo;
}  // AcumGto

void Listado(tListaMes &LstM) {
	float totAnu = 0.0,
        totMes,
        ImpAcum;
        tListaDia pSlstDia;
        tInfoDia  rInfoD;
        pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL","MAYO",
                             "JUNIO","JULIO","AGOSTO","SEPTIEMBRE",
                             "OCTUBRE","NOVIEMBRE","DICIEMBRE"
                         };

	freopen("LstGtosMDb.Lst","w",stdout);
	cout << "(b) Listado de Gastos por Mes y Dia Acumulado (b)" << endl << endl;
	cout.setf(ios::fixed);
	cout.precision(2);
	for (register i = 1; i <= MESES; i++) {
    SacarPrimerNodo(LstM,pSlstDia);
    totMes = 0.0;
    cout << "Mes: " << setw(2) << i << " ";
    cout.setf(ios::left);
    cout << mesCad[i] << endl;
    cout.unsetf(ios::left);
    cout << "         Dia           Imp.Acum." << endl;
    while (pSlstDia) {
		  SacarPrimerNodo(pSlstDia,rInfoD);
		  if (rInfoD.ImpAcum > 0.0) {
		    totMes += rInfoD.ImpAcum;
		    cout << setw(9) << "";
		    cout << setw(2) << (short) rInfoD.Dia;
		    cout << setw(9) << "";
		    cout << "$ ";
		    cout << setw(10) << rInfoD.ImpAcum << endl;
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
	tListaMes ListaMes = NULL;

	Abrir(&Gastos);
	ArmarED(ListaMes);
	while (readf(Gastos,rGasto))
    AcumGto(ListaMes,rGasto);
  Listado(ListaMes);
	fclose(Gastos);

	return 0;
} // main
