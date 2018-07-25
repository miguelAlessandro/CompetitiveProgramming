/**
 *	GSS1
 *	@overview maximum subarray problem for range.
 *	- consider divide and conquer solution.
 *	- then, my answer = max between {
 *		answer right child
 *		answer left child
 *		maximum prefix in right child + maximum sufix in left child
 *	}
 *	- maintaining suffix and prefix is easy while also 
 *	maintaining the sum.
 */


#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5;
struct node {
	int max, sum;
	int preff, suff;
} st[MAX_N<<2];
int n, q;
int a[MAX_N];
const int inf = 1e9;
node nil = {-inf, 0, -inf, -inf};
node merge(node p, node q) {
	node ans;
	ans.sum = p.sum + q.sum;
	ans.preff = max(p.preff, p.sum + q.preff);
	ans.suff = max(q.suff, q.sum + p.suff);
	ans.max = max(max(p.max, q.max), p.suff + q.preff);
	return ans;
}

void build (int nx = 1, int l = 1, int r = n) {
	if (l == r) {
		st[nx] = {a[r], a[r], a[r], a[r]};
		return;
	}
	int mid = (l+r)/2;
	build(2*nx, l, mid);
	build(2*nx+1, mid+1, r);
	st[nx] = merge(st[2*nx], st[2*nx+1]);
}

node query (int a, int b, int nx = 1, int l = 1, int r = n) {
	if (a > r or b < l) return nil;
	if (a <= l and r <= b) return st[nx];
	int mid = (l+r)/2;
	return merge(query(a, b, 2*nx, l, mid), query(a, b, 2*nx+1, mid+1, r));
}

int main () {

	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", a+i);

	build();
	scanf ("%d", &q);
	while (q--) {
		int l, r;
		scanf ("%d %d", &l, &r);
		printf ("%d\n", query(l, r).max);
	}

	return 0;
}
