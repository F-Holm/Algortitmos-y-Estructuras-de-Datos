/**************
*  Id.Programa: G5Ej01Pila.cpp
*  Autor......: Lic. Hugo Cuello
*  Fecha......: octubre-2014
*  Comentario.: Lee de Gastos.Dat (desordenado), importe y mes
*               genera nodos colgado de un vector de punteros a
*               Pilas, del mes leido, en orden inverso.
***************/

#include <iomanip>
#include <iostream>
using namespace std;

const
  MESES = 12;

typedef unsigned char byte;
typedef char *pChar;
typedef float  tInfo;
typedef struct sNodo *tPila;

struct sNodo {
 tInfo Info;
 tPila Ant;
};

typedef tPila tvPila[MESES + 1];

struct sGasto {
  float importe;
  byte  mes;
};

void Push(tPila &Pila, tInfo valor) {
	tPila pNodo;

	pNodo = new sNodo;
	pNodo->Info = valor;
	pNodo->Ant = Pila;
	Pila = pNodo;
} // Push - Meter

void Pop(tPila &Pila, tInfo &valor) {
	tPila pElim;

	pElim = Pila;
	valor = Pila->Info;
	Pila = Pila->Ant;
	delete pElim;
} // Pop - Sacar

void InicTbl(tvPila vP) {
  for(register i = 1; i <= MESES; i++)
    vP[i] = NULL;
} //InicTbl

void Listado(tvPila vP) {
  float totMes,
        totAnual;
  tInfo impo;
  pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL",
                       "MAYO","JUNIO","JULIO","AGOSTO",
                       "SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"
                   };

  freopen("Gastos.Lst","w",stdout);
  cout.precision(2);
  cout.setf(ios::fixed);
  cout << "Listado de Gastos ordenados por mes y en orden inverso de importes de lectura" << endl;
  for (register i = 1; i <= MESES; i++) {
    cout << "Mes: " << setw(2) << i << " ";
    cout.setf(ios::left);
    cout << setw(10) << mesCad[i];
    cout.unsetf(ios::left);
    cout << "     Importes" << endl;
    totMes = 0;
    while (vP[i]) {
      Pop(vP[i], impo);
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

void Abrir(FILE **Gtos) {
  *Gtos = fopen("Gastos.Dat","rb");
} //Abrir

int main() {
  FILE   *Gastos;
  sNodo  *vPilas[MESES + 1];
  sGasto rGasto;

  Abrir(&Gastos);
  InicTbl(vPilas);
  while (fread(&rGasto, sizeof(rGasto), 1, Gastos))
    Push(vPilas[rGasto.mes],rGasto.importe);
  Listado(vPilas);
  fclose(Gastos);

  return 0;
}
