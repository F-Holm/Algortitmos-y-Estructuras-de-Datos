#include "formatear.hpp"

#ifdef _WIN32

#include <windows.h>

inline void Clean() {
  STARTUPINFO si{};
  si.cb = sizeof(si);
  PROCESS_INFORMATION pi;
  si.dwFlags = STARTF_USESHOWWINDOW;
  si.wShowWindow = SW_HIDE;

  const char* command =
      "cmd /c git clean -Xfd && timeout /t 1 /nobreak >nul && setup.bat";

  BOOL success = CreateProcessA(NULL, (LPSTR)command, NULL, NULL, FALSE,
                                CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

  if (success) {
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
  } else {
    // Manejo de error opcional
    // DWORD errorCode = GetLastError();
    // printf("Error al ejecutar proceso: %lu\n", errorCode);
  }
}

#else

inline void Clean() {
  system("nohup bash -c 'git clean -Xfd && sleep 5 && ./setup.sh' &");
}

#endif

int main() {
  Formatear(true, false);
  Clean();
  return 0;
}
