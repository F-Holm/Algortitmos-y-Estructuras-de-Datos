// Unidad 1 - Ejercicio 15C
#include <iostream>

using namespace std;
//num perfecto = suma de sus partes alicuotas excepto el propio número es el número dado
//2^(n-1) * (2^n -1)

bool esPrimo(unsigned long num){
    switch (num){
        case 0:        
        case 1:
        return false;

        default:
        for (unsigned long i = 2; i < num/2;i++)
            if (num % i == 0)
                return false;
        return true;
    }
}

int main(){
    unsigned int k = 0, num = 0;
    while(k < 5){
        num += 2;
        unsigned int sumDiv = 1;

        for (unsigned int i = 2;i <= num/2;i++)
            if (num % i == 0)
                sumDiv += i;

        if (num == sumDiv){
            k++;
            cout << k << ") " << num << " es un número perfecto\n";
        }
    }
    return 0;
}