/*
	Id.Programa: G1-Ej FuncPrimMat.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion primitiva poly de una variable.
	Lenguaje...: Borland V.5.5
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>

#include "Borland.h"

using namespace std;

const float PI = 3.141592654;

int main() {
  div_t rDiv;
  double x; //pos 0  1  2  3
  double vC[4] = {3, 1, 5, 2};
  short  a,
         b,
         n;


  x = -24.8623;
  cout.precision(2);
  cout << fixed;
  cout << "Valor abs -348: " << abs(-348) << endl;
  cout << "Valor abs 348: " << abs(348)  << endl;
  cout << "Valor abs " << x << ": " <<fabs(x) << endl;
  cout << "Valor abs 24.8623: " << fabs(24.8623) << endl;
  cout << "Raiz cuad. 25: " << sqrt(25) << endl;
  cout << "Potencia 2 ^ 3: " << pow(2,3) << endl;
  x = 30;
  cout << "sin " << x << ": " << sin(x * PI / 180) << endl;
  cout << "cos " << x + 30 << ": " << cos((x + 30) * PI / 180) << endl;
  cout << "atan " << 1 << ": " << atan(1) * 180 / PI << endl;
  x = 100;
  cout << "ln  " << x << ": " << log(x) << endl;
  cout << "log " << x << ": " << log(x) / log(10) << endl;
  cout << "exp " << 1 << ": " << exp(1) << endl;
  cout << "exp base 10 " << 2 << ": " << exp(2 * log(10)) << endl;
  cout << "fmod 7, 3 " << fmod(7, 3) << endl; // obtiene el resto entero.
  rDiv = div(7, 3);
  cout << "div 7, 3:" << endl;
  cout << "  Cociente: " << rDiv.quot << endl;
  cout << "  Resto...: " << rDiv.rem << endl;
  x = -3.2;
  cout << "floor " << fabs(x) << ": " << floor(fabs(x)) << endl;
  cout << "floor " << fabs(x) + 0.5 << ": " << floor(fabs(x)+0.5) << endl;
  cout << "floor " << x << ": " << floor(x) << endl;
  cout << "floor " << x - 0.5 << ": " << floor(x - 0.5) << endl;
  cout << "ceil " << fabs(x) << ": " << ceil(fabs(x)) << endl;
  cout << "ceil " << fabs(x) + 0.5 << ": " << ceil(fabs(x)+0.5) << endl;
  cout << "ceil " << x << ": " << ceil(x) << endl;
  cout << "ceil " << x - 0.5 << ": " << ceil(x - 0.5) << endl;
  cout << "random [1,6]: " << random(6) + 1;
  a = 12;
  b = 35;
  for (short i = 1; i <= 10; i++)
    cout << "random [12, 35]: " << random(b - a + 1) + a << endl;
  randomize(); // solo Borland.
  cout << "---------------" << endl;
  for (short i = 1; i <= 10; i++)
    cout << "random [12, 35]: " << random(b - a + 1) + a << endl;//solo Borland.
  srand(time(NULL)); // standard
  cout << "---------------" << endl;
  for (short i = 1; i <= 10; i++)
    cout << "rand [12, 35]: " << rand() % (b - a +1) + a << endl;// standard.
  cout << "hypot 4, 3: " << hypot(4, 3) << endl;
  x = 2;
  n = 3;  // vC[3] * x ^ 3 + vC[2] * x ^ 2 + vC[1] * 2 + vC[0]
  cout << "poly x, n, vC: " << poly(x,n,vC) << endl;
  return 0;
}