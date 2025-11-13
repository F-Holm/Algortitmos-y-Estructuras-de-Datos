/*
   Id.Programa: CreaArticulos.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: 2018-oct.
   Comentario.: Crea archivo de ArticulosABB.Dat a partir
                de un archivo de texto Articulos.Txt.
*/

#include <fstream>
#include <iomanip>
using namespace std;

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

bool LeeUnArt(ifstream &ArtT, sArt &rArt) {
  ArtT.get(rArt.codArt,6);
  ArtT.ignore();
  ArtT.get(rArt.descrip,21);
  ArtT >> rArt.rubro >> rArt.precio >> rArt.stkAct >> rArt.stkMin >> rArt.ptoRep;
  ArtT.ignore();
  return ArtT.good();
} // LeeUnArt

main() {
  ifstream ArticulosT("Articulos.Txt");
  fstream  ArticulosB("Articulos.Dat",ios::in | ios::out | ios::trunc | ios::binary);
  sArt  rArt;
  short i = 0;

  freopen("LstArticulosOriginal.Lst","w",stdout);
  while(LeeUnArt(ArticulosT,rArt))
    ArticulosB.write((const char *) &rArt,sizeof rArt); // Cnv. txt a bin de Articulos.
  cout << "** Articulos.Dat" << endl;
  cout << "Ord C.Art.Descripcion          Rub   Precio    SA    SM    PR" << endl;
  ArticulosB.seekg(0);
  //-----< Lee lo que Grabo y Muestra en Pantalla >-----
  while(ArticulosB.read((char *) &rArt,sizeof rArt))
    cout << setw(3) << i++ << ' '
         << setw(5) << rArt.codArt << ' ' << setw(20) << rArt.descrip << ' '
         << setw(3) << rArt.rubro << ' ' << setw(8) << rArt.precio << ' '
         << setw(5) << rArt.stkAct << ' ' << setw(5) << rArt.stkMin << ' '
         << setw(5) << rArt.ptoRep << endl;
  ArticulosT.close();
  ArticulosB.close();
    freopen("CON","w",stdout);
} // main
