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
		if (x == o.x) return y < o.y;
		return x < o.x;
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

T dist2(pt a, pt b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

pt perp(pt p) { return { -p.y, p.x }; }

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

struct line {
	pt v; T c;
	// from direction vector v and offset c
	line(pt v, T c) : v(v), c(c) {}
	// from equation ax + by = c
	line(T a, T b, T c) : v({ b,-a }), c(c) {}
	// from points p and q
	line(pt p, pt q) : v(q - p), c(cross(v, p)) {}

	T side(pt p) { return cross(v, p) - c; }

	double dist(pt p) { return abs(side(p)) / abs(v); }

	pt proj(pt p) { return p - perp(v) * side(p) / sq(v); }
};



// devuelve true si r est� en el lado izquierdo de la l�nea pq
bool ccw(pt p, pt q, pt r) {
	return orient(p, q, r) > 0; // >= para puntos colineales
}

vector<pt> convexHull(vector<pt>& P) {
	int n = int(P.size()), k = 0;
	vector<pt> H(2 * n);
	sort(P.begin(), P.end());
	// build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && !ccw(H[k - 2], H[k - 1], P[i])) --k;
		H[k++] = P[i];
	}
	// build upper hull
	for (int i = n - 2, t = k + 1; i >= 0; --i) {
		while (k >= t && !ccw(H[k - 2], H[k - 1], P[i])) --k;
		H[k++] = P[i];
	}
	H.resize(k);
	return H;
}



int main() {
	int edad, radio;
	while (cin >> edad >> radio) {
		vector<pt> vectorVelas = vector<pt>();
		pt punto;
		for (int i = 0; i < edad; i++) {
			cin >> punto.x >> punto.y;
			vectorVelas.push_back(punto);
		}
		vector<pt> envolvente = convexHull(vectorVelas);
		if (envolvente.size() < 2) cout << 0 << '\n';
		else if (envolvente.size() == 2) cout << dist2(envolvente[0], envolvente[1]) << '\n';
		else {
			double ret =1e9;
			for (int i = 0, j = 0; i < envolvente.size() - 1; i++) {
				line linea(envolvente[i], envolvente[i + 1]);
				double a = linea.dist(envolvente[(j + 1) % envolvente.size()]); double b = linea.dist(envolvente[j]);
				while (linea.dist(envolvente[(j + 1) % envolvente.size()]) >= linea.dist(envolvente[j])) j = (j + 1) % envolvente.size();
				ret = min(ret, linea.dist(envolvente[j]));
			}
			
			cout << setprecision(17) << ret << '\n';
		}
	}
}