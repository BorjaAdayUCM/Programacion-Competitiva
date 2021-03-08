#include <iostream>
#include <string>

using namespace std;

int main() {
    int numHuevos, capacidad, tiempo;
    cin >> numHuevos >> capacidad;
    while (numHuevos != 0 || capacidad != 0) {
        if (numHuevos % capacidad == 0) tiempo = numHuevos / capacidad * 10;
        else tiempo = numHuevos / capacidad * 10 + 10;
        cout << tiempo << '\n';
        cin >> numHuevos >> capacidad;
    }
}