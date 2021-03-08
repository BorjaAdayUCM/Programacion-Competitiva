#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <climits>

using namespace std;

const unsigned long long int MAX_PRIME = 46340;
bitset<MAX_PRIME + 1> bs; // #include <bitset>
vector<unsigned int> primes; // unsigned int
vector<bool> ret;

void sieve() {
	bs.set(); // De momento, todos son primos 
	bs[0] = bs[1] = 0; // El 0 y el 1 no lo son. 
	for (unsigned int i = 2; i <= MAX_PRIME; ++i) {
		if (bs[i]) {
			// El actual es primo. Tiramos sus multiplos 
			for (unsigned int j = i * i; j <= MAX_PRIME; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}

int main() {
	primes = vector<unsigned int>();
	sieve();
	unsigned long long int l1, l2;
	while (cin >> l1 >> l2) {
		long long int lastPrime = -1, first, last, minDistance = LLONG_MAX, maxDistance = LLONG_MIN;
		ret = vector<bool>(1000001, false);
		for (int i = 0; i < primes.size(); i++) {
			int factor = (l1 - 1) / primes[i] + 1;
			if (factor < 2) factor = 2;
			int factor1 = l2 / primes[i];
			for (int j = factor; j <= factor1; j++) ret[j * primes[i] - l1] = true;
		}
		for (int i = 0; i <= l2 - l1; i++) {
			if (!ret[i]) {
				if (lastPrime != -1) {
					if (i - lastPrime > maxDistance) {
						maxDistance = i - lastPrime;
						first = i + l1;
					}
					if (i - lastPrime < minDistance) {
						minDistance = i - lastPrime;
						last = i + l1;
					}
				}
				if (i + l1 != 1) lastPrime = i;
			}
		}
		if (minDistance == LLONG_MAX || maxDistance == LLONG_MIN) cout << "There are no adjacent primes.\n";
		else cout << last - minDistance << "," << last << " are closest, " << first - maxDistance << "," << first << " are most distant.\n";
	}
}
