/*
        Id.Programa: G4-Ej06 CorteCtrl stream.cpp     Corte de Control n = 2.
        Autor......: Lic. Hugo Cuello
        Fecha......: jun-2016
        Comentario.: Examen a alumnos de distintas Universidades y Facultades.
                   Tecnica de Corte de Control.
    Lenguaje...: Borland C++ V. 5.5.
*/

#include <fstream>
#include <iomanip>
using namespace std;

typedef unsigned int word;
typedef unsigned short ushort;
typedef char str5[6];
typedef char str15[16];
typedef char str20[21];

struct sExa {
  str5 CodUni,
      CodFacu;   // 12
  long NroLeg;   //   4
  str20 ApeNom;  //  21
  ushort Nota;   //   2  = 39 + 1 ushort DE RELLENO = 40 ushortS
};

// Prototipos ---------------------------------------------------------
void Abrir(ifstream &Examen);
void Inic(word &totInsGral, word &totAprGral);
void EmiteCabLst();
void IniCab(word &totIns, word &totApr, str5 Clave, str5 ClaveAnt);
void EmiteCabCte(str15 titulo, str5 codigo);
void ProcAlum(sExa rExa, word &tInsFacu, word &tAprFacu);
void CalcPie(word totIns, word totApr, word &totInsM, word &totAprM);
void EmitePie(str15 titulo, word totInsFacu, word totAprFacu);
// Fin Prototipos -----------------------------------------------------

main() {
  ifstream Examenes;
  sExa rExamen;
  word totInsGral, totAprGral, totInsUni, totAprUni, totInsFacu, totAprFacu;
  str5 UniAnt, FacuAnt;

  Abrir(Examenes);
  freopen("Examenes.Lst", "w", stdout);
  Inic(totInsGral, totAprGral);
  EmiteCabLst();
  Examenes.read((char *)(&rExamen), sizeof(rExamen));
  while (!Examenes.eof()) {
    IniCab(totInsUni, totAprUni, rExamen.CodUni, UniAnt);
    EmiteCabCte("*Cod.Univ.: ", rExamen.CodUni);
    while (!Examenes.eof() && strcmp(rExamen.CodUni, UniAnt) == 0) {
      IniCab(totInsFacu, totAprFacu, rExamen.CodFacu, FacuAnt);
      EmiteCabCte("**Cod.Fac.: ", rExamen.CodFacu);
      while (!Examenes.eof() && strcmp(rExamen.CodUni, UniAnt) == 0 &&
             strcmp(rExamen.CodFacu, FacuAnt) == 0) {
        ProcAlum(rExamen, totInsFacu, totAprFacu);
        Examenes.read((char *)(&rExamen), sizeof(rExamen));
      }
      CalcPie(totInsFacu, totAprFacu, totInsUni, totAprUni);
      EmitePie("Facu.: ", totInsFacu, totAprFacu);
    }
    CalcPie(totInsUni, totAprUni, totInsGral, totAprGral);
    EmitePie("Univ..: ", totInsUni, totAprUni);
  }
  EmitePie("General: ", totInsGral, totAprGral);
  freopen("CON", "w", stdout);
  Examenes.close();
  return 0;
}  // main

void Abrir(ifstream &Exa) {
  Exa.open("Examenes.Dat", ios::binary);
}  // Abrir

void Inic(word &tInsG, word &tAprG) {
  tInsG = tAprG = 0;
}  // Inic

void EmiteCabLst() {
  cout << "Listado examen a alumnos Aprobados" << endl;
}  // EmiteCab

void IniCab(word &totIns, word &totApr, str5 Clave, str5 ClaveAnt) {
  totIns = totApr = 0;
  strcpy(ClaveAnt, Clave);
}  // IniCab

void EmiteCabCte(str15 titulo, str5 codigo) {
  cout << endl << titulo << " " << codigo;
  if (strstr(titulo, "Fac") != NULL)
    cout << endl << setw(5) << " " << "Nro.Leg.  Nota" << endl;
}  // EmiteCabCte

void ProcAlum(sExa rExa, word &tInsFacu, word &tAprFacu) {
  ++tInsFacu;
  if (rExa.Nota >= 4) {
    ++tAprFacu;
    cout << setw(6) << "  " << setw(6) << rExa.NroLeg << "    " << setw(2)
         << rExa.Nota << endl;
  }
}  // ProcAlum

void CalcPie(word totIns, word totApr, word &totInsM, word &totAprM) {
  totInsM += totIns;
  totAprM += totApr;
}  // CalcPie

string replicate(char car, unsigned n) {
  string cad = "";

  for (unsigned i = 1; i <= n; i++)
    cad += car;
  return cad;
}  // replicate

void EmitePie(str15 titulo, word totIns, word totApr) {
  string ast;

  if (titulo[0] == 'F')
    ast = replicate('*', 2);
  else if (titulo[0] == 'U')
    ast = replicate('*', 1);
  cout << endl;
  cout << " " << ast << "Tot.Insc. " << titulo << " " << setw(6) << totIns
       << endl;
  cout << " " << ast << "Tot.Apr.. " << titulo << " " << setw(6) << totApr
       << endl;
  cout << endl;
}  // EmitePie
