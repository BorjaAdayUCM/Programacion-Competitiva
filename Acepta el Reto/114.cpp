#include <iostream>

using namespace std;

int ultimaCifraFactorial(int n);

int main() {
	int tam, numero;
	cin >> tam;
	while (tam > 0) {
		cin >> numero;
		cout << ultimaCifraFactorial(numero) << '\n';
		tam--;
	}
}

int ultimaCifraFactorial(int n) {
	if (n == 0 || n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 6;
	else if (n == 4) return 4;
	else return 0;
}