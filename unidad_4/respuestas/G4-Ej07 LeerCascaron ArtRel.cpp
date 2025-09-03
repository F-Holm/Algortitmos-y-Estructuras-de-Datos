/*
        Id.Programa: G2Ej07stream.Cpp
        Autor......: Lic. Hugo Cuello
        Fecha......: jun-2016
        Comentario.: Leer Articulos cascaron.
*/

#include <fstream>
using namespace std;

typedef char str20[21];

struct sArt {
  short CodArt;   // valor cero inactivo.
  str20 Descrip;  // cadena vacia.
  float PreUni;   // cero real.
};

main() {
  ifstream Articulos("ArtRel.Dat", ios::binary);
  sArt rArticulo;
  cout.precision(8);
  cout.fixed;
  while (Articulos.read((char *)&rArticulo, sizeof rArticulo))
    cout << rArticulo.CodArt << rArticulo.Descrip << rArticulo.PreUni << endl;
  Articulos.close();
  return 0;
}
