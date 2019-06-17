#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e8 + 10;
int n;
int prime[maxN / 15];
bitset<maxN> composite;

void sieve(int m) {
	for (int i = 2; i <= m; ++i) {
		if (not composite[i]) {
			prime[n++] = i;
		}
		for (int j = 0; prime[j]; ++j) {
			if (prime[j] * i > m) break;
			composite[prime[j] * i] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

int write(int n) {
	if (n == 0) putchar('0');
	else {
		register char num[10];
		int t = 0;
		while (n > 0) {
			num[t++] = n % 10;
			n /= 10;
		}
		for (int i = t-1; i >= 0; --i) putchar(num[i] + '0');
	}
	putchar('\n');
}

int main() {
	sieve(maxN-10);
	for (int i = 0; i < n; i += 100) write(prime[i]);
	return 0;
}
