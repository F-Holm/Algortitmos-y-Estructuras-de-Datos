#pragma once

#include <filesystem>

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
inline const fs::path kRespuestas[] = {"./Unidad 1/Respuestas/",
                                       "./Unidad 1/Respuestas STD/",
                                       "./Unidad 1/Diagramas en VISIO/"};
inline const uint8_t kCantRespuestas = sizeof(kRespuestas) / sizeof(fs::path);
};  // namespace Configuracion