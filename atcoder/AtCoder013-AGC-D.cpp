/**
 * @name AtCoder 013 AGC D
 * @author Miguel Mini
 * @tag dp, greedy
 * @idea
 *		- let dp[i][j] number of solutions
 *		with start number of red blocks j
 *  	and i operations.
 *		- to avoid double count, only
 *		consider solutions with at least
 *		an election with minimum number of 
 * 		red blocks.
 *
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010;
const int mod = 1e9+7;
bool vis[maxn][maxn][2];
int memo[maxn][maxn][2];
int n, m;

int add(int a, int b) {return (a+b)%mod;}
int mul(long long a, long long b) {return a*b%mod;}

int dp(int pos, int r, int b, bool k) {
	if (pos == m) return k;
	if (vis[pos][r][k]) return memo[pos][r][k];
	int &ans = memo[pos][r][k] = 0;
	if (r > 0) {
		ans = add(ans, dp(pos+1, r-1, b+1, k|(r==1)));
		ans = add(ans, dp(pos+1, r, b, k|(r==1)));
	}
	if (b > 0) {
		ans = add(ans, dp(pos+1, r+1, b-1, k|(r==0)));
		ans = add(ans, dp(pos+1, r, b, k|(r==0)));
	}
	vis[pos][r][k] = 1;
	return ans;
}

int main() {
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans = add(ans, dp(0, i, n-i, 0));
	}
	cout << ans << endl;
	return 0;
}
