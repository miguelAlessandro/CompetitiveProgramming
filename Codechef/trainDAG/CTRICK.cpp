#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e4 + 10;
int t, n;
int a[maxN];
int st[maxN<<2];

void build(int nx=1, int l=0, int r=n) {
	if (l == r) {
		st[nx] = 1;
		return;
	}	
	int mid = (l + r) / 2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1];
}

void upd(int pos, int nx=1, int l=0, int r=n) {
	if (pos < l or r < pos) return;
	if (l == r) {
		st[nx] = 0;
		return;
	}
	int mid = (l+r)/2;
	upd(pos, nx<<1, l, mid);
	upd(pos, nx<<1|1, mid+1, r);
	st[nx] = st[nx<<1] + st[nx<<1|1]; 
}

int qry(int ll, int rr, int nx=1, int l=0, int r=n) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}

pair<int, int> kth(int ll, int rr, int k, int nx=1, int l=0, int r=n) {
	if (rr < l or r < ll) return {-1, 0};
	if (ll <= l and r <= rr and st[nx] < k) return {-1, st[nx]};
	if (l == r) {
		if (st[nx] == 1) return {r, 1};
		return {-1, 0};
	}
	int mid = (l+r)/2;
	auto L = kth(ll, rr, k, nx<<1, l, mid);
	if (L.first == -1) return kth(ll, rr, k - L.second, nx<<1|1, mid+1, r);
	return L;
}

void print(int k) {
	for (int i = 1; i <= n-k+1; ++i) {
		cout << kth(0, n-1, i).first+1 << " ";
	}
	cout << endl;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		build(); 
		int pos = 0;
		for (int i = 1; i <= n; ++i) {
			pos = (pos + i) % (n - i + 1) + 1;
			a[pos = kth(0, n-1, pos).first % n] = i;
			upd(pos);
			pos = qry(0, pos);
		}
		for (int i = 0; i < n; ++i) {
			printf("%d ", a[i]);
		} puts("");
	}

	return 0;
}
