#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> corrientes;
int ini1, ini2, dest1, dest2;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;
const int INF = 1e9;
int df[] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };


void dijkstra(int s, vvii& adjList, vi& dist) {
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

bool ok(int fila, int col, int filaMax, int colMax) {
	return 0 <= fila && fila < filaMax && 0 <= col && col < colMax;
}

int main() {
	int filaMax, colMax, numeroInt, numCasos, filaIni, colIni, filaDest, colDest;
	char numeroChar;
	while (cin >> filaMax) {
		cin >> colMax;
		vvii adjList = vvii(filaMax * colMax);
		for (int i = 0; i < filaMax; i++) {
			for (int j = 0; j < colMax; j++) {
				cin >> numeroChar;
				numeroInt = numeroChar - 48;
				for (int k = 0; k < 8; k++) {
					if (ok(i + df[k], j + dc[k], filaMax, colMax)) {
						if (k == numeroInt) adjList[i * colMax + j].push_back(make_pair(0, (i + df[k]) * colMax + (j + dc[k])));
						else adjList[i * colMax + j].push_back(make_pair(1, (i + df[k]) * colMax + (j + dc[k])));
					}
				}
			}
			cin.get();
		}
		cin >> numCasos;
		for (int i = 0; i < numCasos; i++) {
			cin >> filaIni >> colIni >> filaDest >> colDest;
			vi dist = vi(filaMax * colMax);
			dijkstra((filaIni - 1) * colMax + (colIni - 1), adjList, dist);
			cout << dist[(filaDest - 1) * colMax + (colDest - 1)] << '\n';
		}


	}
}