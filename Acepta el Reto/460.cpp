#include <iostream>
#include <string>

using namespace std;

int main() {
	string cadena;
	while (getline(cin, cadena)) {
			for (int i = 0; i < cadena.size() - 1; i++) cout << cadena[i] << '0'; 
			cout << cadena[cadena.size() - 1] << '\n';
	}
	return 0;
}