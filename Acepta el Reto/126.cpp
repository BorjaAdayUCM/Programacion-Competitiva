#include <iostream>

using namespace std;

int main() {
	int factorial, divisor;
	cin >> divisor >> factorial;
	while (factorial >= 0 && divisor >= 0) {
		if (divisor == 1 || (divisor <= factorial)) cout << "YES\n";
		else cout << "NO\n";
		cin >> divisor >> factorial;
	}
}