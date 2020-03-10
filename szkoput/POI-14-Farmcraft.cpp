/**
 *  @name POI 2014 FarmCraft
 *  @author Miguel Mini
 *  @tag dp, exchange-argument
 *  @idea
 *      - we can use dp with a selection
 *      euristic
 *  
 *      - the two items euristic is determined
 *      to ecuation 
 *        max(1 + dp[v], sz[v] + 2 + dp[u]) < max(1 + dp[u], sz[u] + 2 + dp[v])
 *
 *      we note that the first term in the left is less than the second term
 *      in the right, such that, we only need compare second terms.
 *
 *      the only diference is node 1, this is fixed to consider before run
 *      the dp.
**/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int c[maxn];
vector<int> g[maxn];
int sz[maxn], dp[maxn];
int n;

typedef pair<int, int> pii;
void dfs(int x, int p = 0) {
	vector<pii> t;
	sz[x] = 1;
	for (int v : g[x]) {
		if (v == p) continue;
		dfs(v, x);
		sz[x] += sz[v];
		t.push_back({sz[v], dp[v]});
	}
	sort(t.begin(), t.end(), [](pii p, pii q) {
		return 2 * p.first - p.second < 2 * q.first - q.second;	
	});
	dp[x] = max(2*sz[x]-2, c[x]);
	int s = 1;
	for (auto e : t) {
		dp[x] = max(dp[x], s + max(2*e.first-1, e.second));
		s += 2 * e.first;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", c+i);
	for (int i = 1; i <= n-1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	cout << max(2*sz[1]-2+c[1], dp[1]) << endl;
	return 0;
}
