#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e4 + 10;
int t[maxN];
int st[maxN<<2];
pair<int, int> b[maxN];
long long res[maxN];
int n;

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {st[nx] = 1; return;}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1];
}

void upd(int ll, int v, int nx=1, int l=1, int r=n) {
	if (ll < l or r < ll) return;
	if (ll <= l and r <= ll) {
		st[nx] += v;
		return;
	}
	int mid = (l+r)/2;
	upd(ll, v, nx<<1, l, mid);
	upd(ll, v, nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1];
} 

int qry(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}

int main() {
	while(scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", t+i);
			b[i] = {t[i], i};
		}
		build();
		sort(b+1, b+n+1);
		long long ans = 0;
		int cnt = 0, last = 0;
		for (int i = 1; i <= n;) {	
			int k = b[i].first;
			ans += (n - cnt)*1ll*(k - 1 - last);
			while (i <= n and b[i].first == k) {
				res[b[i].second] = ans + qry(1, b[i].second);
				ans += 1;
				upd(b[i].second, -1);
				cnt += 1;
				i += 1;
			}
			ans += qry(1, n);
			last = k;
		}
		for (int i = 1; i <= n; ++i) {
			printf("%lld ", res[i]);
		} puts("");
	}
	return 0;	
}
