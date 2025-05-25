#include "ejecutar.hpp"

#include <iostream>
#include <string>

#include "formatear.hpp"

using std::string;

int main(int argc, char* argv[]) {
  string unidad = argc >= 3 ? argv[1] : "";
  string ejercicio = argc >= 3 ? argv[2] : "";

  while (!EsValido(unidad) || !EsValido(ejercicio)) {
    std::cout << "Unidad: ";
    std::cin >> unidad;
    std::cout << "Ejercicio: ";
    std::cin >> ejercicio;
    std::cout << std::endl;
  }

  Ejecutar(unidad, ejercicio);

  Formatear(true, false);
  return 0;
}