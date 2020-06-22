/**
 *	@name POI 2010 Beads
 *	@author Miguel Mini
 *	@tag hashing
 *	@idea
 *		- the numbers of segment to analize
 *		is O(n + n/2 + n/3 + ... + 1), that
 *		is equal to O(nlogn).
 *
 *		- we can make in O(n) hashing for  
 *		every range.
 *
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
const int mod = 1e9 + 9;
const int B = 3e5 + 11;
int rnk[2][maxn];
int a[maxn];
int rb[maxn];

int add(int a, int b) {
	return a + b < mod ? a+b : a+b-mod;
}
	
int mul(long long a, long long b) {
	return a * b % mod;
}

int ex(int a, int b) {
	int r = 1;
	while (b > 0) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

void preprocess(int r, int n, int a[]) {
	int hash = 0, b = 1;
	for (int i = 0; i < n; ++i) {
		hash = rnk[r][i] = add(hash, mul(a[i], b)); 
		b = mul(b, B);
	}	
}

int get(int r, int pos, int len) {
	if (pos == 0) return rnk[r][len-1];
	return mul(add(rnk[r][pos+len-1], mod - rnk[r][pos-1]), rb[pos]);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}
	preprocess(0, n, a);
	reverse(a, a+n);
	preprocess(1, n, a);
	int invb = ex(B, mod-2);
	rb[0] = 1;
	for (int i = 1; i < n; ++i) {
		rb[i] = mul(rb[i-1], invb);
	}
	int mx = 0;
	vector<int> pos;
	for (int i = 1; i <= n; ++i) {
		set<pair<int, int>> s;
		for (int j = 0; j + i - 1 < n; j += i) {
			int L = get(0, j, i);
			int R = get(1, n - (j + i - 1) - 1, i);
			if (L > R) swap(L, R);
			s.insert({L, R});
		}
		if (mx < s.size()) {
			mx = s.size();
			pos = {i};		
		} else if (mx == s.size()) {
			pos.push_back(i);
		}
	}
	printf("%d %d\n", mx, (int)pos.size());
	for (int v : pos) printf("%d ", v);
	puts("");
	return 0;
}
