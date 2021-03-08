#include<iostream>
#include<vector>
#include<queue>

using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int,int>>;
using vii = vector<pair<int, int>>;


/*void dijkstra(int s, vi& dist, vector<vii> &adjList) {
	dist.assign(adjList.size(), 1e9);
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
}*/


int main() {
	int numCasos;
	cin >> numCasos;
	for (int casos = 0; casos < numCasos; casos++) {
		int fila, col;
		cin >> fila >> col;
		vector<vii> adjList(fila, vii(col));
		vector<vector<int>> pesos(fila, vi(col));
		for (int i = 0; i < fila; i++) {
			for (int j = 0; j < col; j++) {
				cin >> pesos[i][j];
			}
		}
		for (int i = 0; i < fila * col - 1; i++) {
			int filaNodo = i / col;
			int colNodo = i % col;
			adjList[i].push_back(make_pair(i + 1, pesos[filaNodo][colNodo]));
		}
	}
	cout << "hola" << endl;
}
