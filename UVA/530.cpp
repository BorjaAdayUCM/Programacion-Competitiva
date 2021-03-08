#include <iostream>

using namespace std;

int main(){
    int  n, k;
    long long int sol;
    cin >> n >> k;
    while( n != 0 && k != 0){
        sol = 1;
       if(k > n / 2) k = n - k;
       for(int i = 0; i < k; i++) {
           sol *= (n - i);
           sol /= (1 + i);
       }
       cout << sol << '\n';
       cin >> n >> k;
    }

    return 0;
}