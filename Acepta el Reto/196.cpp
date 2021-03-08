#include <iostream>

using namespace std;

typedef char tSudoku[9][9];

void casoDePrueba() {
    tSudoku sudoku;
    bool mal = false;
    int contador = 0;
    int filaContraria, columnaContraria;
    for (int fila = 0; fila < 9; ++fila) {
        for (int columna = 0; columna < 9; ++columna) {
            cin >> sudoku[fila][columna];
        }
    }
    for (int fila = 0; fila < 9; ++fila) {
        for (int columna = 0; columna < 9; ++columna) {
            if (sudoku[fila][columna] == '1' || sudoku[fila][columna] == '2' || sudoku[fila][columna] == '3' || sudoku[fila][columna] == '4' || sudoku[fila][columna] == '5' || 
                sudoku[fila][columna] == '6' || sudoku[fila][columna] == '7' || sudoku[fila][columna] == '8' || sudoku[fila][columna] == '9') contador++;
        }
    }
    if (contador > 32) mal = true;
    for (int fila = 0; fila < 9; ++fila) {
        for (int columna = 0; columna < 9; ++columna) {
            filaContraria = 8 - fila;
            columnaContraria = 8 - columna;
            if ((sudoku[fila][columna] == '1' || sudoku[fila][columna] == '2' || sudoku[fila][columna] == '3' || sudoku[fila][columna] == '4' || sudoku[fila][columna] == '5' || 
                 sudoku[fila][columna] == '6' || sudoku[fila][columna] == '7' || sudoku[fila][columna] == '8' || sudoku[fila][columna] == '9') && ((sudoku[filaContraria][columnaContraria] == '-'))) mal = true;
        }
    }
    if (!mal) cout << "SI" << endl;
    else cout << "NO" << endl;
}

int main() {
    unsigned int numCasos, i;
    cin >> numCasos;
    for (i = 0; i < numCasos; ++i) casoDePrueba();
    return 0;
}