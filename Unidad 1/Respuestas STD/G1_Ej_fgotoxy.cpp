/*
	Id.Programa: G1_Ej_fgotoxy.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Funcion gotoxy de usuario.
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void gotoxy(int x, int y) {
  HANDLE hCon;
  hCon = GetStdHandle (STD_OUTPUT_HANDLE);

  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition (hCon,dwPos);
} // gotoxy

main() {
  gotoxy(0,0);
  printf("*");
  getchar();
  gotoxy(20,10);
  printf("+");
  getchar();
  return 0;
}
