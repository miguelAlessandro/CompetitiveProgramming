/**
 *  @problem: count number of segments [l, r] such than max(a[l:r]) == min(b[l:r]) 
 *  @solution:
 *      - if l is fixed, the function min(b[l:r]) - max(a[l:r]) is decreasing.
 *      - solve with binary search (use fast rmq query)
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN], b[MAXN];
int st[2][MAXN][20];
int n;

int main() {

	scanf("%d", &n);
	map<int, int> id;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		id[a[i]];
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", b+i);	
		id[b[i]];	
	}
	int t = 0;
	for (auto& v : id)
		v.second = t++;

	for (int i = 1; i <= n; ++i) {
		a[i] = id[a[i]];
		b[i] = id[b[i]];
	}

	for (int i = 1; i <= n; ++i) {
		st[0][i][0] = a[i];
		st[1][i][0] = b[i];
	}
	
	for (int k = 1; k <= 18; ++k)
		for (int i = 1; i + (1<<k) <= n+1; ++i) {
			st[0][i][k] = max(st[0][i][k-1], st[0][i+(1<<k-1)][k-1]);		
			st[1][i][k] = min(st[1][i][k-1], st[1][i+(1<<k-1)][k-1]);			
		}

	auto query = [&](int id, int x, int y) {
		int r = 31 - __builtin_clz(y-x+1);		
		return id ? 
			min(st[id][x][r], st[id][y-(1<<r)+1][r]) 
		:
			max(st[id][x][r], st[id][y-(1<<r)+1][r])
		;
	};

	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > b[i]) continue;
	
		int lo = i, hi = n;
		while (lo < hi) {
			int mid = lo + (hi-lo)/2;
			if (query(1, i, mid) > query(0, i, mid)) lo = mid+1;
			else hi = mid;
		}
		if (lo > n) continue;
		int l = lo;
		if (query(0, i, lo) != query(1, i, lo)) continue;

		hi = n;
		while (lo < hi) {
			int mid = lo + (hi-lo+1)/2;
			if (query(0, i, mid) == query(1, i, mid)) lo = mid;
			else hi = mid-1;
		}
		ans += lo-l+1;
	}

	printf("%lld\n", ans);
	return 0;
}
