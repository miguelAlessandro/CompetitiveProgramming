#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e4 + 10;

struct Node {
	int maxSum;
	int sum;
	int maxPref;
	int maxSuff;
	Node operator +(Node p) {
		return {
			max({maxSum, p.maxSum, maxSuff + p.maxPref}),
			sum + p.sum,
			max(maxPref, sum + p.maxPref),
			max(maxSuff + p.sum, p.maxSuff)
		};
	}
} st[maxN<<2];
int n, m;
int A[maxN];

void bld(int nx=1, int l=1, int r=n) {
	if (l == r) {
		st[nx] = {A[r], A[r], A[r], A[r]};
		return;
	}
	int mid = (l+r)>>1;
	bld(nx<<1, l, mid);
	bld(nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1];
}

const int inf = 1e9;
Node qry(int a, int b, int nx=1, int l=1, int r=n) {
	if (a > r or b < l) return {-inf, 0, -inf, -inf};
	if (a <= l and r <= b) return st[nx];
	int mid = (l+r)>>1;
	return qry(a, b, nx<<1, l, mid) + qry(a, b, nx<<1|1, mid+1, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
	}
	bld();
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {	
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", qry(l, r).maxSum);
	}
	return 0;
}
