/*
  Id.Programa: LeerArtBin2Pan_R2-P1.cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: febrero-2025
  Comentario.: Indexar archivo de Articulos por 1) Cod.Art. y 2) Descrip.
                 en arreglos uno por cada indice.
               Listar ambos indices 1) Ord. x Cod. Art. 2) Ord. x Descrip.
               Grabar ambos archivos de indices en archivo de texto.
  Compilador.: Embarcadero C++ Builder 12.
*/

#include <iostream>
#include <tchar.h>
#include <iomanip>
#include <fstream>
using namespace std;

typedef char str20[21];

struct sArt {
  short codArt,
        cant;
  str20 descrip;
  float preUni;
};

void Abrir(ifstream &Art) {
  Art.open("Articulos.Dat", ios::binary);
} // Abrir

int _tmain(int argc, _TCHAR* argv[]) {
  ifstream Art;
  sArt     rArt;

  Abrir(Art);
  cout << "------->Listado de Articulos desordenado<------" << endl;
  cout << "Cod.Art. Cant. Descripcion            Pre.Unit." << endl;
  cout << "-----------------------------------------------" << endl;
  while (Art.read((char *) &rArt, sizeof rArt))
    cout << setw(5) << rArt.codArt << ' ' << setw(7) << rArt.cant << "  "
         << setw(20) << rArt.descrip << ' ' << setw(10) << rArt.preUni << endl;
  cout << "-----------------------------------------------" << endl;
  Art.close();
  system("pause");
  return 0;
}
