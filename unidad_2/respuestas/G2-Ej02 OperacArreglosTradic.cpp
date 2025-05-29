/*
    Id.Programa: G2-Ej02 OperacArreglosTradic.cpp
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
#include<iomanip.h>
#include<windows>
#include<fstream>
using namespace std;

const
  MAX_ELEM = 101;

typedef unsigned int word;
typedef short tvec[MAX_ELEM];

// Prototipos ------------------
short ObtCard();
void GenVec(short [] , short );
void EmitirVec(short [] , short );
word SumVec(short [] , short );
float PromVec(tvec , short );
short MaxVec(short [] , short );
short MinVec(short [] , short );
char Menu(short [] , short );
// Fin Prototipos -------------

main() {
  short vEnt[MAX_ELEM];
  short  cantElem;

  cantElem = ObtCard();
  GenVec(vEnt,cantElem);
  EmitirVec(vEnt,cantElem);
  Menu(vEnt,cantElem);
  return 0;
}

short ObtCard() {
  short cantElem;

  do {
    gotoxy(5,3); clreol();
    cout << "Ing.Cardinalidad del vector [1.." << MAX_ELEM -1 << "]: ";
    cin >> cantElem;
  } while (!(cantElem >= 1 && cantElem < MAX_ELEM));
  return cantElem;
} //ObtenerCard

void GenVec(short vE[], short card) {

  for (short i = 1; i <= card; i++)
    vE[i] = random(501) + 100;
} //GenVec

void EmitirVec(short vE[], short card) {

  cout << "Valores en el vector..." << endl;
  for (short i = 1; i <= card; i++)
    cout << setw(5) << vE[i] << ' ';
  gotoxy(1,22);
  cout << "Oprima Enter para continuar...";
  getche();
} //EmitirVec

word SumVec(short vE[], short card) {
  word sum = 0;

  for (short i = 1; i <= card; i++)
    sum += vE[i];
  return sum;
} //SumVec

float PromVec(tvec vE, short card) {

  return SumVec(vE,card) / float (card);
} //PromVec

short MaxVec(short vE[], short card) {
  short maxElem;

  maxElem = vE[1];
  for (short i = 2; i <= card; i++)
    //vE[i] > maxElem && (maxElem = vE[i]);
    if (vE[i] > maxElem)
        maxElem = vE[i];
  return maxElem;
} //MaxVec

short MinVec(short vE[], short card) {
  short minElem;

  minElem = vE[1];
  for (short i = 2; i <= card; i++)
    //vE[i] < minElem && (minElem = vE[i]);
    if (vE[i] < minElem)
        minElem = vE[i];
  return minElem;
} //MinVec

void CalcOpc(short vE[], short card, char opc) {
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
} // CalcOpc

char Menu(short vE[], short card) {
  char opc;

  cout.precision(2);
  cout.setf(ios::fixed);
  do {
    //clrscr();
    system("cls");
    gotoxy(20, 1); cout << "Operaciones con Arreglos";
    gotoxy(10, 5); cout << "A: Promedio";
    gotoxy(10, 7); cout << "B: Maximo elemento";
    gotoxy(10, 9); cout << "C: Minimo elemento";
    gotoxy(10,11); cout << "D: Sumatoria";
    gotoxy(10,13); cout << "E: Salir";
    do {
      gotoxy(15,16); cout << "Elija su opcion: [ ]";
      gotoxy(wherex() - 2, wherey());
      opc = toupper(getche());
      Sleep(2000);
    } while (!(opc >= 'A' && opc <= 'E'));
    //Sleep(1000);
    gotoxy(wherex()-1,wherey());
    cout << '*';
    CalcOpc(vE,card,opc);
    if (opc != 'E') {
      gotoxy(1,24);
      cout << "Oprima Enter para continuar...";
      getche();
    }
  } while (!(opc == 'E'));
  return opc;
} //Menu


