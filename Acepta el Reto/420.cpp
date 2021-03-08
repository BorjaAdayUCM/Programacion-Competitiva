#include <iostream>
#include <string>

using namespace std;

int sumConsecutivos(string secuencia, int sumaClave) {
	int suma = 0, i = 0, ini = 0, cont = 0;
	while (i <= secuencia.length()) {
		if (suma > sumaClave) {
			while (suma > sumaClave) {
				suma -= int(secuencia[ini]) - int('0');
				ini++;
			}
		}
		if (suma == sumaClave) {
			cont++;
			suma -= int(secuencia[ini]) - int('0');
			ini++;
		}
		suma += int(secuencia[i]) - int('0');
		++i;
	}
	return cont;
}

void resuelve() {
	int sumaClave;
	string secuencia;
	cin >> sumaClave >> secuencia;
	cout << sumConsecutivos(secuencia, sumaClave) << '\n';
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resuelve();
	return 0;
}