#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
int t, n;
int a[maxN], st[maxN<<2], res[maxN];

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {st[nx]=1; return;}
	int mid = (l+r)/2;
	build(nx<<1, l, mid); build(nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1];
}

int kth(int pos, int nx=1, int l=1, int r=n) {
	if (l == r) return r;
	int mid = (l+r)/2;
	if (st[nx<<1] >= pos) return kth(pos, nx<<1, l, mid);
	return kth(pos-st[nx<<1], nx<<1|1, mid+1, r);
}

void upd(int pos, int v, int nx=1, int l=1, int r=n) {
	if (pos < l or r < pos) return;
	if (l == r) {st[nx] += v; return;}
	int mid = (l+r)/2;
	upd(pos, v, nx<<1, l, mid);
	upd(pos, v, nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", a+i);
		build();
		for (int i = n; i >= 1; --i) {
			res[i] = kth(i - a[i]);
			upd(res[i], -1);
		}
		for (int i = 1; i <= n; ++i) printf("%d ", res[i]); puts("");
	}
	return 0;
}
