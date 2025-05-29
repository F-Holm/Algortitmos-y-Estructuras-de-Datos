/*
    Id.Programa: G2-Ej02 OperacArreglos.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: ago-2014
    Comentario.: Operaciones con arreglos, opc. de Menu:
                   a) Promedio
                   b) Maximo
                   c) Minimo
                   d) Sumatoria
    Lenguaje...: Borland C++ V.5.5
*/

#include<conio.h>
#include<iomanip>
#include<windows>   // funcion Sleep
#include<fstream>
using namespace std;

const
  MAX_ELEM = 100,
  MIN      = 53,
  MAX      = 391;

typedef unsigned short word;
typedef short tvEnt[MAX_ELEM];

// Prototipos ------------------
short ObtCard();
void GenVec(tvEnt , short );
void EmitirVec(tvEnt , short );
word SumVec(tvEnt , short );
float PromVec(tvEnt , short );
short MaxVec(tvEnt , short );
short MinVec(tvEnt , short );
void Menu(tvEnt , short );
// Fin Prototipos -------------

short ObtCard() {
  word cantElem;

  do {
    gotoxy(5,3); clreol();
    cout << "Ing.Cardinalidad del vector [1.." << MAX_ELEM << "]: ";
    cin >> cantElem;
  } while (!(cantElem >= 1 && cantElem <= MAX_ELEM));
  return cantElem;
} //ObtenerCard

void GenVec(tvEnt vE, short card) {
  randomize();
  for (short i = 0; i < card; i++)
    vE[i] = random(MAX - MIN + 1) + MIN;
} //GenVec

void EmitirVec(tvEnt vE, short card) {
  clrscr();
  for (short i = 0; i < card; i++)
    cout << setw(6) << vE[i];
  gotoxy(1,24);
  cout << "Oprima Enter para continuar...";
  getche();
} //EmitirVec

word SumVec(tvEnt vE, short card) {
  word sum = 0;

  for (short i = 0; i < card; i++)
    sum += vE[i];
  return sum;
} //SumVec

float PromVec(tvEnt vE, short card) {

  return SumVec(vE,card) / (float) card;
} //PromVec

short MaxVec(tvEnt vE, short card) {
  short maxElem;

  maxElem = vE[0];
  for (short i = 1; i < card; i++)
    if (vE[i] > maxElem)
      maxElem = vE[i];
  return maxElem;
} //MaxVec

short MinVec(tvEnt vE, short card) {
  short minElem;

  minElem = vE[0];
  for (short i = 1; i < card; i++)
    if (vE[i] < minElem)
      minElem = vE[i];
  return minElem;
} //MinVec

void Menu(tvEnt vE, short card) {
  char opc;

  cout.precision(2);
  cout.setf(ios::fixed);
  do {
    clrscr();
    gotoxy(15,3); cout << "Operaciones con Arreglos";
    gotoxy(10, 5); cout << "A: Promedio";
    gotoxy(10, 7); cout << "B: Maximo elemento";
    gotoxy(10, 9); cout << "C: Minimo elemento";
    gotoxy(10,11); cout << "D: Sumatoria";
    gotoxy(10,13); cout << "E: Salir";
    do {
      gotoxy(20, 15); cout << "Elija su opcion: [ ]";
      gotoxy(wherex() - 2, wherey());
      opc = toupper(getche());
      Sleep(500);
    } while (!(opc >= 'A' && opc <= 'E'));
    gotoxy(20,20);
    switch (opc) {
      case 'A': cout << "Promedio.: " << setw(8) << PromVec(vE,card);
                break;
      case 'B': cout << "Maximo...: " << setw(8) << MaxVec(vE,card);
                break;
      case 'C': cout << "Minimo...: " << setw(8) << MinVec(vE,card);
                break;
      case 'D': cout << "Sumatoria: " << setw(8) << SumVec(vE,card);
                break;
    }
    if (opc != 'E') {
      gotoxy(1,24);
      cout << "Oprima Enter para continuar...";
      getche();
    }
  } while (!(opc == 'E'));
} //Menu

main() {
  tvEnt vEnt;
  short cantElem;

  cantElem = ObtCard();
  GenVec(vEnt,cantElem);
  EmitirVec(vEnt,cantElem);
  Menu(vEnt,cantElem);
  return 0;
}
