
#include <fstream>
using namespace std;

const double PI = 3.1415926;

main() {
  // double x = 6, y;
  short a = 12, b = 37;  // [12, 37]
  cout << "Hola" << endl;
  randomize();
  for (short i = 1; i <= 15; i++)
    cout << random(b - a + 1) + 12 << endl;

  return 0;
}
