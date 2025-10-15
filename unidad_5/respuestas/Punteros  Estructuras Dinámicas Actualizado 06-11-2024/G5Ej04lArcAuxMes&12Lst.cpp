/**************
*	Id. Programa: G5Ej04lArcCascaron.Cpp
*	Autor.......: Lic. Hugo Cuello
*	Fecha.......: octubre-2014
*	Comentario..: Archivo de Gastos con:
*                 Mes, Dia, Importe  (desordenado).
*               Se pide:
*                 Emitir un listado ord. x Mes y Dia  con
*                 importes acumulados por dia de cada
*                 mes.
*               Estructuras de Datos:
*                 Archivo cascaron con 12 componentes,
*                 una por cada mes del año, de punteros a
*                 listas de Días (total de nodos 365, uno
*                 por cada día del año).
***************/

#include <iomanip>
#include <iostream>
#include "h:\tc\prgsFtes\Include\DG5E04GtArcAuxMeslstDias.hpp"
using namespace std;

const
  MESES = 12;

// Se define la macro readf con 2 argumentos-parametros
// f : Nombre Logico del archivo
// r : Buffer de almacenamiento
#define readf(f,r)  fread (&(r),sizeof((r)),1,(f))
#define writef(f,r) fwrite(&(r),sizeof((r)),1,(f))

typedef unsigned char byte;
typedef unsigned short word;
typedef char *pChar;

struct sGasto{
  float Impo;
  byte  Mes,
        Dia;
};

void Abrir(FILE **Gtos, FILE **AGtos) {
	*Gtos  = fopen("GastosMD.Dat","rb");
	*AGtos = fopen("GastosAux.Tmp","w+b");
} // Abrir

void ArmarED(FILE *AGtos) {
  tListaDia pLstDia = NULL;

  for (register i = 1; i <= MESES + 1; i++)
    writef(AGtos,pLstDia);
} // ArmarED

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

void AcumGto(FILE *AGtos, sGasto rGto) {
  tListaDia pLstDia,
            pNodoDia,
            pAntDia;
  sInfoDia  rInfoD;

  fseek(AGtos,rGto.Mes * sizeof (tListaDia),SEEK_SET);
  readf(AGtos,pLstDia);
  pNodoDia = ExisteNodo(pLstDia,pAntDia,rGto.Dia);
  if (!pNodoDia) {
    rInfoD.Dia = rGto.Dia;
    rInfoD.ImpAcum = rGto.Impo;
    CrearNodo(pLstDia,pAntDia,rInfoD);
    if (!pAntDia) {
      fseek(AGtos,rGto.Mes * sizeof (tListaDia),SEEK_SET);
      writef(AGtos,pLstDia);
    }
  }
  else
    pNodoDia->Info.ImpAcum += rGto.Impo;
}  // AcumGto

void Listado(FILE *AGtos) {
	float totAnu = 0.0,
        totMes;
        pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL","MAYO",
                             "JUNIO","JULIO","AGOSTO","SEPTIEMBRE",
                             "OCTUBRE","NOVIEMBRE","DICIEMBRE"
                         };
        tListaDia pLstDia;
        sInfoDia  rInfoD;

	freopen("LstGtosMDl.Lst","w",stdout);
	cout << "(l) Listado de Gastos por Mes y Dia Acumulado (l)" << endl << endl;
	cout.setf(ios::fixed);
	cout.precision(2);
	rewind(AGtos);
	readf(AGtos,pLstDia); // Forzar leer pos. cero que no se usa.
	for (register i = 1; i <= MESES; i++) {
    readf(AGtos,pLstDia);
    totMes = 0.0;
    cout << "Mes: " << setw(2) << i << " ";
    cout.setf(ios::left);
    cout << mesCad[i] << endl;
    cout.unsetf(ios::left);
    cout << "         Dia           Imp.Acum." << endl;
    while (pLstDia) {
		  SacarPrimerNodo(pLstDia,rInfoD);
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

void CerrarEliminar(FILE *Gtos, FILE *AGtos) {
  fclose(Gtos);
  fclose(AGtos);
  remove("GastosAux.Tmp");
} // CerrarEliminar

int main() {
	FILE   *Gastos,
	       *AuxGtos;
	sGasto rGasto;

	Abrir(&Gastos,&AuxGtos);
	ArmarED(AuxGtos);
	while (readf(Gastos,rGasto))
    AcumGto(AuxGtos,rGasto);
  Listado(AuxGtos);
	CerrarEliminar(Gastos,AuxGtos);

	return 0;
} // main
