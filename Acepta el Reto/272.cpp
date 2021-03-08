#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

const int MAX = 100;

void convertirB6(int &numeroB10, int &numeroB6, int &i);

void casoDePrueba() {
    int casosDePrueba, numeroB6 = 0, numeroB10, i = 0;
    cin >> numeroB10;
    if (numeroB10 < 5) numeroB6 = numeroB10;
    else convertirB6(numeroB10, numeroB6, i);
    cout << numeroB6 << endl;
}

int main() {
    unsigned int numCasos, i;
    cin >> numCasos;
    for (i = 0; i < numCasos; ++i) casoDePrueba();
    return 0;
}

void convertirB6(int &numeroB10, int &numeroB6, int &i) {
    if (numeroB10 > 5) {
        numeroB6 += (numeroB10 % 6) * pow(10, i);
        numeroB10 = numeroB10 / 6;
        i++;
        convertirB6(numeroB10, numeroB6, i);
    }
    else numeroB6 += numeroB10 * pow(10, i);
}