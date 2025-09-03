// Unidad 3 - Ejercicio 1
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  try {
    fs::path cwd = fs::current_path();
    std::cout << "Directorio actual de ejecución: " << cwd << std::endl;
  } catch (const fs::filesystem_error& e) {
    std::cerr << "Error al obtener el directorio actual: " << e.what()
              << std::endl;
    return 1;
  }

  return 0;
}
