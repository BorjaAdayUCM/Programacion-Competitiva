#include <iostream>

using namespace std;

typedef char tMatriz[60][60];

typedef struct {
    tMatriz matriz;
    int maxFila;
    int maxColumna;
    int arboles;
} tCuadricula;

bool casoDePrueba() {
    tCuadricula matriz;
    int filaArbol, columnaArbol;
    int contador = 0;
    cin >> matriz.maxColumna >> matriz.maxFila >> matriz.arboles;
    for (int fila = 0; fila < matriz.maxFila; ++fila) {
        for (int columna = 0; columna < matriz.maxColumna; ++columna) {
            matriz.matriz[fila][columna] = '-';
        }
    }
    for (int i = 0; i < matriz.arboles; i++) {
        cin >> columnaArbol >> filaArbol;
        matriz.matriz[filaArbol - 1][columnaArbol - 1] = '*';
    }
    if (matriz.maxFila == 0 && matriz.maxColumna == 0 && matriz.arboles == 0) return false;
    else
    {
        for (int fila = 0; fila < matriz.maxFila; ++fila) {
            for (int columna = 0; columna < matriz.maxColumna; ++columna) {
                if ((fila - 1 >= 0) && (columna - 1 >= 0) && (matriz.matriz[fila][columna] == '*') && (matriz.matriz[fila - 1][columna - 1] == '-')) matriz.matriz[fila - 1][columna - 1] = '^';
                if ((fila - 1 >= 0) && (matriz.matriz[fila][columna] == '*') && (matriz.matriz[fila - 1][columna] == '-')) matriz.matriz[fila - 1][columna] = '^';
                if ((fila - 1 >= 0) && (matriz.matriz[fila][columna] == '*') && (matriz.matriz[fila - 1][columna + 1] == '-')) matriz.matriz[fila - 1][columna + 1] = '^';
                if ((fila >= 0) && (columna + 1 >= 0) && (matriz.matriz[fila][columna] == '*') && (matriz.matriz[fila][columna + 1] == '-')) matriz.matriz[fila][columna + 1] = '^';
                if ((matriz.matriz[fila][columna] == '*') && (matriz.matriz[fila + 1][columna + 1] == '-')) matriz.matriz[fila + 1][columna + 1] = '^';
                if ((matriz.matriz[fila][columna] == '*') && (matriz.matriz[fila + 1][columna] == '-')) matriz.matriz[fila + 1][columna] = '^';
                if ((columna - 1 >= 0) && (matriz.matriz[fila][columna] == '*') && (matriz.matriz[fila + 1][columna - 1] == '-')) matriz.matriz[fila + 1][columna - 1] = '^';
                if ((columna - 1 >= 0) && (matriz.matriz[fila][columna] == '*') && (matriz.matriz[fila][columna - 1] == '-')) matriz.matriz[fila][columna - 1] = '^';
            }
        }
        for (int fila = 0; fila < matriz.maxFila; ++fila) {
            for (int columna = 0; columna < matriz.maxColumna; ++columna) {
                if (matriz.matriz[fila][columna] == '^') contador++;
            }
        }
        cout << contador << endl;
        return true;
    }
}

int main() {
    while (casoDePrueba()) {}
    return 0;
}