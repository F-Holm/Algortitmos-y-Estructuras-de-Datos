// Unidad 1 - Ejercicio 22
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

using namespace std;

#define CENTINELA "*"
#define ISOSCELES 'I'
#define ESCALENO 'E'
#define EQUILATERO 'Q'
typedef char str20[21];

void GenerarTriangulo(unsigned short &a, unsigned short &b, unsigned short &c) {
  const unsigned short MIN = 6, MAX = 10;
  a = rand() % (MAX - MIN) + MIN;
  b = rand() % (MAX - MIN) + MIN;
  do {
    c = rand() % (MAX - MIN) + MIN;
  } while (c > a + b && b > a + c && a > b + c);

  cout << "Lados: a = " << a << "; b = " << b << "; c = " << c << endl;
}

void Calcular(unsigned short a, unsigned short b, unsigned short c,
              unsigned short &perimetro, char &tipo) {
  perimetro = a + b + c;
  if (a == b && a == c)
    tipo = EQUILATERO;
  else if (a == b || a == c || b == c)
    tipo = ISOSCELES;
  else
    tipo = ESCALENO;
}

void Responder(unsigned short &perimetro, char &tipo) {
  cout << "Perímetro: " << flush;
  cin >> perimetro;
  do {
    cout << "Tipo ( Isosceles (" << ISOSCELES << ") | Escaleno (" << ESCALENO
         << ") | Equilatero (" << EQUILATERO << ") ):" << endl;
    cin >> tipo;
  } while (tipo != ISOSCELES && tipo != ESCALENO && tipo != EQUILATERO);
}

void Verificar(str20 alumno, unsigned short perimetro, char tipo,
               unsigned short perimetroAlumno, char tipoAlumno,
               unsigned short &rCorrectas, unsigned short &rIncorrectas) {
  if (tipo != tipoAlumno || perimetro != perimetroAlumno) {
    cout << "RESPUESTA INCORRECTA\n";
    cout << "La respuesta correcta es:\n\tperimetro = " << perimetro
         << "\n\ttipo = " << tipo << endl;
    cout << alumno << " - debe estudiar más\n\n";
    rIncorrectas++;
  } else {
    cout << "RESPUESTA CORRECTA\n";
    cout << alumno << " - O.K.\n\n";
    rCorrectas++;
  }
}

int main() {
  srand(time(NULL));
  str20 alumno;
  unsigned short respuestas_correctas = 0, respuestas_incorrectas = 0;
  cout << "Ingrese su nombre (" << CENTINELA << " = SALIR)" << endl;
  cin.get(alumno, 21);

  while (strcmp(alumno, CENTINELA)) {
    unsigned short a, b, c, perimetro, perimetroAlumno;
    char tipo, tipoAlumno;
    GenerarTriangulo(a, b, c);
    Calcular(a, b, c, perimetro, tipo);
    Responder(perimetroAlumno, tipoAlumno);
    Verificar(alumno, perimetro, tipo, perimetroAlumno, tipoAlumno,
              respuestas_correctas, respuestas_incorrectas);

    cout << "Ingrese su nombre (" << CENTINELA << " = SALIR)" << endl;
    cin.ignore();
    cin.get(alumno, 21);
  }

  cout << "Respuestas correctas: " << respuestas_correctas << endl;
  cout << "Respuestas incorrectas: " << respuestas_incorrectas << endl;
  return 0;
}
