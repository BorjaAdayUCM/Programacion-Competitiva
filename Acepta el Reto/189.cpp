#include <iostream>
#include <string>

using namespace std;

void embarque(int pasajeros[], int &numPasajeros, int cubierta) {
	int i = 0, j = 0;
	while (i < numPasajeros) {
		if (pasajeros[i] != cubierta) {
			pasajeros[j] = pasajeros[i];
			j++;
		}
		i++;
	}
	numPasajeros = j;
	cout << numPasajeros << '\n';
}

void resuelve(int numPasajeros) {
	int pasajeros[1000000];
	for (int i = 0; i < numPasajeros; i++) cin >> pasajeros[i];
	int numConsultas;
	string consulta;
	cin >> numConsultas;
	for (int i = 0; i < numConsultas; i++) {
		cin >> consulta;
		if (consulta == "EMBARQUE") {
			int cubierta;
			cin >> cubierta;
			embarque(pasajeros, numPasajeros, cubierta);
		}
		else {
			int pasajero;
			cin >> pasajero;
			cout << pasajeros[pasajero - 1] << '\n';
		}
	}
	cout << '*' << '\n';
}

int main() {
	int numPasajeros;
	cin >> numPasajeros;
	while (numPasajeros != 0) {
		resuelve(numPasajeros);
		cin >> numPasajeros;
	}
	return 0;
}