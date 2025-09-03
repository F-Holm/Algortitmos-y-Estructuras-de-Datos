/*
	Id.Programa: G4-Ej02 ActArtic stream.Cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: jun-2016
	Comentario.: Actualizacion de Precio en archivo de Articulos.
    Lenguaje...: Borland C++ V. 5.5.
*/

#define modeOpen ios::in | ios::out | ios::binary
#define record struct
#include <conio>
#include <iomanip>
#include <fstream>
using namespace std;

typedef char str20[21];

record sArt {
  short CodArt;
  str20 Descrip;
  float PreUni;
};

// Prototipos ------------------
void ObtDato(float &);
void ActReg(fstream &, sArt );
// Fin Prototipos --------------

void ObtDato(float &porc) {
  clrscr();
  gotoxy(10,5); clreol();
  cout << "Porcentaje: ";
  cin >> porc;
} // ObtDato

void ActReg(fstream &Art, sArt rArt) {
  Art.seekp(Art.tellp() - (int) sizeof rArt);
      // Art.seekp(-1 * sizeof rArt, ios::cur); otra alternativa
  Art.write((char *) &rArt, sizeof rArt);
} // ActReg

main() {
  sArt    rArticulo;
  float   porcje;
  fstream Articulos;

  Articulos.open("Articulos.Dat", modeOpen);
  ObtDato(porcje);
  while (Articulos.read((char *) &rArticulo, sizeof(rArticulo))) {
    rArticulo.PreUni *= (1 + porcje / 100);
    ActReg(Articulos,rArticulo);
  }
  Articulos.close();
  return 0;
}
