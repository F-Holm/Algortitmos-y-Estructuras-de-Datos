/*
	Id.Programa: G1_Ej18.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Crear una funcion que dado dos valores enteros
	              retorne el MCD.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iostream>
using namespace std;

int mcd (int x, int y) {
  int resto;

  while (y) {
    resto = x % y;
    x = y;
    y = resto;
  }
  return x;
} // mcd

main() {
  int a,
      b,
      maxComDiv,
     *p;

  cout << "Tamaño del tipo int.: " << sizeof(int) << endl;
  cout << "Tamaño del tipo long: " << sizeof(long) << endl;
  cout << "Tamaño de un puntero: " << sizeof(p) << endl;
  cout << "Funcion que retorna el m.c.d. entre 2 valores enteros" << endl;
  cout << "Entero a: ";
  cin >> a;
  cout << "Entero b: ";
  cin >> b;
  maxComDiv = mcd(a,b);
  cout << "m.c.d.: " << maxComDiv << endl;
  cout << "Aplicacion del m.c.d.: "<< endl;
  cout << a << " / " << b << " = " << a / maxComDiv << "/" << b / maxComDiv;
  cout << " que es la fraccion irreducible al dividir " << endl;
  cout << "numerador y denominador por el m.c.d. = " << maxComDiv;
  return 0;
}
