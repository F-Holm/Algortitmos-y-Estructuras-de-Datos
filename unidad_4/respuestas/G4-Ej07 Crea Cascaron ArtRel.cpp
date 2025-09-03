/*
        Id.Programa: G2Ej07stream.Cpp
        Autor......: Lic. Hugo Cuello
        Fecha......: jun-2016
        Comentario.: Crear ArtRel cascaron.
*/

#include <fstream>
using namespace std;

typedef char str20[21];

struct sArt {
  short CodArt;   // valor cero inactivo.
  str20 Descrip;  // cadena vacia.
  float PreUni;   // cero real.
};

void InicReg(sArt &rArt) {
  rArt.CodArt = 0;
  strcpy(rArt.Descrip, "");
  rArt.PreUni = 0.0;
}  // InicReg

main() {
  ofstream Articulos("ArtRel.Dat", ios::binary);
  sArt rArticulo;

  InicReg(rArticulo);
  cout << "Tam.componente: " << sizeof(rArticulo) << endl;
  cout << "Antes: " << Articulos.tellp() << endl;
  for (short i = 0; i <= 100; i++)
    Articulos.write((char *)&rArticulo, sizeof rArticulo);
  cout << "Despues: " << Articulos.tellp() << endl;
  Articulos.close();
  return 0;
}
