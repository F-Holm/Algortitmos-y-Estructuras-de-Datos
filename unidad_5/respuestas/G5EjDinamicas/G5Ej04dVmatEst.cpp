/**************
*  Id.Programa: G5Ej04dVmatEst.Cpp (VmatEst = Version Matriz Estatica)
*  Autor......: Lic. Hugo Cuello
*  Fecha......: octubre-2014
*  Comentario.: Matriz Estatica
*                de filas    = MESES + 1 y
*                de columnas = DIAS (siempre 32)
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
typedef float tMat[MESES + 1][DIAS + 1];

struct sGasto{
  float Impo;
  byte  Mes,
        Dia;
};

void Abrir(FILE **Gtos) {
	*Gtos = fopen("GastosMD.Dat","rb");
} //Abrir

void IniTbl(tMat mIA) {
  for (register i = 1; i <= MESES; i++)
    for (register j = 1; j <= DIAS; j++)
      mIA[i][j] = 0.0;
} // IniTbl

void AcumGto(tMat mIA, sGasto rGto) {
  mIA[rGto.Mes][rGto.Dia] += rGto.Impo;
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

void Listado(tMat mIA) {
  float totAnu = 0.0,
        totMes;
  byte  cantDiasMes;
  pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL",
                        "MAYO","JUNIO","JULIO","AGOSTO",
                        "SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"
                    };

  freopen("LstGtosMDd.Lst","w",stdout);
  cout << "(d) Listado de Gastos por Mes y Dia Acumulado (d)" << endl << endl;
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
      if (mIA[i][j] > 0.0) {
        totMes += mIA[i][j];
        cout << setw(9) << "";
        cout << setw(2) << j;
        cout << setw(9) << "";
        cout << "$ ";
        cout << setw(10) << mIA[i][j] << endl;
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
  tMat   mImpAcum;

  Abrir(&Gastos);
  IniTbl(mImpAcum);
  while (readf(Gastos,rGasto))
    AcumGto(mImpAcum,rGasto);
  Listado(mImpAcum);
  fclose(Gastos);

  return 0;
} //main


