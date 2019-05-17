#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
struct Node {
	int mi, ma;
} st[maxN<<2];
int lazy[maxN<<2];
pair<int, int> a[maxN];
int f[maxN], rev[maxN];
int n, q;

Node merge(Node p, Node q) {
	return {
		min(p.mi, q.mi),
		max(p.ma, q.ma)
	};
}

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {
		st[nx] = {a[r].first, a[r].first};
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

void updNode(int nx, int v) {
	st[nx].mi += v; st[nx].ma += v;
	lazy[nx] += v;
}

void push(int nx) {
	if (lazy[nx]) {
		updNode(nx<<1, lazy[nx]);
		updNode(nx<<1|1, lazy[nx]);
		lazy[nx] = 0;
	}
}

void upd(int X, int v, int nx=1, int l=1, int r=n) {
	if (st[nx].ma < X) return;
	if (st[nx].mi >= X) {
		updNode(nx, v);
		return;
	}
	int mid =(l+r)/2;
	push(nx);
	upd(X, v, nx<<1, l, mid);
	upd(X, v, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

void upd2(int pos, int v, int nx=1, int l=1, int r=n) {
	if (r < pos or pos < l) return;
	if (l == r) {
		updNode(nx, v);
		return;
	}
	int mid = (l+r)/2;
	push(nx);
	upd2(pos, v, nx<<1, l, mid);
	upd2(pos, v, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

int qry(int X, int nx=1, int l=1, int r=n) {
	if (st[nx].ma < X) return 0;
	if (st[nx].mi >= X) return r - l + 1;	
	int mid = (l+r)/2;
	push(nx);
	return qry(X, nx<<1, l, mid) + qry(X, nx<<1|1, mid+1, r);
}

int qry2(int pos, int nx=1, int l=1, int r=n) {
	if (r < pos or pos < l) return -1;
	if (l == r) return st[nx].ma;
	int mid = (l+r)/2;
	push(nx);
	return max(qry2(pos, nx<<1, l, mid), qry2(pos, nx<<1|1, mid+1, r));
}

int upper(int X, int nx=1, int l=1, int r=n) {
	if (st[nx].ma < X) return -1;
	if (st[nx].mi > X) return -1;	
	if (st[nx].mi == st[nx].ma) return r;
	int mid = (l+r)/2;
	push(nx);
	return max(upper(X, nx<<1, l, mid), upper(X, nx<<1|1, mid+1, r));
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(&a[1], &a[n]+1);
	for (int i = 1; i <= n; ++i) {
		f[a[i].second] = i;
		rev[i] = a[i].second;
	}
	build();
	for (int i = 1; i <= q; ++i) {
		int t, x;
		scanf("%d %d", &t, &x);
		if (t == 1) {
			int fx = f[x];
			int y = qry2(fx);
			int p = upper(y);
			int q = rev[p];
			if (x != q) {
				f[x] = p;
				f[q] = fx;
				rev[fx] = q;
				rev[p] = x;
			}
			upd2(f[x], 1);
		} 
		if (t == 2) {
			printf("%d\n", qry(x));
		}
		if (t == 3) {
			upd(x, -1);
		}
	}
	return 0;
}
