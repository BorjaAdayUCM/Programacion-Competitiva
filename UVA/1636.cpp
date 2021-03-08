#include <stdio.h>

#include <iostream>

using namespace std;

int main() {
	string cadena;
	while (cin >> cadena;) {
		int ceros = 0, z = 0;
		for (int i = 0; i < cadena.length(); i++) {
			if (cadena[i] == '0') {
				ceros++;
				if (cadena[(i + 1) % cadena.length()] == '0') z++;
			}
		}
		int a = z * cadena.length(), b = ceros * ceros;
		if (a < b) cout << "ROTATE" << '\n';
		else if(a == b) cout << "EQUAL" << '\n';
		else  cout << "SHOOT" << '\n';
	}
}

