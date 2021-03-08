#include <iostream>
#include <vector>
using namespace std;

class FenwickTree{
	vector<int> ft;
public:

	FenwickTree(int n) { ft.assign(n + 1, 0); }
		
	int getSum(int b) {
		int ret = 0;
		while (b) {
			ret += ft[b];
			b -= (b & -b);
		}
		return ret;
	}

	void add(int pos,int val){
		while (pos < ft.size()) {
		ft[pos] += val; pos += (pos & -pos); 
		} 
	}

	int getSum(int a, int b){
		return getSum(b) - getSum(a - 1);
	}

	int getValue(int pos) {
		return getSum(pos) - getSum(pos - 1);
	}

	void setValue(int pos, int val) {
		add(pos, val - getValue(pos));
	}
};

int main() {
	int numResis, resis, numCaso = 1, l1, l2;
	string opcion;
	cin >> numResis;
	while (numResis != 0 && numCaso <= 3) {
		FenwickTree arbol = FenwickTree(numResis);
		for (int i = 1; i <= numResis; i++) {
		cin >> resis;
		arbol.add(i, resis);
	}

	cout << "Case " << numCaso << ":\n";
	cin >> opcion;
	while (opcion != "END") {
		cin >> l1 >> l2;
		if (opcion == "M"){
			if (l1 == l2) cout << arbol.getValue(l1) << '\n';
			else cout << arbol.getSum(l1, l2) << '\n';
		}
		else if (opcion == "S") arbol.setValue(l1, l2);
		cin >> opcion;
	}

	numCaso++;
	cin >> numResis;
	cout << '\n';
	}
	return 0;
}