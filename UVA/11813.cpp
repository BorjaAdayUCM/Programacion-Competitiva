#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>
#include <math.h>


using namespace std;

using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;
using vvii = vector<vii>;

vvii adjList;

int N, M, cont;

vector<int> tiendas;
vector<int> distDijkstra;
vector<vector<int>> dist; //matriz de adyacencia del grafo

void dijkstra(int s) {
	distDijkstra.assign(adjList.size(), 1000000);
	distDijkstra[s] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > distDijkstra[u]) continue;
		for (auto a : adjList[u]) {
			if (distDijkstra[u] + a.first < distDijkstra[a.second]) {
				distDijkstra[a.second] = distDijkstra[u] + a.first;
				pq.push({ distDijkstra[a.second], a.second });
			}
		}
	}
}

int V; // vértices del grafo completo
vector<vector<int>> memo; // tabla de DP


// devuelve el coste de ir desde pos al origen (el vértice 0)
// pasando por todos los vértices no visitados (con un bit a 0)
int tsp(int pos, int visitados) {
	if (visitados == (1 << V) - 1) // hemos visitado ya todos los vértices
		return dist[pos][0]; // volvemos al origen
	if (memo[pos][visitados] != -1)
		return memo[pos][visitados];

	int res = 1000000000;
	for (int i = 1; i < V; ++i)
		if (!(visitados & (1 << i))) // no hemos visitado vértice i
			res = min(res, dist[pos][i] + tsp(i, visitados | (1 << i)));
	return memo[pos][visitados] = res;
}


int main() {
	int ncs, l1, l2, cost;
	cin >> ncs;
	while (ncs--) {

		cin >> N >> M;
		adjList = vector<vector<pair<int, int>>>(N);
		for (int i = 0; i < M; i++) {
			cin >> l1 >> l2 >> cost;
			adjList[l1].push_back(make_pair(cost, l2));
			adjList[l2].push_back(make_pair(cost, l1));
		}

		int tienda, numTiendas;
		cin >> numTiendas;
		V = numTiendas + 1;
		tiendas = vi();
		tiendas.push_back(0);
		
		for (int i = 1; i < numTiendas + 1; i++) {
			cin >> tienda;
			tiendas.push_back(tienda);
		}

		dist = vector<vector<int>>(V, vector<int>(V));
		for (int i = 0; i < numTiendas + 1; i++) {
			distDijkstra.clear();
			dijkstra(tiendas[i]);
			for (int j = 0; j < tiendas.size(); j++) {
				dist[i][j] = distDijkstra[tiendas[j]];
			}
		}
		memo.assign(V, vector<int>(1 << V, -1));
		cout << tsp(0, 1) << '\n';
	}
	return 0;
}