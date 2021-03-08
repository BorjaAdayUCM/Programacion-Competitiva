#include <iostream>
#include <string>
#include <cmath>
#include <math.h>

using namespace std;

void descomponer(int &numero, int &i, int &numeroFinal);

bool casoDePrueba();

int main() {
    while (casoDePrueba()) {}
    return 0;
}

bool casoDePrueba() {
    int numero;
    cin >> numero;
    if (!cin)return false;
    else {
        int i = 0;
        int numeroFinal = 0;
        descomponer(numero, i, numeroFinal);
        cout << numeroFinal << endl;
    }
}

void descomponer(int &numero, int &i, int &numeroFinal) {
    numeroFinal = (numero * 4 * pow(4, i)) + numeroFinal;
    numero = numero / 2;
    i++;
    if (numero / 2 >= 1) descomponer(numero, i, numeroFinal);
    else numeroFinal = (numero * 4 * pow(4, i)) + numeroFinal;
}