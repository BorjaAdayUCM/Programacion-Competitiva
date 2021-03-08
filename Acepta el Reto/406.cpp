#include <iostream>
#include <string>

using namespace std;

void analizarCaso(string & calle);

void mostrar(string calle);

bool casoDePrueba();

int main() {
	while (casoDePrueba()) {}
	return 0;
}

bool casoDePrueba() {
	string calle;
	cin >> calle;
	if (!cin) return false;
	else {
		analizarCaso(calle);
		mostrar(calle);
		return true;
	}
}

void analizarCaso(string & calle) {
	int j = 1, cont_coches = 0, cont_libres = 0; char coches[250000];
	for (int i = 0; i < calle.size(); i++) {
		if ((calle[i] != '|') && (calle[i] != '.')) {
			coches[cont_coches] = calle[i];
			cont_coches++;
		}
		else if (calle[i] == '.') cont_libres++;
		else {
			j = 1;
			while ((cont_coches + cont_libres) > 0) {
				if (cont_coches > 0) {
					calle[i - j] = coches[cont_coches - 1];
					cont_coches--;
				}
				else {
					calle[i - j] = '.';
					cont_libres--;
				}
				j++;
			}
			cont_coches = 0;
			cont_libres = 0;
		}
	}

	int k = cont_coches + cont_libres;

	while (k > 0) {
		calle[calle.length() - k] = '.';
		k--;
	}
}

void mostrar(string calle) {
	int numeroConsultas,consulta;
	cin >> numeroConsultas;
	for (int i = 0; i < numeroConsultas - 1; i++) {
		cin >> consulta;
		cout << calle[consulta-1] << " ";
	}
	cin >> consulta;
	cout << calle[consulta-1]<< endl;
}