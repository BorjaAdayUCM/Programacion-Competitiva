#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int resuelve(int mapa[10][1001], int dist)
{
	int tabla[10][1001];
	tabla[9][0] = mapa[9][0];
	tabla[9][1] = tabla[9][0] + 30 + mapa[9][1];
	tabla[8][1] = tabla[9][0] + 60 + mapa[8][1];
	tabla[9][2] = min(tabla[9][1] + 30, tabla[8][1] + 20) + mapa[9][2];
	tabla[8][2] = min(tabla[9][1] + 60, tabla[8][1] + 30) + mapa[8][2];
	tabla[7][2] = tabla[8][1] + 60 + mapa[7][2];

	for (int i = 3; i <= dist; i++)
	{
		for (int j = 9; ((i < 10 && j >= 9 - i) || (i >= 10 && j >= 9 - (dist - i))) && j >= 0; j--)
		{
			if (j == 9 - i) tabla[j][i] = tabla[j + 1][i - 1] + 60 + mapa[j][i];
			else if (j == 0 || j == 10 - i) tabla[j][i] = min(tabla[j][i - 1] + 30, tabla[j + 1][i - 1] + 60) + mapa[j][i];
			else if (j == 9) tabla[j][i] = min(tabla[j][i - 1] + 30, tabla[j - 1][i - 1] + 20) + mapa[j][i];
			else tabla[j][i] = min(min(tabla[j][i - 1] + 30, tabla[j + 1][i - 1] + 60), tabla[j - 1][i - 1] + 20) + mapa[j][i];
		}
	}

	tabla[9][dist] = min(tabla[9][dist - 1] + 30, tabla[8][dist - 1] + 20);
	return tabla[9][dist];
}

int main() {
	
	int n;
	cin >> n;

	for (int m = 0; m < n; m++)
	{
		int mapa[10][1001];
		int dist;
		cin >> dist;
		dist /= 100;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < dist; j++)
			{
				cin >> mapa[i][j];
				mapa[i][j] *= -1;
			}
		}

		cout << resuelve(mapa, dist) << "\n\n";
	}
	return 0;
}