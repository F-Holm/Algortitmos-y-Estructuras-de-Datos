/*
    Id.Programa: G4Ej02 OperacArreglos.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: ago-2014
    Comentario.: Operaciones con arreglos, opc. de Menu:
                   a) Promedio
                   b) Maximo
                   c) Minimo
                   d) Sumatoria
*/

#include <conio.h>

#include <iomanip>
#include <iostream>
using namespace std;

const MAX_ELEM = 100, MIN = 53, MAX = 391;

typedef unsigned char byte;
typedef unsigned short word;
typedef byte tvEnt[MAX_ELEM];

// Prototipos ------------------
byte ObtCard();
void GenVec(tvEnt, byte);
void EmitirVec(tvEnt, byte);
word SumVec(tvEnt, byte);
float PromVec(tvEnt, byte);
byte MaxVec(tvEnt, byte);
byte MinVec(tvEnt, byte);
void Menu(tvEnt, byte);
// Fin Prototipos -------------

byte ObtCard() {
  word cantElem;

  do {
    gotoxy(5, 3);
    clreol();
    cout << "Ing.Cardinalidad del vector [1.." << MAX_ELEM << "]: ";
    cin >> cantElem;
  } while (!(cantElem >= 1 && cantElem <= MAX_ELEM));
  return cantElem;

}  // ObtenerCard

void GenVec(tvEnt vE, byte card) {
  randomize();
  for (byte i = 0; i < card; i++)
    vE[i] = random(MAX - MIN + 1) + MIN;
}  // GenVec

void EmitirVec(tvEnt vE, byte card) {
  clrscr();
  for (byte i = 0; i < card; i++)
    cout << setw(8) << (short)vE[i];
  gotoxy(1, 24);
  cout << "Oprima Enter para continuar...";
  getche();
}  // EmitirVec

word SumVec(tvEnt vE, byte card) {
  word sum = 0;

  for (byte i = 0; i < card; i++)
    sum += vE[i];
  return sum;
}  // SumVec

float PromVec(tvEnt vE, byte card) {
  return SumVec(vE, card) / (float)card;
}  // PromVec

byte MaxVec(tvEnt vE, byte card) {
  byte maxElem;

  maxElem = vE[0];
  for (byte i = 1; i < card; i++)
    if (vE[i] > maxElem)
      maxElem = vE[i];
  return maxElem;
}  // MaxVec

byte MinVec(tvEnt vE, byte card) {
  byte minElem;

  minElem = vE[0];
  for (byte i = 1; i < card; i++)
    if (vE[i] < minElem)
      minElem = vE[i];
  return minElem;
}  // MinVec

void Menu(tvEnt vE, byte card) {
  char opc;

  cout.precision(2);
  cout.setf(ios::fixed);
  do {
    clrscr();
    gotoxy(20, 1);
    cout << "Operaciones con Arreglos";
    gotoxy(10, 5);
    cout << "A: Promedio";
    gotoxy(10, 7);
    cout << "B: Maximo elemento";
    gotoxy(10, 9);
    cout << "C: Minimo elemento";
    gotoxy(10, 11);
    cout << "D: Sumatoria";
    gotoxy(10, 13);
    cout << "E: Salir";
    do {
      gotoxy(15, 16);
      cout << "Elija su opcion: [ ]";
      gotoxy(wherex() - 2, wherey());
      opc = toupper(getch());
    } while (!(opc >= 'A' && opc <= 'E'));
    gotoxy(20, 20);
    switch (opc) {
      case 'A':
        cout << "Promedio.: " << setw(8) << PromVec(vE, card);
        break;
      case 'B':
        cout << "Maximo...: " << setw(8) << (short)MaxVec(vE, card);
        break;
      case 'C':
        cout << "Minimo...: " << setw(8) << (short)MinVec(vE, card);
        break;
      case 'D':
        cout << "Sumatoria: " << setw(8) << SumVec(vE, card);
        break;
    }
    if (opc != 'E')
      getche();
  } while (!(opc == 'E'));
}  // Menu

int main() {
  tvEnt vEnt;
  byte cantElem;

  cantElem = ObtCard();
  GenVec(vEnt, cantElem);
  EmitirVec(vEnt, cantElem);
  Menu(vEnt, cantElem);
  return 0;
}
