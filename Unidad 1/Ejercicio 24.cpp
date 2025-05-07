// Unidad 1 - Ejercicio 24
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

typedef char str20[21];

using namespace std;

struct Venta {
    unsigned short cod_ven,
           cant;
    str20  descrip;
    float  precio_uni;
};

string DivisorHorizontal(){
    string str = "";
    for (unsigned short i = 0;i < 65;i++)
        str += '-';
    return str;
}

Venta CrearVenta() {
    Venta venta;
    cout << "Ingrese los datos de la venta (0 = SALIR):\n\n";

    cout << "codigo: ";
    cin >> venta.cod_ven;
    if (venta.cod_ven == 0)
        return venta;

    cout << "cantidad: ";
    cin >> venta.cant;

    cout << "descripcion: ";
    cin.ignore();
    cin.get(venta.descrip, 21);
    cin.ignore(100, '\n');

    cout << "precio: ";
    cin >> venta.precio_uni;

    cout << DivisorHorizontal() << "\n\n";
    return venta;
}

void EmitirVenta(Venta v, ofstream &ventas){
    ventas << setfill('0') << setw(3) << v.cod_ven << "  |  " <<
            setfill('0') << setw(4) << v.cant << "  |  " <<
    left << setfill(' ') << setw(20) << v.descrip << "  |  " <<
    right << setfill('0') << setw(8) << v.precio_uni << '\n';
}

float GetPrecioTotalVenta(string venta){
    return stof(venta.substr(8, 4))*stof(venta.substr(42, 8));
}

int GetCodVen(string venta){
    return stoi(venta.substr(0, 3));
}

void LeerRegistroVentas(string* str, unsigned short size, ifstream &ventas){
    for (unsigned short i = 0;i < size && getline(ventas, str[i]);i++);
}

void Reordenar(string* str_ventas, unsigned short size){
}

void GuardarSalida(string* str_ventas, unsigned short size, ofstream &salida){
    unsigned short mejor_vendedor = 0, vendedor = 0;
    float mas_vendido = 0.0f, total_vendedor = 0.0f, total = 0.0f;

    salida << "Registro de ventas\n\n" << DivisorHorizontal() <<
            "\nVen  |  Cant  |      Descripción       |  Pre Unit  |  Prec Total" <<
            '\n' << DivisorHorizontal() << "\n\n";

    for (unsigned short i = 0;i < size;i++){
        int cod_ven = GetCodVen(str_ventas[i]);
        float precio_total_venta = GetPrecioTotalVenta(str_ventas[i]);

        if (vendedor == 0)
            vendedor = cod_ven;
        else if (cod_ven != vendedor){
            if (mas_vendido < total_vendedor){
                mas_vendido = total_vendedor;
                mejor_vendedor = vendedor;
            }
            salida << DivisorHorizontal() << "\n\n";
            total += total_vendedor;
            total_vendedor = 0.0f;
            vendedor = cod_ven;
        }

        total_vendedor += precio_total_venta;
        salida << str_ventas[i] << "  |  " <<
                fixed << setprecision(2) <<
                setfill('0') << setw(10) <<
                precio_total_venta << endl;
        
        if (i == size - 1)
            if (mas_vendido < total_vendedor){
                mas_vendido = total_vendedor;
                mejor_vendedor = vendedor;
            }
    }


    salida << DivisorHorizontal() << "\n\n\nEl mayor vendedor es " <<
            mejor_vendedor << endl << 
            "Consiguió un total de " << mas_vendido;
}

int main() {
    bool condicion=true;
    unsigned short codAnterior,
        contador=0;
    Venta venta;

    ofstream ventas("RegistroVentas.txt");

    cout << "Ingrese las ventas:" << DivisorHorizontal() << "\n\n\n";

    venta = CrearVenta();
    ventas << fixed << setprecision(2);
    while (venta.cod_ven != 0){
        EmitirVenta(venta, ventas);
        contador++;
        venta = CrearVenta();
    }
    ventas.close();

    ifstream lector_ventas("RegistroVentas.txt");
    ofstream salida("Salida.txt");

    string* rv = new string[contador];

    LeerRegistroVentas(rv, contador, lector_ventas);
    Reordenar(rv, contador);
    GuardarSalida(rv, contador, salida);

    delete[] rv;
    lector_ventas.close();
    salida.close();
    return 0;
}
