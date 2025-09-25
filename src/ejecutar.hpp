#pragma once

#include <cstring>
#include <filesystem>
#include <string>

using std::string;
using std::string_view;
namespace fs = std::filesystem;

inline bool EsValido(const string& dir);
inline void Ejecutar(const string& unidad, const string& ejercicio);

inline bool EsValido(const string& dir) {
  if (dir.empty() || dir.length() > 200)
    return false;

  constexpr string_view caracteres_invalidos = R"(\/:*?"<>| .;'",)";

  for (char c : dir) {
    if (std::isupper(static_cast<unsigned char>(c)) ||
        caracteres_invalidos.find(c) != std::string::npos)
      return false;
  }

  return true;
}

inline void Ejecutar(const string& unidad, const string& ejercicio) {
  fs::path cmd("./unidad_" + unidad + "/ejercicio_" + ejercicio);
  cmd = fs::absolute(cmd);
  cmd.replace_extension(".exe");
  fs::path old_cwd = fs::current_path();
  fs::current_path(cmd.parent_path());

#ifdef _WIN32
  system(("./" + cmd.filename().string()).c_str());
#else
  system(("wine ./" + cmd.filename().string()).c_str());
#endif

  fs::current_path(old_cwd);
}