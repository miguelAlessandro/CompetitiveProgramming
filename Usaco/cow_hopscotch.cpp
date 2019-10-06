/**
 *	@name cow hopscotch
 *	@author Miguel Mini
 *	@tag dp, BIT
 *	@idea
 *			- we can solve it with the 
 *			sum of solutions for the 
 *			previous rows minus the 
 *			contribution of the same color.
 *
 *			- as the amount of memory 
 *			affects the execution time, 
 *			we can compress the lists only 
 *			in the columns that each 
 *			color appears, having O(nm)
 * 		of memory.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 755;
const int mod = 1e9 + 7;
vector<int> ft[maxn * maxn];
vector<int> pos[maxn * maxn];
int mat[maxn][maxn];
int n, m, k;

int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}

int upper(int k, int x) {
	int lo = 0, hi = (int)pos[k].size() - 1;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (pos[k][mid] <= x) lo = mid;
		else hi = mid-1;
	}
	return pos[k][lo] > x ? -1 : lo;
}

int lower(int k, int x) {
	int lo = 0, hi = (int)pos[k].size() - 1;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (pos[k][mid] < x) lo = mid+1;
		else hi = mid;
	}
	return pos[k][lo] < x ? pos[k].size() + 1 : lo; 
}

void update(int k, int x, int val) {
	x = lower(k, x);
	while (x < pos[k].size()) {
		ft[k][x] = add(ft[k][x], val);
		x = x | (x+1);
	}
}

int query(int k, int x) {
	x = upper(k, x);
	int ans = 0;
	while (x >= 0) {
		ans = add(ans, ft[k][x]);
		x = (x & (x + 1)) - 1;
	}
	return ans;
}

int dp[maxn][maxn], sum[maxn][maxn];
int solve() {
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (pos[mat[i][j]].empty() or pos[mat[i][j]].back() != j) {
				pos[mat[i][j]].push_back(j);
				ft[mat[i][j]].push_back(0);
			}
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i <= m; ++i) {
		sum[1][i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		sum[i][1] = 1;
	}
	update(mat[1][1], 1, 1);
	for (int i = 2; i <= n; ++i) {
		for (int j = m; j >= 2; --j) {
			dp[i][j] = add(sum[i-1][j-1], mod - query(mat[i][j], j-1)); 
			update(mat[i][j], j, dp[i][j]);
		}
		for (int j = 2; j <= m; ++j) {
			sum[i][j] = add(
				add(dp[i][j], sum[i-1][j]), 
				add(sum[i][j-1], mod - sum[i-1][j-1])
			);
		}
	}
	return dp[n][m];
} 

int main() {
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", mat[i]+j);
		} 
	}
	printf("%d\n", solve());
	return 0;
}
