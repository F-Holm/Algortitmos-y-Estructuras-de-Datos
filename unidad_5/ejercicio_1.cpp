// Unidad 5 - Ejercicio 1
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

struct tsNodo;

const short MESES = 12;
typedef struct tsNodo* tPila;
typedef tPila tvPilas[MESES];

struct tsNodo {
  float importe;
  tPila ant;
};

void push(tPila& stack, float valor) {
  tPila pNodo = new tsNodo;
  pNodo->importe = valor;
  pNodo->ant = stack;
  stack = pNodo;
}

void pop(tPila& stack, float& valor) {
  tPila pElim = stack;
  valor = stack->importe;
  stack = stack->ant;
  delete pElim;
}

void InicializarPilas(tvPilas& vPilas) {
  for (short i = 0; i < MESES; i++)
    vPilas[i]->ant = NULL;
}

bool LeerLinea(ifstream& Gastos, tvPilas& vPilas) {
  if (Gastos.good()) {
    short mes, importe;
    Gastos >> mes >> importe;
    push(vPilas[mes - 1], importe);
  }
  return Gastos.good();
}

void CalcularMostrarResultados(tvPilas& vPilas) {
  float total = 0.0f;
  const char* tab = "  ";
  const char* meses[MESES] = {
      "Enero", "Febrero", "Marzo",      "Abril",   "Mayo",      "Junio",
      "Julio", "Agosto",  "Septiembre", "Octuble", "Noviembre", "Diciembre"};
  cout << setprecision(2) << fixed;
  for (short i = 0; i < MESES; i++) {
    cout << meses[i] << ":\n";
    float totalMensual = 0.0f;
    while (vPilas[i]) {
      float importe;
      pop(vPilas[i], importe);
      cout << tab << "Importe: " << importe << '\n';
      totalMensual += importe;
    }
    cout << tab << "Total de " << meses[i] << ": " << totalMensual
         << "\n\n----------\n\n";
    total += totalMensual;
  }
  cout << "Total: " << total;
}

int main() {
  tvPilas vPilas;
  ifstream Gastos("Gastos.txt");

  InicializarPilas(vPilas);
  while (LeerLinea(Gastos, vPilas))
    ;
  CalcularMostrarResultados(vPilas);
  return 0;
}
