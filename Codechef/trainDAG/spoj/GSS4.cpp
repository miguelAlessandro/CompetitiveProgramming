#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e5 + 10;
const long long inf = 2e18;
struct Node {
	long long sum;
	long long max, min;
	long long lazy;
} st[maxN<<2];
int N, M;
long long A[maxN];

Node merge(Node p, Node q) {
	return {
		p.sum + q.sum,
		max(p.max, q.max),
		min(p.min, q.min),
		0ll
	};
}

void build(int nx=1, int l=1, int r=N) {
	if (l == r) {
		st[nx] = {A[r], A[r], A[r], 0};
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

void upd(int nx, int l, int r, long long val) {
	st[nx] = {val * (r - l + 1), val, val, val};
}

void push(int nx, int l, int r) {
	if (st[nx].lazy) {
		int mid = (l+r)/2;
		upd(nx<<1, l, mid, st[nx].lazy);		
		upd(nx<<1|1, mid+1, r, st[nx].lazy);
		st[nx].lazy = 0;
	}
}

long long bisqrt(long long x) {
	long long lo = 0, hi = 1e9;
	while (lo < hi) {
		long long mid = lo + (hi-lo+1)/2;
		if (mid * mid <= x) lo = mid;
		else hi = mid-1;	
	}
	return lo;
}

void upd(int ll, int rr, int nx=1, int l=1, int r=N) {
	if (rr<l or r<ll or (st[nx].max <= 1 and st[nx].min >= 0)) return;
	if (ll <= l and r <= rr and st[nx].max == st[nx].min) {
		long long q = bisqrt(abs(st[nx].max));
		upd(nx, l, r, q);
		return;
	}
	int mid = (l+r)/2;
	push(nx, l, r);
	upd(ll, rr, nx<<1, l, mid);
	upd(ll, rr, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

Node qry(int ll, int rr, int nx=1, int l=1, int r=N) {
	if (rr<l or r<ll) return {0ll, -inf, inf, 0ll};
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	push(nx, l, r);
	return merge(
		qry(ll, rr, nx<<1, l, mid),
		qry(ll, rr, nx<<1|1, mid+1, r)
	);
}

int main() {
	int nc=1;
	while (scanf("%d", &N) == 1) {
		printf("Case #%d:\n", nc++);
		for (int i = 1; i <= N; ++i) {
			scanf("%lld", A+i);
		}
		build();
		scanf("%d", &M);
		for (int i = 1; i <= M; ++i) {
			int t;
			long long x, y;
			scanf("%d %lld %lld", &t, &x, &y);
			if (x > y) swap(x, y);
			if (t == 0) upd(x, y);
			else printf("%lld\n", qry(x, y).sum);
		}
		puts("");
	}
	return 0;
}
