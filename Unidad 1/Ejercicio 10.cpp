// Unidad 1 - Ejercicio 10
#include <iostream>

using namespace std;

int main() {
    unsigned int ant = 1, antUlt = 0;
    unsigned short n;

    cout << "Ingrese un número natural incluido el 0 y se mostraran n términos de Fibonacci\n";
    cin >> n;

    for (unsigned short i = 0;i <= n;i++){
        switch (i){
            case 0:
            cout << "fib(0) = 0\n";
            break;
            case 1:
            cout << "fib(1) = 1\n";
            break;
            default:
            unsigned int fib = ant + antUlt;
            cout << "fib(" << i << ") = " << fib << endl;
            antUlt = ant;
            ant = fib;
            break;
        }
    }

    return 0;
}
