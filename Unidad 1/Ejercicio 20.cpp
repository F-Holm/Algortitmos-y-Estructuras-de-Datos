// Unidad 1 - Ejercicio 20
#include <iostream>

using namespace std;

int resto(int dividendo, int divisor){
    return dividendo % divisor;
}

int main() {
    cout << "Resto de 234/5464: " << resto(234, 5464) << endl;
    return 0;
}
