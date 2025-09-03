/*
  Id.Programa: G4-Ej03 LeerMayoresStream.Cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: junio-2016
  Comentario.: Leer stream archivo de Articulos.
*/

#include <iomanip>
#include <fstream>
using namespace std;

typedef char str20[21];
struct sMay {
	short CodArt;
	float  PreUni;
};

// Prototipos -----------
void Abrir(ifstream &);
// Fin Prototipos -------

string spaces(short n) {
  string espacios = "";

  for (short i = 0; i < n; i++)
    espacios += ' ';
  return espacios;
}

main() {
	ifstream Mayores;
	sMay rMayores;

	Abrir(Mayores);
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Archivo: Mayores.Dat" << endl;
	cout << "C.Art.   Pre.Uni." << endl;
	while (Mayores.read((char*) &rMayores, sizeof rMayores)) {
		cout << setw( 4) << rMayores.CodArt << spaces(3)
             << setw( 9) << rMayores.PreUni << endl;
	}
	Mayores.close();
	return 0;
} // main

void Abrir(ifstream &May) {
	May.open("Mayores.Dat",ios::binary);
} // Abrir

