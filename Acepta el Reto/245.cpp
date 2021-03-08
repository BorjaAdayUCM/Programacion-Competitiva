#include <iostream>

using namespace std;

void analiza(int tam) {
	long long int i = 1, numActual, numMayorMenor; bool daltonmenor = true, daltonmayor = true;
	cin >> numMayorMenor;
	while (i < tam) {
		cin >> numActual;
		if (numActual <= numMayorMenor) daltonmenor = false;
		if (numActual >= numMayorMenor) daltonmayor = false;
		numMayorMenor = numActual;
		i++;
	}
	if (daltonmenor || daltonmayor) cout << "DALTON" << '\n';
	else cout << "DESCONOCIDOS" << '\n';
}

int main() {
	long long int tam = 0;
	cin >> tam;
	while (tam != 0) {
		analiza(tam);
		cin >> tam;
	}
	return 0;
}