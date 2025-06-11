// Unidad 2 - Ejercicio 15
#include <iostream>

using namespace std;

typedef unsigned short ushort;
typedef ushort Matriz5[5][5];

bool Completar(Matriz5& m, ushort actual, ushort i, ushort j);
bool Explorar(Matriz5 m, ushort i, ushort j, ushort& i_ret, ushort& j_ret);

int main() {
  Matriz5 m = {{0, 0, 0, 12, 0},
               {8, 0, 0, 0, 0},
               {1, 0, 0, 20, 0},
               {0, 0, 18, 0, 0},
               {0, 4, 0, 0, 0}};
  Completar(m, 1, 2, 0);
  return 0;
}

bool Completar(Matriz5& m, ushort actual, ushort i, ushort j) {}

bool Explorar(Matriz5 m, ushort i, ushort j, ushort& i_ret, ushort& j_ret) {}