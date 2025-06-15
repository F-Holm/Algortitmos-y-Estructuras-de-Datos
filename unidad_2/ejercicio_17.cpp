// Unidad 2 - Ejercicio 17
#include <fstream>
#include <iostream>

using namespace std;

struct Gasto {
  short mes, dia;
  float importe;
};

typedef float Calendario[365];

void InicCalen(Calendario& calendario);
void CargarDatos(Calendario& calendario, ifstream& archivo);
short CantDiasMes(short mes);
short CantDias(short mes);
void Mostrar(Calendario& calendario);

int main() {
  Calendario calendario;
  ifstream archivo("Gastos.txt");

  InicCalen(calendario);
  CargarDatos(calendario, archivo);
  Mostrar(calendario);
  archivo.close();
  return 0;
}

void InicCalen(Calendario& calendario) {
  for (short i = 0; i < 364; i++)
    calendario[i] = 0.0f;
}
short CantDias(short mes) {
  short cant = 0;
  for (short i = 1; i < mes; i++) {
    cant = cant + CantDiasMes(mes);
  }
  return cant;
}
short CantDiasMes(short mes) {
  return mes == 2
             ? 28
             : ((mes < 8 && mes % 2 == 1) || (mes >= 8 && mes % 2 == 0) ? 31
                                                                        : 30);
}

void CargarDatos(Calendario& calendario, ifstream& archivo) {
  do {
    Gasto gasto;

    archivo >> gasto.mes >> gasto.dia >> gasto.importe;
    archivo.ignore();

    calendario[CantDias(gasto.mes) + gasto.dia] += gasto.importe;

  } while (archivo.good());
}

void Mostrar(Calendario& calendario) {
}
