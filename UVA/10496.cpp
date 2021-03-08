#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V; // vértices del grafo completo

vector<vector<int>> memo; // tabla de DP

// devuelve el coste de ir desde pos al origen (el vértice 0)
// pasando por todos los vértices no visitados (con un bit a 0)
int tsp(int pos, int visitados, vector<vector<int>> dist) {
	if (visitados == (1 << V) - 1) // hemos visitado ya todos los vértices
		return dist[pos][0]; // volvemos al origen
	if (memo[pos][visitados] != -1)
		return memo[pos][visitados];

	int res = 1000000000;
	for (int i = 1; i < V; ++i)
		if (!(visitados & (1 << i))) // no hemos visitado vértice i
			res = min(res, dist[pos][i] + tsp(i, visitados | (1 << i), dist));
	return memo[pos][visitados] = res;
}

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int tamX, tamY, rX, rY, numB;
		cin >> tamX >> tamY >> rX >> rY >> numB;
		vector<pair<int, int>> pos(numB + 1);
		pos[0] = make_pair(rX, rY);

		vector<vector<int>> dist(numB + 1, vector<int>(numB + 1, 0));
		for (int j = 1; j < numB + 1; j++)
		{
			int  x, y;
			cin >> x >> y;
			pos[j] = make_pair(x, y);
		}

		for (int k = 0; k < numB + 1; k++)
		{
			for (int l = k + 1; l < numB + 1; l++)
			{
				dist[k][l] = abs(pos[k].first - pos[l].first) + abs(pos[k].second - pos[l].second);
				dist[l][k] = dist[k][l];
			}
		}
		V = numB + 1;
		memo.assign(V, vector<int>(1 << V, -1));
		cout << "The shortest path has length " << tsp(0, 1 << 0, dist) << '\n';


	}
}
