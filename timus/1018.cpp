/**
 * @author Miguel Mini
 * @tag dp on trees, connect component approach
 * @idea
 *      - dp on tree aplication
**/

#include <bits/stdc++.h>
using namespace std;
const int maxN = 110;
int dp[maxN][maxN];
vector<pair<int, int>> g[maxN];
int n, q;

int dfs(int x, int p) {
	for (auto v : g[x]) {
		if (v.first == p) continue;
		dfs(v.first, x);
	}
	for (auto v : g[x]) {
		if (v.first == p) continue;
		for (int i = q-1; i >= 0; --i) {
			for (int j = 0; j <= i; ++j) {
				dp[x][i+1] = max(dp[x][i+1], dp[x][i-j] + v.second + dp[v.first][j]);
			}
		} 
	}
	return dp[x][q];
}

int main() {
	cin >> n >> q;
	for (int i = 1; i < n; ++i) {	
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	cout << dfs(1, 0) << endl;
	return 0;
}
