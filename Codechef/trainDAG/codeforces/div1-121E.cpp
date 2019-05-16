#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
typedef pair<int, int> ii;
ii st[maxN<<2][1<<5];
int lazy[maxN<<2];
int lucky[1<<5], a[maxN];
int nl = 0;
int n, m;

ii merge(ii p, ii q) {
	if (p.first > q.first) return p;
	if (q.first > p.first) return q;
	return {p.first, p.second + q.second};
}

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {
		for (int k = 0; k < nl; ++k) {
			st[nx][k] = {a[r], 1};
		}
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	for (int k = 0; k < nl; ++k) {
		st[nx][k] = merge(st[nx<<1][k], st[nx<<1|1][k]);
	}
}

void updNode(int nx, int d) {
	for (int k = 0; k < nl; ++k) st[nx][k].first += d;
	lazy[nx] += d;
}

void push(int nx) {
	if (lazy[nx]) {
		updNode(nx<<1, lazy[nx]);
		updNode(nx<<1|1, lazy[nx]);
		lazy[nx] = 0;
	}
}

void erase(int k, int nx=1, int l=1, int r=n) {
	if (st[nx][k].first <= lucky[k]) return;
	if (l == r) {
		st[nx][k] = {-100000, 1}; 
		return;
	}
	int mid = (l+r)/2;
	push(nx);
	erase(k, nx<<1, l, mid);
	erase(k, nx<<1|1, mid+1, r);
	st[nx][k] = merge(st[nx<<1][k], st[nx<<1|1][k]);
}

void upd(int ll, int rr, int d, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		updNode(nx, d);
		return;
	}
	int mid = (l+r)/2;
	push(nx);
	upd(ll, rr, d, nx<<1, l, mid);
	upd(ll, rr, d, nx<<1|1, mid+1, r);
	for (int k = 0; k < nl; ++k) {
		st[nx][k] = merge(st[nx<<1][k], st[nx<<1|1][k]);
	}
}

int qry(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) {
		int ans = 0;
		for (int k = 0; k < nl; ++k) {
			if (st[nx][k].first == lucky[k]) ans += st[nx][k].second;
		}
		return ans;
	}
	int mid = (l+r)/2;
	push(nx);
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}

int main() {
	for (int len = 1; len <= 4; ++len) {
		for (int mask = 0; mask < 1<<len; ++mask) {
			int num = 0;
			for (int i = 0; i < len; ++i) {
				num = 10 * num + (((mask>>i)&1)?4:7);
			}
			lucky[nl++] = num;
		}
	}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	getchar();
	build();
	char s[30];
	while (m--) {
		scanf("%s", s);
		int l, r, d;
		if (s[0] == 'c') {
			scanf("%d %d\n", &l, &r);
			for (int k = 0; k < nl; ++k) erase(k);
			printf("%d\n", qry(l, r));
		} else {
			scanf("%d %d %d\n", &l, &r, &d);
			upd(l, r, d);
		}	
	}
	return 0;
}
