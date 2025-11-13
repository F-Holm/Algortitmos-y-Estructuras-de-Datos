/*
   Id.Programa: CreaArtIdx.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: 2018-oct.
   Comentario.: Crea archivo de indices de Articulos.Dat
                utilizando un Arbol Binario ordenada y luego
                graba en el archivo Articulos.Idx
*/

#include <iomanip>
#include <conio>
#include <fstream>
using namespace std;

typedef char str5 [ 6];
typedef char str20[21];

struct sArt {
  str5  codArt;
  str20 descrip;
  short rubro;
  float precio;
  short stkAct,
        stkMin,
        ptoRep;
};

struct sIdx {
  str5 codArt;
  int  refArt;
  bool estado;
};

main() {
  ifstream Articulos("Articulos.Dat",ios::binary);
  ofstream ArtIdx("Articulos.Idx",ios::binary);
  sArt rArt;
  sIdx rIdx;
  int  i = 0;
  short vEstado[] = {1,1,1,1,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,0,1,0,0,1,1,0,0,1,1,1};
  while (Articulos.read((char *) &rArt,sizeof rArt)) {
    cout << i << ' ' << rArt.codArt << endl;
    strcpy(rIdx.codArt,rArt.codArt);
    rIdx.refArt = i;
    rIdx.estado = vEstado[i++];
    ArtIdx.write((char *) &rIdx, sizeof rIdx);
  }
  Articulos.close();
  ArtIdx.close();
  return 0;
} // main



