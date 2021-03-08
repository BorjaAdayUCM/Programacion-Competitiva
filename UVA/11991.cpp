#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef pair<int, vector<int>> elemDiccionario;

int main() {
	int numElem, numConsul;
	while (cin >> numElem) {
		cin >> numConsul;
		unordered_map<int, vector<int>> diccionario;
		int i = 0, elem;
		while (i < numElem) {
			cin >> elem;
			auto it = diccionario.find(elem);
			if (it == diccionario.cend()) {
				vector <int> vector;
				vector.push_back(i + 1);
				diccionario.insert(elemDiccionario(elem, vector));
			}
			else {
				diccionario.at(elem).push_back(i + 1);
			}
			i++;
		}
		i = 0;
		int numeroConsulta, posConsulta, res;
		while (i < numConsul) {
			cin >> posConsulta >> numeroConsulta;
			if (diccionario.find(numeroConsulta) == diccionario.cend() || diccionario.at(numeroConsulta).size() < posConsulta) cout << "0\n";
			else cout << diccionario.at(numeroConsulta)[posConsulta - 1] << '\n';
			i++;
		}
	}
	return 0;
}
