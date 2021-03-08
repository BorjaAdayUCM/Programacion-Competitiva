#include <vector>
#include <iostream>
#include <math.h>
#include<queue>
using namespace std;

vector<bool> visited;
vector<int> parent;
vector<vector<int>> cap;
int INF = 1e9;
vector<vector<int>> adj;
int numNodos;

// En parent dejamos el anterior en el recorrido BFS
void bfs(int s, int t) {
	queue<int> q;
	visited = vector<bool>(numNodos, false);
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
	int flow = INF, v = t;
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

int edmonKarps(int s, int t) {
	int ret = 0;
	int flow = 0;
	do {
		flow = sendFlow(s, t);
		ret += flow;
	} while (flow > 0);
	return ret;
}

int main()
{
	int numCasos = 1;
	int numSource, numDestination, numConexion, source, destination, capacity;
	cin >> numNodos;
	while (numNodos != 0) {
		parent = vector<int>(numNodos);
		cap = vector<vector<int>>(numNodos, vector<int>(numNodos));
		adj = vector<vector<int>>(numNodos);
		cin >> numSource >> numDestination >> numConexion;
		for (int i = 0; i < numConexion; i++) {
			cin >> source >> destination >> capacity;
			source--; destination--;
			adj[source].push_back(destination);
			adj[destination].push_back(source);
			cap[source][destination] += capacity;
			cap[destination][source] += capacity;
		}
		cout << "Network " << numCasos << '\n';
		cout << "The bandwidth is " << edmonKarps(numSource - 1, numDestination - 1) << ".\n\n";
		numCasos++;
		cin >> numNodos;
	}
}