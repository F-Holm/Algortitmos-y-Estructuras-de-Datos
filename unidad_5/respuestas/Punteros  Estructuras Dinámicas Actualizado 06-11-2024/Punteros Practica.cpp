/*
  Id.Programa: Punteros Practica.cpp
  Autor......: Lic. Hugo Cuello
  Fecha......: 2023-octubre
  Comentario.: variable puntero a tipo de dato.
               Un puntero lejano con una arquitectura
               y software de 32 bits (4 bytes) puede
               apuntar un máximo de 4 Gb. 2 ^ 32 bytes
               y con una arquitectura de hardware y
               software de 64 bits (8 bytes) puede apuntar
               una cantidad de 2 ^ 64 bytes.
               El byte que es la menor unidad direccionable
               podemos ver su dir. como un numero
               compuesto, como lo es la hora (hh:mm) o bien
               como un múmero simple (hhmm), equivalente a
               decir (Seg:Ofs) como dir. compuesta o como
               (SegOfs) como un número simple. Representado
               en el sistema hexadecimal, sería 4 dígitos
               para el Segmento y 4 dígitos para el Offset.
*/

#include <fstream>
using namespace std;

main () {
  short a,
        b = 7,
        *p,
        *q;
  char  cad[21],
        *pCar;

  a = 5;
  p = &a;
  *p = *p + 3;
  p = new short;
  *p = a;
  *p = *p - 3;
  q = p;
  if (p == q)
    cout << "Las vars. puntero p y q apuntan a la misma dir." << endl;
  p = &a;
  cout << "Contenido de (a): " << a << endl; // 8
  cout << "Contenido de a apuntado por p (*p): " << *p << endl; // 8
  cout << "Dir. donde esta p (&p): " << &p << endl; // donde se enc. p
  cout << "Dir. donde apunta p (p): " << p << endl; // donde apunta p la dir. a
  cout << "Dir. donde esta a (&a): " << &a << endl; // donde esta a
  cout << "Dir. donde esta b (&b): " << &b << endl;
  cout << "Contenido de la var.din. apuntada por q (*q): " << *q << endl; // 5
  cout << "Dir. donde esta q (&q): " << &q << endl; // donde esta q
  cout << "Dir. donde apunta q (q): " << q << endl; // donde apunta q
  p--;
  cout << "p apunta a (b): " << p << endl;
  cout << "el contenido donde apunta p es el de b: " << *p << endl;
  p = NULL; // La var.ptr. p ahora no apunta a nada,
  delete q; // la var.din. apuntada por q ha sido eliminada, q queda indefinida.
  strcpy(cad,"supermancito");
  pCar = cad;
  cout << "El cont. de (pCar) es una cadena; NO donde apunta: " << pCar << endl;
  cout << "El contenido de (*pCar) es un car " << *pCar << endl;
  cout << "Dir. donde esta pCar (&pCar): " << &pCar << endl;
  printf("Dir. donde apunta (pCar formato %%p con printf) es %p \n",pCar);
  cout << "Dir. donde esta cad (&pCar): " << &cad << endl;
  cout << "Error logico *q por estar indefinido, error *p por ser NULL" << endl;
  cout << *q << endl;
  cout << *p << endl;
  return 0;
}
