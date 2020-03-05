/**
 *	@name Codeforces 1267 NERC Eurasia K
 *	@author Miguel Mini
 *	@tag math, greedy
 *	@idea
 *			- from every sequence we can make
 *			a integer if it doesn't end with 0
 *			and i >= a[i].
 *
 *			- we can calculate without first 
 *			constraint, and then we calculate
 *			every configuration with ending 0.
 *
 *			- to calculate this value, this is
 *			equal to the product of admisible 
 *			values - i + 1. divided by factorial 
 *  		of number of repeat elements.
**/

#include <bits/stdc++.h>
using namespace std;

deque<int> gen(long long k) {
	deque<int> t;
	for (int i = 2; i <= 30; ++i) {
		if (k == 0) break;
		t.push_back(k % i);
		k /= i;
	}
	return t;
}

const int maxn = 25;
int cnt[maxn];
long long f[maxn];
long long solve(deque<int> q) {
	memset(cnt, 0, sizeof cnt);
	long long d = 1;
	int k = 0, last = -1;
	int c0 = 0;
	for (int v : q) {
		if (v != last) d *= f[k], last = v, k = 1;
		else k += 1;
		if (v == 0) c0 += 1;
		cnt[max(0, v-1)] += 1;
	}
	d *= f[k];
	for (int i = 1; i < maxn; ++i) {
		cnt[i] += cnt[i-1];
	}
	long long res = 1;
	for (int i = 0; i < q.size(); ++i) {
		res *= max(0, cnt[i] - i);
	}
	res /= d;
	return res;
}

int main() {
	f[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		f[i] = f[i-1] * i;
	}
	int t;
	cin >> t;
	while (t--) {
		long long k;
		cin >> k;
		deque<int> p = gen(k);		
		sort(p.begin(), p.end());
		long long res = solve(p) - 1;
		if (p[0] == 0) {
			p.pop_front();
			res -= solve(p);
		}
		cout << res << endl;
	}
	return 0;
}
