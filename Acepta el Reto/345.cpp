#include <iostream>

using namespace std;

typedef int tSudoku[9][9];

void casoDePrueba() {
    tSudoku sudoku;
    bool mal = false;
    for (int fila = 0; fila < 9; ++fila) {
        for (int columna = 0; columna < 9; ++columna)  {
            cin >> sudoku[fila][columna];
        }
    }
    for (int fila = 0; fila < 9; ++fila) {
        for (int columna = 0; columna < 9; ++columna)  {
            for (int fila1 = 0; fila1 < 9; ++fila1) {
                if (fila == fila1) fila1++;
                if (fila < 9 && columna < 9 && fila1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna])  mal = true;
            }
            for (int columna1 = 0; columna1 < 9; ++columna1) {
                if (columna == columna1) columna1++;
                if (fila < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila][columna1]) mal = true;
            }
        }
    }
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            for (int fila1 = 0; fila1 < 3; fila1++) {
                for (int columna1 = 0; columna1 < 3; columna1++) {
                    if (fila == fila1 && columna == columna1) columna1++;
                    if (fila < 9 && fila1 < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna1]) mal = true;
                }
            }
        }
    }
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 3; columna < 6; columna++) {
            for (int fila1 = 0; fila1 < 3; fila1++) {
                for (int columna1 = 3; columna1 < 6; columna1++) {
                    if (fila == fila1 && columna == columna1) columna1++;
                    if (fila < 9 && fila1 < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna1]) mal = true;
                }
            }
        }
    }
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 6; columna < 9; columna++){
            for (int fila1 = 0; fila1 < 3; fila1++) {
                for (int columna1 = 6; columna1 < 9; columna1++) {
                    if (fila == fila1 && columna == columna1) columna1++;
                    if (fila < 9 && fila1 < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna1]) mal = true;
                }
            }
        }
    }
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 6; columna < 9; columna++) {
            for (int fila1 = 0; fila1 < 3; fila1++) {
                for (int columna1 = 6; columna1 < 9; columna1++) {
                    if (fila == fila1 && columna == columna1) columna1++;
                    if (fila < 9 && fila1 < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna1]) mal = true;
                }
            }
        }
    }
    for (int fila = 3; fila < 6; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            for (int fila1 = 3; fila1 < 6; fila1++) {
                for (int columna1 = 0; columna1 < 3; columna1++) {
                    if (fila == fila1 && columna == columna1) columna1++;
                    if (fila < 9 && fila1 < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna1]) mal = true;
                }
            }
        }
    }
    for (int fila = 3; fila < 6; fila++) {
        for (int columna = 3; columna < 6; columna++) {
            for (int fila1 = 3; fila1 < 6; fila1++) {
                for (int columna1 = 3; columna1 < 6; columna1++) {
                    if (fila == fila1 && columna == columna1) columna1++;
                    if (fila < 9 && fila1 < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna1]) mal = true;
                }
            }
        }
    }
    for (int fila = 3; fila < 6; fila++) {
        for (int columna = 6; columna < 9; columna++) {
            for (int fila1 = 3; fila1 < 6; fila1++) {
                for (int columna1 = 6; columna1 < 9; columna1++) {
                    if (fila == fila1 && columna == columna1) columna1++;
                    if (fila < 9 && fila1 < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna1]) mal = true;
                }
            }
        }
    }
    for (int fila = 6; fila < 9; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            for (int fila1 = 6; fila1 < 9; fila1++) {
                for (int columna1 = 0; columna1 < 3; columna1++) {
                    if (fila == fila1 && columna == columna1) columna1++;
                    if (fila < 9 && fila1 < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna1]) mal = true;
                }
            }
        }
    }
    for (int fila = 6; fila < 9; fila++) {
        for (int columna = 3; columna < 6; columna++) {
            for (int fila1 = 6; fila1 < 9; fila1++) {
                for (int columna1 = 3; columna1 < 6; columna1++) {
                    if (fila == fila1 && columna == columna1) columna1++;
                    if (fila < 9 && fila1 < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna1]) mal = true;
                }
            }
        }
    }
    for (int fila = 6; fila < 9; fila++) {
        for (int columna = 6; columna < 9; columna++) {
            for (int fila1 = 6; fila1 < 9; fila1++) {
                for (int columna1 = 6; columna1 < 9; columna1++) {
                    if (fila == fila1 && columna == columna1) columna1++;
                    if (fila < 9 && fila1 < 9 && columna < 9 && columna1 < 9 && sudoku[fila][columna] == sudoku[fila1][columna1]) mal = true;
                }
            }
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