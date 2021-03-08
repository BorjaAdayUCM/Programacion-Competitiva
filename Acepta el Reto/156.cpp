#include <iostream>

using namespace std;

int recorridoAscensor(int n, int actual) {
	int recorrido = 0, siguiente = n;
	while (siguiente != -1) {
		if (actual != siguiente) {
			recorrido += abs(actual - siguiente);
		}
		actual = siguiente;
		cin >> siguiente;
	}
	return recorrido;
}

int main() {
	int primerNum, siguienteNum;
	cin >> primerNum;
	while (primerNum >= 0) {
		siguienteNum = primerNum;
		cout << recorridoAscensor(primerNum, siguienteNum) << '\n';
		cin >> primerNum;
	}
	return 0;
}