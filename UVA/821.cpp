#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

const int MAX = 100;

void floyd(vector<vector<int>> &adjMat) {
	for (int k = 0; k < MAX; k++) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) {
					adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
				}
			}
		}
	}
}

int main() {
	int l1, l2;
	cin >> l1 >> l2;
	int numCaso = 1;
	while (l1 != 0 && l2 != 0) {
		int numNodos = 0;
		vector<vector<int>> adjMat(MAX, vector<int>(MAX, 1e9));
		while (l1 != 0 && l2 != 0) {
			if (adjMat[l1 - 1][l1 - 1] == 1e9) numNodos++;
			adjMat[l1 - 1][l1 - 1] = 0;
			adjMat[l1 - 1][l2 - 1] = 1;
			cin >> l1 >> l2;
		}
		floyd(adjMat);
		int suma = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if(adjMat[i][j] != 1e9) suma += adjMat[i][j];
			}
		}
		float sol = (float)((float)(suma) / (float)(numNodos * (numNodos - 1)));
		cout << "Case " << numCaso << ": average length between pages = " << fixed << setprecision(3) << sol << " clicks\n";
		numCaso++;
		cin >> l1 >> l2;
	}
}