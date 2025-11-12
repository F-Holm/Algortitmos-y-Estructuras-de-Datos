/*
  Id.Programa: LeerIdxArt_CodArt_R2-P1.cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: febrero-2025
  Comentario.: Indexar archivo de Articulos por 1) Cod.Art. y 2) Descrip.
                 en arreglos uno por cada indice.
               Listar ambos indices 1) Ord. x Cod. Art. 2) Ord. x Descrip.
               Grabar ambos archivos de indices en archivo de texto.
  Compilador.: Embarcadero C++ Builder 12.
*/

#include <tchar.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <tchar.h>
using namespace std;

struct sIdx {
  short codArt,
        refArt;
};

void Abrir(ifstream &ArtIdx) {
  ArtIdx.open("IdxCodArt.Idx", ios::binary);
} // Abrir

int _tmain(int argc, _TCHAR* argv[]) {
  ifstream ArtIdx;
  sIdx     rIdx;

  Abrir(ArtIdx);
  cout << "Listado de Articulos ordenado por Codigo de Articulo" << endl;
  cout << "Cod.Art. Ref.Art." << endl;
  cout << "-----------------" << endl;
  while (ArtIdx.read((char *) &rIdx, sizeof rIdx))
    cout << setw(5) << rIdx.codArt << ' ' << setw(7) << rIdx.refArt << endl;
  cout << "-----------------" << endl;
  ArtIdx.close();
  system("pause");
  return 0;
}
