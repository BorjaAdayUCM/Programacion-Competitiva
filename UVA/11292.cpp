#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int resuelve(vector<int> cabezas, vector<int> caballeros) {
	int valor = 0, i = 0, j = 0;
	while (i < caballeros.size() && j < cabezas.size()){
		if (caballeros[i] >= cabezas[j]){
			valor += caballeros[i];
			j++;
		}
		i++;
	}
	if (j == cabezas.size()) return valor;
	else return -1;
}

int main() {
	int numCabezas, numCaballeros;
	cin >> numCabezas >> numCaballeros;
	while (numCabezas != 0 && numCaballeros != 0) {
		vector<int> cabezas(numCabezas), caballeros(numCaballeros);
		for (int i = 0; i < numCabezas; i++) cin >> cabezas[i];
		for (int i = 0; i < numCaballeros; i++) cin >> caballeros[i];
		sort(cabezas.begin(), cabezas.end());
		sort(caballeros.begin(), caballeros.end());
		int resultado = resuelve(cabezas, caballeros);
		if (resultado == -1) cout << "Loowater is doomed!\n";
		else cout << resultado << '\n';
		cin >> numCabezas >> numCaballeros;
	}
}