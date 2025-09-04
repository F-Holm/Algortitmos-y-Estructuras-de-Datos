#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "configuracion.hpp"
#include "ejecutar.hpp"
#include "formatear.hpp"

using std::string;
using std::vector;
namespace fs = std::filesystem;

// bool kDebug = false;
bool kRelease = false;
bool kNoEjecutar = false;

inline string ComandoCompilar(const string& unidad, const string& ejercicio);
inline void VerificarArgumentos(string& unidad, string& ejercicio,
                                const vector<string>& args);

int main(int argc, char* argv[]) {
  Formatear(true, false);

  vector<string> args;

  for (int i = 1; i < argc; i++)
    args.push_back(string(argv[i]));

  string unidad = "";
  string ejercicio = "";

  VerificarArgumentos(unidad, ejercicio, args);

  while (!EsValido(unidad) || !EsValido(ejercicio)) {
    std::cout << "Unidad: ";
    std::cin >> unidad;
    std::cout << "Ejercicio: ";
    std::cin >> ejercicio;
    std::cout << std::endl;
  }

  system(ComandoCompilar(unidad, ejercicio).c_str());

  if (!kNoEjecutar)
    Ejecutar(unidad, ejercicio);
  return 0;
}

inline string ComandoCompilar(const string& unidad, const string& ejercicio) {
  using namespace Configuracion;
  fs::path src("./unidad_" + unidad + "/ejercicio_" + ejercicio + ".cpp");
  fs::path exe = src;

#ifdef _WIN32
  exe.replace_extension(".exe");
#else
  exe.replace_extension("");
#endif

  return string(kCompilador) + " " + string(kEstandar) + " " +
         string(kExtraInfo) + " " +
         string(kModoCompilar == Modo::DEBUG_ && kRelease == false
                    ? kDebugFlags
                    : kReleaseFlags) +
         " " + string(kInclude) + " \"" + src.string() + "\" -o \"" +
         exe.string() + "\"";
}

inline void VerificarArgumentos(string& unidad, string& ejercicio,
                                const vector<string>& args) {
  for (const string& s : args) {
    if (s.size() == 2) {
      if (Flags::CmpFlags(s.c_str(), Flags::kRelease)) {
        kRelease = true;
        continue;
      } else if (Flags::CmpFlags(s.c_str(), Flags::kNoEjecutar)) {
        kNoEjecutar = true;
        continue;
      }
    }
    if (unidad == "")
      unidad = s;
    else if (ejercicio == "")
      ejercicio = s;
    else
      std::cout << "AFUERA: " << s;
  }
}