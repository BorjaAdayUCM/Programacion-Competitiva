#include <iostream>

using namespace std;

int main()
{
	int array[] = { 1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,5,4,4,5,9,6,2,7,3,6,2,1,1,2,8,1,7,2,8,5,9,8,8,9,3,0,6,1,7,0,6,5,5,6,2,5,1,6,2,9,3,2,2,3,7,4,0,5,1,4,0,9,9,0,6,9,5,0,6,3,7,6,6,7,1,8,4,9,5,8,4,3,3,4,0,3,9,4,0,7,1,0,0 };

	string  num;
	cin >> num;
	while (num != "0") {
		if (num.size() == 1) cout << array[num[0] - 49] << '\n';
		else
		{
			if (num[num.size() - 2] == 48 && num[num.size() - 1] == 48) cout << 0 << '\n';
			else cout << array[(num[num.size() - 2] - 48) * 10 + num[num.size() - 1] - 49] << '\n';
		}
		cin >> num;
	}
}