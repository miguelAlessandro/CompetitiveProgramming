/**
 *	@name COI 2016 Torrent
 *	@author Miguel Mini
 *	@tag dp, binary_search
 *	@idea
 *			- we should note that
 *			it is always better for
 *			A to visit a connect 
 *			component, and B equal.
 *
 *			- the cut is always in
 *			path(A-B), note that a
 *			cut farther from A only
 *			increases we response.
 *			Same to B.
 *			
 *			- the answer is always 
 *			in the last point that
 * 		ans(A) < ans(B) or first
 *			point that ans(A) >= ans(B).
 *			
**/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
vector<int> p, g[maxn];
int n, a, b;
bool vis[maxn];
int dp[maxn];

bool get_path(int x, int y, int p, vector<int>& P) {
	if (x == y) return 1;
	for (int& v : g[x]) {
		if (v == p) continue;
		P.emplace_back(v);
		if (get_path(v, y, x, P)) return 1;
		P.pop_back();
	}
	return 0;
}

int dfs(int x, int p=0) {
	vector<int> t;
	for (int v : g[x]) {
		if (v == p) continue;
		t.push_back(dfs(v, x));
	}
	sort(t.rbegin(), t.rend());
	dp[x] = 0;
	for (int i = 0; i < t.size(); ++i) {
		dp[x] = max(dp[x], t[i] + i + 1);
	}
	return dp[x];
}

void remov(int x, int v) {
	for (int& u : g[x]) {
		if (u == v) {
			swap(g[x].back(), u);
			break;
		}
	}
	g[x].pop_back();
}	

int x, y;
int f(int t) {
	remov(p[t], p[t+1]);
	remov(p[t+1], p[t]);
	x = dfs(a);
	y = dfs(b);
	int ans = x < y;
	g[p[t]].emplace_back(p[t+1]);
	g[p[t+1]].emplace_back(p[t]);
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}	
	p = {a};
	get_path(a, b, 0, p);
	int lo = 0, hi = p.size() - 2;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) lo = mid+1;
		else hi = mid;
	}	
	int ans = INT_MAX;
	f(lo);
	ans = max(x, y);
	if (lo - 1 >= 0) {
		f(lo-1);
		ans = min(ans, max(x, y));
	}
	cout << ans << endl;
	return 0;
}
