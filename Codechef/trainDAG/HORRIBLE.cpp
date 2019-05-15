#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
long long st[maxN<<2];
long long lazy[maxN<<2];
int T, N, M;

void upd(int nx, int l, int r, long long v) {
	st[nx] += v*(r-l+1);
	lazy[nx] += v;
}

void push(int nx, int l, int r) {
	if (lazy[nx]) {
		int mid = (l+r)/2;
		upd(nx<<1, l, mid, lazy[nx]);
		upd(nx<<1|1, mid+1, r, lazy[nx]);
		lazy[nx] = 0;
	}
}

void update(int ll, int rr, int v, int nx=1, int l=1, int r=N) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		upd(nx, l, r, v);
		return;
	}
	int mid = (l+r)/2;
	push(nx, l, r);
	update(ll, rr, v, nx<<1, l, mid);
	update(ll, rr, v, nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1];
}

long long qry(int ll, int rr, int nx=1, int l=1, int r=N) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	push(nx, l, r);
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(st, 0, sizeof st);
		memset(lazy, 0, sizeof lazy);
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= M; ++i) {
			int t, l, r, v;
			scanf("%d %d %d", &t, &l, &r);
			if (t) {	
				printf("%lld\n", qry(l, r));
			} else {
				scanf("%d", &v);
				update(l, r, v);
			}
		}
	}
	return 0;
}
