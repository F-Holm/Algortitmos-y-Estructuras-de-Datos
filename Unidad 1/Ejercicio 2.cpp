        // Unidad 1 - Ejercicio 2
        #include <iostream>

        using namespace std;

        int main() {
            int a, b;
            cout << "Ingrese un número entero: ";
            cin >> a;
            do {
                cout << "Ingrese un número entero distinto a " << a << ": ";
                cin >> b;
            } while (a == b);

            if (a > b)
                cout << a << " > " << b << endl;
            else
                cout << b << " > " << a << endl;
            return 0;
        }
