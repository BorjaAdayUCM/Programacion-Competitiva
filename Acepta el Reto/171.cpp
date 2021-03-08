#include <iostream>

using namespace std;

const int TAM = 100000;

void cargarArray(int vector[TAM], int tam);

int analizaArray(int vector[TAM], int tam);

int main() {
	int vector[TAM];
	int tam, contador = 1, i = 0, mayor;
	cin >> tam;
	while (tam != 0) {
		cargarArray(vector, tam);
		cout << analizaArray(vector, tam) << '\n';
		cin >> tam;
	}
}

void cargarArray(int vector[TAM], int tam) {
	for (int i = 0; i < tam; i++) {
		cin >> vector[i];
	}
}

int analizaArray(int vector[TAM], int tam) {
	int i = tam - 2, mayor = vector[tam - 1], contador = 1;
	while (i >= 0) {
		if (vector[i] > mayor) {
			mayor = vector[i];
			contador++;
		}
		i--;
	}
	return contador;
}