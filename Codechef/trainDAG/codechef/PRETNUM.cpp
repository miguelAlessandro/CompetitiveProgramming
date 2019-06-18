#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
bool comp[maxN];
vector<int> prime;
long long temp[maxN];
int d[maxN];

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
	sieve(1e6);
	int t; cin >> t;
	while (t--) {
		long long l, r; cin >> l >> r;
		for (int i = 0; i <= r-l; ++i) temp[i] = l+i;
		for (int i = 0; i <= r-l; ++i) d[i] = 1;
		for (int p : prime) {
			for (long long i = (l + p - 1) / p * p; i <= r; i += p) {
				int e = 0;
				while (temp[i-l] % p == 0) {
					temp[i-l] /= p;
					e += 1;
				}
				d[i-l] *= e+1;
			}
		}
		for (int i = 0; i <= r-l; ++i) if (temp[i] != 1) d[i] <<= 1;
		int ans = 0;
		for (int i = 0; i <= r-l; ++i) if (not comp[d[i]]) ans += 1;
		cout << ans << endl;
	}
	return 0;
}
