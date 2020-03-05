/**
 *	@name Codeforces 1188B div1 B
 *	@author Miguel Mini
 *	@tag math
 *	@idea
 *			- multiply both sides by (ai - aj)
 *			- count number of pairs with equal ai^4 - k * ai
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p, k;
	cin >> n >> p >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	map<int, int> cnt;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int temp = a[i] *1ll* a[i] % p;
		temp = temp * 1ll * temp % p;
		temp = (temp + p - k *1ll* a[i]%p) % p;
		ans += cnt[temp];
		cnt[temp] += 1;
	}
	cout << ans << endl;
	return 0;
}
