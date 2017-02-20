#include <iostream>
using namespace std;

long long t, n, m;

int main(){

	cin >> t;
	while(t--){
		cin >> n >> m;
		if((n*m)&1LL) cout << "No" << endl;
		else cout << "Yes" << endl;
	}

	return 0;
}
