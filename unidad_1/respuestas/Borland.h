/*
    Este archivo contiene funciones específicas de borland
    que no se encuentran en los compiladores modernos.
    
    El #pragma once solo se encuentra implementado
    en compiladores modernos como gcc o clang++.
*/

#pragma once

#include <ctime>
#include <cstdlib>
#include <iostream>

void randomize() {
  srand(static_cast<unsigned int>(time(nullptr)));
}
  
int random(int n) {
  return rand() % n;
}

void clrscr(){
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
  
double poly(double x, int degree, double coef[]) {
  double result = coef[0];
  for (int i = 1; i <= degree; ++i) {
    result = result * x + coef[i];
  }
  return result;
}

void clreol() {
    std::cout << "\033[K";
}

#ifdef _WIN32
#include <windows.h>
void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle (STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition (hCon,dwPos);
  }
#endif