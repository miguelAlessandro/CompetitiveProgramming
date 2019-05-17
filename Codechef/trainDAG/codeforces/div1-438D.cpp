#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
long long st[maxN<<2];
int maxSt[maxN<<2], minSt[maxN<<2];
int lazy[maxN<<2];
int a[maxN];
int n, m;

void init(int nx, long long s, int a, int b) {
	st[nx] = s;
	minSt[nx] = a;
	maxSt[nx] = b;
}

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {
		init(nx, a[r], a[r], a[r]);
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	init(nx, st[nx<<1] + st[nx<<1|1], 
	min(minSt[nx<<1], minSt[nx<<1|1]), max(maxSt[nx<<1], maxSt[nx<<1|1]));
}

void updNode(int nx, int l, int r, int x) {
	st[nx] = x *1ll* (r - l + 1);
	maxSt[nx] = minSt[nx] = x;
	lazy[nx] = x;
}

void push(int nx, int l, int r) {
	if (~lazy[nx]) {
		int mid = (l+r)/2;
		updNode(nx<<1, l, mid, lazy[nx]);
		updNode(nx<<1|1, mid+1, r, lazy[nx]);
		lazy[nx] = -1;
	}	
}

long long qry(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	push(nx, l, r);
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}

void updMod(int ll, int rr, int x, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll or maxSt[nx] < x) return;
	if (ll <= l and r <= rr and maxSt[nx] == minSt[nx]) {
		updNode(nx, l, r, maxSt[nx] % x);
		return;
	}
	int mid = (l+r)/2;
	push(nx, l, r);
	updMod(ll, rr, x, nx<<1, l, mid);
	updMod(ll, rr, x, nx<<1|1, mid+1, r);
	init(nx, st[nx<<1] + st[nx<<1|1], 
	min(minSt[nx<<1], minSt[nx<<1|1]), max(maxSt[nx<<1], maxSt[nx<<1|1]));
}

void upd(int pos, int x, int nx = 1, int l=1, int r=n) {
	if (pos < l or r < pos) return;
	if (l == r) {
		init(nx, x, x, x);
		return;
	}
	int mid = (l+r)/2;
	push(nx, l, r);
	upd(pos, x, nx<<1, l, mid);
	upd(pos, x, nx<<1|1, mid+1, r);
	init(nx, st[nx<<1] + st[nx<<1|1], 
	min(minSt[nx<<1], minSt[nx<<1|1]), max(maxSt[nx<<1], maxSt[nx<<1|1]));
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", a+i);
	memset(lazy, -1, sizeof lazy);
	build();
	while (m--) {
		int t, l, r, x;
		scanf("%d %d %d", &t, &l, &r);
		if (t == 1) printf("%lld\n", qry(l, r));
		if (t == 2) {
			scanf("%d", &x);
			updMod(l, r, x);
		}		
		if (t == 3) {
			upd(l, r);
		}
	}
	return 0;
}
