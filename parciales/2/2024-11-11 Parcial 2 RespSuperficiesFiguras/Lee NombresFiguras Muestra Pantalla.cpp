// Lee NombresFiguras.Dat muestra en Pantalla.

#define record struct
#include <fstream>
using namespace std;

typedef char str20[21];

main() {
  ifstream NomFig("NombresFiguras.Dat",ios::binary);
  str20    nomFig;


  while (NomFig.read(nomFig, sizeof nomFig))
    cout << nomFig << endl;
  NomFig.close();
  return 0;
}
