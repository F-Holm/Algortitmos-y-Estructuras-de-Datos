/*
  Id.Programa: PunteroFuncionOperArtimeticas2.cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: noviembre-2023
  Comentario.: Operaciones aritmeticas
               Todas las funciones tienen
             el mismo formato float (float, float)
               Se establece una funci¢n que recibe
             dos operandos y el puntero a la funcion
             de la operaci¢n aritmetica a calcular.
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

float fOperArit (float x, float y, float (*fCalcular) (float, float)) {
  return fCalcular (x, y);
} // fOperArit

main() {
  float a = 12,
        b = 2;
  cout << "Operaciones Aritmeticas" << endl;
  cout << a << " + " << b << " = " << fOperArit(a, b, sumar) << endl;
  cout << a << " - " << b << " = " << fOperArit(a, b, restar) << endl;
  cout << a << " * " << b << " = " << fOperArit(a, b, multiplicar) << endl;
  cout << a << " / " << b << " = " << fOperArit(a, b, dividir) << endl;
  return 0;
}
