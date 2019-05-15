#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
struct Node {
	int m1, m2;
} st[maxN<<2];
int A[maxN];
int N, Q;

Node merge(Node p, Node q) {
	return {
		max(p.m1, q.m1),
		p.m1 > q.m1 ? max(p.m2, q.m1) : max(p.m1, q.m2) 
	};
}

void build(int nx=1, int l=1, int r=N) {
	if (l == r) {
		st[nx] = {A[r], 0};
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

void upd(int pos, int v, int nx=1, int l=1, int r=N) {
	if (pos < l or r < pos) return;
	if (l == r) {
		st[nx] = {v, 0};
		return;
	}
	int mid = (l+r)/2;
	upd(pos, v, nx<<1, l, mid);
	upd(pos, v, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

Node qry(int ll, int rr, int nx=1, int l=1, int r=N) {
	if (rr < l or r < ll) return {0, 0};	
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	return merge(
		qry(ll, rr, nx<<1, l, mid),
		qry(ll, rr, nx<<1|1, mid+1, r)
	);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", A+i);
	}
	build();
	scanf("%d\n", &Q);
	for (int i = 1; i <= Q; ++i) {
		char t;
		int x, y;
		scanf("%c %d %d\n", &t, &x, &y);
		if (t == 'Q') {
			Node q = qry(x, y);
			printf("%d\n", q.m1 + q.m2);
		} else upd(x, y);
	}
	return 0;	
}
