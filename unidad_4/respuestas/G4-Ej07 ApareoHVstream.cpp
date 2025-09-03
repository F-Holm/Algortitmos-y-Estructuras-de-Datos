/*
    Id.Programa: G4-Ej07 ApareoHVstream.cpp
    Autor......: Lic. Hugo Cuello
    Fecha......: jun-2016
    Comentario.: Apareo entre MaeVjo y Nov.
                   Genera MaeNvo y LstErr.
                   Tecnica con HIGH_VALUE.
    Lenguaje...: Borland C++ V. 5.5.
*/

#include <fstream>
using namespace std;

#define HIGH_VALUE 10000
// EQUIV. const HIGH_VALUE = 10000;
typedef char str20[21];

struct sMae {
  long cmpClv;
  int cmp1, cmp2;
  str20 RazSoc, Domic, Local;
  long NroCUIT;
};

struct sNov {
  sMae rMaeN;
  char codMov;
};

// Prototipos -------------------------------------------
void Abrir(ifstream &, ofstream &, ifstream &);
void ApareoHV(ifstream &, ofstream &, ifstream &);
void LecHV(ifstream &, sMae &);
void LecHV(ifstream &, sNov &);
void CerrarEliminarRenombrar(ifstream &, ofstream &, ifstream &);
// Fin Prototipos ---------------------------------------

void Abrir(ifstream &MaeV, ofstream &MaeN, ifstream &Nov) {
  MaeV.open("MaeVjo.Dat", ios::binary);
  MaeN.open("MaeNvo.Dat", ios::binary);
  Nov.open("Noved.Dat", ios::binary);
}  // Abrir

void LecHV(ifstream &MaeV, sMae &rMaeV) {
  MaeV.read((char *)&rMaeV, sizeof(rMaeV));
  if (MaeV.eof())
    rMaeV.cmpClv = HIGH_VALUE;
}  // LecHV

void LecHV(ifstream &Nov, sNov &rNov) {
  Nov.read((char *)&rNov, sizeof(rNov));
  if (Nov.eof())
    rNov.rMaeN.cmpClv = HIGH_VALUE;
}  // LecHV

void ApareoHV(ifstream &MaeV, ofstream &MaeN, ifstream &Nov) {
  sMae rMaeV, rMaeN;
  sNov rNov;

  freopen("ErroresABMHD.Lst", "w", stdout);
  LecHV(MaeV, rMaeV);
  LecHV(Nov, rNov);
  while (rMaeV.cmpClv != HIGH_VALUE || rNov.rMaeN.cmpClv != HIGH_VALUE)
    if (rMaeV.cmpClv == rNov.rMaeN.cmpClv) {
      switch (rNov.codMov) {
        case 'A':
          cout << "Error por Alta Existente, clave: " << rNov.rMaeN.cmpClv
               << "Ubicacion: "
               << (Nov.tellg() - (long)sizeof(rNov)) / sizeof(rNov) << endl;
          rMaeN = rMaeV;
          MaeN.write((const char *)&rMaeN, sizeof(rMaeN));
          break;
        case 'M':
          rMaeN = rMaeV;
          rMaeN.cmp1 = rNov.rMaeN.cmp1;
          strcpy(rMaeN.Domic, rNov.rMaeN.Domic);
          MaeN.write((const char *)&rMaeN, sizeof(rMaeN));
          break;
      }
      LecHV(MaeV, rMaeV);
      LecHV(Nov, rNov);
    } else if (rMaeV.cmpClv > rNov.rMaeN.cmpClv) {
      switch (rNov.codMov) {
        case 'A':
          rMaeN = rNov.rMaeN;
          MaeN.write((const char *)&rMaeN, sizeof(rMaeN));
          break;
        case 'B':
          cout << "Error por Baja inexistente, clave: " << rNov.rMaeN.cmpClv
               << "Ubicacion: "
               << (Nov.tellg() - (long)sizeof(rNov)) / sizeof(rNov) << endl;
          break;
        default:
          cout << "Error por Modificacion inexistente, clave: "
               << rNov.rMaeN.cmpClv << "Ubicacion: "
               << (Nov.tellg() - (long)sizeof(rNov)) / sizeof(rNov) << endl;
      }
      LecHV(Nov, rNov);
    } else {
      rMaeN = rMaeV;
      MaeN.write((const char *)&rMaeN, sizeof(rMaeN));
      LecHV(MaeV, rMaeV);
    }
  freopen("CON", "w", stdout);
}  // ApareoHV

void CerrarEliminarRenombrar(ifstream &MaeV, ofstream &MaeN, ifstream &Nov) {
  MaeV.close();
  MaeN.close();
  Nov.close();
  // remove("MaeVjo.Dat");
  // rename("MaeNvo.Dat","MaeVjo.Dat");
}  // CerrarEliminarRenombrar

main() {
  ifstream MaeVjo, Noved;
  ofstream MaeNvo;

  Abrir(MaeVjo, MaeNvo, Noved);
  ApareoHV(MaeVjo, MaeNvo, Noved);
  CerrarEliminarRenombrar(MaeVjo, MaeNvo, Noved);
  return 0;
}
