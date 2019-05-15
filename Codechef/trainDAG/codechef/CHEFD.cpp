#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int a[maxN], st[maxN<<2][3], lazy[maxN<<2][3];
bool term[maxN<<2];
int p[] = {2, 3, 5};
int rev[10] = {0, 0, 0, 1, 0, 2};
int n, m;

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {
		term[nx] = 1;
		for (int i = 0; i < 3; ++i) {
			while (a[r] % p[i] == 0) {
				st[nx][i] += 1;
				a[r] /= p[i];
			}
		}
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
}

void updNode(int k, int nx, int v) {
	if (term[nx]) st[nx][k] = max(0, st[nx][k] - v);
	else lazy[nx][k] += v;
}

void push(int k, int nx) {
	if (lazy[nx][k]) {
		updNode(k, nx<<1, lazy[nx][k]);
		updNode(k, nx<<1|1, lazy[nx][k]);
		lazy[nx][k] = 0;
	}
}

void upd(int k, int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		updNode(k, nx, 1);
		return;
	}
	int mid = (l+r)/2;
	push(k, nx);
	upd(k, ll, rr, nx<<1, l, mid);
	upd(k, ll, rr, nx<<1|1, mid+1, r);
}

void change(int pos, int nx=1, int l=1, int r=n) {
	if (pos < l or r < pos) return;
	if (l == r) {
		for (int i = 0; i < 3; ++i) {
			st[nx][i] = 0;
			while (a[r] % p[i] == 0) {
				st[nx][i] += 1;
				a[r] /= p[i];
			}
		}
		return;
	}
	int mid = (l+r)/2;
	for (int i = 0; i < 3; ++i) push(i, nx);
	change(pos, nx<<1, l, mid);
	change(pos, nx<<1|1, mid+1, r);
}

int qry(int pos, int nx=1, int l=1, int r=n) {
	if (pos < l or r < pos) return 0;
	if (l == r) {
		int num = a[r];
		for (int i = 0; i < 3; ++i) {
			for (int k = 0; k < st[nx][i]; ++k) num *= p[i];
		}
		return num;
	}
	int mid = (l+r)/2;
	for (int i = 0; i < 3; ++i) push(i, nx);
	return qry(pos, nx<<1, l, mid) + qry(pos, nx<<1|1, mid+1, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	build();
	scanf("%d", &m);
	while (m--) {
		int t, l, r, d;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d %d", &l, &r, &d);
			upd(rev[d], l, r);
		} else {
			scanf("%d %d", &l, &d);
			a[l] = d;
			change(l);
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", qry(i));
	} puts("");
	return 0;
}
