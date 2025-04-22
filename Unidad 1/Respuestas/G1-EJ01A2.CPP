/*
	Id.Programa: G1-Ej01a2.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Dados las medidas de los 2 catetos de un triangulo rectangulo,
	              hallar la 	Lenguaje...: cygwin64 gcc 64bits for windows
	              medida de su hipotenusa.
	              Version modularizada 2.
	Lenguaje...: Borland V.5.5
*/

#include <fstream>
using namespace std;

void ObtDatos (float &cata, float &catb) {
  cout << "Calculo hipotenusa con datos de catetos a y b" << endl;
  do {
    cout << "Cateto a: ";
    cin >> cata;
    cout << "Cateto b: ";
    cin >> catb;
  }
  while ( cata + catb == 0);
}  // ObtDatos

float CalcHipot (float cata, float catb) {
  return sqrt(pow(cata,2) + pow(catb,2));
} // CalcHipot

void EmiteHipot (float hipot) {
  cout << "Hipotenusa: " << hipot << endl;
} // EmiteHipot

main () {
  float a,
        b;

  ObtDatos(a,b);
  EmiteHipot(CalcHipot(a,b));
  return 0;
}
