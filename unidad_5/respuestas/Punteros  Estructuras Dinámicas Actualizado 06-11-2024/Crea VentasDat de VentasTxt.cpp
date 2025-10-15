
// Crea Ventas.Dat a partir de Ventas.Txt

#include <fstream>
using namespace std;

typedef char str20[21];

struct sArt {
  int   codArt,
        cant;
  float preUni;
  str20 descrip;
};

bool Lee(ifstream &Vtas, sArt &rVta) {
  Vtas >> rVta.codArt >> rVta.cant >> rVta.preUni;
  Vtas.ignore();
  Vtas.get(rVta.descrip,21);
  Vtas.ignore();
  return Vtas.good();
}

main() {
  ifstream VentasT("Ventas.Txt");
  ofstream Ventas("Ventas.Dat",ios::binary);
  sArt rVenta;

  while (Lee(VentasT,rVenta))
    Ventas.write((char *) &rVenta,sizeof rVenta);
  VentasT.close();
  Ventas.close();
  return 0;
}
