#include <iostream>

using namespace std;

int main() {
	int numToros, mayor = 0, numActual;
	while (cin >> numToros) {
		int i = 0;
		while (i < numToros) {
			cin >> numActual;
			if (numActual > mayor) mayor = numActual;
			i++;
		}
		cout << mayor << '\n';
	}
}
