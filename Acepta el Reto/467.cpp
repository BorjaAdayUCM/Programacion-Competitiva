#include <iostream>
#include <string>

using namespace std;

int main() {
	int numCasos; string palabra1, palabra2;
	cin >> numCasos;
	while (numCasos != 0) {
		cin >> palabra1; cin.ignore(4) ; cin >> palabra2;
		for (int i = 0; i < palabra1.length(); i++) palabra1[i] = tolower(palabra1[i]);
		for (int i = 0; i < palabra2.length(); i++) palabra2[i] = tolower(palabra2[i]);
		if (palabra1 == palabra2) cout << "TAUTOLOGIA\n";
		else cout << "NO TAUTOLOGIA\n";
		numCasos--;
	}
}