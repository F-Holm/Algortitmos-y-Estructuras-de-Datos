#include <iostream>

using namespace std;

int main(){
    short n = 0;
    long double fact = 1;
    cout << "Ingrese un numero natural (incluido el 0) y se calculará su factorial!" << endl;
    do {
        cin >> n;
    } while(n<0);
    for(short int i = 1; i<=n; i++){
        fact*=i;
    }
    cout << "El valor de " << n << "! es: " << fact << endl;
    return 0;
}