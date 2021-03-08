#include <iostream>

using namespace std;

void resuelve() {
	int tam, numActual, numSiguiente, up = 0, down = 0;
	cin >> tam >> numActual;
	while (tam > 1)
	{
		cin >> numSiguiente;
		if (numActual < numSiguiente) up++;
		else if (numActual > numSiguiente) down++;
		numActual = numSiguiente;
		tam--;
	}
	cout << up << " " << down << '\n';
}

int main() {
	int numCasos;
	cin >> numCasos;
	while (numCasos > 0)
	{
		resuelve();
		numCasos--;
	}
}