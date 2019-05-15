#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e4 + 10;
const int inf = 2e9;
int A[maxN];
int t, N, M;
struct Node {
	int maxSum;
	int sum;
	int pref, suff;
} st[maxN<<2];
const Node id = {inf, inf, inf, inf};

Node merge(Node p, Node q) {
	if (p.maxSum == inf) return q;
	if (q.maxSum == inf) return p;
	return {
		max(max(p.maxSum, q.maxSum), p.suff + q.pref),
		p.sum + q.sum,
		max(p.pref, p.sum + q.pref),
		max(q.suff, q.sum + p.suff)
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

Node qry(int ll, int rr, int nx=1, int l=1, int r=N) {
	if (r < ll or rr < l) return id;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	return merge(
		qry(ll, rr, nx<<1, l, mid),	
		qry(ll, rr, nx<<1|1, mid+1, r)
	);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", A+i);
		}
		build();
		scanf("%d", &M);
		for (int i = 1; i <= M; ++i) {
			int x_1, x_2, y_1, y_2;
			scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
			int ans = -inf;
			if (y_1 < x_2) {
				Node a = qry(x_1, y_1);				
				Node b = qry(x_2, y_2);
				if (y_1+1 == x_2) ans = max(ans, a.suff + b.pref);
				else {
					Node c = qry(y_1+1, x_2-1);
					ans = max(ans, a.suff + c.sum + b.pref);
				}
			} else { 
				if (x_1 < x_2) {
					Node a = qry(x_1, x_2-1);
					Node b = qry(x_2, y_2);
					ans = max(ans, a.suff + b.pref);
				}
				if (y_1 < y_2) {	
					Node a = qry(x_2, y_1);
					Node b = qry(y_1+1, y_2);
					ans = max(ans, a.suff + b.pref);
				}
				ans = max(ans, qry(x_2, y_1).maxSum);
			}
			printf("%d\n", ans);
		}			
	}
	return 0;
}
