#include <iostream>
using namespace std;

const int MAX = 100000;

//Complejidad: O(n)
void juego(int v[], int n) {
	int suma = 0, i = 0, ini = 0, fin = 0, p = 0, q = 0, mayorSuma = v[0];
	while (i < n) {
		suma += v[i];
		if ((suma > mayorSuma) || (suma == mayorSuma && (q - p < fin - ini))) {
			mayorSuma = suma;
			fin = q;
			ini = p;
		}
		if (suma <= 0) {
			suma = 0;
			p = i + 1;
			q = i;
		}
		++q;
		++i;
	}
	cout << ini + 1 << " " << fin + 1 << '\n';
}

void resuelve() {
	int array[MAX];
	int dias;
	cin >> dias;
	for (int i = 0; i < dias; ++i) {
		cin >> array[i];
	}
	juego(array, dias);
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) {
		resuelve();
	}
	return 0;
}