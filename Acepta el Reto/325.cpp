#include <iostream>
#include <string>

using namespace std;

void bolasHelado();

void formaHelado(int bolaV, int bolaC, char cadena[15], int i, bool &espacio);

int main() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        bolasHelado();
        cout << endl;
    }
}

void bolasHelado() {
    int bolaV, bolaC;
    char cadena[15];
    int i = 0;
    bool espacio = false;
    cin >> bolaC >> bolaV;
    formaHelado(bolaV, bolaC, cadena, i, espacio);
}

void formaHelado(int bolaV, int bolaC, char cadena[15], int i, bool &espacio) {
    if ((bolaC == 0) && (bolaV == 0)) {
        if (espacio == true) cout << " ";
        else espacio = true;
        for (int j = 0; j < i; j++) cout << cadena[j];
        return;
    }
    if (bolaC > 0) {
        cadena[i] = 'C';
        formaHelado(bolaV, bolaC - 1, cadena, i + 1, espacio);
    }
    if (bolaV > 0) {
        cadena[i] = 'V';
        formaHelado(bolaV - 1, bolaC, cadena, i + 1, espacio);
    }
    return;
}