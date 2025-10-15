/**************
*	Id. Programa: G5Ej04aListaSubLstOpc1.Cpp
*	Autor.......: Lic. Hugo Cuello
*	Fecha.......: octubre-2014
*	Comentario..: Archivo de Gastos con:
*                 Mes, Dia, Importe  (desordenado).
*               Se pide:
*                 Emitir un listado ord. x Mes y Dia  con
*                 importes acumulados por dia de cada mes.
*               Estructuras de Datos:
*                  Lista y SubLista, ambas pre-armadas:
*                   Info de la Lista con:
*                     tListaDia pSlstDia
*                   Info de la SubLista con:
*                     float ImpAcum.
***************/

#include <iomanip>
#include <fstream>
#include "DG5E04GtOpc1.hpp"
using namespace std;

const
  MESES = 12;

typedef char *pChar;

struct sGasto{
  float Impo;
  byte  Mes,
        Dia;
};

void Abrir(ifstream &Gtos) {
	Gtos.open("GastosMD.Dat",ios::binary);
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
  for (register i = MESES; i >= 1; i--) {
    InsertaInicio(LstM,NULL);
    for (register j = 1; j <= CantDiasMes(i); j++)
      InsertaInicio(LstM->pSlstDia,0.0);
  }
} // ArmarEd

void AcumGto(tListaMes &LstM, sGasto rGto) {
  tListaMes pNodoMes;
  tListaDia pNodoDia;

  pNodoMes = BuscarPosNodo(LstM, rGto.Mes);
  pNodoDia = BuscarPosNodo(pNodoMes->pSlstDia,rGto.Dia);
  pNodoDia->ImpAcum += rGto.Impo;
}  // AcumGto

void Listado(tListaMes &LstM) {
	float totAnu = 0.0,
        totMes,
        ImpAcum;
        tListaDia pSlstDia;
        pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL","MAYO",
                             "JUNIO","JULIO","AGOSTO","SEPTIEMBRE",
                             "OCTUBRE","NOVIEMBRE","DICIEMBRE"
                         };

	freopen("LstGtosMDa.Lst","w",stdout);
	cout << "(a) Listado de Gastos por Mes y Dia Acumulado (a)" << endl << endl;
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
       for (register j = 1; j <= CantDiasMes(i); j++) {
		  SacarPrimerNodo(pSlstDia,ImpAcum);
		  if (ImpAcum > 0.0) {
		    totMes += ImpAcum;
		    cout << setw(9) << "";
		    cout << setw(2) << j;
		    cout << setw(9) << "";
		    cout << "$ ";
		    cout << setw(10) << ImpAcum << endl;
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
	ifstream Gastos;
	sGasto    rGasto;
	tListaMes ListaMes = NULL;

	Abrir(Gastos);
	ArmarED(ListaMes);
	while (Gastos.read((char *) &rGasto, sizeof rGasto))
      AcumGto(ListaMes,rGasto);
    Listado(ListaMes);
	Gastos.close();
	return 0;
} // main
