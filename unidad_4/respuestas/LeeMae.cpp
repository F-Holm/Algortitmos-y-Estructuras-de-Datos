/*
    Id.Programa: LeeMae.cpp Apareo
    Autor......: Lic. Hugo Cuello
    Fecha......: sep-2019
    Comentario.: Lee bin graba txt.
*/

#include <fstream>
#include <iomanip>
using namespace std;

typedef char str20[21];

struct sMae {
  long cmpClv;
  int cmp1, cmp2;
  str20 RazSoc, Domic, Local;
  long NroCUIT;
};

string replicate(char car, unsigned n) {
  string cad = "";

  for (unsigned i = 1; i <= n; i++)
    cad += car;
  return cad;
}  // replicate

main() {
  ifstream Mae("MaeNvo.Dat", ios::binary);
  sMae rMae;
  short i = 0;

  freopen("MaeNvo.Txt", "w", stdout);
  cout << replicate('-', 93) << endl;
  cout << "Ord. cClv cmp1 cmp2 Raz. Soc.            Domicilio"
       << "            Localidad             Nro. CUIT" << endl;
  cout << replicate('-', 93) << endl;
  while (Mae.read((char *)&rMae, sizeof rMae))
    cout << right << setw(4) << ++i << ' ' << setw(4) << rMae.cmpClv << ' '
         << setw(4) << rMae.cmp1 << ' ' << setw(4) << rMae.cmp2 << ' ' << left
         << setw(20) << rMae.RazSoc << ' ' << setw(20) << rMae.Domic << ' '
         << setw(20) << rMae.Local << ' ' << right << setw(10) << rMae.NroCUIT
         << endl;
  cout << replicate('-', 93) << endl;
  freopen("CON", "w", stdout);
  Mae.close();
  return 0;
}
