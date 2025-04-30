// Unidad 1 - Ejercicio 22
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

#define CENTINELA "*"
#define ISOSCELES 'I'
#define ESCALENO 'E'
#define EQUILATERO 'Q'
typedef char str20[21];

void generarTriangulo(unsigned short &a, unsigned short &b, unsigned short &c){
    const unsigned short MIN = 6, MAX = 10;
    a = rand() % (MAX - MIN) + MIN;
    b = rand() % (MAX - MIN) + MIN;
    do {
        c = rand() % (MAX - MIN) + MIN;
    } while(c > a + b && b > a + c && a > b + c);

    cout << "Lados: a = " << a << "; b = " << b << "; c = " << c << endl;
}

void calcular(unsigned short a, unsigned short b, unsigned short c, unsigned short &perimetro, char &tipo){
    perimetro = a + b + c;
    if (a == b && a == c)
        tipo = EQUILATERO;
    else if (a == b || a == c || b == c)
        tipo = ISOSCELES;
    else
        tipo = ESCALENO;
}

void responder(unsigned short &perimetro, char &tipo){
    cout << "Perímetro: ";
    cin >> perimetro;
    do {
        cout << "Tipo ( Isosceles (" << ISOSCELES << ") | Escaleno (" << ESCALENO << ") | Equilatero (" << EQUILATERO << ") ):\n";
        cin >> tipo;
    } while(tipo != ISOSCELES && tipo != ESCALENO && tipo != EQUILATERO);
}

void verificar(str20 alumno, unsigned short perimetro, char tipo, unsigned short perimetroAlumno, char tipoAlumno, unsigned short rCorrectas, unsigned short rIncorrectas){
    if (tipo == tipoAlumno && perimetro == perimetroAlumno) {
        cout << "RESPUESTA INCORRECTA\n";
        cout << "La respuesta correcta es:\n\tperimetro = " << perimetro << "\n\ttipo = " << tipo << endl;
        cout << alumno << " - debe estudiar más\n\n";
        rIncorrectas++;
    } else{
        cout << "RESPUESTA CORRECTA\n";
        cout << alumno << " - O.K.\n\n";
        rCorrectas++;
    }
}

int main() {
    srand(time(NULL));
    str20 alumno;
    unsigned short rCorrectas = 0, rIncorrectas = 0;
    cout << "Ingrese su nombre (" << CENTINELA << " = SALIR)\n";
    cin.get(alumno, 21);
    cin.ignore(100, '\n');

    while(strcmp(alumno, CENTINELA)) {
        unsigned short a, b, c, perimetro,
                    perimetroAlumno;
        char tipo, tipoAlumno;
        generarTriangulo(a, b, c);
        calcular(a, b, c, perimetro, tipo);
        responder(perimetroAlumno, tipoAlumno);
        verificar(alumno, perimetro, tipo, perimetroAlumno, tipoAlumno, rCorrectas, rIncorrectas);

        cout << "Ingrese su nombre (" << CENTINELA << " = SALIR)\n";
        cin.get(alumno, 21);
        cin.ignore(100, '\n');
    }

    cout << "Respuestas correctas: " << rCorrectas << endl;
    cout << "Respuestas incorrectas: " << rIncorrectas << endl;
    return 0;
}
