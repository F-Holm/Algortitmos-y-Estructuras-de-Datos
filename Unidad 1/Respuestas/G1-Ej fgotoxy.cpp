  /*
    Id.Programa: G1-Ej fgotoxy.cpp
    Autor......: Lic. Hugo Cuello
    Fecha......: julio-2013
    Comentario.: Funcion gotoxy de usuario.
    Lenguaje...: Borland V.5.5
  */

  #include <dos.h> // no se que es pero no funciona en linux -- Creo que es de Borland
  #include <windows.h> //función específica de windows
  #include <stdio.h>
  #include <stdlib.h>
  #include <iostream>

  using namespace std;

  void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle (STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition (hCon,dwPos);
  } // gotoxy

  int main() {
    gotoxy(0,0);
    printf("*");
    getchar();
    gotoxy(20,10);
    printf("+");
    system("pause>NULL");
    return 0;
  }
