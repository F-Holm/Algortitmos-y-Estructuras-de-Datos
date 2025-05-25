#pragma once

#include <cstring>
#include <string>

using std::string;
using std::string_view;

inline bool EsValido(const string& dir);
inline void Ejecutar(const string& unidad, const string& ejercicio);

inline bool EsValido(const string& dir) {
  if (dir.empty() || dir.length() > 200) return false;

  constexpr string_view caracteres_invalidos = R"(\/:*?"<>| .;'",)";

  for (char c : dir) {
    if (std::isupper(static_cast<unsigned char>(c)) ||
        caracteres_invalidos.find(c) != std::string::npos)
      return false;
  }

  return true;
}

inline void Ejecutar(const string& unidad, const string& ejercicio) {
#ifdef _WIN32
  string cmd = "unidad_" + unidad + "\\ejercicio_" + ejercicio + ".exe";
#else
  string cmd = "./unidad_" + unidad + "/ejercicio_" + ejercicio;
#endif

  system(cmd.c_str());
}