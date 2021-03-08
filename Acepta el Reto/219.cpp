#include <iostream>
#include <string>

using namespace std;

//Pre: 1<=n<=longitud(numeros)
int analizarCaso(int numeros[], int numElementos) {
    int contador = 0;
    for (int i = 0; i < numElementos; i++) /*I: (0<=i<n)^(contador=#numPares(j) pt j: 0<=j<=i: v[j]) */{
        if (numeros[i] % 2 == 0) contador++;
    }
    return contador;
}

//Post: ret #numPares(v[k]) pt k : 0<=k<n: v[k]
// numPares: ret  k%2==0
int main() {
    int numeroCasos;
    cin >> numeroCasos;
    for (int i = 0; i < numeroCasos; i++) {
        int numElementos, numeros[10000];
        cin >> numElementos;
        for (int i = 0; i < numElementos; i++) cin >> numeros[i];
        cout << analizarCaso(numeros, numElementos) << '\n';
    }
}