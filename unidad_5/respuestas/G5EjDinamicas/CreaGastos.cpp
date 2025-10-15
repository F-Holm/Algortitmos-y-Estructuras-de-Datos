/**************
*  Id.Programa: CreaGastos.cpp
*  Autor......: Lic. Hugo Cuello
*  Fecha......: octubre-2014
*  Comentario.: Crea archivo binario de Gastos.Dat
*                 G5Ej01, 02 y 03. Pila, Cola, Lista.
***************/

#include <iostream>
using namespace std;

typedef unsigned char byte;

struct sGasto{
  float importe;
  byte  mes;
};

int main() {
  FILE   *GastosTxt,
         *Gastos;
  sGasto rGasto;

  GastosTxt = fopen("Gastos.Txt","r");
  Gastos    = fopen("Gastos.Dat","wb");
  while (fscanf(GastosTxt,"%f%hu",&rGasto.importe,&rGasto.mes) && !feof(GastosTxt)) {
    cout << rGasto.importe << "  " << (short) rGasto.mes << " " << endl;
    fwrite(&rGasto,sizeof(rGasto),1,Gastos);
  }
  fcloseall();
}
