#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int st[maxN<<2];
int t, n;
struct Node {
	int a, b, c;
} s[maxN];

void upd(int pos, int v, int nx=1, int l=1, int r=n) {
	if (pos < l or r < pos) return;
	if (l == r) {
		st[nx] = v;
		return;
	}
	int mid = (l+r)/2;
	upd(pos, v, nx<<1, l, mid);
	upd(pos, v, nx<<1|1, mid+1, r);
	st[nx] = max(st[nx<<1], st[nx<<1|1]);
}

int qry(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (r < ll or rr < l) return 0;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	return max(
		qry(ll, rr, nx<<1, l, mid),
		qry(ll, rr, nx<<1|1, mid+1, r)
	);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d", &s[i].a, &s[i].b, &s[i].c);
			s[i].a  = n - s[i].a + 1;
			s[i].b  = n - s[i].b + 1;
			s[i].c  = n - s[i].c + 1;
		}
		sort(s, s+n, [](Node p, Node q) {
			return p.a > q.a;
		});
		memset(st, 0, sizeof st);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i].b == n) {
				ans += 1;
				upd(s[i].b, s[i].c);
				continue;
			}
			int v = qry(s[i].b+1, n);
			if (v < s[i].c) ans += 1;
			upd(s[i].b, s[i].c);
		}
		printf("%d\n", ans);
	}
	return 0;
}
