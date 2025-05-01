// Unidad 1 - Ejercicio 18
#include <iostream>

using namespace std;

int mcd(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int main() {
    cout << mcd(322, 7322) << endl;
    return 0;
}
