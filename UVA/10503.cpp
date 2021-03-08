#include <iostream>

using namespace std;

void resuelve(int numSpaces, int numFichas, int matriz[14][2],int numDis[] ,int extIzq, int extDer, bool disponible[], bool &sol)
{
	if (numSpaces == 0) {
		sol = true;
	};

	if (((numSpaces > 1) && (numDis[extIzq] != 0 || numDis[extDer] != 0)) || ((numSpaces == 1) && (numDis[extIzq] > 0 || numDis[extDer] > 0)))
	{
		int i = 0;
		while (i < numFichas) {
			int extCambiado;
			if ((numSpaces > 1) && (disponible[i]) && (extIzq == matriz[i][0] || extIzq == matriz[i][1])) {
				disponible[i] = false;
				extCambiado = extIzq;
				(extIzq == matriz[i][0]) ? extIzq = matriz[i][1] : extIzq = matriz[i][0];
				numDis[extIzq]--;
				resuelve(numSpaces - 1, numFichas, matriz, numDis, extIzq, extDer, disponible, sol);
				disponible[i] = true;
				extIzq = extCambiado;
				numDis[extIzq]++;
			}
			if ((numSpaces > 1) && (disponible[i]) && (extDer == matriz[i][0] || extDer == matriz[i][1])) {
				disponible[i] = false;
				extCambiado = extDer;
				(extDer == matriz[i][1]) ? extDer = matriz[i][0] : extIzq = matriz[i][1];
				numDis[extDer]--;
				resuelve(numSpaces - 1, numFichas, matriz, numDis, extIzq, extDer, disponible, sol);
				disponible[i] = true;
				extDer = extCambiado;
				numDis[extDer]++;
			}
			else if ((numSpaces == 1) && (disponible[i]) && ((extIzq == matriz[i][0] && extDer == matriz[i][1]) || (extDer == matriz[i][0] && extIzq == matriz[i][1]))) {
				resuelve(numSpaces - 1, numFichas, matriz, numDis, extIzq, extDer, disponible, sol);
			}
			i++;
		}

	}
}

int main()
{
	int numSpaces, numFichas, matriz[14][2], numDis[7], extIzq, extDer, dummy;
	bool disponible[14], sol = false;

	cin >> numSpaces;
	while (numSpaces != 0)
	{
		for (int i = 0; i < 14; i++) {
			if (i < 7) numDis[i] = 0;
			disponible[i] = true;
		}
		sol = false;
		cin >> numFichas >> dummy >> extIzq >> extDer >> dummy;
		for (int i = 0; i < numFichas; i++) {
			cin >> matriz[i][0] >> matriz[i][1];
			numDis[matriz[i][0]]++;
			numDis[matriz[i][1]]++;
		}
		resuelve(numSpaces, numFichas, matriz, numDis, extIzq, extDer, disponible, sol);
		if (sol) cout << "YES\n";
		else cout << "NO\n";
		cin >> numSpaces;
	}

}