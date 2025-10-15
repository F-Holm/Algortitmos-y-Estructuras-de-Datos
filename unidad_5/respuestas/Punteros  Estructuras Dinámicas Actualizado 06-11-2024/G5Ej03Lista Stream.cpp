/*
*  Id.Programa: G5Ej03Lista.cpp
*  Autor......: Lic. Hugo Cuello
*  Fecha......: octubre-2014
*  Comentario.: Lee de Gastos.Dat (desordenado), importe y mes
*               genera nodos colgado de un vector de punteros a
*               Listas, del mes leido y, ordenado por importes.
*/

#include <iomanip>
#include <fstream>
using namespace std;

const
  MESES = 12;

typedef unsigned char byte;
typedef char  *pChar;
typedef float  tInfo;
typedef struct sNodo * tLista;

struct sNodo {
 tInfo Info;
 tLista Sgte;
};

typedef tLista tvLista[MESES + 1];

struct sGasto {
  float importe;
  byte  mes;
};

void InsertaInicio(tLista &Lista, tInfo valor) {
	tLista pNodo = new sNodo;
	pNodo->Info = valor;
	pNodo->Sgte = Lista;
	Lista = pNodo;
} // InsertaInicio

void InsertaEnLugar (tLista &pAct, tInfo valor) {
    tLista pNodo = new sNodo;

	pNodo->Info = valor;
	pNodo->Sgte = pAct->Sgte;
	pAct->Sgte = pNodo;
} // InsertaEnLugar

void InsertaEnMedio(tLista &Lista, tInfo valor) {
	tLista pAct;

	pAct = Lista;
	while (pAct->Sgte && valor > pAct->Sgte->Info)
      pAct = pAct->Sgte;
    InsertaEnLugar(pAct,valor);
} // InsertaEnMedio

void InsertaNodo(tLista &Lista, tInfo valor) {
	if (!Lista || valor < Lista->Info)
		InsertaInicio(Lista,valor);
	else
		InsertaEnMedio(Lista,valor);
} // InsertaNodo

void SacarPrimerNodo(tLista &Lista, tInfo &valor) {
    tLista pElim = Lista;
    valor = Lista->Info;
    Lista = Lista->Sgte;
    delete pElim;
} // SacarPrimerNodo

void InicTbl(tvLista vL) {
  for(register i = 1; i <= MESES; i++)
    vL[i] = NULL;
} //InicTbl

void Listado(tvLista vL) {
  float totMes,
        totAnual = 0;
  tInfo impo;
  pChar mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL",
                       "MAYO","JUNIO","JULIO","AGOSTO",
                       "SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"
                   };

  freopen("GastosL.Lst","w",stdout);
  cout.precision(2);
  cout.setf(ios::fixed);
  cout << "Listado de Gastos ordenados por mes y en orden de importes de "
       << "lectura" << endl;
  for (register i = 1; i <= MESES; i++) {
    cout << "Mes: " << setw(2) << i << " ";
    cout.setf(ios::left);
    cout << setw(10) << mesCad[i];
    cout.unsetf(ios::left);
    cout << "     Importes" << endl;
    totMes = 0;
    while (vL[i]) {
      SacarPrimerNodo(vL[i], impo);
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
  cout.fill(' ' );
  freopen("CON","w",stdout);
} //Listado

main() {
  ifstream Gastos("Gastos.Dat",ios::binary);
  tvLista vListas;
  sGasto rGasto;

  InicTbl(vListas);
  while (Gastos.read((char *) &rGasto, sizeof(rGasto)))
    InsertaNodo(vListas[rGasto.mes],rGasto.importe);
  Listado(vListas);
  Gastos.close();
  return 0;
}
