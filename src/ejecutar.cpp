#include <iostream>
#include <string>
#include <cstring>

#include "formatear.hpp"

using std::string;

inline bool EsValido(string dir);

int main(int argc, char* argv[]){
    string unidad = argc >= 3 ? argv[1] : "";
    string ejercicio = argc >= 3 ? argv[2] : "";

    while (EsValido(unidad) && EsValido(ejercicio)){
        std::cout << "Unidad: ";
        std::cin >> unidad;
        std::cout << "Ejercicio: ";
        std::cin >> ejercicio;
        std::cout << std::endl;
    }

#ifdef _WIN32
    string cmd = "./unidad_" + unidad + "/ejercicio_" + ejercicio + ".exe";
#else
string cmd = "./unidad_" + unidad + "/ejercicio_" + ejercicio;
#endif

    system(cmd.c_str());

    Formatear(true, false);
    return 0;
}

inline bool EsValido(string dir){
    if (dir.empty() || dir.length() > 200)
        return false;

    constexpr string_view caracteres_invalidos = R"(\/:*?"<>| .,)";

    for (char c : nombre) {
        if (std::isupper(static_cast<unsigned char>(c))) return false;
        if (caracteres_invalidos.find(c) != std::string::npos) return false;
    }

    return true;
}