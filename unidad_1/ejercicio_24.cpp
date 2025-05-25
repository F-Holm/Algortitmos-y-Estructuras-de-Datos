// Unidad 1 - Ejercicio 24
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

typedef char str20[21];
typedef unsigned short ushort;

using namespace std;

struct Venta {
  ushort cod_ven, cant;
  str20 descrip;
  float precio_uni;
};

string DivisorHorizontal();
Venta CrearVenta();
void EmitirVenta(Venta v, ofstream& ventas);
int GetCodVen(string venta);
float GetPrecioTotalVenta(string venta);
void LeerRegistroVentas(string* str, ushort size, ifstream& ventas);

// Sorting functions
void Ordenar(string* str_ventas, ushort size);  // TimSort
int CalcRun(ushort n);
bool EsMayoQue(const string& a, const string& b);
void InsertionSort(string* arr, ushort left, ushort right);
void MergeSort(string* arr, ushort left, ushort mid, ushort right);

void GuardarSalida(string* str_ventas, ushort size, ofstream& salida);

int main() {
  ushort contador = 0;
  Venta venta;

  ofstream ventas("RegistroVentas.txt");

  cout << "Ingrese las ventas:" << DivisorHorizontal() << "\n\n\n";

  venta = CrearVenta();
  ventas << fixed << setprecision(2);
  while (venta.cod_ven != 0) {
    EmitirVenta(venta, ventas);
    contador++;
    venta = CrearVenta();
  }
  ventas.close();

  ifstream lector_ventas("RegistroVentas.txt");
  ofstream salida("Salida.txt");

  string* rv = new string[contador];

  LeerRegistroVentas(rv, contador, lector_ventas);
  Ordenar(rv, contador);
  GuardarSalida(rv, contador, salida);

  delete[] rv;
  lector_ventas.close();
  salida.close();
  return 0;
}

string DivisorHorizontal() {
  string str = "";
  for (ushort i = 0; i < 65; i++) str += '-';
  return str;
}

Venta CrearVenta() {
  Venta venta;
  cout << "Ingrese los datos de la venta (0 = SALIR):\n\n";

  cout << "codigo: ";
  cin >> venta.cod_ven;
  if (venta.cod_ven == 0) return venta;

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

void EmitirVenta(Venta v, ofstream& ventas) {
  ventas << setfill('0') << setw(3) << v.cod_ven << "  |  " << setfill('0')
         << setw(4) << v.cant << "  |  " << left << setfill(' ') << setw(20)
         << v.descrip << "  |  " << right << setfill('0') << setw(8)
         << v.precio_uni << '\n';
}

void LeerRegistroVentas(string* str, ushort size, ifstream& ventas) {
  for (ushort i = 0; i < size && getline(ventas, str[i]); i++);
}

int GetCodVen(string venta) { return stoi(venta.substr(0, 3)); }

float GetPrecioTotalVenta(string venta) {
  return stof(venta.substr(8, 4)) * stof(venta.substr(42, 8));
}

// TimSort
void Ordenar(string* str_ventas, ushort size) {
  if (size <= 1) return;

  ushort RUN = CalcRun(size);

  // Ordenar por insertion sort en bloques de tamaño RUN
  for (ushort i = 0; i < size; i += RUN) {
    ushort right = i + RUN - 1;
    if (right >= size) right = size - 1;
    InsertionSort(str_ventas, i, right);
  }

  // Combinar subarrays ordenados de tamaño RUN
  for (int run_size = RUN; run_size < size; run_size *= 2) {
    for (int left = 0; left < size; left += 2 * run_size) {
      int mid = left + run_size - 1;
      int right = left + 2 * run_size - 1;

      if (mid >= size) continue;
      if (right >= size) right = size - 1;

      MergeSort(str_ventas, left, mid, right);
    }
  }
}

int CalcRun(ushort size) {
  int r = 0;
  while (size >= 32) {
    r |= size & 1;
    size >>= 1;
  }
  return size + r;
}

bool EsMayoQue(const std::string& a, const std::string& b) {
  return a.substr(0, 3) > b.substr(0, 3);
}

void InsertionSort(string* arr, ushort left, ushort right) {
  for (ushort i = left + 1; i <= right; i++) {
    string temp = arr[i];
    int j = i - 1;
    while (j >= left && EsMayoQue(arr[j], temp)) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

void MergeSort(string* arr, ushort left, ushort mid, ushort right) {
  ushort len1 = mid - left + 1;
  ushort len2 = right - mid;

  string* leftArr = new string[len1];
  string* rightArr = new string[len2];

  for (ushort i = 0; i < len1; i++) leftArr[i] = arr[left + i];
  for (ushort i = 0; i < len2; i++) rightArr[i] = arr[mid + 1 + i];

  ushort i = 0, j = 0, k = left;

  while (i < len1 && j < len2) {
    if (EsMayoQue(rightArr[j], leftArr[i]))
      arr[k++] = leftArr[i++];
    else
      arr[k++] = rightArr[j++];
  }

  while (i < len1) arr[k++] = leftArr[i++];
  while (j < len2) arr[k++] = rightArr[j++];

  delete[] leftArr;
  delete[] rightArr;
}

void GuardarSalida(string* str_ventas, ushort size, ofstream& salida) {
  ushort mejor_vendedor = 0, vendedor = 0;
  float mas_vendido = 0.0f, total_vendedor = 0.0f, total = 0.0f;

  salida
      << "Registro de ventas\n\n"
      << DivisorHorizontal()
      << "\nVen  |  Cant  |      Descripción       |  Pre Unit  |  Prec Total"
      << '\n'
      << DivisorHorizontal() << "\n\n";

  for (ushort i = 0; i < size; i++) {
    int cod_ven = GetCodVen(str_ventas[i]);
    float precio_total_venta = GetPrecioTotalVenta(str_ventas[i]);

    if (vendedor == 0)
      vendedor = cod_ven;
    else if (cod_ven != vendedor) {
      if (mas_vendido < total_vendedor) {
        mas_vendido = total_vendedor;
        mejor_vendedor = vendedor;
      }
      salida << DivisorHorizontal() << "\n\n";
      total += total_vendedor;
      total_vendedor = 0.0f;
      vendedor = cod_ven;
    }

    total_vendedor += precio_total_venta;
    salida << str_ventas[i] << "  |  " << fixed << setprecision(2)
           << setfill('0') << setw(10) << precio_total_venta << endl;

    if (i == size - 1)
      if (mas_vendido < total_vendedor) {
        mas_vendido = total_vendedor;
        mejor_vendedor = vendedor;
      }
  }

  salida << DivisorHorizontal() << "\n\n\nEl mayor vendedor es "
         << mejor_vendedor << endl
         << "Consiguió un total de " << mas_vendido << " ventas"
         << "\n\nTotal vendido: " << total;
}