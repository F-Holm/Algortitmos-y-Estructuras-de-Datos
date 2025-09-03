/*
   Id.Programa: CuadradoPerfectoEuler.cpp
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
#include <conio>
#include <iomanip>

main() {
  short i = 0, j, n;
  short mat[16][16] = {0};
  short vCol[17] = {0};
  short sumaFila;
  short sumaDiagPpal = 0;
  short sumaDiagSec = 0;

  cout << "Ing. cantidad de filas o cols. impar: ";
  do {
    gotoxy(40, 1);
    clreol();
    cin >> n;
  } while (!(n % 2));
  j = n / 2;
  cout << "Elemento central: " << (pow(n, 2) + 1) / 2 << ' '
       << "Suma p/c(F-C-DP-DS): " << (pow(n, 2) + 1) / 2 * n << endl;
  for (short num = 1; num <= n * n; num++) {
    mat[i][j] = num;
    i--;
    j++;
    if (i == -1 && j == n) {
      i += 2;
      j--;
    } else if (i == -1)
      i = n - 1;
    else if (j == n)
      j = 0;
    else if (mat[i][j]) {
      i += 2;
      j--;
    }
  }

  for (short i = 0; i < n; i++) {
    sumaFila = 0;
    for (short j = 0; j < n; j++) {
      cout << setw(4) << mat[i][j];
      sumaFila += mat[i][j];
      vCol[j] += mat[i][j];
      if (i == j)
        sumaDiagPpal += mat[i][j];
      if (n - i - 1 == j)
        sumaDiagSec += mat[n - i - 1][j];
    }
    cout << " = " << setw(4) << sumaFila;
    cout << endl;
  }
  cout << "------------------------------------" << endl;
  vCol[n] = sumaDiagPpal;
  for (short i = 0; i < n; i++)
    cout << setw(4) << vCol[i];
  cout << endl << "Suma Diag. Papl.: " << setw(4) << vCol[n];
  cout << endl << "Suma Diag. Sec. : " << setw(4) << sumaDiagSec;

  return 0;
}
