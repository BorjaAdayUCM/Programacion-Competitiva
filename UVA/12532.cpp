#include <vector>
#include <iostream>
using namespace std;

class FenwickTree {
	vector<long long int> ft;
public:
	FenwickTree(long long int n) { ft.assign(n + 1, 0); }
	long long int getSum(long long int b) {
		long long int ret = 0;
		while (b) {
			ret += ft[b]; b -= (b & -b);
		}
		return ret;
	}
	void add(long long int pos, long long int val) {
		while (pos < ft.size()) {
			ft[pos] += val; pos += (pos & -pos);
		}
	}
	long long int getSum(long long int a, long long int b) {
		return getSum(b) - getSum(a - 1);
	}
	long long int getValue(long long int pos) {
		return getSum(pos) - getSum(pos - 1);
	}
	void setValue(long long int pos, long long int val) {
		add(pos, val - getValue(pos));
	}
};


int main()
{
	long long int n, k;
	while (cin >> n)
	{
		cin >> k;
		FenwickTree tree(n);
		for (long long int i = 1; i <= n; i++)
		{
			long long int temp;
			cin >> temp;
			if (temp < 0)	tree.add(i, 1);
			else if (temp == 0) tree.add(i, -100000);
			else tree.add(i, 0);
		}
		for (long long int i = 0; i < k; i++)
		{
			char op;
			cin >> op;
			if (op == 'C')
			{
				long long int temp, pos, newValue;
				cin >> pos >> temp;

				if (temp < 0)	newValue = 1;
				else if (temp == 0)newValue = -100000;
				else newValue = 0;
				tree.setValue(pos, newValue);
			}
			else
			{

				long long int posA, posB;
				cin >> posA >> posB;
				long long int valor = tree.getSum(posA, posB);

				if (valor >= 0) 
				{
					if (valor == 0 || (valor % 2) == 0) cout << '+';
					else cout << '-';
				}
				else cout << '0';
				
			}
		}
		cout << '\n';
	}
}