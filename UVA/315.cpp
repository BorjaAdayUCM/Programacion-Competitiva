#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;

void dfs(int u, int uParent, vvi adj, int &hora, vi &horaVertice, vi &alcanzable, vb &solucion, int &hijosRaiz) {
	horaVertice[u] = alcanzable[u] = hora; hora++;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == uParent) continue;
		if (horaVertice[v] == 0) {
			if (uParent == 0)
				hijosRaiz++;

			dfs(v, u, adj, hora, horaVertice, alcanzable, solucion, hijosRaiz);

			if (alcanzable[v] >= horaVertice[u])
				if (uParent != 0) // u es punto de articulacion.
					solucion[u] = true;

			alcanzable[u] = min(alcanzable[u], alcanzable[v]);
		}
		else
			alcanzable[u] = min(alcanzable[u], horaVertice[v]);
	}
}

int main() {
	int numNodos, hora, hijosRaiz;
	string text;
	vi linea;
	cin >> numNodos;
	while (numNodos != 0) {
		hora = 1;
		vvi adj = vvi(numNodos + 1, vi());
		vi horaVertice = vi(numNodos + 1, 0);
		vi alcanzable = vi(numNodos + 1, -1);
		vb solucion = vb(numNodos + 1);
		cin.get();
		getline(cin, text);
		while (text != "0") {
			istringstream iss(text);
			vi linea((istream_iterator<int>(iss)), istream_iterator<int>());
			for (int i = 1; i < linea.size(); i++) {
				adj[linea[0]].push_back(linea[i]);
				adj[linea[i]].push_back(linea[0]);
			}
			getline(cin, text);
		}
		for (int i = 1; i <= numNodos; ++i) {
			if (!horaVertice[i]) {
				hijosRaiz = 0;
				dfs(i, 0, adj, hora, horaVertice, alcanzable, solucion, hijosRaiz);
				if (hijosRaiz > 1)
					solucion[i] = true;
			}
		}
		cout << count(solucion.begin(), solucion.end(), true) << '\n';
		cin >> numNodos;
	}
}