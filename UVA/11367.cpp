#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int INF = 1e9;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvii = vector<vii>;


vvii adjList;
vi costGas;
vi dist;
int maxGas;

void dijkstra(int s, vi& dist) {
	dist.assign(adjList.size(), INF);
	dist[s] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (auto a : adjList[u]) {

			if (dist[u] + a.first < dist[a.second]) {
				dist[a.second] = dist[u] + a.first;

				pq.push({ dist[a.second], a.second });
			}		}	}}

int main() {
	int numCiudades, numConexiones, c1, c2, cost, numCon;
	adjList = vvii(numCiudades, vector<ii>());
	costGas = vi(numCiudades);
	dist = vi(numCiudades);
	for (int i = 0; i < numCiudades; i++) cin >> costGas[i];
	for (int i = 0; i < numConexiones; i++) {
		cin >> c1 >> c2 >> cost;
		adjList[c1].push_back(make_pair(cost, c2));
		adjList[c2].push_back(make_pair(cost, c1));
	}
	cin >> numCon;
	for (int i = 0; i < numCon; i++) {
		cin >> maxGas >> c1 >> c2;
		dijkstra(c1, dist);
		if (dist[c2] == INF) cout << "impossible\n";
		else cout << dist[c2] << '\n';
	}
	
}