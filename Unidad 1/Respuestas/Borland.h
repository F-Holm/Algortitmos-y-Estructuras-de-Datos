/*
    Este archivo contiene funciones específicas de borland que no se encuentran en los compiladores modernos
*/

#pragma once

#include <ctime>
#include <cstdlib>

void randomize() {
  srand(static_cast<unsigned int>(time(nullptr)));
}
  
int random(int n) {
  return rand() % n;
}
  
double poly(double x, int degree, double coef[]) {
  double result = coef[0];
  for (int i = 1; i <= degree; ++i) {
    result = result * x + coef[i];
  }
  return result;
}