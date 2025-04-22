/*
	Id.Programa: G1-Ej20.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Crear una funcion que recibe dos valores enteros y retorne
								 el resto de la division entera.
	Lenguaje...: Borland V.5.5
*/

#include <cmath>
#include <iostream>

using namespace std;

const
  float PI = 3.141592654;

int Resto (int x, int y) {
  return x - x / y * y;
} // Resto

int main() {
  int   a,
        b;
  float x = 30.0;

  cout << "Funcion que retorna el resto de una division entre enteros" << endl;
  cout << "Entero a: ";
  cin >> a;
  cout << "Entero b: ";
  cin >> b;
  cout << "Resto(" << a << ", " << b << ") = " << Resto(a,b) << endl;
  // Agregado
  cout << sin(x * PI / 180) << endl;
  cout << cos((x+30) * PI / 180) << endl;
  cout << atan(1) * 180 / PI;
  return 0;
}
