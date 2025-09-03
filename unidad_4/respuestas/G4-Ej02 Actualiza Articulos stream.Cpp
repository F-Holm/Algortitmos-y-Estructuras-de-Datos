/*
	Id.Programa: G4-Ej05 Actualiza Articulos stream.Cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: jun-2016
	Comentario.: Actualizacion de Precio en archivo de Articulos.
    Lenguaje...: Borland C++ V. 5.5.
*/

#include <conio.h>
#include <iomanip.h>
#include <fstream>
using namespace std;

#define modeOpen ios::in | ios::out | ios::binary

typedef char str20[21];
typedef unsigned short ushort;

struct sArt {
	short CodArt;
	str20  Descrip;
	float  PreUni;
};

// Prototipos ------------------

void ObtDato(float &);
void ActReg(fstream &, sArt );
// Fin Prototipos --------------

void ObtDato(float &porc) {
	clrscr();
	gotoxy(10,5); clreol();
	cout << "Porcentaje: ";
	cin >> porc;
} // ObtDato

void ActReg(fstream &Art, sArt rArt) {

	Art.seekg(-1*sizeof rArt,ios::cur);
    Art.write((const char *) &rArt, sizeof rArt);
} // ActReg

main() {
	sArt  rArticulo;
	float porcje;
    long  pos;
    fstream Articulos;

    cout << setprecision(2); //cout.precision(2);
    cout << fixed;           //cout.setf(ios::fixed);
    Articulos.open("Articulos.Dat", modeOpen);
	ObtDato(porcje);
	cout << "Ptr.lee: " << Articulos.tellg()/sizeof rArticulo
	<< " Ptr.graba: " << Articulos.tellp()/sizeof rArticulo << endl << endl;
	while (Articulos.read((char *) &rArticulo,sizeof(rArticulo))) {
      cout << setw(4) << rArticulo.CodArt << ' ' << left << setw(20)
           << rArticulo.Descrip << ' '
           << right << setw(8) << rArticulo.PreUni << endl;
	  cout << "Ptr.lee: " << Articulos.tellg()/sizeof rArticulo
	       << " Ptr.graba: " << Articulos.tellp()/sizeof rArticulo << endl;
      rArticulo.PreUni *= (1 + porcje / 100);
      ActReg(Articulos,rArticulo);
      cout << "Ptr.lee: " << Articulos.tellg()/sizeof rArticulo
	       << " Ptr.graba: " << Articulos.tellp()/sizeof rArticulo << endl;
      cout << "* " << setw(4) << rArticulo.CodArt << ' ' << left << setw(20)
           << rArticulo.Descrip << ' '
           << right << setw(8) << rArticulo.PreUni << endl;
	}
	Articulos.close();
	return 0;
}




