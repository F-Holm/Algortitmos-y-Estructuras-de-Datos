/*
    Id.Programa: 3.LeeTxtGraBin.cpp
    Autor......: Lic. Hugo Cuello
    Fecha......: jun-2014
    Comentario.: Lee archivo de texto y graba en archivo binario
*/

#include <iomanip.h>
#include <iostream>
using namespace std;
typedef char str20[21];

struct sVen {
    int    codVen,
           cant;
    float  preUni;
    str20  descrip;
  };

int main () {
  FILE  *aVentasTxt,
        *aVentas;
  sVen  rVenta;
  char  car;

  cout.precision(2);
  cout.setf(ios::fixed);
  aVentasTxt = fopen("Ventas.Txt","r");
  aVentas    = fopen("Ventas.Dat","w+b");
  fscanf(aVentasTxt,"%d%d%f%c",&rVenta.codVen,&rVenta.cant,&rVenta.preUni,&car);
  fgets(rVenta.descrip,22,aVentasTxt);
  while (!feof(aVentasTxt)) {
        cout << ". ";
    fwrite(&rVenta, sizeof(rVenta),1,aVentas);
    fscanf(aVentasTxt,"%d%d%f%c",&rVenta.codVen,&rVenta.cant,&rVenta.preUni,&car);
    fgets(rVenta.descrip,22,aVentasTxt);
  }
  rewind(aVentas);
  while (fread(&rVenta,sizeof (rVenta),1,aVentas))
    cout << rVenta.codVen << " " << rVenta.cant << " " << rVenta.preUni << " " << rVenta.descrip << endl;

  fclose(aVentasTxt);
  fclose(aVentas);

  return 0;
}
