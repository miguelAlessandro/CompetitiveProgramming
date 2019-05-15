#include <bits/stdc++.h>
using namespace std;
const int mod = 1e4 + 7;
const int maxN = 1e5 + 10;
int n, m;

int add(int a, int b) {
	return (a+b)%mod;
}

int mul(int a, int b) {
	return a*b%mod;
}

struct Node {	
	int a, b, c;
	Node operator +(Node p) {
		return {
			add(a, p.a),
			add(b, p.b),
			add(c, p.c)
		};
	}
} st[maxN<<2], lazy[maxN<<2];

int sum2(int r) {
	return mul(mul(r, mul(add(r, 1), add(mul(2, r), 1))), (mod+1)/6);
}

int sum1(int r) {
	return mul(mul(r, add(r, 1)), (mod+1)/2);
}

int sum0(int r) {
	return r;
} 

void updNode(int nx, int l, int r, int a, int b, int c) {
	st[nx].a = add(st[nx].a, mul(a, add(sum2(r), mod - sum2(l-1))));
	st[nx].b = add(st[nx].b, mul(b, add(sum1(r), mod - sum1(l-1))));
	st[nx].c = add(st[nx].c, mul(c, add(sum0(r), mod - sum0(l-1))));
	lazy[nx].a = add(lazy[nx].a, a);
	lazy[nx].b = add(lazy[nx].b, b);
	lazy[nx].c = add(lazy[nx].c, c);
}

void push(int nx, int l, int r) {
	if (lazy[nx].a or lazy[nx].b or lazy[nx].c) {
		int mid = (l+r)/2;
		updNode(nx<<1, l, mid, lazy[nx].a, lazy[nx].b, lazy[nx].c);
		updNode(nx<<1|1, mid+1, r, lazy[nx].a, lazy[nx].b, lazy[nx].c);
		lazy[nx] = {0, 0, 0};
	}
}

void upd(int ll, int rr, int a, int b, int c, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		updNode(nx, l, r, a, b, c);
		return;
	}
	int mid = (l+r)/2;
	push(nx, l, r);
	upd(ll, rr, a, b, c, nx<<1, l, mid);
	upd(ll, rr, a, b, c, nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1];
}

Node qry(int ll, int rr, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return {0, 0, 0};
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	push(nx, l, r);
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}

int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int x_0, x_1, a, b, c;
			scanf("%d %d %d %d %d", &x_0, &x_1, &a, &b, &c);
			upd(x_0, x_1, a, b, c);
		} else {
			int x_0, x_1;
			scanf("%d %d", &x_0, &x_1);
			auto q = qry(x_0, x_1);
			printf("%d\n", add(q.a, add(q.b, q.c)));
		}
	}
	return 0;
}
