@echo off
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/build.cpp -o build.exe
REM clang++ -std=c++23 -Wall -Wextra -Wpedantic -g -O0 -DDEBUG ./src/build.cpp -o build.exe
REM clang++ -std=c++23 -Wall -Wextra -Wpedantic -g -O0 -DDEBUG ./src/compilar.cpp -o c.exe
REM clang++ -std=c++23 -Wall -Wextra -Wpedantic -g -O0 -DDEBUG ./src/clean.cpp -o g.exe
REM clang++ -std=c++23 -Wall -Wextra -Wpedantic -g -O0 -DDEBUG ./src/formatear.cpp -o f.exe
REM clang++ -std=c++23 -Wall -Wextra -Wpedantic -g -O0 -DDEBUG ./src/nuevo.cpp -o n.exe