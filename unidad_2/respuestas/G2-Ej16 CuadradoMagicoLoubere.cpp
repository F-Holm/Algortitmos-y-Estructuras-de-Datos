/*
   Id.Programa: CuadradoMagicoEuler.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: ago-2000
   Comentario.: Matriz de n x n con elementos entero
                 desde 1 hasta n^2, en donde, la suma
                 de cada fila, de cada columna y de
                 ambas diagonales (principal y secundaria)
                 dan el mismo valor x.
*/

#include <fstream>
using namespace std;
#include <iomanip>
#include <conio>
#define repeat do
#define until while
#define and &&
#define or ||
#define not !

const
  MAX_CF = 16;

typedef short tMat0[MAX_CF][MAX_CF];
typedef short tMat1[MAX_CF+1][MAX_CF+1];

void CantFilasImpar(short &cant) {
  cout << "Ing. cantidad de filas o cols. impar: ";
  repeat {
    gotoxy(40,1);
    clreol();
    cin >> cant;
  }
  until (!(cant % 2 and cant > 2 and cant < MAX_CF));
} // CantFilasImpar

void CuadradoMagico0(tMat0 mat, short max_cf) {
  short i = 0,
        j,
        maxElemCuad = pow(max_cf,2);

  j = max_cf / 2;

  for (short num = 1; num <= maxElemCuad; num++) {
    mat[i][j] = num;
    i--;
    j++;
    if (i == -1 and j == max_cf) {
      i+= 2;
      j--;
    }
    else
      if (i == -1)
        i = max_cf - 1;
      else
        if (j == max_cf)
          j = 0;
          else
            if (mat[i][j]) {
              i+= 2;
              j--;
            }
  }
} // CuadradoMagico0

void CuadradoMagico1(tMat1 mat, short max_cf) {
  short i = 1,
        j,
        maxElemCuad = pow(max_cf,2);

  j = (max_cf + 1) / 2;
  for (short num = 1; num <= maxElemCuad; num++) {
    mat[i][j] = num;
    i--;
    j++;
    if (i == 0 and j == max_cf + 1) {
      i+= 2;
      j--;
    }
    else
      if (i == 0)
        i = max_cf;
      else
        if (j == max_cf+1)
          j = 1;
          else
            if (mat[i][j]) {
              i+= 2;
              j--;
            }
  }
} // CuadradoMagico1

void EmiteSumasCuadradoMagico0(tMat0 mat, short max_cf) {
  short vCol[MAX_CF + 1] = {0},
        sumaFila,
        sumaDiagPpal = 0,
        sumaDiagSec = 0,
        maxElemCuad = pow(max_cf,2);

  cout << "*Elemento central: " << (maxElemCuad + 1) / 2 << ' '
       << "*Suma p/c(F-C-DP-DS): " << (maxElemCuad + 1) / 2 * max_cf << endl;
  for (short i = 0; i < max_cf; i++) {
    sumaFila = 0;
    for (short j = 0; j < max_cf; j++) {
      cout << setw(4) << mat[i][j];
      sumaFila += mat[i][j];
      vCol[j] += mat[i][j];
      if (i == j)
        sumaDiagPpal += mat[i][j];
      if (max_cf - i - 1 == j)
        sumaDiagSec += mat[max_cf - i - 1][j];
    }
    cout << " = " << setw(4) << sumaFila;
    cout << endl;
  }
  cout << "------------------------------------" << endl;
  vCol[max_cf] = sumaDiagPpal;
  for (short i = 0; i < max_cf; i++)
    cout << setw(4) << vCol[i];
  cout << endl << "Suma Diag. Papl.: " << setw(4) << vCol[max_cf];
  cout << endl << "Suma Diag. Sec. : " << setw(4) << sumaDiagSec;
  cout << endl;
} // EmiteSumasCuadradoMagico0

void EmiteSumasCuadradoMagico1(tMat1 mat, short max_cf) {
  short vCol[MAX_CF + 1] = {0},
        sumaFila,
        sumaDiagPpal = 0,
        sumaDiagSec = 0,
        maxElemCuad = pow(max_cf,2);

  cout << "+Elemento central: " << (maxElemCuad + 1) / 2 << ' '
       << "+Suma p/c(F-C-DP-DS): " << (maxElemCuad + 1) / 2 * max_cf << endl;
  for (short i = 1; i <= max_cf; i++) {
    sumaFila = 0;
    for (short j = 1; j <= max_cf; j++) {
      cout << setw(4) << mat[i][j];
      sumaFila += mat[i][j];
      vCol[j] += mat[i][j];
      if (i == j)
        sumaDiagPpal += mat[i][j];
      if (max_cf - i + 1 == j)
        sumaDiagSec += mat[max_cf - i + 1][j];
    }
    cout << " = " << setw(4) << sumaFila;
    cout << endl;
  }
  cout << "------------------------------------" << endl;
  vCol[max_cf] = sumaDiagPpal;
  for (short i = 1; i <= max_cf; i++)
    cout << setw(4) << vCol[i];
  cout << endl << "Suma Diag. Papl.: " << setw(4) << vCol[max_cf];
  cout << endl << "Suma Diag. Sec. : " << setw(4) << sumaDiagSec;
  cout << endl;
} // EmiteSumasCuadradoMagico1

int main() {
  short n;
  short mat0[MAX_CF][MAX_CF] = {0};
  short mat1[MAX_CF+1][MAX_CF+1] = {0};

  CantFilasImpar(n);
  CuadradoMagico0(mat0,n);
  CuadradoMagico1(mat1,n);
  EmiteSumasCuadradoMagico0(mat0,n);
  EmiteSumasCuadradoMagico1(mat1,n);
  return 0;
}
