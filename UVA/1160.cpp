#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

// union-find
vector<int> C;
int numSets;

void init(int n) {
	C.assign(n, 0);
	for (int i = 0; i < n; ++i) C[i] = i;
	numSets = n;
}
int find(int a) {
	return (C[a] == a) ? a : C[a] = find(C[a]);
}
// find(a) != find(b)
void merge(int a, int b) {
	C[find(a)] = find(b);
	--numSets;
}

int main()
{
	int x, y, n = 0;
	while (cin >> x)
	{
		n = 0;
		init(100000);
		while (x != -1)
		{
			cin >> y;
			if (find(C[x]) == find(C[y]))n++;
			else merge(x, y);
			cin >> x;

		}
		cout << n << "\n";
	}
}