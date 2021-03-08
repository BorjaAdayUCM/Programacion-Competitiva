#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using T = double; // using T = int;

using namespace std;

struct pt {
	T x, y;
	pt operator+(pt p) const { return { x + p.x, y + p.y }; }
	pt operator-(pt p) const { return { x - p.x, y - p.y }; }
	pt operator*(T d) const { return { x * d, y * d }; }
	pt operator/(T d) const { return { x / d, y / d }; } // only for floating-point

	bool operator==(pt o) const { return x == o.x && y == o.y; }
	bool operator!=(pt o) const { return !(*this == o); }
	bool operator<(pt o) const { // sort points lexicographically
		if (x == o.x) return y > o.y;
		return x > o.x;
	}

	// bool operator<(pt o) const { // #define EPS 1e-9
	// if (fabs(x - o.x) < EPS) return y < o.y;
	// return x < o.x;
	// }
};

T sq(pt v) { return v.x * v.x + v.y * v.y; }

double abs(pt v) { return sqrt(sq(v)); }

double dist(pt a, pt b) { // Euclidean distance
	return hypot(a.x - b.x, a.y - b.y);
}

int main() {
	int casos, nPt;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		cin >> nPt;
		vector<pt> puntos = vector<pt>(nPt);
		for (int j = 0; j < nPt; j++) {
			cin >> puntos[j].x >> puntos[j].y;
		}
		sort(puntos.begin(), puntos.end());
		int alturaMaxima = 0;
		double sunnyLength = 0;
		for (int k = 1; k < puntos.size(); k++) {
			if (puntos[k].y > alturaMaxima) {
				sunnyLength += dist(puntos[k], puntos[k - 1]) * (puntos[k].y - alturaMaxima) / (puntos[k].y - puntos[k - 1].y);
				alturaMaxima = puntos[k].y;
			}
		}
		cout << fixed << setprecision(2) << sunnyLength << '\n';
	}
	
}