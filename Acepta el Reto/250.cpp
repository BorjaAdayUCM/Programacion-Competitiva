#include <iostream>
using namespace std;

const int MAX = 100000;

int analiza(int v[], int n, int & sumD) {
	int i = 0, sumI = 0, menorDif = abs(abs(sumI) - abs(sumD)), pos = 0;
	while (i < n) {
		sumD -= -1 * v[i];
		sumI += v[i];
		if (abs(abs(sumI) - abs(sumD)) < menorDif) {
			menorDif = abs(abs(sumI) - abs(sumD));
			pos = i + 1;
		}
		i++;
	}
	return pos;
}

int resuelve(int tam) {
	int array[MAX], sumD = 0;
	for (int i = 0; i < tam; ++i) {
		cin >> array[i];
		sumD += -1 * array[i];
	}
	return analiza(array, tam, sumD);
}

int main() {
	int tam;
	cin >> tam;
	while (tam != 0) {
		cout << resuelve(tam) << '\n';
		cin >> tam;
	}
	return 0;
}