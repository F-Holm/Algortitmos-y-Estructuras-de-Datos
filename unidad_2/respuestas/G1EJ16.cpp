
#include <fstream>
using namespace std;

main() {
  bool a, b;

  cout << "Muestra de manejo vars. booleanas o logicas" << endl;
  a = b = true;
  while (a) {
    cout << boolalpha << a << ' ' << b << ' ' << (a && b) << endl;
    if (!b)
      a = !a;
    else
      b = !b;
  }
  return 0;
}
