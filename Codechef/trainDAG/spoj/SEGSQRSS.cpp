#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
struct Node {
	long long a, b;
} lazy[maxN<<2], st[maxN<<2];
int t, n, q;
long long a[maxN];

Node merge(Node p, Node q) {
	return {
		p.a + q.a,
		p.b + q.b
	};
}

void build(int nx=1, int l=1, int r=n) {
	lazy[nx] = {1ll, 0ll};
	if (l == r) {
		st[nx] = {a[r] * a[r], a[r]};
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]); 
}

void updNode(int nx, int l, int r, long long a, long long b) {
	st[nx].a = st[nx].a * a;
	st[nx].b = st[nx].b * a;
	st[nx].a = st[nx].a + 2*b*st[nx].b + b*b*(r-l+1);
	st[nx].b = st[nx].b + b*(r-l+1);
}

void push(int nx, int l, int r) {
	int mid = (l+r)/2;
	updNode(nx<<1, l, mid, lazy[nx].a, lazy[nx].b);
	updNode(nx<<1|1, mid+1, r, lazy[nx].a, lazy[nx].b);
	lazy[nx] = {1, 0};
}

void upd(int ll, int rr, long long a, long long b, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		updNode(nx, l, r, a, b);
		return;
	}
	int mid = (l+r)/2;
	push(nx, l, r);
	upd(ll, rr, a, b, nx<<1, l, mid);
	upd(ll, rr, a, b, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

long long qry(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx].a;
	int mid = (l+r)/2;
	push(nx, l, r);
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}

int main() {
	scanf("%d", &t);
	int nc=1;
	while (t--) {
		printf("Case %d:\n", nc++);
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; ++i) scanf("%lld", a+i);
		build();
		while (q--) {
			int t, l, r, x;
			scanf("%d %d %d", &t, &l, &r);
			if (t==2) printf("%lld\n", qry(l, r));
			else if (t==1) {
				scanf("%d", &x);
				upd(l, r, 1, x);
			} else {
				scanf("%d", &x);
				upd(l, r, 0, x);
			}
		}
	}
	return 0;
}
