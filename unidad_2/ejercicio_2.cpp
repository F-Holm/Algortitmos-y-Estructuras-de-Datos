// Unidad 2 - Ejercicio 2
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

#define TAMANO 50

short Maximo(const short *v) {
  short max = -32768;
  for (int i = 0; i < TAMANO; i++) {
    if (v[i] > max) max = v[i];
  }
  return max;
}
short Minimo(const short *v) {
  short min = 32767;
  for (int i = 0; i < TAMANO; i++) {
    if (v[i] < min) min = v[i];
  }
  return min;
}
int Sumatoria(const short *v) {
  int sum = 0;
  for (int i = 0; i < TAMANO; i++) {
    sum += v[i];
  }
  return sum;
}
double Promedio(const short *v) { return Sumatoria(v) / (double)TAMANO; }

char Menu() {
  cout << "\n1 promedio, 2 máximo, 3 mínimo, 4 sumatoria, 5 salir." << endl;
  char opcion;
  cin >> opcion;
  return opcion;
}

void GenerarVector(short *v) {
  for (int i = 0; i < TAMANO; i++) v[i] = rand() % 32768;
}

int main() {
  srand(time(NULL));
  short vector[TAMANO];
  GenerarVector(vector);
  bool salir = false;
  while (!salir) {
    switch (Menu()) {
      case '1':
        cout << "Promedio: " << Promedio(vector) << endl;
        break;
      case '2':
        cout << "Máximo: " << Maximo(vector) << endl;
        break;
      case '3':
        cout << "Mínimo: " << Minimo(vector) << endl;
        break;
      case '4':
        cout << "Sumatoria: " << Sumatoria(vector) << endl;
        break;
      case '5':
        salir = true;
        break;
    }
  }
  return 0;
}
