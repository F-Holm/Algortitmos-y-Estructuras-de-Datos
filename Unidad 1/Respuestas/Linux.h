#ifndef PLATFORM_UTILS_H
#define PLATFORM_UTILS_H

#include <iostream>

// Detectar el sistema operativo
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// Función gotoxy para Windows y Linux
void gotoxy(int x, int y) {
    #ifdef _WIN32
        // Código para Windows
        HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hCon, dwPos);
    #else
        // Código para Linux
        // En Linux, usamos códigos de escape ANSI para mover el cursor
        std::cout << "\033[" << y << ";" << x << "H";
    #endif
}

// Función para pausar la ejecución de manera compatible
void pause_execution() {
    #ifdef _WIN32
        system("pause > NULL");  // Pausa en Windows
    #else
        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.ignore();  // Pausa en Linux
    #endif
}

#endif // PLATFORM_UTILS_H
