#pragma once

#include <filesystem>
#include <string>

using std::string;
typedef std::string_view str;
namespace fs = std::filesystem;

enum class Modo : bool { RELEASE_ = true, DEBUG_ = false };

namespace Configuracion {
inline constexpr Modo kModoBuild = Modo::RELEASE_;
inline constexpr Modo kModoCompilar = Modo::DEBUG_;
inline constexpr str kCompilador = "clang++";
inline constexpr str kEstandar = "-std=c++23";
inline constexpr str kExtraInfo = "-Wall -Wextra -Wpedantic";
inline constexpr str kDebugFlags = "-g -O0 -DDEBUG";
inline constexpr str kReleaseFlags = "-O3 -DNDEBUG";
inline const fs::path kRespuestas[] = {
    "./unidad_1/respuestas/", "./unidad_1/respuestas_std/",
    "./unidad_1/diagramas_en_visio/", "./unidad_2/respuestas/"};
inline const uint8_t kCantRespuestas = sizeof(kRespuestas) / sizeof(fs::path);
};  // namespace Configuracion

namespace Flags {
constexpr char kExcluir[2] = {'-', 'e'};
constexpr char kDebug[2] = {'-', 'd'};
constexpr char kRelease[2] = {'-', 'r'};
constexpr char kNoEjecutar[2] = {'-', 'n'};
constexpr char kEliminarTodo[2] = {'-', 't'};

inline bool CmpFlags(const char f1[2], const char f2[2]) {
  return f1[0] == f2[0] && f1[1] == f2[1];
}
}  // namespace Flags