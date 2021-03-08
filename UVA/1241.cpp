

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_N 10
#define MAX_JUGADORES (1 << MAX_N)

bool v[MAX_JUGADORES];//0-base

int cuantos(bool& rival, int a, int b) {
	if (a == b) {
		rival = v[b];
		return 0;
	}
	bool r1 = true, r2 = true;
	int m = (a + b) / 2;
	int izq = cuantos(r1, a, m);
	int der = cuantos(r2, m + 1, b);

	rival = r1 || r2;

	return izq + der + (r1 != r2 ? 1 : 0);
}

void resuelve() {
	int n, novienen;
	cin >> n >> novienen;

	memset(v, 1, (1 << n) * sizeof(v[0]));//pone un trozo de memoria al valor que usted quiera

	while (novienen--) {
		int pos;
		cin >> pos;
		v[pos - 1] = false;
	}

	bool r;
	cout << cuantos(r, 0, (1 << n) - 1) << '\n';
}


int main() {
	int ncs;
	cin >> ncs;

	while (ncs--)
		resuelve();

	return 0;
}