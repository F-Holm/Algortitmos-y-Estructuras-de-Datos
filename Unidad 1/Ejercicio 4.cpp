// Unidad 1 - Ejercicio 4
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  unsigned short cantTriangulos = 0, cantHyp100 = 0;
  double a, b, sumHyp = 0.0;

  cout << "Ingrese los catetos de un triángulo rectángulo" << endl;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;

  while (a > 0 && b > 0) {
    double hyp = hypot(a, b);
    sumHyp += hyp;
    cantTriangulos++;
    if (hyp > 100) cantHyp100++;
    cout << "la hipotenusa del triángulo ingresado es: " << hyp << "\n\n";

    cout << "Ingrese los catetos de un triángulo rectángulo\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
  }

  cout << "Cantidad de triángulos ingresados: " << cantTriangulos << endl;
  cout << "Porcentaje con hypotenusas > 100: "
       << cantHyp100 / cantTriangulos * 100
       << endl;  // se podría usar static_cast<double> pero no lo vimos
  cout << "Promedio de las medidas de las hipotenusas: "
       << sumHyp / cantTriangulos << endl;
  cout << "porcentaje con hipotenusa <= 100: "
       << (cantTriangulos - cantHyp100) / cantTriangulos * 100 << endl;
  return 0;
}
