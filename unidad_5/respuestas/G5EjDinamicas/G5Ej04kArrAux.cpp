/**************
*	Id. Programa: G5Ej04kArrAux.Cpp
*	Autor.......: Lic. Hugo Cuello
*	Fecha.......: octubre-2014
*	Comentario..: Archivo de Gastos con:
*                 Mes, Dia, Importe  (desordenado).
*               Se pide:
*                 Emitir un listado ord. x Mes y Dia  con
*                 importes acumulados por dia de cada
*                 mes.
*               Estructuras de Datos:
*                 Vector con 365 posiciones 1 x c/dia anual.
***************/

#include <iomanip>
#include <iostream>
using namespace std;

const
  MESES = 12;

// Se define la macro readf con 2 argumentos-parametros
// f : Nombre Logico del archivo
// r : Buffer de almacenamiento
#define readf(f,r)  fread (&(r),sizeof((r)),1,(f))

typedef unsigned char byte;
typedef unsigned short word;
typedef char *pChar;
typedef float tvImpAcum[365];

struct sGasto{
  float Impo;
  byte  Mes,
        Dia;
};

void Abrir(FILE **Gtos) {
	*Gtos  = fopen("GastosMD.Dat","rb");
} // Abrir

void ArmarED(tvImpAcum vIA) {

  for (register i = 0; i <= 364; i++)
    vIA[i] = 0.0;
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

void AcumGto(tvImpAcum vIA, sGasto rGto) {
  vIA[CantDias(rGto.Mes) + rGto.Dia - 1] += rGto.Impo;
}  // AcumGto

void Listado(tvImpAcum vIA) {
	float totAnu = 0.0,
        totMes,
        impAcum;
  word  posV;
        pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL","MAYO",
                             "JUNIO","JULIO","AGOSTO","SEPTIEMBRE",
                             "OCTUBRE","NOVIEMBRE","DICIEMBRE"
                         };

	freopen("LstGtosMDk.Lst","w",stdout);
	cout << "(k) Listado de Gastos por Mes y Dia Acumulado (k)" << endl << endl;
	cout.setf(ios::fixed);
	cout.precision(2);
	for (register i = 1; i <= MESES; i++) {
    totMes = 0.0;
    cout << "Mes: " << setw(2) << i << " ";
    cout.setf(ios::left);
    cout << mesCad[i] << endl;
    cout.unsetf(ios::left);
    cout << "         Dia           Imp.Acum." << endl;
    for (register j = 1; j <= CantDiasMes(i); j++) {
		  posV = CantDias(i) + j - 1;
		  if (vIA[posV] > 0.0) {
		    totMes += vIA[posV];
		    cout << setw(9) << "";
		    cout << setw(2) << j;
		    cout << setw(9) << "";
		    cout << "$ ";
		    cout << setw(10) << vIA[posV] << endl;
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
	FILE      *Gastos,
	          *AuxGtos;
	sGasto    rGasto;
	tvImpAcum vImpAcum;

	Abrir(&Gastos);
	ArmarED(vImpAcum);
	while (readf(Gastos,rGasto))
    AcumGto(vImpAcum,rGasto);
  Listado(vImpAcum);
	fclose(Gastos);

	return 0;
} // main
