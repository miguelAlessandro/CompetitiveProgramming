#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int st[maxN<<2][26];
int lazy[maxN<<2][26];
int n, m;
char s[maxN];

void build(int nx=1, int l=0, int r=n-1) {
	if (l == r) {
		for (int k = 0; k < 26; ++k) st[nx][k] = s[r] == 'a' + k;
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	for (int k = 0; k < 26; ++k) st[nx][k] = st[nx<<1][k] + st[nx<<1|1][k];
}

void updNode(int k, int nx, int l, int r, int v) {
	st[nx][k] = v * (r - l + 1); 
	lazy[nx][k] = v;
}

void push(int k, int nx, int l, int r) {
	if (~lazy[nx][k]) {
		int mid = (l+r)/2;
		updNode(k, nx<<1, l, mid, lazy[nx][k]);
		updNode(k, nx<<1|1, mid+1, r, lazy[nx][k]);
		lazy[nx][k] = -1;
 	}
}

void upd(int k, int ll, int rr, int val, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		updNode(k, nx, l, r, val);
		return;
	}
	int mid = (l+r)/2;
	push(k, nx, l, r);
	upd(k, ll, rr, val, nx<<1, l, mid);
	upd(k, ll, rr, val, nx<<1|1, mid+1, r);
	st[nx][k] = st[nx<<1][k] + st[nx<<1|1][k];
}

int qry(int k, int ll, int rr, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx][k];
	int mid = (l+r)/2;
	push(k, nx, l, r);
	return qry(k, ll, rr, nx<<1, l, mid) + qry(k, ll, rr, nx<<1|1, mid+1, r);
}

int cnt[30];
int main() {
	scanf("%d %d\n%s", &n, &m, s);
	memset(lazy, -1, sizeof lazy);
	build();
	while (m--) {
		int l, r, p;
		scanf("%d %d %d", &l, &r, &p);
		l -= 1; r -= 1;
		for (int i = 0; i < 26; ++i) {
			cnt[i] = qry(i, l, r);
			upd(i, l, r, 0);
		}
		if (p == 0) {
			for (int t = 25; t >= 0; --t) {
				if (cnt[t] == 0) continue;
				upd(t, l, l + cnt[t] - 1, 1);
				l += cnt[t];
			}
		} else {
			for (int t = 0; t < 26; ++t) {
				if (cnt[t] == 0) continue;
				upd(t, l, l + cnt[t] - 1, 1);
				l += cnt[t];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		int t = 0;
		for (; t < 26; ++t) {
			if (qry(t, i, i) == 1) break;
		}
		putchar(t + 'a');
	}
	return 0;
}
