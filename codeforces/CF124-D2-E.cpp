/**
 *	@name Codeforces 124E div2 Brackets
 *	@author Miguel Mini
 *	@tag binary search, dp
 *	@idea
 *		- observe that every element (i, j)
 *		with i+j == c has the same value.
 *		- sort by priority and assign in order 
 *		to each element '(' and count with dp 
 *		if (cnt < k) assign ')' and k -= cnt.
 */


#include <bits/stdc++.h>
using namespace std;
const int maxN = 110;
int n, m;
long long k;
int p[maxN<<1];
const long long INF = 1.1e18;
int arr[maxN<<1];
const int O = 150;
bool vis[maxN<<1][maxN<<2];
long long memo[maxN<<1][maxN<<2];

long long dp(int pos, int sum) {
	if (sum < 0) return 0;
	if (pos == n+m-1) return sum == 0;
	if (vis[pos][sum]) return memo[pos][sum];	
	long long &ans = memo[pos][sum] = 0;
	if (arr[pos]) ans = dp(pos+1, sum+arr[pos]);
	else {
		ans += dp(pos+1, sum + 1);
		ans += dp(pos+1, sum - 1);
		ans = min(ans, INF);
	}
	vis[pos][sum] = 1;
	return ans;
}

int main() {
	cin >> n >> m >>k;
	memset(p, 1, sizeof p);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x; 
			cin >> x;
			p[i+j] = min(p[i+j], x);
		} 
	}	
	vector<pair<int, int>> o;
	for (int i = 0; i < n+m-1; ++i) {
		o.push_back({p[i], i});
	}
	sort(begin(o), end(o));
	for (auto e : o) {
		arr[e.second] = 1;
		memset(vis, 0, sizeof vis);
		long long cnt = dp(0, 0);
		if (cnt < k) arr[e.second] = -1, k -= cnt;
	}	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << (arr[i+j] == 1 ? '(' : ')');
		}
		cout << endl;
	}
	return 0;
}
