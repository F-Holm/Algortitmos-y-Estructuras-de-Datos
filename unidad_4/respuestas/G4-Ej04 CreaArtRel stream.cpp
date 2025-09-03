/*
  Id.Programa: G4-Ej04 CreaArtRel stream.Cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: junio-2016
  Comentario.: Crear archivo cascaron de Articulos.
  Lenguaje...: Borland C++ V. 5.5.
*/

#include <fstream>
using namespace std;

typedef char str20[21];

struct sArt {
  short CodArt;
  str20 Descrip;
  float PreUni;
};

// Prototipos -----------
void Abrir(ofstream &);
void InicReg(sArt &);
// Fin Prototipos -------

main() {
  ofstream Articulos;
  sArt rArticulo;

  Abrir(Articulos);
  InicReg(rArticulo);
  for (unsigned i = 0; i <= 100; i++)
    Articulos.write((char *)&rArticulo, sizeof rArticulo);
  Articulos.close();
}

void Abrir(ofstream &Art) {
  Art.open("ArtRel.Dat", ios::binary);
}  // Abrir

void InicReg(sArt &rArt) {
  rArt.CodArt = 0;
  strcpy(rArt.Descrip, "");
  rArt.PreUni = 0.0;
}  // InicReg
