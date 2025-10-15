/**************
*	Id. Programa: G5Ej04cListaSubLstOpc3.Cpp
*	Autor.......: Lic. Hugo Cuello
*	Fecha.......: octubre-2014
*	Comentario..: Archivo de Gastos con:
*                 Mes, Dia, Importe  (desordenado).
*               Se pide:
*                 Emitir un listado ord. x Mes y Dia  con
*                 importes acumulados por dia de cada
*                 mes. Estructuras de Datos: Lista y
*                 SubLista, ambas sin pre-armar:
*                   Info de la Lista con:
*                     byte      Mes
*                     tListaDia pSlstDia
*                   Info de la SubLista con:
*                     byte  Dia,
*                     float ImpAcum
***************/

#include <iomanip>
#include <iostream>
#include "h:\tc\prgsFtes\Include\DG5E04GtOpc3.hpp"
using namespace std;

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

void AcumGto(tListaMes &LstM, sGasto rGto) {
	tListaMes pMes,
            pAntMes;
	tListaDia pDia,
            pAntDia;
	sInfoMes  rInfoM;
	sInfoDia  rInfoD;

	pMes = ExisteNodo(LstM,pAntMes,rGto.Mes);
	if (!pMes) {
    rInfoD.Dia = rGto.Dia;
    rInfoD.ImpAcu = rGto.Impo;
    rInfoM.Mes = rGto.Mes;
    rInfoM.pSlstDia = NULL;
    InsertaInicio(rInfoM.pSlstDia,rInfoD);
    CrearNodo(LstM,pAntMes,rInfoM);
	}
	else {
    pDia = ExisteNodo(pMes->Info.pSlstDia,pAntDia,rGto.Dia);
    if (!pDia) {
		  rInfoD.Dia = rGto.Dia;
		  rInfoD.ImpAcu = rGto.Impo;
		  CrearNodo(pMes->Info.pSlstDia,pAntDia,rInfoD);
    }
    else
		  pDia->Info.ImpAcu += rGto.Impo;
	}
}  // AcumGto

void Listado(tListaMes &LstM) {
	float    totAnu = 0.0,
           totMes;
	sInfoMes rInfoM;
	sInfoDia rInfoD;
  pChar    mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL",
                          "MAYO","JUNIO","JULIO","AGOSTO",
                          "SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"
                      };

	freopen("LstGtosMDc.Lst","w",stdout);
	cout << "(c) Listado de Gastos por Mes y Dia Acumulado (c)" << endl << endl;
	cout.setf(ios::fixed);
	cout.precision(2);
	while (LstM) {
    SacarPrimerNodo(LstM,rInfoM);
    totMes = 0.0;
    cout << "Mes: " << setw(2) << (short) rInfoM.Mes << " ";
    cout.setf(ios::left);
    cout << mesCad[rInfoM.Mes] << endl;
    cout.unsetf(ios::left);
    cout << "         Dia           Imp.Acum." << endl;
    while (rInfoM.pSlstDia) {
		  SacarPrimerNodo(rInfoM.pSlstDia,rInfoD);
		  totMes += rInfoD.ImpAcu;
		  cout << setw(9) << "";
		  cout << setw(2) << (short) rInfoD.Dia;
		  cout << setw(9) << "";
		  cout << "$ ";
		  cout << setw(10) << rInfoD.ImpAcu << endl;
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
	while (readf(Gastos,rGasto))
    AcumGto(ListaMes,rGasto);
  Listado(ListaMes);
	fclose(Gastos);

	return 0;
} // main
