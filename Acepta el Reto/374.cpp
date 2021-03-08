#include <iostream>

using namespace std;

int main() {
	int numCasos;
	cin >> numCasos;
	while (numCasos != 0) {
		long long int temperatura, menor, mayor, contadorMenor = 0, contadorMayor = 0;
		cin >> temperatura;
		menor = temperatura;
		mayor = temperatura;
		while (temperatura != 0) {
			if (temperatura < menor) {
				contadorMenor = 1;
				menor = temperatura;
			}
			else if (temperatura == menor) contadorMenor++;
			if (temperatura > mayor) {
				contadorMayor = 1;
				mayor = temperatura;
			}
			else if (temperatura == mayor) contadorMayor++;
			cin >> temperatura;
		}
		cout << menor << " " << contadorMenor << " " << mayor << " " << contadorMayor << '\n';
		numCasos--;
	}
}