// Unidad 1 - Ejercicio 23
#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void ordenar(int &a, int &b, int &c){
    if (a < b)
        swap(a, b);
    if (a < c)
        swap(a, c);
    if (b < c)
        swap(b, c);
}

void mostrar(int a, int b, int c){
    cout << "terna(" <<  a << "; " << b << "; " << c << ")\n";
}

void ingresar(int &a, int &b, int &c){
    cout << "X: ";
    cin >> a;
    cout << "Y: ";
    cin >> b;
    cout << "Z: ";
    cin >> c;
}

void actualizarMinMax(int a, int b, int c, int &min, int &max){
    if (max < a)
        max = a;
    if (min > c)
        min = c;
}

/*
M.D.
a | b | c
—————————
5 | 3 | 7
—————————
5 | 7 | 3
—————————
3 | 5 | 7
—————————
3 | 3 | 7
—————————
7 | 3 | 7
—————————
7 | 3 | 7
—————————
5 | 3 | 7
—————————
5 | 3 | 7
—————————
3 | 3 | 7
—————————
5 | 3 | 7
—————————
7 | 3 | 7
—————————
5 | 3 | 7
—————————
5 | 3 | 7

*/

int main() {
    unsigned short n;
    int min = 2147483647, max = -2147483648;
    cout << "Ingrese el número de ternas a ingresar: ";
    cin >> n;
    
    for (unsigned short i = 0;i < n;i++){
        int a, b, c;
        ingresar(a, b, c);
        ordenar(a, b, c);
        mostrar(a, b, c);
        actualizarMinMax(a, b, c, min, max);
        cout << endl;
    }

    cout << "Máximo valor ingresaso: " << max << endl;
    cout <<  "Mínimo valor ingresado: " << min << endl;
    return 0;
}
