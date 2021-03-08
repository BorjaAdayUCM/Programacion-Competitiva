#include <iostream>
using namespace std;

typedef char tMatriz[1000][1000];

typedef struct {
    tMatriz matriz;
    int maxFila;
    int maxColumna;
} tCuadricula;

bool casoDePrueba() {
    tCuadricula matriz;
    int contadorDeMinas = 0, contadorDeCasillas = 0;
    cin >> matriz.maxColumna >> matriz.maxFila;
    for (int fila = 0; fila < matriz.maxFila; ++fila) {
        for (int columna = 0; columna < matriz.maxColumna; ++columna) cin >> matriz.matriz[fila][columna];
    }
    if (matriz.maxFila == 0 || matriz.maxColumna == 0) return false;
    else {
        for (int fila = 1; fila < matriz.maxFila - 1; ++fila) {
            for (int columna = 1; columna < matriz.maxColumna - 1; ++columna) {
                if (matriz.matriz[fila][columna] == '-') {
                    if (matriz.matriz[fila - 1][columna - 1] == '*') contadorDeMinas++;
                    if (matriz.matriz[fila][columna - 1] == '*') contadorDeMinas++;
                    if (matriz.matriz[fila + 1][columna - 1] == '*') contadorDeMinas++;
                    if (matriz.matriz[fila - 1][columna] == '*') contadorDeMinas++;
                    if (matriz.matriz[fila + 1][columna] == '*') contadorDeMinas++;
                    if (matriz.matriz[fila - 1][columna + 1] == '*') contadorDeMinas++;
                    if (matriz.matriz[fila][columna + 1] == '*') contadorDeMinas++;
                    if (matriz.matriz[fila + 1][columna + 1] == '*') contadorDeMinas++;
                    if (contadorDeMinas >= 6) contadorDeCasillas++; 
                    contadorDeMinas = 0;
                }
            }
        }
        cout << contadorDeCasillas << endl;
        return true;
    }
}

int main() {
    while (casoDePrueba()) {}
    return 0;
}