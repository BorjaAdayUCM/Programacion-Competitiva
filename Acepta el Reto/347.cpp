#include <iostream>

using namespace std;

void analizarCaso(int largo, int ancho, int contador) {
	if (largo< 10||ancho <10) {
		cout << contador << '\n';
		return;
	}

	if (largo > ancho) analizarCaso(largo%ancho, ancho, contador + largo / ancho);
	else analizarCaso(largo, ancho%largo, contador + ancho / largo);
	return;
}

int main() {
	int largo, ancho;
	cin >> largo>> ancho;
	while (ancho != 0 || largo != 0) {
		analizarCaso(largo,ancho,0);
		cin >> largo >> ancho;
	}
}