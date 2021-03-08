#include<iostream>
#include<queue>
#include<vector>

using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;
vvii adjList;
const int INF = 1e9;

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
			}
		}
	}
}


int main() {
	int numCeldas, celSalida, tiempoMax, numPasadizos;
	while (cin >> numCeldas) {
		cin >> celSalida >> tiempoMax >> numPasadizos;
		if (numCeldas <= 0 || celSalida > numCeldas) {
			cout << 0 << '\n';
			continue;
		}
		adjList = vector<vector<pair<int,int>>>(numCeldas, vector<pair<int, int>>());
		int l1, l2, valor;
		for (int i = 0; i < numPasadizos; i++) {
			cin >> l2 >> l1 >> valor;
			adjList[l1 - 1].push_back(make_pair(valor, l2 - 1));
		}
		vector<int> dist = vector<int>(numCeldas);
		dijkstra(celSalida - 1, dist);
		int contador = 0;
		for (int i = 0; i < dist.size(); i++) {
			if (dist[i] <= tiempoMax && i != celSalida - 1) contador++;
		}
		cout << contador << '\n';

	}
}



