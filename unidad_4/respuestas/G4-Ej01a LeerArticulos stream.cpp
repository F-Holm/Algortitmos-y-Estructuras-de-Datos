/*
        Id.Programa: Leer Articulos stream.Cpp
        Autor......: Lic. Hugo Cuello
        Fecha......: ago-2024
        Comentario.: Lectura stream archivo de Articulos.
        Lenguaje...: Borland C++ V. 5.5.
*/

#define record struct
#include <fstream>
#include <iomanip>
using namespace std;

typedef char str20[21];

record sArt {
  short CodArt;  // 2+21+4+(1 de relleno) = 28 bytes.
  str20 Descrip;
  float PreUni;
};

main() {
  sArt rArticulo;
  ifstream Articulos("Articulos.Dat", ios::binary);

  Articulos.read((char *)&rArticulo, sizeof rArticulo);
  cout << "C.A. Descripcion             Pre.Uni." << endl;
  while (!Articulos.eof()) {
    cout << setw(3) << rArticulo.CodArt << setw(2) << ' ' << setw(20) << left
         << rArticulo.Descrip << ' ' << setw(11) << right << rArticulo.PreUni
         << endl;
    Articulos.read((char *)&rArticulo, sizeof rArticulo);
  }
  Articulos.close();
  return 0;
}
