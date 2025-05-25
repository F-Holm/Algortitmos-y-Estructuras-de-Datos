/*
	Id.Programa: G1_Ej_random.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion primitiva random.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <ctime>
#include <iostream>
using namespace std;

const double PI = 3.1415926;

int main() {
  short a = 12,
        b = 37; // [12, 37]

  cout << "Hola" << endl;
  srand(time(NULL));
  for (short i = 1; i <= 15; i++)
    cout <<  rand() % (b - a + 1) + 12 << endl;
  return 0;
}
