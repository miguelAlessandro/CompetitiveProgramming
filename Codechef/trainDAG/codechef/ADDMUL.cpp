#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;
struct Node {
	int x, y;
} st[maxN<<2], lazy[maxN<<2];
int a[maxN];
int n, q;

int add(int a, int b) {
	return (a+b)%mod;
}

int mul(long long a, long long b) {
	return a*b%mod;
}

Node merge(Node p, Node q) {
	return {
		add(p.x, q.x),
		add(p.y, q.y)
	};
}

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {
		st[nx] = {a[r], 0};		
		lazy[nx] = {1, 0};
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
	lazy[nx] = {1, 0};
}

void updNode(int nx, int l, int r, int a, int b) {
	st[nx].x = mul(st[nx].x, a);
	st[nx].y = mul(st[nx].y, a);
	st[nx].y = add(st[nx].y, mul(b, r - l + 1));
	lazy[nx].x = mul(lazy[nx].x, a);
	lazy[nx].y = mul(lazy[nx].y, a);
	lazy[nx].y = add(lazy[nx].y, b);
}

void push(int nx, int l, int r) {
	int mid = (l+r)/2;
	updNode(nx<<1, l, mid, lazy[nx].x, lazy[nx].y);
	updNode(nx<<1|1, mid+1, r, lazy[nx].x, lazy[nx].y);
	lazy[nx] = {1, 0};
}

void upd(int ll, int rr, int a, int b, int nx=1, int l=1, int r=n) {
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

int qry(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return add(st[nx].x, st[nx].y);	
	int mid = (l+r)/2;
	push(nx, l, r);
	return add(
		qry(ll, rr, nx<<1, l, mid), 
		qry(ll, rr, nx<<1|1, mid+1, r)
	);
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", a+i);
	build();
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			upd(x, y, 1, v);
		}
		if (t == 2) {
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			upd(x, y, v, 0);	
		}
		if (t == 3) {
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			upd(x, y, 0, v);
		}	
		if (t == 4) {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%d\n", qry(x, y));
		}
	}
	return 0;
}
