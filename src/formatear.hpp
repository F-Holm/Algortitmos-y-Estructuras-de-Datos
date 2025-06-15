#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include "configuracion.h"

namespace fs = std::filesystem;
using std::string;
using std::vector;

inline void Formatear(const bool& excluir, const bool& excluir_src);
inline bool EstaExcluido(const fs::path& archivo, const bool& excluir,
                         const bool& excluir_src);
inline vector<fs::path> BuscarCpps(const fs::path& root, const bool& excluir,
                                   const bool& excluir_src,
                                   const vector<string>& extensiones);
inline bool EstaExtension(const string& extension,
                          const vector<string>& extensiones);

inline void Formatear(const bool& excluir, const bool& excluir_src) {
  vector<string> extensiones = {".cpp", ".h", ".hpp"};
  vector<fs::path> archivos =
      BuscarCpps(".", excluir, excluir_src, extensiones);
  for (auto& dir : archivos)
    system((string("clang-format -i \"") + dir.string() + "\"").c_str());
}

inline bool EstaExcluido(const fs::path& archivo, const bool& excluir,
                         const bool& excluir_src) {
  fs::path archivo_abs = fs::absolute(archivo);
  if (excluir) {
    for (size_t i = 0; i < Configuracion::kCantRespuestas; i++) {
      fs::path excluido_abs = fs::absolute(Configuracion::kRespuestas[i]);
      fs::path relative = archivo_abs.lexically_relative(excluido_abs);
      if (!relative.empty() && !(relative.string().compare(0, 2, "..") == 0)) {
        return true;
      }
    }
  }
  if (excluir_src) {
    fs::path excluido_abs = fs::absolute(fs::path("./src/"));
    fs::path relative = archivo_abs.lexically_relative(excluido_abs);
    if (!relative.empty() && !(relative.string().compare(0, 2, "..") == 0)) {
      return true;
    }
  }
  return false;
}

inline vector<fs::path> BuscarCpps(const fs::path& root, const bool& excluir,
                                   const bool& excluir_src,
                                   const vector<string>& extensiones) {
  vector<fs::path> archivos;
  for (auto& p : fs::recursive_directory_iterator(root))
    if (EstaExtension(p.path().extension().string(), extensiones) &&
        !EstaExcluido(p.path(), excluir, excluir_src))
      archivos.push_back(p.path());
  return archivos;
}

inline bool EstaExtension(const string& extension,
                          const vector<string>& extensiones) {
  for (const string& e : extensiones)
    if (e == extension)
      return true;
  return false;
}