/*
        Id.Programa: G4-Ej01 Crear Articulos stream.Cpp
        Autor......: Lic. Hugo Cuello
        Fecha......: jun-2016
        Comentario.: Creacion stream archivo de Articulos.
        Lenguaje...: Borland C++ V. 5.5.
*/

#include <conio.h>

#include <fstream>
using namespace std;

#define CENTINELA 0

typedef char str20[21];

struct sArt {
  short CodArt;
  str20 Descrip;
  float PreUni;
};

short ObtDatos(sArt &rArt) {
  do {
    gotoxy(5, 1);
    cout << "Alta de Articulos.Dat";
    gotoxy(10, 5);
    clreol();
    cout << "Cod.Articulo FIN = " << CENTINELA << ": ";
    cin >> rArt.CodArt;
  } while (!(rArt.CodArt >= 0 && rArt.CodArt <= 100));
  if (rArt.CodArt) {
    do {
      gotoxy(10, 7);
      clreol();
      cout << "Descripcion: ";
      gets(rArt.Descrip);
    } while (!strcmp(rArt.Descrip, ""));
    do {
      gotoxy(10, 9);
      clreol();
      cout << "Pre.Unitario: ";
      cin >> rArt.PreUni;
    } while (!rArt.PreUni);
  }
  return rArt.CodArt;
}  // ObtDatos

main() {
  sArt rArticulo;
  ofstream Articulos("Articulos.Dat", ios::binary);

  while (ObtDatos(rArticulo))
    Articulos.write((char *)&rArticulo, sizeof rArticulo);
  Articulos.close();
  return 0;
}
