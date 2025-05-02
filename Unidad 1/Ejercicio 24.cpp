// Unidad 1 - Ejercicio 24
#include <iostream>
#include <iomanip>

typedef char str20[21];

using namespace std;

struct venta {
    unsigned short codVen,
           cant;
    str20  descrip;
    float  preUni;
};

int main() {
    cout << fixed << setprecision(2);
    int a = 1;
    cout << a << endl;
    cout << setfill('0') << setw(8) << a << endl;
    return 0;
}
