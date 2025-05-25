// Unidad 2 - Ejercicio _2
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

char* FillBlank(char* car, short n) {
  size_t len = strlen(car);
  for (size_t i = len; i < len + n; i++) car[i] = ' ';
  car[len + n] = '\0';
  return car;
}

int main() {
  char* str = new char[110];
  strcpy(str, "123456789");
  FillBlank(str, 100);
  cout << str << "|" << endl;
  delete[] str;
  return 0;
}