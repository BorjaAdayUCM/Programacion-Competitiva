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
	int numcases;
	cin >> numcases;
	for (int i = 0; i < numcases; i++)
	{
		int c, d, v;
		cin >> c >> d >> v;
		vector<pair<int, int>> cats, dogs;
		for (int j = 0; j < v; j++)
		{
			char first, second;
			int  firstInt, secondInt;
			cin >> first >> firstInt >> second >> secondInt;

			if (first == 'D')
			{
				dogs.push_back(make_pair(firstInt, secondInt));
			}
			else
			{
				cats.push_back(make_pair(firstInt, secondInt));
			}
		}

		grafo = vector<vector<int>>(v);
		M = cats.size();
		N = dogs.size();


		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (cats[i].first == dogs[j].second || cats[i].second == dogs[j].first)
					grafo[i].push_back(j);
			}
		}

		cout << v - berge_mcbm() << "\n";
	}
}