// Unidad 2 - Ejercicio 3
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

#define TAMANO 90

void Generar(short* v);
char Menu1();
void Caso1(const short* v);
void Caso2(short* v);
void Swap(short& a, short& b);

int main() {
  srand(time(NULL));
  short v[TAMANO];
  Generar(v);
  if (Menu1() == '1')
    Caso1(v);
  else
    Caso2(v);
  return 0;
}

void Generar(short* v) {
  bool repetido[TAMANO];
  for (short i = 0; i < TAMANO; i++) repetido[i] = false;
  for (short i = 0; i < TAMANO; i++) {
    short n = rand() % TAMANO;
    if (!repetido[n]) {
      v[i] = n + 1;
      repetido[n] = true;
    }
  }
}

char Menu1() {
  cout << "1. Simulando sacar una bolilla, cantarla y meterla en la misma "
          "bolsa\n2. Simluando sacar una bolilla, cantarla y apartarla"
       << endl;
  char op;
  do {
    cin >> op;
  } while (op != '1' && op != '2');
  return op;
}

void Caso1(const short* v) {
  string a;
  do {
    cout << "El número es: " << v[rand() % TAMANO] << "\n0 = SALIR: ";
    cin >> a;
  } while (a != "0");
}

void Caso2(short* v) {
  string a = "";
  for (int i = 0; i < TAMANO && a != "0"; i++) {
    short num = rand() % (TAMANO - i) + i;
    Swap(v[i], v[num]);
    cout << "El número es: " << num << "\n0 = SALIR: ";
    v[num] = 0;
    cin >> a;
  }
}

void Swap(short& a, short& b) {
  short temp = a;
  a = b;
  b = temp;
}