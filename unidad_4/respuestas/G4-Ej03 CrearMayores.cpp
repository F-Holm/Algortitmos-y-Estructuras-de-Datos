/*
        Id.Programa: G4Ej03 CreaMayores stream.Cpp
        Autor......: Lic. Hugo Cuello
        Fecha......: sep-2020
        Comentario.: Generar Mayores a partir de Articulos
                        si Precio > impo.
*/

#include <fstream>
using namespace std;

typedef char str20[21];

struct sArt {
  short CodArt;
  str20 Descrip;
  float PreUni;
};

struct sMay {
  short CodArt;
  float PreUni;
};

void AgregarReg(ofstream &May, sArt rArt) {
  sMay rMay;

  rMay.CodArt = rArt.CodArt;
  rMay.PreUni = rArt.PreUni;
  May.write((char *)&rMay, sizeof rMay);
}  // AgregarReg

main() {
  ifstream Articulos("Articulos.Dat", ios::binary);
  ofstream Mayores("Mayores.Dat", ios::binary);
  float impo;
  sArt rArticulo;

  cout << "Ing. Impo: ";
  cin >> impo;
  while (Articulos.read((char *)&rArticulo, sizeof rArticulo))
    if (rArticulo.PreUni > impo)
      AgregarReg(Mayores, rArticulo);
  Articulos.close();
  Mayores.close();
  return 0;
}
