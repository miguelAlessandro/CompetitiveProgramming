/**
 *	@name retea3
 *	@author Miguel Mini
 *	@tag dp, inclusion-exlucion-principle
 *	@idea
 *			- only import two consecutive
 *			rows, the answer is:
 *
 *			solution_two_consecutive_rows^(m-1)
 *
 *			- to the first two rows we can 
 *			a simple dp
 *
 *			dp(up, down, is_up_taked, is_down_taked)
 *				if up == n and down == n:
 *					return 1
 *
 *				ans = dp(up, down+1, is_up_taked, 0)				
 *				ans += dp(up+1, down, 0, is_down_taked)
 *				ans -= dp(up+1, down+1, 0, 0)
 *
 *				if not is_up_taked or not is_down_taked:
 *					ans += dp(up, down, 1, 1)
 *				return ans
 *
 *			- we substract dp(up+1, down+1, 0, 0) 'cuz
 *			overlap in first and second branch
 *
 * 		- to optimize, we can see than the last
 *			if repeat the same process, which allows
 *			us to override boolean variables.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int mod = 666013;
int n, m;
int memo[maxn][maxn];
bool vis[maxn][maxn];

int add(int a, int b) {
	return a + b < mod ? a + b : a + b - mod;
}

int mul(long long a, int b) {
	return a * b % mod;
}

int ex(int a, int b) {
	int r = 1;
	while (b > 0) {
		if (b&1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

int dp(int l, int r) {
	if (l == n or r == n) return 1;
	if (vis[l][r]) return memo[l][r];
	int ans = 0;
	ans = add(ans, dp(l, r+1));
	ans = add(ans, dp(l+1, r));
	ans = add(ans, mod - dp(l+1, r+1));
	ans = add(ans, ans);
	vis[l][r] = 1;
	return memo[l][r] = ans;
}

int main() {
	freopen("retea3.in", "r", stdin);
	freopen("retea3.out", "w", stdout);
	cin >> m >> n;
	cout << ex(dp(0, 0), m-1) << endl;
	return 0;
}
