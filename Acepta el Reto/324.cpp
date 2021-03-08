#include <iostream>

using namespace std;

int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

bool esta(int v[], int tam, int num) {
    int i = 0;
    while (i < tam && v[i] != num) i++;
    return i < tam;
}

int analiza(int v[], int tam) {
    long long int i = 0, max = 1, tamk = 0;
    int k[100];
    while (i < tam) {
        int j = i, cont = 0;
        while (v[j] != i + 1) {
            j = v[j] - 1;
            cont++;
        }
        if ((cont + 1 != 0) && (!esta(k, tamk, cont + 1))) {
            k[tamk] = cont + 1;
            tamk++;
        }
        else if (!esta(k, tamk, 1)) {
            k[i] = 1;
            tamk++;
        }
        i++;
    }

    for (int i = 0; i < tamk; i++) {
        if (esta(primos, tamk, k[i])) max *= k[i];
    }
    bool enc = false;
    while (!enc) {
        int p = 0;
        enc = true;
        while (p < tamk && enc) {
            if (max % k[p] != 0) enc = false;
            p++;
        }
        max++;
    }
    return max - 1;
}

long long int resuelve(int tam) {
    int v[100];
    for (int i = 0; i < tam; i++) cin >> v[i];
    return analiza(v, tam);
}

int main() {
    int tam = 0;
    cin >> tam;
    while (tam != 0) {
        cout << resuelve(tam) << '\n';
        cin >> tam;
    }
    return 0;
}