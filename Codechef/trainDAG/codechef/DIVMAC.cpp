#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
int n, m;
int a[maxN >> 3];
bool comp[maxN];
vector<int> prime;
int lp[maxN];
int st[maxN];

void sieve(int n) {
	lp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (not comp[i]) {
			prime.emplace_back(i);	
			lp[i] = i;
		}
		for (int p : prime) {
			if (p * i > n) break;
			comp[p * i] = 1;
			lp[p * i] = p;
			if (i % p == 0) break;
		}
	}
}

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {
		st[nx] = a[r]; 
		return;
	}
	int mid = (l+r)>>1;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = lp[st[nx<<1]] > lp[st[nx<<1|1]] ? st[nx<<1] : st[nx<<1|1];
}

void upd(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll or st[nx] == 1) return;
	if (l == r) { 
		st[nx] /= lp[st[nx]];
		return;
	}
	int mid = (l+r)>>1;
	upd(ll, rr, nx<<1, l, mid);
	upd(ll, rr, nx<<1|1, mid+1, r);
	st[nx] = lp[st[nx<<1]] > lp[st[nx<<1|1]] ? st[nx<<1] : st[nx<<1|1];
}

int get(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return 1;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)>>1;
	int L = get(ll, rr, nx<<1, l, mid);
	int R = get(ll, rr, nx<<1|1, mid+1, r);
	return lp[L] > lp[R] ? L : R;
}

int main() {
	sieve(1e6);
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) scanf("%d", a+i);
		build();
		while (m--) {
			int ty, l, r;
			scanf("%d %d %d", &ty, &l, &r);
			if (ty == 0) upd(l, r);
			else printf("%d ", lp[get(l, r)]);
		}
		puts("");
	}
	return 0;
}
