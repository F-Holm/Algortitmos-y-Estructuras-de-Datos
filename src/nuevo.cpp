#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "ejecutar.hpp"
#include "formatear.hpp"

using std::string;

namespace fs = std::filesystem;

inline fs::path Nombre(const string& unidad, const string& ejercicio);
inline string Archivo(const string& unidad, const string& ejercicio);

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

  std::ofstream archivo(Nombre(unidad, ejercicio));
  archivo << Archivo(unidad, ejercicio);
  archivo.close();

  Formatear(true, false);
}

inline fs::path Nombre(const string& unidad, const string& ejercicio) {
  return fs::path(string("./unidad_") + unidad + string("/ejercicio_") +
                  ejercicio + string(".cpp"));
}

inline string Archivo(const string& unidad, const string& ejercicio) {
  return R"(// Unidad )" + unidad + R"( - Ejercicio )" + ejercicio + R"(
    #include <iostream>

    using namespace std;

    int main() {
        ;
        return 0;
    }
    )";
}