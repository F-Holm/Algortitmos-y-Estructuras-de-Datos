#include "configuracion.hpp"
#include "formatear.hpp"

#ifdef _WIN32

#include <windows.h>

inline void Clean(const bool& todo) {
  STARTUPINFO si{};
  si.cb = sizeof(si);
  PROCESS_INFORMATION pi;
  si.dwFlags = STARTF_USESHOWWINDOW;
  si.wShowWindow = SW_HIDE;

  const char* command =
      todo ? "cmd /c git clean -Xfd" : "cmd /c git clean -Xfd && setup.bat";

  BOOL success = CreateProcessA(NULL, (LPSTR)command, NULL, NULL, FALSE,
                                CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

  if (success) {
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
  } else {
    // DWORD errorCode = GetLastError();
    // printf("Error al ejecutar proceso: %lu\n", errorCode);
  }
}

#else

inline void Clean(const bool& todo) {
  if (todo) {
    system("nohup bash -c 'git clean -Xfd' > /dev/null 2>&1 &");
  } else {
    system("nohup bash -c 'git clean -Xfd && ./setup.sh' > /dev/null 2>&1 &");
  }
}

#endif

int main(int argc, char* argv[]) {
  Formatear(true, false);
  Clean(argc > 1 && Flags::CmpFlags(argv[1], Flags::kEliminarTodo));
  return 0;
}
