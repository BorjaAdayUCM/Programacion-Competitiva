#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <typename K, typename V>
bool comparePairs(const pair<K, V>& lhs, const pair<K, V>& rhs)
{
	return lhs.first < rhs.first;
}

int resuelve(vector<pair<int, int>> gasolineras, int tamCarretera) {
	int i = 0, masLargo = i;
	while (i < gasolineras.size() && gasolineras[i].first <= 0) {
		if (gasolineras[i].second >= gasolineras[masLargo].second) masLargo = i;
		i++;
	}
	i = masLargo;
	if (gasolineras[i].first > 0) return -1;
	int necesarios = 1;
	while(i < gasolineras.size() - 1 && gasolineras[i].second < tamCarretera) {
		int j = i + 1; masLargo = i + 1;
		bool dentro = false;
		while (i < gasolineras.size() && j < gasolineras.size() && gasolineras[j].first <= gasolineras[i].second) {
			dentro = true;
			if (gasolineras[j].second > gasolineras[masLargo].second) {
				masLargo = j;
			}
			j++;
		}
		i = masLargo - 1;
		necesarios++;
		if (dentro == false) return -1;
		i++;
	}
	if (gasolineras[i].second < tamCarretera) return -1;
	return necesarios;
}

int main() {
	int tamCarretera, numGasolineras, posGasolinera, radioGasolinera;
	cin >> tamCarretera >> numGasolineras;
	while (tamCarretera != 0 && numGasolineras != 0) {
		vector<pair<int, int>> gasolineras;
		for (int i = 0; i < numGasolineras; i++) {
			cin >> posGasolinera >> radioGasolinera;
			gasolineras.push_back(make_pair(posGasolinera - radioGasolinera, posGasolinera + radioGasolinera));
		}
		sort(gasolineras.begin(), gasolineras.end(), comparePairs<int, int>);
		int sol = resuelve(gasolineras, tamCarretera);
		if (sol == -1) cout << "-1\n";
		else cout << numGasolineras - sol << '\n';
		cin >> tamCarretera >> numGasolineras;
	}
}
