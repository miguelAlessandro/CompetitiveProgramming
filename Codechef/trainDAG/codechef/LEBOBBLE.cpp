#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e4 + 10;
typedef pair<int, int> ii;
ii st[maxN<<2];
int a[maxN], p[maxN];
int val[maxN];
int t, n, m, d;

ii merge(ii p, ii q) {
	return {
		p.first + q.first,
		p.second + q.second
	};
}

void build(int nx=1, int l=1, int r=m) {
	if (l == r) {
		st[nx] = {0, 0};
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = {0, 0};
}

void upd(int pos, int p, int nx=1, int l=1, int r=m) {
	if (pos < l or r < pos) return;
	if (l == r) {
		st[nx].first += p;
		st[nx].second += 1;
		return;
	}
	int mid = (l+r)/2;
	upd(pos, p, nx<<1, l, mid);
	upd(pos, p, nx<<1|1, mid+1, r);
	st[nx] = merge(st[nx<<1], st[nx<<1|1]);
}

ii qry(int x, int nx=1, int l=1, int r=m) {
	if (val[r] <= x) return {0, 0};	
	if (val[l] > x) return st[nx];
	int mid = (l+r)/2;
	return merge(qry(x, nx<<1, l, mid), qry(x, nx<<1|1, mid+1, r));
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &d);
		map<int, int> D;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", a+i);
			D[a[i]];
		}
		m = 1;
		for (auto& e : D) {
			e.second = m++; 
			val[e.second] = e.first;
		} m--;
		build();
		for (int i = 1; i <= n; ++i) scanf("%d", p+i);
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			auto q1 = qry(a[i]);
			auto q2 = qry(a[i] - d);
			auto q3 = qry(a[i] + d);
			ans += (100 - p[i]) * (q2.first + 100 * q1.second - q1.first) + 
					p[i] * (q1.first + 100 * q3.second - q3.first);
			upd(D[a[i]], p[i]);
		}
		printf("%.4lf\n", ans / 10000.);
	}
	return 0;
}
