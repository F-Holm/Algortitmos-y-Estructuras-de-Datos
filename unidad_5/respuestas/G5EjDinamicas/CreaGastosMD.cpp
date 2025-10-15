/**************
*  Id.Programa: CreaGastosMD.cpp
*  Autor......: Lic. Hugo Cuello
*  Fecha......: octubre-2014
*  Comentario.: Crea archivo binario de GastosMD.Dat
*                 G5Ej04 Lista y Sub-Listas.
***************/

#include <iostream>
using namespace std;

typedef unsigned char byte;

struct sGasto{
  float Impo;
  byte  Mes,
        Dia;
};

int main() {
  FILE   *GastosTxt,
         *Gastos;
  sGasto rGasto;

  GastosTxt = fopen("GastosMD.Txt","r");
  Gastos    = fopen("GastosMD.Dat","wb");
  while (fscanf(GastosTxt,"%f%hu%hu",&rGasto.Impo,&rGasto.Mes,&rGasto.Dia) && !feof(GastosTxt)) {
    cout << rGasto.Impo << "  " << (short) rGasto.Mes << " " << (short) rGasto.Dia << endl;
    fwrite(&rGasto,sizeof(rGasto),1,Gastos);
  }
  fcloseall();
}
