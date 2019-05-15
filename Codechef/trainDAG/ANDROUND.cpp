#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e4 + 10;
const int INF = INT_MAX;
int st[maxN<<2];
int a[maxN];
int n, k;

void build(int nx=1, int l=1, int r=n) {
	if (l == r) {
		st[nx] = a[r];
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);	
	st[nx] = st[nx<<1] & st[nx<<1|1];
}

int query(int ll, int rr, int nx=1, int l=1, int r=n) {
	if (rr < l or r < ll) return (1<<30)-1;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	return query(ll, rr, nx<<1, l, mid) & query(ll, rr, nx<<1|1, mid+1, r);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		build();
		for (int i = 1; i <= n; ++i) {
			if (2*k + 1 >= n) cout << st[1] << " ";
			else {
				if (i - k >= 1 and i + k <= n) cout << query(i-k, i+k) << " ";
				else if (i - k >= 1) cout << (query(i-k, n) & query(1, i+k-n)) << " ";
				else cout << (query(1, i + k) & query(i - k + n, n)) << " ";		
			}
		}	
		cout << endl;
	}
	return 0;
}
