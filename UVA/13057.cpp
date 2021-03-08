#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
vi orden;
vvi adjList;
int V, E;
vector<bool> visited;

void dfsProblem(int v) {
	visited[v] = true;
	for (int w : adjList[v]) {
		if (!visited[w]) {
			dfsProblem(w);
		}
	}
	orden.push_back(v);
}

void dfs(int v) {
	visited[v] = true;
	for (int w : adjList[v]) {
		if (!visited[w]) {
			dfs(w);
		}
	}
}


int main() {

	int casos, l1, l2;
	cin >> casos;
	for (int k = 0; k < casos; k++) {
		cin >> V >> E;
		adjList = vvi(V);
		visited = vector<bool>(V);
		for (int i = 0; i < E; i++) {
			cin >> l1 >> l2;
			adjList[l1 - 1].push_back(l2 - 1);
		}
		visited = vector<bool>(V, false);
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				dfsProblem(i);
			}
		}
		int cont = 0;
		visited = vector<bool>(V, false);
		for (int i = orden.size() - 1; i >= 0 ; i--) {
			if (!visited[orden[i]]) {
				dfs(orden[i]);
				cont++;
			}
		}
		orden.clear();
		cout << "Case " << k + 1 << ": " << cont << '\n';
	}

	return 0;

}