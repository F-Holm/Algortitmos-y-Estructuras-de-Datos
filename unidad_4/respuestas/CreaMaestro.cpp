// Ej11 de la Guia 2 Crea Maestro

#include <fstream>
using namespace std;

typedef char str20[21];

struct sMae {
  long cmpClv;
  int cmp1, cmp2;
  str20 RazSoc, Domic, Local;
  long NroCUIT;
};

main() {
  ifstream MaeTxt("MaeVjo.Txt");
  ofstream MaeBin("MaeVjo.Dat", ios::binary);
  sMae rMae;

  MaeTxt >> rMae.cmpClv >> rMae.cmp1 >> rMae.cmp2;
  MaeTxt.ignore();
  MaeTxt.get(rMae.RazSoc, 21);
  MaeTxt.ignore();
  MaeTxt.get(rMae.Domic, 21);
  MaeTxt.ignore();
  MaeTxt.get(rMae.Local, 21);
  MaeTxt >> rMae.NroCUIT;
  while (!MaeTxt.eof()) {
    MaeBin.write((const char*)&rMae, sizeof rMae);
    MaeTxt >> rMae.cmpClv >> rMae.cmp1 >> rMae.cmp2;
    MaeTxt.ignore();
    MaeTxt.get(rMae.RazSoc, 21);
    MaeTxt.ignore();
    MaeTxt.get(rMae.Domic, 21);
    MaeTxt.ignore();
    MaeTxt.get(rMae.Local, 21);
    MaeTxt >> rMae.NroCUIT;
  }
  MaeTxt.close();
  MaeBin.close();
}
