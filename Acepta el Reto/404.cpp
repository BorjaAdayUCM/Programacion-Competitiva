#include <iostream>
#include <string>

using namespace std;

int cuantosPosibles(string cadena, int ini) {
	int ret = 0;
	if (ini == cadena.length()) return 1;
	if (cadena[ini] == 'I') {
		ret += cuantosPosibles(cadena, ini + 1);
		if (cadena[ini + 1] == 'I') {
			ret += cuantosPosibles(cadena, ini + 2);
			if (cadena[ini + 2] == 'I') ret += cuantosPosibles(cadena, ini + 3);
		}
		else if (cadena[ini + 1] == 'V') {
			ret += cuantosPosibles(cadena, ini + 2);
		}
		else if (cadena[ini + 1] == 'X') {
			ret += cuantosPosibles(cadena, ini + 2);
		}
	}
	else if (cadena[ini] == 'V') {
		ret += cuantosPosibles(cadena, ini + 1);
		if (cadena[ini + 1] == 'I') {
			ret += cuantosPosibles(cadena, ini + 2);
			if (cadena[ini + 2] == 'I') {
				ret += cuantosPosibles(cadena, ini + 3);
				if (cadena[ini + 3] == 'I') ret += cuantosPosibles(cadena, ini + 4);
			}
		}
	}
	else if (cadena[ini] == 'X') ret += cuantosPosibles(cadena, ini + 1);
	return ret;
}

int main() {
	string cadena;
	while (getline(cin, cadena)) cout << cuantosPosibles(cadena, 0) << '\n';
}
