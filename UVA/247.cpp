#include <iostream>
#include <unordered_map>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvs = vector<vs>;

unordered_map<string, int> clavesString;
unordered_map<int, string> clavesInt;
vi horaVertice, alcanzable;
vb incurrentscc;
vi sccstack;
vvi adj;
vvs solucion;
int hora;

void scc(int u) {
	horaVertice[u] = alcanzable[u] = hora;
	hora++;
	incurrentscc[u] = true;
	sccstack.push_back(u);
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (!horaVertice[v])
			scc(v);
		if (incurrentscc[v])
			alcanzable[u] = min(alcanzable[u], alcanzable[v]);
	}
	if (horaVertice[u] == alcanzable[u]) {
		// Lo somos
		vs sol = vs();
		vi sc;
		int v;
		do {
			v = sccstack.back();
			sccstack.pop_back();
			sc.push_back(v);
			incurrentscc[v] = false;
			sol.push_back(clavesInt.at(v));
		} while (u != v);
		solucion.push_back(sol);
	}
}

int main() {
	int numNodos, numAristas, numCaso = 1;
	string persona1, persona2;
	cin >> numNodos >> numAristas;
	while (numNodos != 0 || numAristas != 0) {
		clavesString = unordered_map<string, int>();
		clavesInt = unordered_map<int, string>();
		horaVertice = vi(numNodos, 0);
		alcanzable = vi(numNodos, -1);
		incurrentscc = vb(numNodos, false);
		solucion = vvs();
		sccstack.clear();
		adj = vvi(numNodos);
		int id = 0;
		adj = vvi(numNodos);
		for (int i = 0; i < numAristas; i++) {
			cin >> persona1 >> persona2;
			if (clavesString.find(persona1) == clavesString.end()) {
				clavesString[persona1] = id++;
				clavesInt[id - 1] = persona1;
			}
			if (clavesString.find(persona2) == clavesString.end()) {
				clavesString[persona2] = id++;
				clavesInt[id - 1] = persona2;
			}
			adj[clavesString[persona1]].push_back(clavesString[persona2]);
		}
		hora = 1;
		if (numAristas > 0) {
			for (int i = 0; i < numNodos; ++i) {
				if (!horaVertice[i])
					scc(i);
			}
		}
		for (int i = 0; i < solucion.size(); i++) sort(solucion[i].begin(), solucion[i].end());
		sort(solucion.begin(), solucion.end());
		cout << "Calling circles for data set " << numCaso << ":\n";
		for (int i = 0; i < solucion.size(); i++) {
			for (int j = 0; j < solucion[i].size() - 1; j++) {
				cout << solucion[i][j] << ", ";
			}
			cout << solucion[i][solucion[i].size() - 1] << '\n';
		}
		cout << '\n';
		numCaso++;
		cin >> numNodos >> numAristas;
	}
}
