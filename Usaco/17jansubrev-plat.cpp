/**
 *	@name USACO 2017 January, Platinum | P3 Subsequence Reversal
 *	@author Miguel Mini
 *	@tag dp, memory_compression
 *	@idea:
 *			- we can make a naive dp problem
 *			with 4 parameters, we can reduce
 *			the memory using distance how 
 *			compress parameter.
**/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 51;
int memo[maxn][4][maxn][maxn];
int n;
int a[maxn];

int main() {
	freopen("subrev.in", "r", stdin);
	freopen("subrev.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int l = 0; l < n; ++l)
		for (int mn = 1; mn <= 50; ++mn)
			for (int mx = mn; mx <= 50; ++mx) {
				memo[l][1][mn][mx] = mn <= a[l] and a[l] <= mx;
			}
	for (int d = 2; d <= n; ++d) {
		for (int l = 0; l + d - 1 < n; ++l) {
			for (int mn = 1; mn <= 50; ++mn) {
				for (int mx = mn; mx <= 50; ++mx) {
					int& ans = memo[l][d&3][mn][mx] = 0;
					if (mn <= a[l] and a[l] <= mx) {
						ans = max(ans, memo[l+1][(d+3)&3][a[l]][mx] + 1);
						ans = max(ans, memo[l+1][(d+2)&3][mn][a[l]] + 1);
					}
					if (mn <= a[l+d-1] and a[l+d-1] <= mx) {
						ans = max(ans, memo[l][(d+3)&3][mn][a[l+d-1]] + 1);
						ans = max(ans, memo[l+1][(d+2)&3][a[l+d-1]][mx] + 1);
						if (a[l+d-1] <= a[l] and a[l] <= mx) {
							ans = max(ans, memo[l+1][(d+2)&3][a[l+d-1]][a[l]] + 2);
						}	
					}
					ans = max(ans, memo[l+1][(d+3)&3][mn][mx]);
					ans = max(ans, memo[l][(d+3)&3][mn][mx]);
				}
			}
		}	
	}
	cout << memo[0][n&3][1][50] << endl;
	return 0;
}
