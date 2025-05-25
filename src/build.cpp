#include <atomic>
#include <cstdint>
#include <filesystem>
#include <future>
#include <iostream>
#include <mutex>
#include <vector>

#include "configuracion.h"
#include "formatear.hpp"

using std::string;
using std::vector;

enum class Estado : char { ERROR = 'E', WARNING = 'W', SUCCESS = 'S' };

inline string ComandoCompilar(const fs::path& src);
inline void Compilar(const fs::path& archivo);
inline string EjecutarComando(const string& cmd);
inline Estado AnalizarSalida(const std::string& salida);
inline string DivisorHorizontal();
inline void MostrarResultados(const size_t& cant_compilaciones);

namespace Contadores {
std::atomic<int> cant_success = 0;
std::atomic<int> cant_warning = 0;
std::atomic<int> cant_error = 0;
}  // namespace Contadores

std::mutex mutex_compilar;

bool kExcluir = false;
bool kDebug = false;
// bool kRelease = false;

int main(int argc, char* argv[]) {
  Formatear(true, false);

  for (int i = 1; i < argc; i++) {
    if (Flags::CmpFlags(argv[i], Flags::kExcluir)) kExcluir = true;
    if (Flags::CmpFlags(argv[i], Flags::kDebug)) kDebug = true;
    // if (Flags::CmpFlags(argv[i], Flags::kRelease)) kRelease = true;
  }

  vector<fs::path> archivos = BuscarCpps(".", kExcluir, true, {".cpp"});
  vector<std::future<void>> tareas;

  for (const auto& arch : archivos)
    tareas.push_back(std::async(std::launch::async, Compilar, arch));
  for (auto& t : tareas) t.get();

  MostrarResultados(archivos.size());
  return 0;
}

inline string ComandoCompilar(const fs::path& src) {
  using namespace Configuracion;
  fs::path exe = src;

#ifdef _WIN32
  exe.replace_extension(".exe");
#else
  exe.replace_extension("");
#endif

  return string(kCompilador) + " " + string(kEstandar) + " " +
         string(kExtraInfo) + " " +
         string(kModoBuild == Modo::RELEASE_ && kDebug == false ? kReleaseFlags
                                                                : kDebugFlags) +
         " \"" + src.string() + "\" -o \"" + exe.string() + "\" 2>&1";
}

inline bool EstaExcluido(const fs::path& archivo) {
  fs::path archivo_abs = fs::absolute(archivo);
  for (size_t i = 0; i < Configuracion::kCantRespuestas; i++) {
    fs::path excluido_abs = fs::absolute(Configuracion::kRespuestas[i]);
    fs::path relative = archivo_abs.lexically_relative(excluido_abs);
    if (!relative.empty() && !(relative.string().compare(0, 2, "..") == 0)) {
      return true;
    }
  }
  fs::path excluido_abs = fs::absolute(fs::path("./src/"));
  fs::path relative = archivo_abs.lexically_relative(excluido_abs);
  if (!relative.empty() && !(relative.string().compare(0, 2, "..") == 0)) {
    return true;
  }
  return false;
}

inline vector<fs::path> BuscarCpps(const fs::path& root, const bool& excluir) {
  vector<fs::path> archivos;
  for (auto& p : fs::recursive_directory_iterator(root))
    if (p.path().extension() == ".cpp" && (!excluir || !EstaExcluido(p.path())))
      archivos.push_back(p.path());
  return archivos;
}

inline void Compilar(const fs::path& archivo) {
  const string cmd = ComandoCompilar(archivo);
  const string salida = EjecutarComando(cmd);
  const Estado estado = AnalizarSalida(salida);

  if (estado != Estado::SUCCESS) {
    std::lock_guard<std::mutex> lock(mutex_compilar);
    std::cout << salida << '\n' << DivisorHorizontal() << std::flush;
  }

  switch (estado) {
    case Estado::SUCCESS:
      Contadores::cant_success++;
      break;
    case Estado::WARNING:
      Contadores::cant_warning++;
      break;
    case Estado::ERROR:
      Contadores::cant_error++;
      break;
  }
}

inline string EjecutarComando(const string& cmd) {
  string salida;
  char buffer[256];

#ifdef _WIN32
  FILE* pipe = _popen(cmd.c_str(), "r");
#else
  FILE* pipe = popen(cmd.c_str(), "r");
#endif
  if (!pipe) return "Error al ejecutar";
  while (fgets(buffer, sizeof(buffer), pipe)) {
    salida += buffer;
  }
#ifdef _WIN32
  _pclose(pipe);
#else
  pclose(pipe);
#endif
  return salida;
}

inline Estado AnalizarSalida(const std::string& salida) {
  // string s = salida;
  //  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  if (salida.find("error") != std::string::npos) return Estado::ERROR;
  if (salida.find("warning") != std::string::npos) return Estado::WARNING;
  return Estado::SUCCESS;
}

inline string DivisorHorizontal() {
  return "\n--------------------------------------------------\n\n";
}

inline void MostrarResultados(const size_t& cant_compilaciones) {
  // std::lock_guard<std::mutex> lock(mutex_compilar);
  std::cout << "Se compilaron " << cant_compilaciones << " archivos\n    - "
            << Contadores::cant_success << " compilaciones exitosas\n    - "
            << Contadores::cant_warning
            << " compilaciones con advertencias\n    - "
            << Contadores::cant_error << " compilaciones fallidas" << std::endl;
}