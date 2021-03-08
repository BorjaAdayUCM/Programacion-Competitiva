#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int numCasos = 1;
	int Z, I, M, L;
	cin >> Z >> I >> M >> L;
	while (Z != 0 || I != 0 || M != 0 || L != 0)
	{
		vector<int> vect = vector<int>();
		set<int> conjunto;
		int longuitud = -1;
		while (vect.size() == conjunto.size())
		{
			vect.push_back(L);
			conjunto.insert(L);
			L = (Z * L + I) % M;
			longuitud++;
		}
		int inicio = 0; bool salir = false;
		for (int i = 0; i < vect.size() && !salir ; i++) 
		{
			if (vect[i] == vect.back()) 
			{
				inicio = i;
				salir = true;
			}
		}
		cout << "Case " << numCasos++ << ": " << longuitud - inicio << '\n';
		cin >> Z >> I >> M >> L;
	}
}
