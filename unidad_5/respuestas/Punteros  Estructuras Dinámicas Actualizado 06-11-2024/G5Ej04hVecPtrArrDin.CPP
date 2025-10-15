/**************
*	Id. Programa: G5Ej04hVecPtrArrDin.Cpp
*	Autor.......: Lic. Hugo Cuello
*	Fecha.......: octubre-2014
*	Comentario..: Archivo de Gastos con:
*                 Mes, Dia, Importe  (desordenado).
*               Se pide:
*                 Emitir un listado ord. x Mes y Dia  con
*                 importes acumulados por dia de cada
*                 mes.
*               Estructuras de Datos:
*                 (Estatica) tvMes es el tipo del Vector de punteros
*                 a float (13 componentes de meses, pos. 0 no se
*                 utilizara en el proceso) en Arreglo de dias en el
*                 heap (32 componentes de dias, pos. 0 no se
*                 utilizara en el proceso).
***************/

#include <iomanip>
#include <iostream>
using namespace std;

// Se define la macro readf con 2 argumentos-parametros
// f : Nombre Logico del archivo
// r : Buffer de almacenamiento
#define readf(f,r) fread(&(r),sizeof((r)),1,(f))

const
  MESES = 12,
  DIAS  = 31;

typedef char *pChar;
typedef unsigned char byte;
typedef float* tvMes[MESES + 1];

struct sGasto{
  float Impo;
  byte  Mes,
        Dia;
};

void Abrir(FILE **Gtos) {
	*Gtos = fopen("GastosMD.Dat","rb");
} // Abrir

void ArmarED(tvMes vM) {
  for (register i = 1; i <= MESES; i++)
    vM[i] = new float[DIAS + 1];
} // ArmarEd

void AcumGto(tvMes vM, sGasto rGto) {
  vM[rGto.Mes][rGto.Dia] += rGto.Impo;
}  // AcumGto

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

void Listado(tvMes vM) {
	float totAnu = 0.0,
        totMes,
        ImpAcum;
        pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL","MAYO",
                             "JUNIO","JULIO","AGOSTO","SEPTIEMBRE",
                             "OCTUBRE","NOVIEMBRE","DICIEMBRE"
                         };

	freopen("LstGtosMDh.Lst","w",stdout);
	cout << "(h) Listado de Gastos por Mes y Dia Acumulado (h)" << endl << endl;
	cout.setf(ios::fixed);
	cout.precision(2);
	for (register mes = 1; mes <= MESES; mes++) {
    totMes = 0.0;
    cout << "Mes: " << setw(2) << mes << " ";
    cout.setf(ios::left);
    cout << mesCad[mes] << endl;
    cout.unsetf(ios::left);
    cout << "         Dia           Imp.Acum." << endl;
    for (register dia = 1; dia <= CantDiasMes(mes); dia++) {
		  if (vM[mes][dia] > 0.0) {
		    totMes += vM[mes][dia];
		    cout << setw(9) << "";
		    cout << setw(2) << dia;
		    cout << setw(9) << "";
		    cout << "$ ";
		    cout << setw(10) << vM[mes][dia] << endl;
		  }
    }
    delete vM[mes];
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
	FILE   *Gastos;
	sGasto rGasto;
  tvMes  vMes;

	Abrir(&Gastos);
	ArmarED(vMes);
	while (readf(Gastos,rGasto))
    AcumGto(vMes,rGasto);
  Listado(vMes);
	fclose(Gastos);

	return 0;
} // main
