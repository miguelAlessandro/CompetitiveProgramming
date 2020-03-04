/**
 *	@name APIO 2007 ZOO
 *	@author Miguel Miní
 *	@tag dp, bitmask
 *	@idea
 *		- We can run a dp for 
 *		every initial mask, only
 *		is necessary first 4 values.
 *		and dp take O(2^5 n).		
 *
 * 	- final complexity is
 *		O(2^9 n).
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
bool vis[maxn];
int build(int n, int e, vector<int>& t) {
	for (int v : t) vis[v-1] = 1;
	int mask = 0;
	for (int i = 0; i < 5; ++i) {
		if (vis[(e - 1 + i) % n]) {
			mask |= 1<<i;
		}
	}
	for (int v : t) vis[v-1] = 0;
	return mask;
}
int a[maxn][1<<5];
bool check[maxn][1<<4];
int memo[maxn][1<<4];
int n, c;
int dp(int s, int pos, int cur) {
	if (pos == n) return 0;	
	if (check[pos][cur]) return memo[pos][cur];
	int &ans = memo[pos][cur] = 0;
	if (pos + 4 < n) {
		for (int j = 0; j < 2; ++j) {
			ans = max(ans, dp(s, pos+1, (cur|(j<<4))>>1) + a[pos][cur|(j<<4)]);
		}
	} else {
		int bit = (s>>pos+4-n)&1;
		ans = max(ans, dp(s, pos+1, (cur|(bit<<4))>>1) + a[pos][cur|(bit<<4)]);
	}
	check[pos][cur] = 1;
	return ans;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> c;
		memset(a, 0, sizeof a);
		for (int i = 0; i < c; ++i) {
			int e, f, l;
			cin >> e >> f >> l;
			vector<int> F(f), L(l);
			for (int& x : F) cin >> x;
			for (int& x : L) cin >> x;
			int maskF = build(n, e, F);
			int maskL = build(n, e, L);
			for (int s = 0; s < 1<<5; ++s) {
				a[e-1][s] += (s & maskL) or (~s & maskF);
			}
		}
		int ans = 0;
		for (int s = 0; s < 1<<4; ++s) {
			memset(check, 0, sizeof check);
			ans = max(ans, dp(s, 0, s));
		}
		cout << ans << endl;
	}
	return 0;
}
