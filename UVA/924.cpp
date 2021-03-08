#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int s, vector<bool> visited, vector<vector<int>> adjList, int &maxEnterados, int &maxDias) {
	queue<int> q;
	int dias = 1, cont = 1;
	visited[s] = true;
	q.push(s);
	while (!q.empty()) {
		int suma = 0;
		for (int i = 0; i < cont; i++) {
			int v = q.front(); q.pop();
			for (int w : adjList[v]) {
				if (!visited[w]) {
					suma++;
					visited[w] = 1;
					q.push(w);
				}
			}
		}
		if (suma > maxEnterados) {
			maxEnterados = suma;
			maxDias = dias;
		}
		cont = suma;
		dias++;
	}
}

int main() {
	int numEmpleados;
	while (cin >> numEmpleados) {
		vector<vector<int>> adjList = vector<vector<int>>(numEmpleados, vector<int>());
		int numAmigos, amigo, numCasos, primero;
		for (int i = 0; i < numEmpleados; i++) {
			cin >> numAmigos;
			for (int j = 0; j < numAmigos; j++) {
				cin >> amigo;
				adjList[i].push_back(amigo);
			}
		}
		cin >> numCasos;
		for (int i = 0; i < numCasos; i++) {
			vector<bool> visited = vector<bool>(numEmpleados, false);
			int maxDias = -1, maxEnterados = -1;
			cin >> primero;
			bfs(primero, visited, adjList, maxEnterados, maxDias);
			cout << maxEnterados << " ";
			if (maxEnterados)  cout << maxDias;
			cout << '\n';
		}

	}

	return 0;
}