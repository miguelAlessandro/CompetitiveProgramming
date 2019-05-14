#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int maxN = 1e5 + 10;
int st[maxN<<2][3];
int lazy[maxN<<2];
int n, q;

void build(int nx=1, int l=0, int r=n-1) {
	if (l == r) {
		st[nx][0] = 1;
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	for (int i = 0; i < 3; ++i) st[nx][i] = st[nx<<1][i] + st[nx<<1|1][i];
}

void updNode(int nx, int v) {
	int var[3];
	for (int i = 0; i < 3; ++i) var[i] = st[nx][(i+v)%3];
	for (int i = 0; i < 3; ++i) st[nx][i] = var[i];
	lazy[nx] = (lazy[nx] + v)%3;
}

void push(int nx) {
	if (lazy[nx]) {
		updNode(nx<<1, lazy[nx]);
		updNode(nx<<1|1, lazy[nx]);
		lazy[nx] = 0;
	}
}

void upd(int ll, int rr, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		updNode(nx, 1);
		return;
	}
	int mid = (l+r)/2;
	push(nx);
	upd(ll, rr, nx<<1, l, mid);
	upd(ll, rr, nx<<1|1, mid+1, r);
	for (int i = 0; i < 3; ++i) st[nx][i] = st[nx<<1][i] + st[nx<<1|1][i];
}

int qry(int ll, int rr, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx][0];
	int mid = (l+r)/2;
	push(nx);
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}


int main() {
	scanf("%d %d", &n, &q);
	build();
	while (q--) {
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		if (t) printf("%d\n", qry(a, b));
		else upd(a, b);
	}
	return 0;
}
