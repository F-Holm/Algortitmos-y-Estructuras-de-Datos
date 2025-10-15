/*
  Id.Programa: PunteroFuncionOperArtimeticas.cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: noviembre-2023
  Comentario.: Operaciones aritmeticas
               Todas las funciones tienen
             el mismo formato float (float, float)
               Se establecen 4 punteros a
             funcion por medio de un vector.
               A cada componente se le asigna
             el nombre de una funcion
             sumar, restar, multiplicar, dividir.
*/

#include <fstream>
using namespace std;

float sumar(float x, float y) {
  return x + y;
} // sumar

float restar(float x, float y) {
  return x - y;
} // restar

float multiplicar(float x, float y) {
  return x * y;
} // multiplicar

float dividir(float x, float y) {
  return x / y;
} // dividir

main() {
  float a = 12,
        b = 2;

  float (*pfuncOpArit[4]) (float, float) =
              {sumar,restar,multiplicar,dividir};
  char operador[4] = {'+','-','*','/'};

  cout << "Operaciones aritmeticas" << endl;
  for (short i = 0; i < 4; i++)
    cout << a << ' '
         << operador[i] << ' '
         << b << ' '
         << '=' << ' '
         << pfuncOpArit[i](a,b) << endl;
  return 0;
}
