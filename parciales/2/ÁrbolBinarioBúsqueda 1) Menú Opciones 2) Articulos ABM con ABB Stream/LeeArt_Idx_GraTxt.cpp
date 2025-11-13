// LeeArt_Idx_GraTxt.cpp

typedef char str5[6];
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

struct sArtIdx {
  str5 codArt; //es la clave
  int  refArt;
  bool estado;
};

#include <iomanip>
#include <fstream>
using namespace std;

main() {
  sArtIdx rArtIdx;
  sArt    rArt;
  short   i = 0;

  ifstream ArtIdx("Articulos.Idx", ios::binary);
  ofstream ArtIdxTxt("ArticulosIdx.Txt");
  while (ArtIdx.read((char *) &rArtIdx, sizeof rArtIdx)) {
    cout << i << endl;
    ArtIdxTxt << setw(2) << i++ << ' ' << rArtIdx.codArt << ' ' << setw(2)
              << rArtIdx.refArt << ' ' << rArtIdx.estado << endl;
  }
  ArtIdx.close();
  ArtIdxTxt.close();
  return 0;
}