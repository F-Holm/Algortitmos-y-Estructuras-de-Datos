@echo off
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/build.cpp -o build.exe
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/ejecutar.cpp -o e.exe
clang++ -std=c++23 -Wall -Wextra -Wpedantic -g -O0 -DDEBUG ./src/compilar.cpp -o c.exe
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/limpiar.cpp -o l.exe
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/formatear.cpp -o f.exe
REM clang++ -std=c++23 -Wall -Wextra -Wpedantic -g -O0 -DDEBUG ./src/nuevo.cpp -o n.exe