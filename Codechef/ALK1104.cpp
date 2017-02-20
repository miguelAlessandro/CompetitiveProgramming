#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		if(__builtin_popcount(n) == 1) cout << "BKUL" << endl;
		else cout << "BMEENA" << endl;
	}


	return 0;
}
