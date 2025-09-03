/*
    Id.Programa: G4Ej17Rutas.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: septiembre-2014
    Comentario.: Consultas de Localidades.

    *Estructuras de Datos

    Vector de Localidades con nomLoc (str20) CON MAX_LOC ord. ascendente.
    Matriz cuadrada de Rutas con Distancias_NroRutas con MAX_LOC:
      Inicializar en cero la matirz con la cantidad de Localidades canLoc.
      procesadas en el archivo de Localidades.
      Distancias en la triangular inferior (i > j)
      Nros. de Rutas en la triangular superior (i < j)
*/

#include <conio.h>

#include <iomanip>
#include <iostream>
using namespace std;

#define readf(file, buf) fread(&(buf), sizeof((buf)), 1, (file))

const MAX_LOC = 100;

typedef char str20[21];
typedef unsigned char byte;
typedef unsigned short word;

struct sRut {
  str20 nomLoc1, nomLoc2;
  word dist, nroRuta;
};

typedef str20
    tvLoc[MAX_LOC + 1];  // tvLoc es el vector de Localidades, pos. 0 no se usa
typedef word tmRut[MAX_LOC + 1][MAX_LOC + 1];  // tmRut es la matriz de Rutas
                                               //(Tri.Inf.: Dist., Tri.Sup.:
                                               // NroRuta) pos. 0 no se usa

// Prototipos ------------------------------
void Abrir(FILE **, FILE **);
void IntCmb(str20, str20);
void IntCmb(byte &, byte &);
void OrdxBur(tvLoc, byte);
void GenLocal(FILE *, tvLoc, byte &);
void InicRut(tmRut, byte);
byte BusBinVec(tvLoc, str20, byte);
void GenRutas(FILE *, tmRut, tvLoc, byte);
void EmiteMat(tmRut, tvLoc, byte);
void ObtLocal(byte &, byte &, tvLoc, byte);
void EncontroLoc(word &, word &, str20, bool &, word, word, word);
void CalcDist(tmRut, byte, byte, byte, word &, word &, str20, word &, word &);
void EmiteDist(word, word, str20, tvLoc, word, word);
void Cerrar(FILE *, FILE *);
// Fin Prototipos --------------------------

void Abrir(FILE **Loc, FILE **Rut) {
  *Loc = fopen("Localidades.Dat", "rb");
  *Rut = fopen("Rutas.Dat", "rb");
}  // Abrir

void IntCmb(str20 elem1, str20 elem2) {
  str20 aux;

  strcpy(aux, elem1);
  strcpy(elem1, elem2);
  strcpy(elem2, aux);
}  // IntCmb

void IntCmb(byte &elem1, byte &elem2) {
  byte aux;

  aux = elem1;
  elem1 = elem2;
  elem2 = aux;
}  // IntCmb

void OrdxBur(tvLoc vLoc, byte card) {
  bool ordenado;
  byte k = 0;

  do {
    ordenado = true;
    k++;
    for (byte i = 1; i <= card - k; i++)
      if (strcmp(vLoc[i], vLoc[i + 1]) > 0) {
        ordenado = false;
        IntCmb(vLoc[i], vLoc[i + 1]);
      }
  } while (!ordenado);
}  // OrdxBur

void GenLocal(FILE *Loc, tvLoc vLoc, byte &cLoc) {
  cLoc = 0;
  while (readf(Loc, vLoc[++cLoc]))
    ;
  cLoc--;
  OrdxBur(vLoc, cLoc);
}  // GenLocal

void InicRut(tmRut mRut, byte cLoc) {
  for (byte i = 1; i <= cLoc; i++)
    for (byte j = 1; j <= cLoc; j++)
      mRut[i][j] = 0;
}  // InicRut

byte BusBinVec(tvLoc vLoc, str20 cLoc, byte ult) {
  byte pri = 1, med;

  while (pri <= ult) {
    med = (pri + ult) / 2;
    if (!strcmp(vLoc[med], cLoc))
      return med;
    else if (strcmp(vLoc[med], cLoc) < 0)
      pri = med + 1;
    else
      ult = med - 1;
  }
  return 0;
}  // BusBinVec

void GenRutas(FILE *Rut, tmRut mRut, tvLoc vLoc, byte cLoc) {
  sRut rRut;
  byte pos_i, pos_j;

  InicRut(mRut, cLoc);
  while (readf(Rut, rRut)) {
    pos_i = BusBinVec(vLoc, rRut.nomLoc1, cLoc);
    pos_j = BusBinVec(vLoc, rRut.nomLoc2, cLoc);
    if (pos_i > pos_j) {
      mRut[pos_i][pos_j] = rRut.dist;
      mRut[pos_j][pos_i] = rRut.nroRuta;
    } else {
      mRut[pos_j][pos_i] = rRut.dist;
      mRut[pos_i][pos_j] = rRut.nroRuta;
    }
  }
}  // GenRutas

void EmiteMat(tmRut mRut, tvLoc vLoc, byte cLoc) {
  char nLoc[5];

  // Matriz Triangular Superior indica Nro.de Rutas entre 2 Localidades
  // Matriz Triangular Inferior indica Dist. entre 2 Localidades
  cout << setw(21) << "";
  for (byte i = 1; i <= cLoc; i++) {
    strncpy(nLoc, vLoc[i], 4);
    nLoc[4] = '\0';
    cout << setw(4) << nLoc << ' ';
  }
  cout << endl;
  for (byte i = 1; i <= cLoc; i++) {
    cout << setw(20) << vLoc[i];
    for (byte j = 1; j <= cLoc; j++)
      cout << setw(5) << mRut[i][j];
    cout << endl;
  }
}  // EmiteMat

void ObtLocal(byte &d1, byte &d2, tvLoc vLoc, byte cLoc) {
  str20 nLoc1, nLoc2;
  char *pcad;

  do {
    gotoxy(5, 15);
    clreol();
    cout << "Ing.Nom.Loc.1: ";
    strupr(gets(nLoc1));
    d1 = BusBinVec(vLoc, nLoc1, cLoc);
  } while (d1 == 0);
  do {
    gotoxy(5, 17);
    clreol();
    cout << "Ing.Nom.Loc.2: ";
    strupr(gets(nLoc2));
    d2 = BusBinVec(vLoc, nLoc2, cLoc);
  } while (d2 == 0);
}  // ObtLocal

void EncontroLoc(word &dist, word &locInt, str20 mnsj, bool &existe, word km1,
                 word km2, word x, word &ckm1, word &ckm2) {
  dist = km1 + km2;
  ckm1 = km1;
  ckm2 = km2;
  strcpy(mnsj, "Dist. pasando por ");
  locInt = x;
  existe = true;
  cout << "Encontro la Localidad... " << endl;
}  // EncontroLoc

void CalcDist(tmRut mRut, byte cLoc, byte i, byte j, word &dist, word &locInt,
              str20 mnsj, word &km1, word &km2) {
  bool existe;
  byte pos_j, k, aux;

  if (j > i)
    IntCmb(i, j);
  dist = locInt = 0;
  strcpy(mnsj, "No hay ruta");
  if (mRut[i][j]) {
    dist = mRut[i][j];
    strcpy(mnsj, "Distancia directa ");
  } else {
    existe = false;
    cLoc++;
    k = i + 1;
    pos_j = 1;
    while ((i > pos_j || cLoc > k) && !existe) {
      if (i > pos_j)
        // Recorrer fila mientras fila i > columna j
        if (mRut[i][pos_j])
          if (pos_j <= j)
            if (mRut[pos_j][j])
              EncontroLoc(dist, locInt, mnsj, existe, mRut[i][pos_j],
                          mRut[j][pos_j], pos_j, km1, km2);
            else
              pos_j++;
          else if (mRut[j][pos_j])
            EncontroLoc(dist, locInt, mnsj, existe, mRut[i][pos_j],
                        mRut[pos_j][j], pos_j, km1, km2);
          else
            pos_j++;
        else
          pos_j++;
      else  // ( i < j )
        // Recorrer Columna j desde fila i + 1 hasta ultima fila
        if (mRut[k][pos_j])
          if (mRut[k][j])
            EncontroLoc(dist, locInt, mnsj, existe, mRut[k][pos_j], mRut[k][j],
                        k, km1, km2);
          else
            k++;
        else
          k++;
    }
  }
}  // CalcDist

void EmiteDist(word dist, word locInt, str20 mnsj, tvLoc vLoc, word km1,
               word km2) {
  if (!dist)
    cout << mnsj << " hasta un nivel";
  else if (!locInt)
    cout << mnsj << " es: " << dist;
  else
    cout << mnsj << vLoc[locInt] << ' ' << km1 << " + " << km2
         << " es: " << dist;
  getch();
}  // EmiteDist

void Cerrar(FILE *Loc, FILE *Rut) {
  fclose(Loc);
  fclose(Rut);
}  // Cerrar

main() {
  FILE *Localidades, *Rutas;
  byte i, j, cantLocal = 0;
  word localInt, distan, dist1, dist2;
  str20 mens;
  tvLoc vLocal;
  tmRut mRutas;

  Abrir(&Localidades, &Rutas);
  GenLocal(Localidades, vLocal, cantLocal);
  GenRutas(Rutas, mRutas, vLocal, cantLocal);
  EmiteMat(mRutas, vLocal, cantLocal);
  ObtLocal(i, j, vLocal, cantLocal);
  CalcDist(mRutas, cantLocal, i, j, distan, localInt, mens, dist1, dist2);
  EmiteDist(distan, localInt, mens, vLocal, dist1, dist2);
  Cerrar(Localidades, Rutas);
  return 0;
}  // main
