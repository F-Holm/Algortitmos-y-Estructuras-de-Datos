
#include <fstream>
using namespace std;

string iif(bool expLog, string x, string y) {
  if (expLog)
    return x;
  else
    return y;
}  // iif

short sgn(float x) {
  if (!x)
    return x;
  else
    return x / fabs(x);
}  // sgn

main() {
  float a;

  cout << "Valor real: ";
  cin >> a;
  cout << "sgn x: "
       << iif(a == 0, "cero", iif(sgn(a) == 1, "Positivo", "Negativo"));
  return 0;
}
