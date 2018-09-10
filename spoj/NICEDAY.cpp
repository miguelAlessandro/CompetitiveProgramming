/**
 *  NICEDAY - SPOJ
 *  @overview let A < B only if A.x < B.x and A.y < B.y and A.z < B.z, 
 *  find number of elements A without do there exist C such that C < A.
 *  
 *  - sort by x for less
 *  - consider element y < cur_y in sweep line traverse
 *  - then there exist C if cur_min in range [1, cur_y) is such that cur_z > z.
 */ 


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int ft[N];
int n, t;
struct node {
	int x, y, z;
	bool operator<(node p) {
		return x < p.x;
	}
} P[N];

void upd(int pos, int v) {
	while (pos < N) {
		ft[pos] = min(ft[pos], v);
		pos += pos&-pos;
	}
}
int query(int pos) {
	int ans = INT_MAX;
	while (pos > 0) {
		ans = min(ans, ft[pos]);
		pos -= pos&-pos;
	}
	return ans;
}


int main() {
	
	scanf("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x, y, z;
			scanf ("%d %d %d", &x, &y, &z);
			P[i] = {x, y, z};
		}
		sort(P, P+n);
		for (int i = 1; i <= n; ++i) ft[i] = INT_MAX;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (query(P[i].y) > P[i].z) ans += 1;
			upd(P[i].y, P[i].z);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
