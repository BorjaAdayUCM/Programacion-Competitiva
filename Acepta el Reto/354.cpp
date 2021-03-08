#include <iostream>
#include <string>

using namespace std;

int cuentaNinos(long long int v[], int tam) {
	int mayor = v[0], contInter = 0, mayorInter = v[0], contNinos = 1, i = 1;
	while (i < tam) {
		if (v[i] > mayor) {
			if (v[i] > mayorInter) mayorInter = v[i];
			contInter++;
		}
		else {
			mayor = mayorInter;
			contNinos += contInter + 1;
			contInter = 0;
		}
		i++;
	}
	return contNinos;
}

int resuelve(int tam) {
	long long int v[200000];
	for (int i = 0; i < tam; i++) cin >> v[i];
	return cuentaNinos(v, tam);
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