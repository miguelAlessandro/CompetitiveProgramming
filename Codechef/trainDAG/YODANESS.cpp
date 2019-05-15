#include <bits/stdc++.h>
using namespace std;
int t, n;
const int maxN = 3e4;
int st[maxN << 2];

void upd(int pos, int v, int nx=1, int l=0, int r=n-1) {
	if (pos < l or r < pos) return;
	if (l == r) {
		st[nx] = v;
		return;
	}
	int mid = (l+r)/2;
	upd(pos, v, nx<<1, l, mid);
	upd(pos, v, nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1];
}

int qry(int ll, int rr, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		map<string, int> id;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			id[s] = i;
		}
		memset(st, 0, sizeof st);
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			int pos = id[s];
			ans += qry(pos, n-1);
			upd(pos, 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
