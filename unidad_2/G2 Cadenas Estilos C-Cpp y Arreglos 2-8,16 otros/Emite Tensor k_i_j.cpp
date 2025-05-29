/*
  Id.Programa: Emite Tensor k_i_j.cpp
  Fecha......: sep-2019
  Autor......: Lic. Hugo Cuello
  Comentario.: Tensor i: Fila, j: Columna, k: Profundidad.
               Emite el tensor for k, for i, for j.
*/

#include <iomanip>
#include <fstream>
using namespace std;

typedef short tVec[5];
typedef tVec tMat[100][10];
// typedef short tTensor[100][10][5];

main() {
  tMat mat;

  for (auto i = 0; i < 100; i++)
    for (auto j = 0; j < 10; j++)
      for (auto k = 0; k < 5; k++)
        mat[i][j][k] = random(900) + 100;

  freopen("Tensor k_i_j.Txt","w",stdout);
  for (auto k = 0; k < 5; k++) {
    for (auto i = 0; i < 100; i++) {
      cout << "P(" << k << "),F(" << setw(2) << i << "): ";
      for (auto j = 0; j < 10; j++)
        cout << setw(4) << mat[k][i][j] << ' ';
      cout << endl;
    }
    cout << endl << endl;
  }
  freopen("CON","w",stdout);
  return 0;
}
