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

venta crearVenta() {
    venta v;
    cout << "codigo: ";
    cin >> v.codVen;
    if (v.codVen == 0)
        return v;

    cout << "cantidad: ";
    cin >> v.cant;

    cout << "descripcion: ";
    cin.ignore();
    cin.get(v.descrip, 21);

    cout << "precio: ";
    cin >> v.preUni;

    return v;
}

void divisorHorizontal(){
    string str = "";
    for (unsigned short i = 0;i < 60;i++)
        str += '—';
    cout << str << endl;
}

void emitirVenta(venta v, ofstream &ventas){
    ventas << setfill('0') << setw(3) << v.codVen << "\t|\t" <<
    setfill('0') << setw(4) << v.cant << "\t|\t" <<
    setfill(' ') << setw(20) << v.descrip << "\t|\t" <<
    setfill('0') << setw(7) << v.preUni << endl;
}

string* leerRegistroVentas(ifstream &iRegistro){
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
    ofstream salida("Salida.txt");

    cout << "ventas agrupadas por vendedor" << endl;
    cout << "ingrese las ventas: " << endl << endl;;

    v = crearVenta();
    while (v.codVen != 0){
        emitirVenta(v, ventas);
        contador++;
        v = crearVenta();
    }

    ifstream iRegistro("RegistroVentas.txt");
    
    cout << fixed << setprecision(2);
    float a = 101.1;
    cout << a << endl;
    cout << setfill('0') << setw(8) << a << endl;
    return 0;
}
