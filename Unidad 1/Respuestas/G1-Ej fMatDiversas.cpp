/*
   	Id.Programa: G1-Ej fMatDiversas.cpp
   	Autor......: Lic. Hugo Cuello
   	Fecha......: julio-2013
   	Comentario.: Guia 1 Ejercicios de Funciones Matematicas
                 diversas:
                 Vabs(),Sgn(x),Iif(b,x,y),Resto(x,y),
                 EsDivis(x,y),Mcd(,x,y),EsPrimo(x),EsPar(x).
	Lenguaje...: Borland V.5.5
*/

#include <iostream>

using namespace std;

float Vabs(float x) {

	if ( x >= 0)
		return x;
	else
		return -x;
} // Vabs

int Iif(bool expLog, int x, int y) {

  if ( expLog )
  	return x;
  else
  	return y;
} // Iif

short Sgn(float x) {
  if ( x == 0)
    return x;
  else
    return x / Vabs(x);
} // Sgn

int Resto(int x, int y) {
  return x - x / y * y;
} // Resto

int Mcd(int x, int y) {
  int rest;

  while ( y != 0 ) {
  	rest = Resto(x,y);
  	x = y;
  	y = rest;
  }
  return x;
} // Mcd

bool EsDivis(int x, int y) {
  return Resto(x,y) == 0;
} // EsDivis

bool EsPar(int x) {
  return x % 2 == 0; // return Resto(x,2) == 0;
} // EsPar

bool EsPrimo(int x) {
  if (x == 2)
    return true;
  else
    if (EsPar(x) || x == 1)
      return false;
  for (int i = 3; i <= x / 2; i += 2) // i = i + 2;
    if (!Resto(x,i))  // equiv. Resto(x,i) == 0
      return false;
  return true;
} // EsPrimo

int main() {
  float a;
  int   c,
        d;

  cout << "Ing. un valor real: ";
  cin >> a;
  cout << " | " << a << " | = " << Vabs(a) << endl;
  cout << "sgn " << a << " = " << Sgn(a) << endl;
  cout << "Ing. 2 valores enteros: ";
  cin >> c >> d;
  cout << "M.C.D. entre: " << c << " y " << d << " = " << Mcd(c,d) << endl;
  cout << c << " / " << d << " = " << c / Mcd(c,d) << " / " << d / Mcd(c,d)
       << endl;
  cout << "Resto entre " << c << " y " << d << " = " << Resto(c,d) << endl;
  cout << c << " es divisible por " << d << "? " << boolalpha << EsDivis(c,d)
       << endl;
  cout << "Emite el mayor valor entre " << c << " y " << d << " : "
       << Iif(c > d,c,d) << endl;
  cout << "Es par " << c << "?: " << EsPar(c) << endl;
  cout << "Es primo " << c << "?: " << noboolalpha << EsPrimo(c) << endl;
  return 0;
}
