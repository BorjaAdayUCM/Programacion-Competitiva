#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

void resuelve(vector<long long int> &soluciones,int calculado, int aCalcular) {
	for (int i = calculado + 1; i <= aCalcular; i++) {
		soluciones.push_back(soluciones[i - 1] + soluciones[i - 2] * 4 + soluciones[i - 3] * 2);
	}
}

int main() {
	int numCasos, longitud, calculado = 2;
	cin >> numCasos;
	vector<long long int> soluciones;
	soluciones.push_back(1);
	soluciones.push_back(1);
	soluciones.push_back(5);
	for (int i = 0; i < numCasos; i++) {
		cin >> longitud;
		if (longitud > calculado) {
			resuelve(soluciones, calculado, longitud);
			calculado = longitud;
		}
		cout << soluciones.at(longitud) << '\n';
	}
}