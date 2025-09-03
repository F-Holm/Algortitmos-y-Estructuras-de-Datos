
/*
	Id.Programa: G4-Ej2 ActualizArtic.Cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: oct-2013
	Comentario.: Actualizacion de Precio en archivo de Articulos.
*/

#include <conio.h>
#include <iomanip>
#include <iostream>
using namespace std;

typedef unsigned short ushort;

struct RegArt {
	ushort CodArt;
	char   Descrip[21];
	float  PreUni;
};

void Abrir(FILE **Art) {
	*Art = fopen("Articulo.Dat","r+b");
} // Abrir

void EmiteDatos(FILE *Art, char cartel[]) {
  RegArt rArt;

  cout << cartel << endl;
  while (fread(&rArt,sizeof rArt,1,Art))
    cout << setw(3) << rArt.CodArt  << ' '
         << setw(20) << left << rArt.Descrip << ' ' << right
         << setw(8) << rArt.PreUni  << endl;
  rewind(Art);
  getchar();
} //EmiteDatos

void ObtDato(float &porc) {
	clrscr();
	gotoxy(10,5); clreol();
	cout << "Porcentaje: ";
	cin >> porc;
} // ObtDato

void ActReg(FILE *Art, RegArt rArt) {
	fseek(Art,ftell(Art) - sizeof(rArt),SEEK_SET);
	fwrite(&rArt,sizeof(rArt),1,Art);
	fseek(Art,ftell(Art),SEEK_SET);
} // ActReg

void main() {
	FILE *Articulos;
	RegArt rArticulo;
	float porcje;

	Abrir(&Articulos);
	cout.precision(2);
	cout << fixed;
	EmiteDatos(Articulos,"Antes...");
	ObtDato(porcje);
	while (fread(&rArticulo,sizeof(rArticulo),1,Articulos)) {
		rArticulo.PreUni *= (1 + porcje / 100);
		ActReg(Articulos,rArticulo);
	}
	rewind(Articulos);
	EmiteDatos(Articulos,"Despues...");
	fclose(Articulos);
}
