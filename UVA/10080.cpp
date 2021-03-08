#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int M, N; // M parte izquierda, N parte derecha
vector<vector<int>> grafo; // dirigido, tamaño M
vector<int> match, vis;

int aug(int l) { // Devuelve 1 si encuentra un augmenting path para el matching M representado en match.
	if (vis[l]) return 0;
	vis[l] = 1;
	for (auto r : grafo[l])
	{
		if (match[r] == -1 || aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int berge_mcbm()
{
	int mcbm = 0;
	match.assign(N + M, -1);
	for (int l = 0; l < M; l++) {
		vis.assign(M, 0);
		mcbm += aug(l);
	}
	return mcbm;
}


int main()
{
	int s, v;
	while (cin >> M)
	{
		cin >> N >> s >> v;
		vector<pair<float, float>>  posG(M);
		for (int i = 0; i < M; i++)
		{
			float temp1, temp2;
			cin >> temp1 >> temp2;
			posG[i] = make_pair(temp1, temp2);
		}
		vector<pair<float, float>>  posH(N);
		for (int i = 0; i < N; i++)
		{
			float temp1, temp2;
			cin >> temp1 >> temp2;
			posH[i] = make_pair(temp1, temp2);
		}

		grafo = vector<vector<int>>(N + M);

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (s >= ((sqrt(pow((posG[i].first - posH[j].first), 2) + pow(posG[i].second - posH[j].second, 2))) / v))
					grafo[i].push_back(M + j);
			}
		}

		cout << M - berge_mcbm() << "\n";
	}
}


