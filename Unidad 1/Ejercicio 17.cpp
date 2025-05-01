// Unidad 1 - Ejercicio 17
#include <iostream>

using namespace std;

int iif(bool condicion, int a, int b){
    if (condicion)
        return a;
    return b;
}

int main() {//iif(a, b, c) == a ? b : c
    cout << iif(1 > 2, 1, 2) << endl;
    return 0;
}
