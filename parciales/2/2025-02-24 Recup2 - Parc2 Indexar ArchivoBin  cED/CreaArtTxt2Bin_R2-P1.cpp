/*
  Id.Programa: CreaArtTxt2Bin_R2-P1.cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: febrero-2025
  Comentario.: Indexar archivo de Articulos por 1) Cod.Art. y 2) Descrip.
                 en arreglos uno por cada indice.
               Listar ambos indices 1) Ord. x Cod. Art. 2) Ord. x Descrip.
               Grabar ambos archivos de indices en archivo de texto.
  Compilador.: Embarcadero C++ Builder 12.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <tchar.h>
using namespace std;

typedef char str20[21];

struct sArt {
  short codArt,
        cant;
  str20 descrip;
  float preUni;
};


void Abrir(ifstream &ArtTxt, fstream &Art) {
  ArtTxt.open("Articulos.Txt");
  Art.open("Articulos.Dat", ios::binary | ios::in | ios::out);
} // Abrir

bool LeerUnArt(ifstream &Art, sArt &rArt) {
  Art >> rArt.codArt >> rArt.cant;
  Art.ignore();
  Art.get(rArt.descrip,21);
  Art >> rArt.preUni;
  Art.ignore();
  return Art.good();
} // LeerUnArt

int _tmain(int argc, _TCHAR* argv[]) {
  ifstream ArtTxt;
  fstream  Art;
  sArt     rArt;

  cout << setprecision(2);
  cout << fixed;
  Abrir(ArtTxt,Art);
  while (LeerUnArt(ArtTxt,rArt))
    Art.write((char *) &rArt, sizeof rArt);
  Art.seekg(0);
  cout << "Creacion archivo Articulos de texto a binario" << endl;
  cout << "Cod.Art. Cant. Descripcion        Pre.Uni." << endl;
  cout << "------------------------------------------" << endl;
  while(Art.read((char *) &rArt, sizeof rArt))
    cout << setw(4) << rArt.codArt << ' ' << setw(4) << rArt.cant << ' '
         << rArt.descrip << ' ' << setw(10) << rArt.preUni << endl;
  cout << "------------------------------------------" << endl;
  ArtTxt.close();
  Art.close();
  system("pause");
  return 0;
}
