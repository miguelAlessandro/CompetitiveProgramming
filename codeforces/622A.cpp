#include <bits/stdc++.h>
using namespace std;

long long n;

int main(){

	cin >> n;
	long long r = 1;
	for(long long i = 1;; ++i)
		if(i*(i+1)/2 <= n) r = i;
		else break;


	if(n - r*(r+1)/2 == 0) cout << r << endl;
	else cout << n - r*(r+1)/2 << endl;

	return 0;
}
