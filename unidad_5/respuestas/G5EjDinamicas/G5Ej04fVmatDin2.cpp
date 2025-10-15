/**************
*  Id.Programa: G5Ej04fVmatDin2.Cpp (VmatDin2 = Version Matriz Dinamica2)
*  Autor......: Lic. Hugo Cuello
*  Fecha......: octubre-2014
*  Comentario.: Matriz dinamica en el Heap
*               Se define:
*                 float *pMat;
*
*               Se crea con new un vector de float
*                 de MESES * DIAS elementos.
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

void CreaIniTblDin(float* &pM) {
  float *pm;

  pM = new float [MESES * DIAS];
  pm = pM;
  for (register i = 1; i <= MESES * DIAS; i++)
    *pm++ = 0.0;
} // CreaIniTblDin

void AcumGto(float* pM, sGasto rGto) {

  pM = pM + (rGto.Mes - 1) * DIAS + (rGto.Dia - 1);
  *pM += rGto.Impo;
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

void Listado(float* pM) {
  float totAnu = 0.0,
        totMes;
  byte  cantDiasMes;
  float *pm;
  pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL","MAYO",
                       "JUNIO","JULIO","AGOSTO","SEPTIEMBRE",
                       "OCTUBRE","NOVIEMBRE","DICIEMBRE"
                   };

  freopen("LstGtosMDf.Lst","w",stdout);
  cout << "(f) Listado de Gastos por Mes y Dia Acumulado (f)" << endl << endl;
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
    for (register j = 1; j <= cantDiasMes; j++) {
      pm = pM + (i - 1) * DIAS + (j - 1);
      if (*pm > 0.0) {
        totMes += *pm;
        cout << setw(9) << "";
        cout << setw(2) << j;
        cout << setw(9) << "";
        cout << "$ ";
        cout << setw(10) << *pm << endl;
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
} //Listado

int main() {
  FILE   *Gastos;
  sGasto rGasto;
  float  *pMat;

  Abrir(&Gastos);
  CreaIniTblDin(pMat);
  while (readf(Gastos,rGasto))
    AcumGto(pMat,rGasto);
  Listado(pMat);
  fclose(Gastos);

  return 0;
} //main
