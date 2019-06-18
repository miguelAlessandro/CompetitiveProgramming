#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e4 + 10;
bool comp[maxN];
vector<int> prime;
int ans[maxN];

void sieve(int n) {
	comp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (not comp[i]) prime.emplace_back(i);
		for (int p : prime) {
			if (p * i > n) break;
			comp[p * i] = 1;
			if (i % p == 0) break;
		}
	}
}

int main() {
	sieve(10000);
	for (int i = 2; i <= 10000; ++i) {
		for (int p : prime) {
			if ((p << 1) >= i) break;
			if (not comp[i - (p << 1)]) ans[i] += 1;
		}
	}
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
