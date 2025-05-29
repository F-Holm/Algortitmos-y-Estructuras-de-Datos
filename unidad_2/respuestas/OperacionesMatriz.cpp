

#include <fstream>
#include <iomanip>
#include <iostream>
#include "borland.h"
using namespace std;
const int
  MAX_FILAS = 5,
  MAX_COLS  = 5;

void GeneraMatriz(short m[][MAX_COLS]) {
  for (short i = 0; i < MAX_FILAS; i++)
    for (short j = 0; j < MAX_COLS; j++)
        m[i][j] = random(101) + 100;
} // GeneraMatriz

void EmiteMatriz(short m[][MAX_COLS]) {
  cout << "Elementos de la matriz" << endl;
  for (short i = 0; i < MAX_FILAS; i++) {
    for (short j = 0; j < MAX_COLS; j++)
        cout << setw(3) << m[i][j] << ' ';
    cout << endl;
  }
  cout << "---------------------" << endl;
} // EmiteMatriz

void EmiteElemDiagPpal(short m[][MAX_COLS]) {
  cout << "Elementos de la diagonal principal" << endl;
  for (short i = 0; i < MAX_FILAS; i++)
    cout << m[i] [i] << ' ';
  cout << endl;
  cout << "---------------------" << endl;
} // EmiteElemDiagPpal

void EmiteElemDiagSec(short m[][MAX_COLS]) {
  cout << "Elementos de la diagonal secundaria" << endl;
  for (short i = 0; i < MAX_FILAS; i++)
    cout << m[i] [MAX_FILAS - i - 1] << ' ';
  cout << endl;  cout << "---------------------" << endl;
} // EmiteElemDiagSec

void LinealizarMatrizEnVector(short m[][MAX_COLS], short v[]) {
  for (short i = 0; i < MAX_FILAS; i++)
    for (short j = 0; j < MAX_COLS; j++)
      v[i * MAX_COLS + j] = m[i][j];
} // LinealizarMatrizEnVector

void EmiteVector(short v[]) {
  cout << "Elementos del vector" << endl;
  for (short i = 0; i < MAX_FILAS * MAX_COLS; i++)
    cout << setw(3) << v[i] << ' ';
  cout << endl;  cout << "---------------------" << endl;
} // EmiteVector

void EmiteTriangularSup(short m[][MAX_COLS]) {
  for (short i = 0; i < MAX_FILAS; i++) {
    for (short j = i + 1; j < MAX_COLS; j++)
      cout << m[i][j] << ' ';
    cout << endl;
    cout << setw((i+1)*4) << ' ';
  }
} // EmiteTriangularSup

void EmiteTriangularInf(short m[][MAX_COLS]) {
  cout << endl;
  for (short i = 1; i < MAX_FILAS; i++) {
    for (short j = 0; j < i; j++ )
      cout << m[i][j] << ' ';
    cout << endl;
  }
} // EmiteTriangularInf

int main() {
  short a[MAX_FILAS][MAX_COLS],
        b[MAX_FILAS * MAX_COLS];

  GeneraMatriz(a);
  EmiteMatriz(a);
  EmiteElemDiagPpal(a);
  EmiteElemDiagSec(a);
  LinealizarMatrizEnVector(a,b);
  EmiteVector(b);
  EmiteTriangularSup(a);
  EmiteTriangularInf(a);
  return 0;
}
