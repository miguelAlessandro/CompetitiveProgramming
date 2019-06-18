#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
vector<int> prime;
vector<long long> g[maxN];
bool composite[maxN];
int lp[maxN];

void sieve(int n) {
	for (int i = 2; i <= n; ++i) {
		if (not composite[i]) {
			prime.emplace_back(i);
			lp[i] = i;
		}
		for (int p : prime) {
			if (p * i > n) break;
			composite[p * i] = 1;
			lp[p * i] = p;
			if (i % p == 0) break;
		}
	}
}

int factors2(int n) {
	int ans = 1;
	while (lp[n]) {
		int f = lp[n], e = 0;
		while (n % f == 0) {
			n /= f;
			e += 1;
		}
		ans *= e<<1|1;
	}
	return ans;
}

int main() {
	int t, k;
	long long l, r;
	sieve(100000);
	for (int i = 1; i <= 100000; ++i) {
		int ans = factors2(i);
		if (ans <= 10000) {
			g[ans].emplace_back(i *1ll* i);
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d %lld %lld", &k, &l, &r);
		if (g[k].empty()) puts("0");
		else {
			int ans = upper_bound(begin(g[k]), end(g[k]), r) - lower_bound(begin(g[k]), end(g[k]), l);
			printf("%d\n", ans);
		}
	}
	return 0;
}
