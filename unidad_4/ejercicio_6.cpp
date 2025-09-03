// Unidad 4 - Ejercicio 6
#include <fstream>
#include <iostream>

using namespace std;

typedef char str5[6];
typedef char str30[31];

struct tsExamen {
  str5 codUni;
  str5 codFac;
  str30 apeYNom;
  int numLeg;  // 7 dígitos
  short nota;  // 2 dígitos
};

int main() {
  ifstream Exam("Examenes.dat", ios::binary | ios::in);
  tsExamen sExam;
  while (!Exam.eof()) {
    str5 uni;
    while (!Exam.eof()) {
      str5 fac;
      while (!Exam.eof()) {
      }
    }
  }
  return 0;
}
