#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int st[maxN<<2];
int a[maxN], b[maxN], nxt[maxN], bck[maxN];
int n, q;

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {
		st[nx] = b[r];
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = max(st[nx<<1], st[nx<<1|1]);
}

int qry(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (r < ll or rr < l) return INT_MIN;	
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;	
	return max(
		qry(ll, rr, nx<<1, l, mid),
		qry(ll, rr, nx<<1|1, mid+1, r)
	);
}


int main() {
	while (scanf("%d %d", &n, &q) == 2) {
		for (int i = 1; i <= n; ++i)	{
			scanf("%d", a+i);
		}	
		b[1] = 1;
		for (int i = 2; i <= n; ++i) {
			b[i] = a[i] == a[i-1] ? b[i-1] + 1 : 1;
		}
		bck[1] = 1;
		for (int i = 2; i <= n; ++i) {
			bck[i] = a[i] == a[i-1] ? bck[i] = bck[i-1] : i;
		}
		nxt[n] = n;
		for (int i = n-1; i >= 1; --i) {
			nxt[i] = a[i] == a[i+1] ? nxt[i] = nxt[i+1] : i;
		}
		build();
		while (q--) {
			int l, r;
			scanf("%d %d", &l, &r);
			if (a[l] == a[r]) printf("%d\n", r-l+1);
			else {
				int ll = nxt[l] + 1;
				int rr = bck[r] - 1;
				int ans = max(ll - l, r - rr);
				ans = max(ans, qry(ll, rr));
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
