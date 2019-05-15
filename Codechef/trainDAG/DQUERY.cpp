#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e4 + 10;
int st[maxN<<6], L[maxN<<6], R[maxN<<6];
int n, q;
int a[maxN];
int elems;
int root[maxN];

int make() {return ++elems;}

void build(int nx, int l=0, int r=n) {
	if (l == r) return;
	int mid = (l+r)/2;
	build(L[nx] = make(), l, mid);
	build(R[nx] = make(), mid+1, r);
}

void upd(int last, int nx, int pos, int v, int l=0, int r=n) {
	if (pos < l or r < pos) return;
	if (l == r) {
		st[nx] = st[last] + v;
		return;
	}	
	L[nx] = L[last];
	R[nx] = R[last];
	int mid = (l+r)/2;
	if (pos <= mid) L[nx] = make();
	else R[nx] = make();
	upd(L[last], L[nx], pos, v, l, mid);
	upd(R[last], R[nx], pos, v, mid+1, r);
	st[nx] = st[L[nx]] + st[R[nx]];
}

int qry(int ll, int rr, int nx, int l=0, int r=n) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	int lq = qry(ll, rr, L[nx], l, mid);	
	int rq = qry(ll, rr, R[nx], mid+1, r);
	return lq+rq;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	map<int, int> last;
	build(root[0] = make());
	for (int i = 1; i <= n; ++i) {
		int troot = make();
		upd(root[i-1], troot, last[a[i]], -1);	
		upd(troot, root[i]=make(), i, 1);
		last[a[i]] = i;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", qry(l, r, root[r]));
	}
	return 0;
}
