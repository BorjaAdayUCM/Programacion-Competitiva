
#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

double calculaC(double x, double y, double b) {
	double hX = sqrt(pow(x, 2) - pow(b, 2));
	double hY = sqrt(pow(y, 2) - pow(b, 2));

	double gX = asin(hX / x);
	double gY = asin(hY / y);

	return (tan(gY) * ((tan(gX) * b) / (tan(gY) + tan(gX))));
}

void resuelve(double a, double b, double c, double ini, double fin, double&result) {
	//caso base

	double cPrueba = calculaC(a, b, (ini + fin) / 2.0);
	if (abs(cPrueba - c) < 0.000001) {
		result = (ini + fin) / 2.0;
		return;
	}
	if (cPrueba < c) {
		resuelve(a, b, c, ini, (ini + fin) / 2.0, result);
	}
	else if (cPrueba > c) {
		resuelve(a, b, c, (ini + fin) / 2.0, fin, result);
	}
	else {
		result = (ini + fin) / 2.0;
		return;
	}
}

int main() {
	double a, b, c, result = 0;
	while (cin >> a) {
		cin >> b >> c;
		double ini = 0, fin = min(a, b);
		resuelve(a, b, c, ini, fin, result);
		cout << fixed << setprecision(3) << result << endl;
	}
	return 0;
}
