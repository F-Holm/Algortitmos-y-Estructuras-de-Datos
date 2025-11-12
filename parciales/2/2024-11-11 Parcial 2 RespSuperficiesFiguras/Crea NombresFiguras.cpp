// Crea NombresFiguras.Dat a partir de NombresFiguras.Txt

#define record struct
#include <fstream>
using namespace std;

typedef char str20[21];

main() {
  ifstream NomFigTxt("NombresFiguras.Txt");
  ofstream NomFig("NombresFiguras.Dat", ios::binary);
  str20    nomFig;

  NomFigTxt.get(nomFig,21);
  NomFigTxt.ignore();
  while (!NomFigTxt.eof()) {
    NomFig.write(nomFig, sizeof nomFig);
    NomFigTxt.get(nomFig,21);
    NomFigTxt.ignore();
  }
  NomFig.close();
  NomFig.close();
  return 0;
}
