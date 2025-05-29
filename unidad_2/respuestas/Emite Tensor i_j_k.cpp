/*
  Emite Tensor i_j_k.cpp
  Fecha......: sep-2019
  Autor......: Lic. Hugo Cuello
  Comentario.: Tensor i: Fila, j: Columna, k: Profundidad.
               Emite el tensor for i, for j, for k.
*/

#include <iomanip>
#include <fstream>
using namespace std;

typedef short tVec[5];
typedef tVec tMat[100][10];
// typedef short tTensor[100][10][5];

int main() {
  tMat mat;

  for (auto i = 0; i < 100; i++)
    for (auto j = 0; j < 10; j++)
      for (auto k = 0; k < 5; k++)
        mat[i][j][k] = random(900) + 100;

  freopen("Tensor i_j_k.Txt","w",stdout);
  for (auto i = 0; i < 100; i++) {
    for (auto j = 0; j < 10; j++) {
      cout << "F(" << setw(2) << i << "),C(" << j << "): ";
      for (auto k = 0; k < 5; k++)
        cout << setw(4) << mat[i][j][k] << ' ';
      cout << endl;
    }
    cout << endl << endl;
  }
  freopen("CON","w",stdout);
  return 0;
}
