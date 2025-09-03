/*
  Id.Programa: G2Ej04.Cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: oct-2013
  Comentario.: Leer stream archivo de Articulos.
*/

#define record struct
#include <iomanip>
#include <fstream>
using namespace std;

typedef char str20[21];

record sArt {
  short CodArt;
  str20 Descrip;
  float PreUni;
};

// Prototipos -----------
void Abrir(ifstream &);
// Fin Prototipos -------

void Abrir(ifstream &Art) {
	Art.open("Articulos.Dat",ios::binary | ios::in);
} // Abrir

main() {
  ifstream Articulos;
  sArt     rArticulo;

  Abrir(Articulos);
  freopen("ListaArt.Txt","w",stdout);
  cout.precision(2);
  cout.setf(ios::fixed);
  cout << "C.Art. Descripcion           Pre.Uni.<--" << endl;
  while (Articulos.read((char *) &rArticulo, sizeof rArticulo))
	cout << setw( 4) << rArticulo.CodArt << "   " << left
	     << setw(20) << rArticulo.Descrip << ' ' << right
	     << setw( 9) << rArticulo.PreUni << endl;
  Articulos.close();
  freopen("CON","w",stdout);
  return 0;
} // main


