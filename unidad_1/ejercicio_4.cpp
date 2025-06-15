// Unidad 1 - Ejercicio 4
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  unsigned short cant_triangulos = 0, cant_hyp100 = 0;
  double a, b, sum_hyp = 0.0;

  cout << "Ingrese los catetos de un triángulo rectángulo" << endl;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;

  while (a > 0 && b > 0) {
    double hyp = hypot(a, b);
    sum_hyp += hyp;
    cant_triangulos++;
    if (hyp > 100)
      cant_hyp100++;
    cout << "la hipotenusa del triángulo ingresado es: " << hyp << "\n\n";

    cout << "Ingrese los catetos de un triángulo rectángulo\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
  }

  cout << "Cantidad de triángulos ingresados: " << cant_triangulos << endl;
  cout << "Porcentaje con hypotenusas > 100: "
       << cant_hyp100 / cant_triangulos * 100
       << endl;  // se podría usar static_cast<double> pero no lo vimos
  cout << "Promedio de las medidas de las hipotenusas: "
       << sum_hyp / cant_triangulos << endl;
  cout << "porcentaje con hipotenusa <= 100: "
       << (cant_triangulos - cant_hyp100) / cant_triangulos * 100 << endl;
  return 0;
}
