/*
   Id.Programa: CreaNovedades.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: 2018-oct.
   Comentario.: Crea archivo de Novedades.Dat a partir
                de un archivo de texto Novedades.Txt.
*/

#include <iomanip>
#include <fstream>
#include <stdio.h>
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

struct sNov {
  sArt rArt;
  char codMov;
};

bool LeeUnaNov(ifstream &NovT, sNov &rNov) {
  NovT.get(rNov.rArt.codArt,6);
  NovT.ignore();
  NovT.get(rNov.rArt.descrip,21);
  NovT >> rNov.rArt.rubro;
  NovT >> rNov.rArt.precio;
  NovT >> rNov.rArt.stkAct;
  NovT >> rNov.rArt.stkMin;
  NovT >> rNov.rArt.ptoRep;
  NovT >> rNov.codMov;
  NovT.ignore();
  return NovT.good();
}

main() {
  ifstream NovedadesT("Novedades.Txt");
  fstream NovedadesB("Novedades.Dat",ios::in | ios::out | ios::binary);
  sNov  rNov;
  short i = 0;

  ofstream Impresora("192.168.1.255");
  if (!Impresora)
    cout << "no se pudo abrir la impresora... ";
  while(LeeUnaNov(NovedadesT, rNov))
    NovedadesB.write((char *) &rNov, sizeof rNov); // Cnv. txt a bin de Novedades.
  Impresora << "Or C.Art.Descripcion          Rub   Precio    SA    SM    PR CM" << endl;
  NovedadesB.seekg(0L,ios::beg);
  //-----< Lee lo que Grabo y Muestra en Pantalla >-----
  while(NovedadesB.read((char *) &rNov,sizeof rNov))
    Impresora << setw(2) << ++i << ' '
         << setw(5) << rNov.rArt.codArt << ' ' << setw(20) << rNov.rArt.descrip << ' '
         << setw(3) << rNov.rArt.rubro << ' ' << setw(8) << rNov.rArt.precio << ' '
         << setw(5) << rNov.rArt.stkAct << ' ' << setw(5) << rNov.rArt.stkMin << ' '
         << setw(5) << rNov.rArt.ptoRep << "  " << rNov.codMov << endl;
  Impresora.close();
  NovedadesT.close();
  NovedadesB.close();
  return 0;
}
