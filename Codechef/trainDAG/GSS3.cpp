#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e4 + 10;
struct Node {
	int maxSum;
	int sum;
	int prefSum;
	int suffSum;
} st[maxN<<2];
const int inf = 2e9;
const Node id = {inf, inf, inf, inf};
int N, M;
int A[maxN];

Node merge(Node p, Node q) {
	if (p.sum == inf) return q;
	if (q.sum == inf) return p;
	return {
		max(max(p.maxSum, q.maxSum), p.suffSum + q.prefSum),
		p.sum + q.sum,
		max(p.prefSum, p.sum + q.prefSum),
		max(q.suffSum, q.sum + p.suffSum)
	};
}

void build(int nx=1, int l=1, int r=N) {
	if (l == r) {
		st[nx] = {A[r], A[r], A[r], A[r]};
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
		st[nx] = {v, v, v, v};
		return;
	}
	int mid = (l+r)/2;
	upd(pos, v, nx<<1, l, mid);
	upd(pos, v, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

Node qry(int ll, int rr, int nx=1, int l=1, int r=N) {
	if (rr < l or r < ll) return id;
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
	scanf("%d", &M);
	for (int i = 1; i <= M; ++i) {
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if (t == 0) upd(x, y);	
		else printf("%d\n", qry(x, y).maxSum);
	}
	return 0;
}
