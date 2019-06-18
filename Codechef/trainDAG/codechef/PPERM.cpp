#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e6 + 10;
bool comp[maxN];
vector<int> prime;
int sum[maxN], phi[maxN];
const int mod = 1e9 + 7;
int t;

int add(int a, int b) {
	return a + b > mod ? a + b - mod : a + b;
}

int mul(long long a, long long b) {
	return a * b % mod;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

void sieve(int n) {
	for (int i = 2; i <= n; ++i) {
		if (not comp[i]) {
			prime.emplace_back(i);
		}
		for (int p : prime) {
			if (p * i > n) break;
			comp[p * i] = 1;
			if (i % p == 0) break;
		}
		sum[i] = sum[i-1] + (not comp[i]);
	}
}

int ans[maxN];
int read() {
	int x = 0;
	register char c = getchar();
	while (c < '0') c = getchar();
	while (c >= '0') {
		x = (x<<3) + (x<<1) + c - '0';
		c = getchar();
	}
	return x;
}

void write(int n) {
	if (n == 0) putchar_unlocked('0');
	else {
		register char num[10];
		int t = 0;
		while (n > 0) {
			num[t++] = n % 10;
			n /= 10;
		}
		for (int i = t-1; i >= 0; --i) putchar_unlocked(num[i] + '0');
	}
	putchar_unlocked('\n');
}

int main() {
	sieve(5e6);
	ans[1] = 1;
	for (int i = 2; i < maxN; ++i) ans[i] = mul(ans[i-1], sum[i] + 1);
	t = read();
	while (t--) {
		int n;
		n = read();
		printf("%d\n", ans[n]);
	}
	return 0;
}
