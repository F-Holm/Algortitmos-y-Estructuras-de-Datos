// Ej11 de la Guia 2 Crea Nov

#include <fstream>
using namespace std;

typedef char str20[21];

struct sMae {
  long cmpClv;
  int cmp1, cmp2;
  str20 RazSoc, Domic, Local;
  long NroCUIT;
};

struct sNov {
  sMae rMae;
  char codMov;
};

main() {
  ifstream NovTxt("Noved.Txt");
  ofstream NovBin("Noved.Dat", ios::binary);
  sNov rNov;

  NovTxt >> rNov.rMae.cmpClv >> rNov.rMae.cmp1 >> rNov.rMae.cmp2;
  NovTxt.ignore();
  NovTxt.get(rNov.rMae.RazSoc, 21);
  NovTxt.ignore();
  NovTxt.get(rNov.rMae.Domic, 21);
  NovTxt.ignore();
  NovTxt.get(rNov.rMae.Local, 21);
  NovTxt >> rNov.rMae.NroCUIT;
  NovTxt.ignore();
  NovTxt >> rNov.codMov;
  while (!NovTxt.eof()) {
    NovBin.write((const char *)&rNov, sizeof rNov);
    NovTxt >> rNov.rMae.cmpClv >> rNov.rMae.cmp1 >> rNov.rMae.cmp2;
    NovTxt.ignore();
    NovTxt.get(rNov.rMae.RazSoc, 21);
    NovTxt.ignore();
    NovTxt.get(rNov.rMae.Domic, 21);
    NovTxt.ignore();
    NovTxt.get(rNov.rMae.Local, 21);
    NovTxt >> rNov.rMae.NroCUIT;
    NovTxt.ignore();
    NovTxt >> rNov.codMov;
  }
  NovTxt.close();
  NovBin.close();
}
