// Unidad 1 - Ejercicio 24
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

typedef char str20[21];

using namespace std;

struct venta {
    unsigned short codVen,
           cant;
    str20  descrip;
    float  preUni;
};

void divisorHorizontal(){
    string str = "";
    for (unsigned short i = 0;i < 60;i++)
        str += '-';
    cout << str << endl;
}

venta crearVenta() {
    venta v;
    cout << "Ingrese los datos de la venta (0 = SALIR):\n\n";

    cout << "codigo: ";
    cin >> v.codVen;
    if (v.codVen == 0)
        return v;

    cout << "cantidad: ";
    cin >> v.cant;

    cout << "descripcion: ";
    cin.ignore();
    cin.get(v.descrip, 21);
    cin.ignore(100, '\n');

    cout << "precio: ";
    cin >> v.preUni;

    divisorHorizontal();
    return v;
}

void emitirVenta(venta v, ofstream &ventas){
    ventas << setfill('0') << setw(3) << v.codVen << "  |  " <<
            setfill('0') << setw(4) << v.cant << "  |  " <<
    left << setfill(' ') << setw(20) << v.descrip << "  |  " <<
    right << setfill('0') << setw(8) << v.preUni << '\n';
}

string* leerRegistroVentas(ifstream &iRegistro, unsigned short size){
    string* str = new string[size];
    return str;
}

void reordenar(string* str_ventas, unsigned short size, ofstream &ventas){
    delete[] str_ventas;
}

int main() {
    bool condicion=true;
    unsigned short codAnterior,
        contador=0;
    venta v;

    ofstream ventas("RegistroVentas.txt");
    //ofstream salida("Salida.txt");

    cout << "ingrese las ventas: " << endl;
    divisorHorizontal();

    v = crearVenta();
    ventas << fixed << setprecision(2);
    while (v.codVen != 0){
        emitirVenta(v, ventas);
        contador++;
        v = crearVenta();
    }

    /*ifstream iRegistro("RegistroVentas.txt");
    
    
    float a = 101.1;
    cout << a << endl;
    cout << setfill('0') << setw(8) << a << endl;*/
    return 0;
}
