// Unidad 4 - Ejercicio 1
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

#define CENTINELA 0
typedef char str20[21];

struct tsArt {
  short codArt;
  str20 desc;
  float precUni;
};

bool ArtValido(tsArt sArt);
bool ObtDatos(tsArt& sArt);
void Escribir(ofstream& Art, tsArt sArt);

int main() {
  tsArt sArt;
  ofstream Art("Articulo.dat", ios::binary | ios::out);

  while (ObtDatos(sArt))
    if (ArtValido(sArt))
      Escribir(Art, sArt);

  Art.close();
  return 0;
}

bool ArtValido(tsArt sArt) {
  return (sArt.codArt >= 1 && sArt.codArt <= 100 && strlen(sArt.desc) > 0 &&
          sArt.precUni > 0);
}

bool ObtDatos(tsArt& sArt) {
  cout << "Código de artículo | 0 = FIN: ";
  cin >> sArt.codArt;
  if (sArt.codArt == 0)
    return false;
  cout << "Descripción: ";
  cin.ignore();
  cin.get(sArt.desc, 21);
  cout << "Precio unitario: ";
  cin >> sArt.precUni;
  return true;
}

void Escribir(ofstream& Art, tsArt sArt) {
  Art.write((char*)&sArt.codArt, sizeof(sArt.codArt));
  Art.write(sArt.desc, 20);
  Art.write((char*)&sArt.precUni, sizeof(sArt.precUni));
}