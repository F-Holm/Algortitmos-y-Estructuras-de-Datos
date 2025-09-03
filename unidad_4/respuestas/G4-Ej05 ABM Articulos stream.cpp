/*
  Id.Programa: G4-Ej05 ABM Articulos stream.Cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: jun-2016
  Comentario.: Altas, Bajas, Modificaciones, Listar archivo de Articulos.
  Lenguaje...: Borland C++ V. 5.5.
*/

#include <conio.h>

#include <fstream>
#include <iomanip>
using namespace std;

typedef char str20[21];

struct sArt {
  short CodArt;
  str20 Descrip;
  float PreUni;
};

// Prototipos -----------
void Abrir(fstream &);
char Menu();
void Alta(fstream &, short, short);
void Baja(fstream &, short, short);
void Modif(fstream &, short, short);
void Listar(fstream &, short, short);
// Fin Prototipos -------

main() {
  fstream Articulos;
  sArt rArticulo;
  char opc;

  Abrir(Articulos);
  cout.precision(2);
  cout.setf(ios::fixed);
  do {
    opc = Menu();
    switch (opc) {
      case 'A':
        Alta(Articulos, 10, 5);
        break;
      case 'B':
        Baja(Articulos, 10, 5);
        break;
      case 'C':
        Modif(Articulos, 10, 5);
        break;
      case 'D':
        Listar(Articulos, 10, 5);
        break;
    }
  } while (opc != 'E');
  Articulos.close();
  return 0;
}  // main

void Abrir(fstream &Art) {
  Art.open("ArtRel.Dat", ios::binary | ios::in | ios::out);
}  // Abrir

char Menu() {
  char opc;

  clrscr();
  gotoxy(5, 1);
  cout << "Actualizacion Maestro de Articulos";
  gotoxy(10, 5);
  cout << "A: Alta";
  gotoxy(10, 7);
  cout << "B: Baja";
  gotoxy(10, 9);
  cout << "C: Modificacion";
  gotoxy(10, 11);
  cout << "D: Listar";
  gotoxy(10, 13);
  cout << "E: Finalizar";
  do {
    gotoxy(15, 16);
    cout << "Su opcion: ";
    opc = toupper(getch());
  } while (!(opc >= 'A' && opc <= 'E'));
  return opc;
}  // Menu

void MstTit(str20 tit, short x, short y) {
  clrscr();
  gotoxy(5, 1);
  cout << tit;
  gotoxy(x, y);
  cout << "Cod.Articulo:";
  gotoxy(x, y + 2);
  cout << "Descripcion.:";
  gotoxy(x, y + 4);
  cout << "Pre.Unitario:";
}  // MstTit

void ObtClv(short &clvCodArt, short x, short y) {
  gotoxy(1, 24);
  cout << "FIN = 0";
  do {
    gotoxy(x, y);
    clreol();
    cin >> clvCodArt;
  } while (!(clvCodArt <= 100));
}  // ObtClv

bool Existe(fstream &Art, short clvCArt, sArt &rArt) {
  Art.seekg(clvCArt * sizeof rArt, ios::beg);
  Art.read((char *)(&rArt), sizeof rArt);
  return rArt.CodArt == clvCArt;
}  // Existe

void MstCmps(sArt rArt, short x, short y) {
  gotoxy(x, y);
  cout << rArt.Descrip;
  gotoxy(x, y + 2);
  cout << rArt.PreUni;
}  // MstCmps

void ObtCmps(sArt &rArt, short x, short y) {
  do {
    gotoxy(x, y);
    clreol();
    cin.get(rArt.Descrip, 21);
    cin.ignore(1000, '\n');
  } while (!strcmp(rArt.Descrip, ""));
  do {
    gotoxy(x, y + 2);
    clreol();
    cin >> rArt.PreUni;
  } while (!rArt.PreUni);
}  // ObtCmps

void GrabaReg(fstream &Art, sArt rArt) {
  Art.seekp(Art.tellp() - (long)sizeof rArt, ios::beg);
  // Art.seekp(-1 * sizeof rArt, ios::cur);
  Art.write((const char *)(&rArt), sizeof rArt);
}  // GrabaReg

void Mnsj(str20 tit, short x, short y) {
  gotoxy(x, y);
  clreol();
  cout << tit << endl;
  system("pause");
}  // Mnsj

void Alta(fstream &Art, short x, short y) {
  short clvCodArt;
  sArt rArt;

  MstTit("Alta", x, y);
  ObtClv(clvCodArt, 25, 5);
  if (clvCodArt)
    if (!Existe(Art, clvCodArt, rArt)) {
      rArt.CodArt = clvCodArt;
      ObtCmps(rArt, 25, 7);
      GrabaReg(Art, rArt);
    } else
      Mnsj("Alta existente", 1, 24);
}  // Alta

bool Confirma(str20 tit, short x, short y) {
  char SiNo;

  do {
    gotoxy(x, y);
    cout << tit << " (S/N):";
    SiNo = toupper(getch());
  } while (!(SiNo == 'S' || SiNo == 'N'));
  return SiNo == 'S';
}  // Confirma

void Baja(fstream &Art, short x, short y) {
  short clvCodArt;
  sArt rArt;

  MstTit("Baja", x, y);
  ObtClv(clvCodArt, 25, 5);
  if (clvCodArt)
    if (Existe(Art, clvCodArt, rArt)) {
      MstCmps(rArt, 25, 7);
      if (Confirma("Eliminar", 1, 24)) {
        rArt.CodArt = 0;
        GrabaReg(Art, rArt);
      } else
        Mnsj("Baja no confirmada", 1, 24);
    } else
      Mnsj("Baja inexistente", 1, 24);
}  // Baja

void Modif(fstream &Art, short x, short y) {
  short clvCodArt;
  sArt rArt;

  MstTit("Modificacion", x, y);
  ObtClv(clvCodArt, 25, 5);
  if (clvCodArt)
    if (Existe(Art, clvCodArt, rArt)) {
      MstCmps(rArt, 25, 7);
      do {
        gotoxy(25, 9);
        clreol();
        cin >> rArt.PreUni;
      } while (!rArt.PreUni);
      GrabaReg(Art, rArt);
    } else
      Mnsj("Modificacion inexistente", 1, 24);
}  // Modif

void MstTitListar(str20 tit, short x, short y) {
  clrscr();
  gotoxy(5, 1);
  cout << tit;
  gotoxy(x, y);
  cout << "Cod.Art.Dsd.:";
  gotoxy(x, y + 2);
  cout << "Cod.Art.Hst.:";
}  // MstTitListar

void MstTitLst(short &nOrd, short cArtDsd, short cArtHst) {
  clrscr();
  gotoxy(5, 1);
  cout << "Listado de Articulos desde " << cArtDsd << " hasta " << cArtHst
       << endl;
  cout << setw(7) << "" << "Nro.Ord. Cod.Art. Descripcion            Pre.Uni."
       << endl;
  nOrd = 0;
}  // MstTitLst

void Listar(fstream &Art, short x, short y) {
  short clvCodArtDsd, clvCodArtHst, nroOrd;
  sArt rArt;

  MstTitListar("Listar", x, y);
  ObtClv(clvCodArtDsd, 25, 5);
  ObtClv(clvCodArtHst, 25, 7);
  MstTitLst(nroOrd, clvCodArtDsd, clvCodArtHst);
  Art.seekg(clvCodArtDsd * sizeof rArt, ios::beg);
  for (short i = clvCodArtDsd; i <= clvCodArtHst; i++) {  // clvhst - clvdsd + 1
    Art.read((char *)(&rArt), sizeof rArt);
    if (rArt.CodArt) {
      nroOrd++;
      cout << setw(9) << ' ' << setw(3) << nroOrd << setw(6) << ' ' << setw(3)
           << rArt.CodArt << setw(4) << "" << setw(20) << left << rArt.Descrip
           << ' ' << setw(9) << right << rArt.PreUni << endl;
    }
  }
  cout << endl;
  system("pause");
}  // Listar
