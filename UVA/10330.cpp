#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int s, t, c, n;
vector<vector<int>> adj, cap;
vector<bool> visited;
vector<int> parent;

void bfs(int s, int t) {
	queue<int> q;
	visited.assign(n*2 + 2, 0);
	q.push(s);
	parent[s] = -1;
	visited[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (!visited[v] && (cap[u][v] > 0)) {
				parent[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

int sendFlow(int s, int t) {
	// Intentamos llegar de s a t
	bfs(s, t);
	if (!visited[t])
		return 0; // No pudimos
		// Buscamos capacidad m´as peque˜na en el camino
	int flow = 1000000, v = t;
	while (v != s) {
		flow = min(cap[parent[v]][v], flow);
		v = parent[v];
	}
	// Mandamos flujo
	v = t;
	while (v != s) {
		cap[parent[v]][v] -= flow;
		cap[v][parent[v]] += flow; // INVERSA
		v = parent[v];
	}
	return flow;
}

int main() {
	int cont = 1;
	int links;
	int l1, l2, capacidad;
	int B, D;
	while (cin >> n) {
		adj = vector<vector<int>>(n * 2 + 2);
		cap = vector<vector<int>>(n * 2 + 2, vector<int>(n * 2 + 2, 0));
		for (int i = 1; i <= n*2; i+=2) {
			adj[i].push_back(i+1);
			adj[i+1].push_back(i);
			cin >> cap[i][i + 1];
		}
		cin >> links;
		for(int i  = 0; i < links; i++) {
			cin >> l1 >> l2 >> capacidad;
			l1 *= 2; l2 = l2 * 2 - 1;
			adj[l1].push_back(l2);
			adj[l2].push_back(l1);
			cap[l1][l2] += capacidad;
		}
		cin >> B >> D;
		for (int i = 0; i < B; i++) {
			cin >> l2;
			l2 = l2 * 2 - 1;
			adj[0].push_back(l2);
			adj[l2].push_back(0);
			cap[0][l2] = 1000000;
		}
		for (int i = 0; i < D; i++) {
			cin >> l2;
			l2 = l2 * 2;
			adj[l2].push_back(n * 2 + 1);
			adj[n * 2 + 1].push_back(l2);
			cap[l2][n * 2 + 1] = 1000000;
		}
		parent = vector<int>(n * 2 + 1, -1);
		int flow = 0, ret = 0;
		do {
			flow = sendFlow(0, n*2 + 1);
			ret += flow;
		} while (flow > 0);

		cout << ret << '\n';

	}

	return 0;

}
