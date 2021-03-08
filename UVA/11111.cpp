#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void resuelve(const vector<int> &linea, stack<pair<int, int>> &matrioshka, int i, bool &sol) {
	if (matrioshka.empty() && i == linea.size()) sol = true;
	if (i < linea.size() && linea[i] < 0 && (matrioshka.empty() || linea[i] > matrioshka.top().second)) {
		matrioshka.push(make_pair(linea[i], linea[i]));
		resuelve(linea, matrioshka, i + 1, sol);
	}
	else if (i < linea.size() && linea[i] == -matrioshka.top().first) {
		matrioshka.pop();
		if(!matrioshka.empty()) matrioshka.top().second += linea[i];
		resuelve(linea, matrioshka, i + 1, sol);
	}
}

int main() {
	string text;
	while (getline(cin, text)) {
		istringstream iss(text);
		vector<int> linea((istream_iterator<int>(iss)), istream_iterator<int>());
		stack<pair<int, int>> matrioshk
		bool sol = false;
		if (!linea.empty()) {
			matrioshka.push(make_pair(linea[0], linea[0]));
			resuelve(linea, matrioshka, 1, sol);
			if (sol) cout << ":-) Matrioshka!\n";
			else cout << ":-( Try again.\n";
		}
		else cout << ":-) Matrioshka!\n";
	}

	

	


}