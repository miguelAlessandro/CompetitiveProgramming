#include <bits/stdc++.h>
using namespace std;

const int N = 5000005;
long long k2, k3, k5, k6;

int main(){

	cin >> k2 >> k3 >> k5 >> k6;

	long long sum = LLONG_MIN;
	for(long long i = 0; i <= min(k2, min(k5, k6)); ++i)
		sum = max(sum, 256LL*i + 32LL*min(k2-i, k3));

	cout << sum << endl;

	return 0;
}
