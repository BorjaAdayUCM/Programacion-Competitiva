#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using vi = vector<int>;
using vii = vector<pair<int,int>>;
using vvi = vector<vi>;

vi horaVertice, alcanzable;
vii solucion;
vvi adj;
int hora;

template <typename K, typename V>
bool comparePairs(const pair<K, V>& lhs, const pair<K, V>& rhs) {
	if(lhs.first < rhs.first) return true;
	if (lhs.first > rhs.first) return false;
	if (lhs.second < rhs.second) return true;
	if (lhs.second > rhs.second) return false;
	return true;
}

void dfs(int u, int uParent) {
	horaVertice[u] = alcanzable[u] = hora; hora++;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == uParent) continue;
		if (horaVertice[v] == 0) {
			dfs(v, u);
			if (alcanzable[v] > horaVertice[u]) {
				if (u < v) {
					if (find(solucion.begin(), solucion.end(), make_pair(u - 1, v - 1)) == solucion.end()) {
						solucion.push_back(make_pair(u - 1, v - 1));
					}
				}
				else {
					if (find(solucion.begin(), solucion.end(), make_pair(v - 1, u - 1)) == solucion.end()) {
						solucion.push_back(make_pair(v - 1, u - 1));
					}
				}
			}
			alcanzable[u] = min(alcanzable[u], alcanzable[v]);
		}
		else
			alcanzable[u] = min(alcanzable[u], horaVertice[v]);
	}
}

int main() {
	int numNodos, servidorIni, numConexiones, servidorFin;
	while (cin >> numNodos) {
		hora = 1;
		adj = vvi(numNodos + 1, vi());
		horaVertice = vi(numNodos + 1, 0);
		alcanzable = vi(numNodos + 1, -1);
		solucion = vii();
		for (int i = 0; i < numNodos; i++) {
			cin >> servidorIni; cin.get(); cin.get(); cin >> numConexiones; cin.get();
			for (int j = 0; j < numConexiones; j++) {
				cin >> servidorFin;
				adj[servidorIni + 1].push_back(servidorFin + 1);
			}
		}
		for (int i = 1; i <= numNodos; ++i) {
			if (!horaVertice[i]) {
				dfs(i, 0);
			}
		}
		cout << solucion.size() << " critical links\n";
		sort(solucion.begin(), solucion.end(), comparePairs<int, int>);
		for (int i = 0; i < solucion.size(); i++) {
			cout << solucion[i].first << " - " << solucion[i].second << '\n';
		}
		cout << '\n';
	}
}