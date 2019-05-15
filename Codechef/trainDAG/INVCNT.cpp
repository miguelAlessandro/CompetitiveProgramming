#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
int st[maxN<<2];
int N, t;
int A[maxN];

void build(int nx=1, int l=1, int r=N) {
	if (l==r) {
		st[nx] = 0;
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	st[nx] = 0;
}

void upd(int pos, int nx=1, int l=1, int r=N) {
	if (pos < l or r < pos) return;
	if (l == r) {
		st[nx] += 1;
		return;
	}	
	int mid = (l+r)/2;
	upd(pos, nx<<1, l, mid);
	upd(pos, nx<<1|1, mid+1, r);	
	st[nx] = st[nx<<1] + st[nx<<1|1];
}

int qry(int ll, int rr, int nx=1, int l=1, int r=N) {
	if (rr < l or r < ll) return 0; 
	if (ll <= l and r <= rr) return st[nx];
	int mid = (l+r)/2;
	return qry(ll, rr, nx<<1, l, mid) + qry(ll, rr, nx<<1|1, mid+1, r);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		map<int, int> Map;
		for (int i = 1; i <= N; ++i) {
			scanf("%d", A+i);
			Map[A[i]];
		}
		int m = 1;
		for (auto& e : Map) {
			e.second = m++;
		}
		for (int i = 1; i <= N; ++i) A[i] = Map[A[i]];
		build();
		long long cnt = 0;
		for (int i = 1; i <= N; ++i) {
			if (A[i] < N) {
				cnt += qry(A[i]+1, N);
			}
			upd(A[i]);
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
