#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e4 + 10;
int st[maxN<<6], L[maxN<<6], R[maxN<<6];
int a[maxN], root[maxN];
int n, q, t;
int elems;
map<int, int> id;

int make() {
	return elems++;
}

void build(int nx, int l=0, int r=t) {
	if (l == r) return;
	int mid = (l+r)/2;	
	build(L[nx]=make(), l, mid);
	build(R[nx]=make(), mid+1, r);
}

void upd(int last, int nx, int pos, int v, int l=0, int r=t) {
	if (pos < l or r < pos) return;
	if (l == r) {
		st[nx] = st[last] + v;
		return;
	}
	int mid = (l+r)/2;
	L[nx] = L[last];
	R[nx] = R[last];
	if (pos <= mid) L[nx] = make();
	else R[nx] = make();
	upd(L[last], L[nx], pos, v, l, mid);
	upd(R[last], R[nx], pos, v, mid+1, r);
	st[nx] = st[L[nx]] + st[R[nx]];
}

int qry(int nl, int nr, int ll, int rr, int l=0, int r=t) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nr] - st[nl];
	int mid = (l+r)/2;
	return qry(L[nl], L[nr], ll, rr, l, mid) + qry(R[nl], R[nr], ll, rr, mid+1, r);
}

void in(int &x) {
	x = 0; 	
	register char c = getchar();
	while (c < '0') c = getchar();
	while (c >= '0') {
		x = (x<<3) + (x<<1) + c - '0';
		c = getchar();
	}
}

void write(int n) {
	if (n == 0) {
		puts("0");
		return;
	}	
	register char t[10];
	int m = 0;
	while (n > 0) {
		t[m++] = n%10 + '0';
		n /= 10;
	}
	for (int i = m-1; i >= 0; --i) putchar(t[i]);
	puts("");
}

int main() {
	in(n);
	int mx = 0, mn = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		in(a[i]);
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
		id[a[i]];
	}
	for (auto& e : id) e.second = t++;
	build(root[0] = make());
	for (int i = 1; i <= n; ++i) {
		upd(root[i-1], root[i] = make(), id[a[i]], 1);
	}
	in(q);
	while (q--) {
		int l, r, k;
		in(l); in(r); in(k);
		if (mx <= k) puts("0");
		else if (k < mn) write(r-l+1);
		else {
			write(qry(root[l-1], root[r], (id.lower_bound(k+1)->second), t));
		}
	}
	return 0;
}
