// Unidad 2 - Ejercicio 16
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const int k = 15;  // impar
int m[k][k];

void ActualizarIJ(int &i, int &j);
void MostrarMatriz();

int main() {
  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++)
      m[i][j] = 0;

  int i, j;
  for (int h = 1; h <= k * k; h++) {
    if (h == 1) {
      i = 0;
      j = (k - 1) / 2;
    } else {
      ActualizarIJ(i, j);
    }
    m[i][j] = h;
  }

  MostrarMatriz();
  return 0;
}

void ActualizarIJ(int &i_, int &j_) {
  int i = i_, j = j_;
  if (i == 0 && j == k - 1)
    i++;
  else {
    if (i == 0)
      i = k - 1;
    else
      i--;
    if (j == k - 1)
      j = 0;
    else
      j++;
  }

  if (m[i][j] == 0) {
    i_ = i;
    j_ = j;
  } else {
    do {
      if (i_ != k - 1)
        i_++;
      else
        i_ = 0;
    } while (m[i_][j_] != 0);
  }
}

void MostrarMatriz() {
  int ancho = static_cast<int>(ceil(log10(pow(k, 2.0))));

  for (int i = 0; i < k; i++) {
    cout << '|';
    for (int j = 0; j < k; j++) {
      cout << ' ' << setw(ancho) << m[i][j] << ' ';
    }
    cout << "|\n";
  }
}

/*
1- 1 fila columna central
2- El siguiente valor una fila antes y una columna después
3- Si salimos por la fila superior retomamos por la fila inferior respetando la
columna de destino
4- Lo mismo para las columnas
5- Si el casilleor de destina está ocupado, entonces lo que tengo que hacer ir
una fila abajo y mantener la columna
6- Si se sale por el vertice  superior derecho, aplique la regla numero 5
*/
