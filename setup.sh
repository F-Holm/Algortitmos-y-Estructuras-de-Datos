#!/usr/bin/env bash
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/build.cpp -o build
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/ejecutar.cpp -o e
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/compilar.cpp -o c
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/limpiar.cpp -o l
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/formatear.cpp -o f
clang++ -std=c++23 -Wall -Wextra -Wpedantic -O3 -DNDEBUG ./src/nuevo.cpp -o n