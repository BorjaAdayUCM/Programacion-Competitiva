#include <iostream>

using namespace std;

const int MAX = 100000;

int bocadillo(int tamanios[], int cortezas, int suma) {
    int b = 0;
    suma -= tamanios[b];
    while (b < cortezas - 1 && tamanios[b] != suma) {
        ++b;
        suma -= tamanios[b];
    }
    return b + 1;
}

void resuelve(int cortezas)
{
    int tamanios[MAX], suma = 0;
    for (int i = 0; i < cortezas; ++i) {
        cin >> tamanios[i];
        suma += tamanios[i];
    }
    int tapa = bocadillo(tamanios, cortezas, suma);
    if (tapa == cortezas) cout << "NO\n";
    else cout << "SI " << tapa << '\n';
}

int main()  {
    int cortezas;
    cin >> cortezas;
    while (cortezas != 0) {
        resuelve(cortezas);
        cin >> cortezas;
    }
    return 0;
}