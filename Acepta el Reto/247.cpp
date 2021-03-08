#include <iostream>
#include <string>

using namespace std;

bool creciente(int numero[], int capacidad);

int main() {
    int cantidad;
    cin >> cantidad;
    while (cantidad != 0) {
        int numero[10000];
        for (int i = 0; i < cantidad; i++) cin >> numero[i];
        if (creciente(numero, cantidad)) cout << "SI" << '\n';
        else cout << "NO" << '\n';
        cin >> cantidad;
    }
}

//Pre: numero[capacidad] : 1<=v<=10000;
bool creciente(int numero[], int capacidad) {
    bool creciente = true;
    int i = 0;
    while (i < capacidad - 1 && creciente == true) /*creciente= numero[k]<numero[n]: 0<=k<n<=i; */{
        if (numero[i] >= numero[i + 1]) creciente = false;
        i++;
    }
    return creciente;
}
//Post: creciente= numero[i]<numero[j] : 0<=i<j<=capacidad;