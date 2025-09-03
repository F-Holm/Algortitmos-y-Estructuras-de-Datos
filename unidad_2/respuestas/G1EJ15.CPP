
#include <iostream>
using namespace std;

int main() {
    int i,
        sum,
        num = 0,
        k = 0;

    cout << "Generar los 3 primeros numeros perfectos" << endl;
    while ( k < 3 ) {
        num += 2;
        sum = 1;
        for (i = 2; i <= num / 2; i++)
            if ( num % i == 0 )
                sum += i;
        if ( num == sum) {
            k++;
            cout << k << "-: " << num << endl;
        }
    }
  return 0;
}
