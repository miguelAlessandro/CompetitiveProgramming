#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int dis[maxN];
bool comp[maxN];
vector<int> prime, g[100];

void sieve(int n) {
	for (int i = 2; i <= n; ++i) {
		if (not comp[i]) {
			prime.emplace_back(i);
			dis[i] = 1;
		}	
		g[dis[i]].emplace_back(i);
		for (int p : prime) {
			if (p * i > n) break;
			comp[p * i] = 1;
			if (i % p == 0) {
				dis[p * i] = dis[i];
				break;
			} else {
				dis[p * i] = dis[i] + 1;
			}
		}
	}
}

int main() {
	sieve(1e5);
	int t; scanf("%d", &t);
	while (t--) {	
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);
		int ans = upper_bound(begin(g[k]), end(g[k]), b) - lower_bound(begin(g[k]), end(g[k]), a);
		printf("%d\n", ans);
	}
	return 0;
}
