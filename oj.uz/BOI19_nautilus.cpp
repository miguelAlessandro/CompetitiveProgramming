/**
 *	@name BOI 2019 Nautilus
 *	@author Miguel Mini
 *	@tag bitmask, dp
 *	@idea
 *		- we can make simple O(nmk) dp
 *		solution. for every position.
 *		is it possible to do complete
 *		path from j-th position.
 *	
 *		- we can optimize using bitmask
 *		to every row. calcule every
 *		row from top, bottom or same row.
**/


#include <bits/stdc++.h>
using namespace std;
const int maxn = 502;
const int maxm = 5002;
bitset<maxn> dp[maxn][maxm], sea[maxn];
int n, m, k;
string s[maxn];
string p;

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j) {
			sea[i][j] = s[i][j] != '#';
		}
	}
	for (int i = 0; i < n; ++i) {
		dp[i][0] = sea[i];
	}
	cin >> p;
	for (int t = 0; t < k; ++t) {
		if (p[t] == 'S') {
			for (int i = 1; i < n; ++i) {
				dp[i][t+1] = dp[i-1][t] & sea[i];
			}	
		} else if (p[t] == 'N') {
			for (int i = 0; i < n; ++i) {
				dp[i][t+1] = dp[i+1][t] & sea[i];
			}
		} else if (p[t] == 'W') {
			for (int i = 0; i < n; ++i) {
				dp[i][t+1] = (dp[i][t] >> 1) & sea[i];
			}			
		} else if (p[t] == 'E') {
			for (int i = 0; i < n; ++i) {
				dp[i][t+1] = (dp[i][t] << 1) & sea[i];
			}
		} else {
			dp[0][t+1] = ((dp[0][t] << 1) 
						| (dp[0][t] >> 1) 
						| (dp[1][t]))
						& sea[0];
			for (int i = 1; i < n; ++i) {
				dp[i][t+1] = ((dp[i][t] << 1)
						| (dp[i][t] >> 1)
						| (dp[i-1][t])
						| (dp[i+1][t]))
						& sea[i];
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cnt += dp[i][k][j] == 1;
		}
	}
	cout << cnt << endl;
	return 0;
}
