#include <iostream>
#include <string>

using namespace std;

bool abuelaVerdadera(string nombre, string v[], int tam) {
	bool abuela = true;
	if (tam <= 1 || v[tam - 1] != nombre) abuela = false;
	int i = 0;
	while (i < tam - 1 && abuela) {
		if (v[i] == nombre) abuela = false;
		i++;
	}
	return abuela;
}

void resuelve() {
	string nombre, v[100];
	int tam;
	cin >> nombre >> tam;
	for (int i = 0; i < tam; i++) cin >> v[i];
	if (abuelaVerdadera(nombre, v, tam)) cout << "VERDADERA\n";
	else cout << "FALSA\n";
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resuelve();
	return 0;
}