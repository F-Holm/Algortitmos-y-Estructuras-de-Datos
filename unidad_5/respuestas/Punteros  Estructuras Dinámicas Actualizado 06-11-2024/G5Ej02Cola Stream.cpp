/**************
*  Id.Programa: G5Ej02Cola.cpp
*  Autor......: Lic. Hugo Cuello
*  Fecha......: octubre-2014
*  Comentario.: Lee de Gastos.Dat (desordenado), importe y mes
*               genera nodos colgado de una matriz de punteros a
*               Colas, del mes leido.
***************/

#include <iomanip>
#include <fstream>
using namespace std;

const
  MESES = 12;

typedef char  *pChar;
typedef float  tInfo;
typedef struct sNodo * tCola;

struct sNodo {
 tInfo Info;
 tCola Sgte;
};

typedef tCola tmCola[MESES + 1][2];

struct sGasto{
  float  importe;
  short  mes;
};

  enum pExtCola {cFte, cFin};

void Enqueue(tCola &qFte, tCola &qFin, tInfo valor) {
  tCola pNodo = new sNodo;
  pNodo->Info = valor;
  pNodo->Sgte = NULL;
  if (!qFte)
    qFte = pNodo;
  else
    qFin->Sgte = pNodo;
  qFin = pNodo;
} //Enqueue

void Dequeue(tCola &qFte, tCola &qFin, tInfo &valor) {
  tCola pElim = qFte;
  valor = qFte->Info;
  qFte = qFte->Sgte;
  if (!qFte)
    qFin = NULL;
  delete pElim;
} //Dequeue

void InicTbl(tmCola mC) {
  for(register i = 1; i <= MESES; i++){
    mC[i][cFte] = NULL;
    mC[i][cFin] = NULL;
  }
} //InicTbl

void Listado(tmCola mC) {
  float totMes,
        totAnual = 0;
  tInfo impo;
  char  *mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL",
                        "MAYO","JUNIO","JULIO","AGOSTO",
                        "SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"
                    };

  freopen("GastosC.Lst","w",stdout);
  cout.precision(2);
  cout.setf(ios::fixed);
  cout << "Listado de Gastos ordenados por mes y en mismo orden de importes "
       << "de lectura" << endl;
  for (register i = 1; i <= MESES; i++) {
    cout << "Mes: " << setw(2) << i << " ";
    cout.setf(ios::left);
    cout << setw(10) << mesCad[i];
    cout.unsetf(ios::left);
    cout << "     Importes" << endl;
    totMes = 0;
    while (mC[i][cFte]) {
      Dequeue(mC[i][cFte], mC[i][cFin], impo);
      cout << setw(19) << "" << "$ " << setw(10) << impo << endl;
      totMes += impo;
    }
    totAnual += totMes;
    cout << endl << "Total del mes: " << setw(4) << "" << "$ ";
    cout.fill('*');
    cout << setw(10) << totMes;
    cout.fill(' ');
    cout << endl << endl;
  }
  cout << endl << "Total anual..: " << setw(4) << "" << "$ ";

  cout.fill('*');
  cout << setw(10) << totAnual << endl;
  cout.fill(' ');
  freopen("CON","w",stdout);
} //Listado

int main() {
  ifstream Gastos("Gastos.Dat",ios::binary);
  tCola mColas[MESES + 1][2];
  sGasto rGasto;

  InicTbl(mColas);
  while (Gastos.read((char *) &rGasto, sizeof(rGasto)))
    Enqueue(mColas[rGasto.mes][cFte], mColas[rGasto.mes][cFin], rGasto.importe);
  Listado(mColas);
  Gastos.close();

  return 0;
}
