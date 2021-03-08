#include <iostream>

using namespace std;

int piezaFalta(int numPiezas, int v[]) {
	int i = 1;
	bool enc = true;
	while (enc) {
		int j = 0;
		enc = false;
		while (j < numPiezas - 1 && !enc) {
			if (v[j] == i) enc = true;
			else j++;
		}
		if (j == numPiezas - 1) enc = false;
		else i++;
	}
	return i;
}

int main() {
	int numPiezas, v[10000];
	cin >> numPiezas;
	while (numPiezas > 0) {
		for (int i = 0; i < numPiezas - 1; i++) {
			cin >> v[i];
		}
		cout << piezaFalta(numPiezas, v) << '\n';
		cin >> numPiezas;
	}
}