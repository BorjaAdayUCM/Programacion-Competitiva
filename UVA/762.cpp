#include <vector>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

bool resuelve(string origen, string destino, map<string, vector<string>> mapa, map<string, bool> visitado, map<string, string>& sol)
{
	queue<string> q;
	visitado[origen] = true;
	q.push(origen);
	while (!q.empty()) {
		string v = q.front();
		if (v == destino) return true;
		q.pop();
		for (string w : mapa[v])
			if (!visitado[w]) {
				visitado[w] = true;
				sol[w] = v;
				q.push(w);
			}
	}
	return false;
}

void print(string a, string b, map<string, string> sol, bool first)
{
	if (a == b) {
		cout << a;
		return;
	}
	print(a, sol[b], sol, false);
	if (!first)
		cout << " " << b << '\n' << b;
	else
		cout << " " << b << '\n';
}

int main()
{
	int numAristas;
	while (cin >> numAristas)
	{
		string arista1, arista2, origen, destino;
		map<string, vector<string>> mapa;
		map<string, bool> visitado;
		map<string, string> sol;
		for (int i = 0; i < numAristas; i++)
		{
			cin >> arista1 >> arista2;
			mapa[arista1].push_back(arista2);
			mapa[arista2].push_back(arista1);
			visitado[arista1] = false;
			visitado[arista2] = false;
		}
		cin >> origen >> destino;

		if (resuelve(origen, destino, mapa, visitado, sol))
		{
			print(origen, destino, sol, true);
			cout << '\n';
		}
		else
			printf("No route\n");
	}
}