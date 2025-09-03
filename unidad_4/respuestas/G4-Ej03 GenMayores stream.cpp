/*
        Id.Programa: G4-Ej03 GenMayores stream.Cpp
        Autor......: Lic. Hugo Cuello
        Fecha......: jun-2016
        Comentario.: Genera archivo de Mayores precios de Articulos.
        Lenguaje...: Borland C++ V. 5.5.
*/

#include <conio.h>

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

// Prototipos -----------------
void Abrir(ifstream &, ofstream &);
void ObtDato(float &);
void GenReg(ofstream &, sArt);
void Cerrar(ifstream &, ofstream &);
// Fin Prototipos -------------

void Abrir(ifstream &Art, ofstream &May) {
  Art.open("Articulos.Dat", ios::in | ios::binary);
  May.open("Mayores.Dat", ios::out | ios::binary);
}  // Abrir

void ObtDato(float &impMax) {
  clrscr();
  gotoxy(10, 5);
  clreol();
  cout << "Importe Maximo: ";
  cin >> impMax;
}  // ObtDato

void GenReg(ofstream &May, sArt rArt) {
  sMay rMay;

  rMay.CodArt = rArt.CodArt;
  rMay.PreUni = rArt.PreUni;
  May.write((char *)&rMay, sizeof rMay);
}  // GenReg

void Cerrar(ifstream &Art, ofstream &May) {
  Art.close();
  May.close();
}  // Cerrar

main() {
  ifstream Articulos;
  ofstream Mayores;
  sArt rArticulo;
  float maxImp;

  Abrir(Articulos, Mayores);
  ObtDato(maxImp);
  while (Articulos.read((char *)&rArticulo, sizeof(sArt)))
    if (rArticulo.PreUni > maxImp)
      GenReg(Mayores, rArticulo);
  Cerrar(Articulos, Mayores);
  return 0;
}
