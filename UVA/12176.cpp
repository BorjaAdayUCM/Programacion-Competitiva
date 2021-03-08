#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using arista = pair<int, pair<int, int>>;
vector<int> C; int numSets;
vector<vector<pair<int, int>>> matriz;

using vi = vector<int>;
using vvi = vector<vi>;
vvi adjList; int V, E,ini,fin;
// Obtiene el numero de nodos que se recorren

int dfs(int v,int pos,int tam,bool &finb)
{
	int tamAux;
	for (auto w : matriz[pos]) {
		if (w.first != v) {
			tamAux = w.second;
			if (w.first == fin) {
				finb = true;
				return max(tam, w.second);
			}
			else {
				tam = max(tamAux,dfs(pos,w.first, tam,finb));
				if (finb) return tam;
			}
		}
	}
	return -1;
}

void init(int n) {
	C.assign(n, 0); numSets = n;
	for (int i = 0; i < n; ++i) C[i] = i;
}

int find(int x) {
	return (C[x] == x) ? x : C[x] = find(C[x]);
}
void merge(int x, int y) {
	C[find(x)] = find(y);
	--numSets;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int V, A;
		cin >> V >> A;
		vector<arista> aristas;
		for (int j = 0; j < A; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			aristas.push_back(make_pair(c, make_pair(a-1, b-1)));
		}

		matriz = vector<vector<pair<int, int>>>(V,vector<pair <int,int>>()) ;

		// < coste, extremos >
		
		// generar aristas y guardarlas en el vector

		// ordenamos las aristas de menor a mayor
		sort(aristas.begin(), aristas.end());

		// Kruskal
		init(V);
		int coste = 0;
		for (auto ar : aristas) {
			if (find(ar.second.first) != find(ar.second.second)) {
				merge(ar.second.first, ar.second.second);
				matriz[ar.second.first].push_back(make_pair(ar.second.second,ar.first));
				matriz[ar.second.second].push_back(make_pair(ar.second.first,ar.first));
			}
			if (numSets == 1) break;
		}
		
		int numConsultas;
		cin >> numConsultas;
		cout << "Case " << i + 1 << '\n';
		for (int j = 0; j < numConsultas; j++) {
			cin >> ini >> fin;
			fin--;
			ini--;
			bool finb = false;
			cout << dfs(ini,ini, 0, finb) << '\n';
		}
		cout << '\n';
	}
}