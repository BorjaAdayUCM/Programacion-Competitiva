#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

enum tColor { BLANCO, NEGRO, NS };


bool resuelve(vector<vector<int>> &adjList, int numNodos, vector<tColor> colores, vector<bool> &visited, int v) {
	bool sol = true, blanco = false, negro = false;
	visited[v] = true;
	for (int w : adjList[v]) {
		if (!visited[w]) {
			blanco = false, negro = false;
			for (int i = 0; i < adjList[w].size(); i++) {
				if (colores[adjList[w][i]] == BLANCO) blanco = true;
				if (colores[adjList[w][i]] == NEGRO) negro = true;
			}
			if (blanco && negro) {
				sol = false;
			}
			else {
				if (blanco) colores[w] = NEGRO;
				else colores[w] = BLANCO;
				sol = sol && resuelve(adjList, numNodos, colores, visited, w);
			}
		}
	}
	return sol;
}

int main() {
	int numNodos, numAristas, l1, l2;
	cin >> numNodos;
	while (numNodos != 0)
	{
		cin >> numAristas;
		bool encontrado = false;
		vector<vector<int>> matAdj(numNodos);
		for (int i = 0; i < numAristas; i++) {
			cin >> l1 >> l2;
			matAdj[l1].push_back(l2);
			matAdj[l2].push_back(l1);
		}
		vector<bool> visited(numNodos, false);
		vector<tColor> colores(numNodos, NS);
		colores[0] = BLANCO;
		visited[0] = true;
		if (resuelve(matAdj, numNodos, colores, visited, 0)) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
		cin >> numNodos;
	}
}
