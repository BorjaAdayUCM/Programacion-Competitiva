#include <iostream>
#include <math.h>

using namespace std;

long int analiza(long int piezas) {
	long int tam = sqrt(piezas);
	while (piezas % tam != 0) tam--;
	if (tam == 1) return piezas;
	else return piezas / tam;
}

int main()
{
	long int piezas;
	cin >> piezas;
	while (piezas != 0) {
		cout << analiza(piezas) << '\n';
		cin >> piezas;
	}
}