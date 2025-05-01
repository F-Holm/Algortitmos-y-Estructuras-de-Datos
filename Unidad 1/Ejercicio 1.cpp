        // Unidad 1 - Ejercicio 1
        #include <iostream>
        #include <cmath>

        using namespace std;

        int main() {
            double a, b;
            do {
                cout << "Ingrese los valores de los catetos a y b de un triángulo rectángulo: " << endl;
                cin >> a;
                cin >> b;
            } while(a < 0 || b < 0);
            //hypotf(a, b) == sqrt(pow(a, 2) + pow(b, 2))
            cout << "El valor de la hipotenusa es: " << hypot(a, b) << endl;
            return 0;
        }
