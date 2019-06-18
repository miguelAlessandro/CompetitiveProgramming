#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
bool composite[maxN], pq[maxN];
vector<int> prime, res;
int d[maxN], ex[maxN];

void sieve(int n) {
	for (int i = 2; i <= n; ++i) {
		if (not composite[i]) { 
			prime.emplace_back(i);
			d[i] = 2;
			ex[i] = 1;
		}
		if (pq[d[i]]) res.emplace_back(i);
		for (int p : prime) {
			if (p * i > n) break;
			composite[p * i] = 1;
			if (i % p == 0) {
				d[p * i] = d[i] / (ex[i] + 1) * (ex[i] + 2);
				ex[p * i] = ex[i] + 1;
				break;
			} else {
				d[p * i] = d[i] << 1;
				ex[p * i] = 1;
				if (not composite[i]) pq[p * i] = 1;
			}
		}
	}
	
}

int main() {
	sieve(1000000);
	for (int i = 8; i < res.size(); i += 9) {
		printf("%d\n", res[i]);
	}
	return 0;
}
