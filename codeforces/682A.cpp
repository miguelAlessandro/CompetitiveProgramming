#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(){
	
	cin >> n >> m;

	long long sum = 0;
	for(int i = 1; i <= n; ++i)
		sum += (m+i%5)/5;
	cout << sum << endl;

	return 0;
}
