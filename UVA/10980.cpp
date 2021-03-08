#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <iomanip>


using namespace std;

typedef map<int, double> mapa;
typedef pair<int, double> oferta;

void resuelve(vector<double> &datos, int max, mapa ofertas) {
	for (int i = 1; i < max; i++) {
		auto it = ofertas.cbegin();
		datos[i] = datos[i - 1] + datos[0];
		while (it != ofertas.cend()) {
			if (it->first == i + 1 && it->second < datos[i]) datos[i] = it->second;
			if(i - it->first >= 0) datos[i] = min(datos[i] , datos[i - it->first]+ it->second);
			it++;
		}
	}
}

int main() {

	int numDatos, cant, j = 1;
	double precio;
	while (cin >> precio) {
		cin >> numDatos;
		vector<double> datos(100, numeric_limits<double>::max());
		datos[0] = precio;
		mapa ofertas;
		for (int i = 0; i < numDatos; i++) {
			cin >> cant >> precio;
			if(precio < datos[0]) datos[0] = precio;
			auto it = ofertas.find(cant);
			if (it == ofertas.cend()) {
				ofertas.insert(oferta(cant, precio));
			}
			else if (precio < it->second) {
				it->second = precio;
			}
		}
		cin.get();
		//Lectura getLine
		string text;
		getline(cin, text);
		istringstream iss(text);
		vector<int> linea((istream_iterator<int>(iss)), istream_iterator<int>());
		int max = *max_element(linea.begin(), linea.end());

		resuelve(datos, max,ofertas);
		cout << "Case " << j << ":\n";
		for(int i = 0; i < linea.size(); i++) {
			cout << "Buy " << linea[i] << " for $" << fixed << setprecision(2) << datos[linea[i] - 1] << '\n';
		}
		j++;
	}
}
