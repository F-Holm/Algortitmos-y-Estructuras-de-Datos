/**************
*  Id.Programa: G5Ej04eVmatDin.Cpp
*  Autor......: Lic. Hugo Cuello
*  Fecha......: octubre-2014
*  Comentario.: Matriz dinamica en el Heap
*               Se define:
*                 float **pMat;
*
*               Se crea con new un vector de punteros a float
*                 de filas = MESES + 1.
*
*                 pMat = new float* [MESES + 1]
*
*                 luego se crean vector de float
*                 de columnas  = DIAS + 1.
*
*                 pMat[i] = new float [DIAS + 1]
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

typedef unsigned char byte;
typedef char *pChar;

struct sGasto{
  float Impo;
  byte  Mes,
        Dia;
};

void Abrir(FILE **Gtos) {
	*Gtos = fopen("GastosMD.Dat","rb");
} //Abrir

void CreaIniTblDin(float **&pM) {
  pM = new float* [MESES + 1];
  for (register i = 1; i <= MESES; i++)
    pM[i] = new float [DIAS + 1];
  for (register i = 1; i <= MESES; i++)
    for (register j = 1; j <= DIAS; j++)
      pM[i][j] = 0.0;
} // CreaIniTblDin

void AcumGto(float **pM, sGasto rGto) {
  pM[rGto.Mes][rGto.Dia] += rGto.Impo;
}  //AcumGto

byte DiasMes(byte mes) {
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
} // DiasMes

void Listado(float **pM) {
  float totAnu = 0.0,
        totMes;
  byte  cantDiasMes;
  pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL",
                       "MAYO","JUNIO","JULIO","AGOSTO",
                       "SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"
                   };

  freopen("LstGtosMDe.Lst","w",stdout);
  cout << "(e) Listado de Gastos por Mes y Dia Acumulado (e)" << endl << endl;
  cout.setf(ios::fixed);
  cout.precision(2);
  for (register i = 1; i <= MESES; i++) {
    totMes = 0.0;
    cout << "Mes: " << setw(2) << i << " ";
    cout.setf(ios::left);
    cout << mesCad[i] << endl;
    cout.unsetf(ios::left);
    cout << "         Dia           Imp.Acum." << endl;
    cantDiasMes = DiasMes(i);
    for (register j = 1; j <= cantDiasMes; j++)
      if (pM[i][j] > 0.0) {
        totMes += pM[i][j];
        cout << setw(9) << "";
        cout << setw(2) << j;
        cout << setw(9) << "";
        cout << "$ ";
        cout << setw(10) << pM[i][j] << endl;
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
} //Listado

void LiberarMatDin(float **pM) {
	for (register i = 1; i <= MESES; i++)
    delete [] pM[i];
  delete [] pM;
} // LiberarMatDin

int main() {
  FILE   *Gastos;
  sGasto rGasto;
  float  **pMat;

  Abrir(&Gastos);
  CreaIniTblDin(pMat);
  while (readf(Gastos,rGasto))
    AcumGto(pMat,rGasto);
  Listado(pMat);
  LiberarMatDin(pMat);
  fclose(Gastos);

  return 0;
} //main
