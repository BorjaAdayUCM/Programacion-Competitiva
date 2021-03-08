#include <iostream>

using namespace std;

const int TAM = 100000;

long long int sumar(long long int vector[TAM], int tam);

void cargarArray(long long int vector[TAM], int tam);

long long int combina(long long int vector[TAM], int tam);

int main() {
	long long int vector[TAM];
	int tam;
	cin >> tam;
	while (tam != 0) {
		cargarArray(vector, tam);
		cout << combina(vector, tam) << '\n';
		cin >> tam;
	}
}

void cargarArray(long long int vector[TAM], int tam) {
	for (int i = 0; i < tam; i++) cin >> vector[i];
}

long long int sumar(long long int vector[TAM], int tam) {
	long long int suma = 0;
	for (int i = 0; i < tam; i++) suma += vector[i];
	return suma;
}

long long int combina(long long int vector[TAM], int tam) {
	long long int suma = sumar(vector, tam);
	long long int resultado = 0, restar = vector[0];
	for (int i = 0; i < tam - 1; i++) {
		resultado += vector[i] * (suma - restar);
		restar += vector[i + 1];
	}
	return resultado;
}
