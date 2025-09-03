/*
    Id.Programa: G4-Ej07 ApareoStream.cpp
    Autor......: Lic. Hugo Cuello
    Fecha......: jun-2016
    Comentario.: Apareo entre MaeVjo y Nov.
                   Genera MaeNvo y LstErr.
    Lenguaje...: Borland C++ V. 5.5.
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

struct sNov {
  sMae rMaeN;
  char codMov;
};

// Prototipos -----------------------------------------
void Abrir(ifstream &, ofstream &, ifstream &);
void Apareo(ifstream &, ofstream &, ifstream &);
void CerrarEliminarRenombrar(FILE *, FILE *, FILE *);
// Fin Prototipos -------------------------------------

void Abrir(ifstream &MaeV, ofstream &MaeN, ifstream &Nov) {
  MaeV.open("MaeVjo.Dat", ios::in | ios::binary);
  MaeN.open("MaeNvo.Dat", ios::out | ios::binary);
  Nov.open("Noved.Dat", ios::in | ios::binary);
}  // Abrir

void Apareo(ifstream &MaeV, ofstream &MaeN, ifstream &Nov) {
  sMae rMaeV, rMaeN;
  sNov rNov;

  freopen("ErroresABM.Lst", "w", stdout);
  MaeV.read((char *)(&rMaeV), sizeof(rMaeV));
  Nov.read((char *)(&rNov), sizeof(rNov));
  while (!MaeV.eof() && !Nov.eof())
    if (rMaeV.cmpClv == rNov.rMaeN.cmpClv) {
      switch (rNov.codMov) {
        case 'A':
          cout << "Error por Alta Existente,           clave: " << setw(4)
               << rNov.rMaeN.cmpClv << " Ubicacion: " << setw(4)
               << (Nov.tellg() - (long)sizeof(rNov)) / sizeof(rNov) << endl;
          rMaeN = rMaeV;
          MaeN.write((const char *)(&rMaeN), sizeof(rMaeN));
          break;
        case 'M':
          rMaeN = rMaeV;
          rMaeN.cmp1 = rNov.rMaeN.cmp1;
          strcpy(rMaeN.Domic, rNov.rMaeN.Domic);
          MaeN.write((char *)(&rMaeN), sizeof(rMaeN));
          break;
      }
      MaeV.read((char *)(&rMaeV), sizeof(rMaeV));
      Nov.read((char *)(&rNov), sizeof(rNov));
    } else if (rMaeV.cmpClv > rNov.rMaeN.cmpClv) {
      switch (rNov.codMov) {
        case 'A':
          rMaeN = rNov.rMaeN;
          MaeN.write((const char *)(&rMaeN), sizeof(rMaeN));
          break;
        case 'B':
          cout << "Error por Baja inexistente,         clave: " << setw(4)
               << rNov.rMaeN.cmpClv << " Ubicacion: " << setw(4)
               << (Nov.tellg() - (long)sizeof(rNov)) / sizeof(rNov) << endl;
          break;
        default:
          cout << "Error por Modificacion inexistente, clave: " << setw(4)
               << rNov.rMaeN.cmpClv << " Ubicacion: " << setw(4)
               << (Nov.tellg() - (long)sizeof(rNov)) / sizeof(rNov) << endl;
      }
      Nov.read((char *)(&rNov), sizeof(rNov));
    } else {
      rMaeN = rMaeV;
      MaeN.write((const char *)(&rMaeN), sizeof(rMaeN));
      MaeV.read((char *)(&rMaeV), sizeof(rMaeV));
    }

  while (!Nov.eof()) {
    switch (rNov.codMov) {
      case 'A':
        rMaeN = rNov.rMaeN;
        MaeN.write((const char *)(&rMaeN), sizeof(rMaeN));
        break;
      case 'B':
        cout << "Error por Baja inexistente,         clave: " << setw(4)
             << rNov.rMaeN.cmpClv << " Ubicacion: " << setw(4)
             << (Nov.tellg() - (long)sizeof(rNov)) / sizeof(rNov) << endl;
        break;
      default:
        cout << "Error por Modificacion inexistente, clave: " << setw(4)
             << rNov.rMaeN.cmpClv << " Ubicacion: " << setw(4)
             << (Nov.tellg() - (long)sizeof(rNov)) / sizeof(rNov) << endl;
    }
    Nov.read((char *)(&rNov), sizeof(rNov));
  }
  while (!MaeV.eof()) {
    rMaeN = rMaeV;
    MaeN.write((const char *)(&rMaeN), sizeof(rMaeN));
    MaeV.read((char *)(&rMaeV), sizeof(rMaeV));
  }
  freopen("CON", "w", stdout);
}  // Apareo

void CerrarEliminarRenombrar(ifstream &MaeV, ofstream &MaeN, ifstream &Nov) {
  MaeV.close();
  MaeN.close();
  Nov.close();
  // remove("MaeVjo.Dat");
  // rename("MaeNvo.Dat","MaeVjo.Dat");
}  // CerrarEliminarRenombrar

int main() {
  ifstream MaeVjo, Noved;
  ofstream MaeNvo;

  Abrir(MaeVjo, MaeNvo, Noved);
  Apareo(MaeVjo, MaeNvo, Noved);
  CerrarEliminarRenombrar(MaeVjo, MaeNvo, Noved);
  return 0;
}
