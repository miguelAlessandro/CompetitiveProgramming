#include <bits/stdc++.h>
using namespace std;
const int maxN = 1010;
vector<pair<int, int>> g[maxN];
int n;
long double x[maxN];
int t[maxN], k[maxN];
bool vis[maxN];

int dfs(int v, long double l, int p=0) {
	vis[v] = 1;
	int ans = k[v] - 1e-10 <= l;
	for (auto u : g[v])	{
		if (not vis[u.first]) {
			long double L = l * x[u.second] / 100;
			if (t[u.second]) L *= L; 
			ans += dfs(u.first, L, v);		
		}
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n-1; ++i) {
		int a, b;
		cin >> a >> b >> x[i] >> t[i];
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	for (int i = 1; i <= n; ++i) cin >> k[i];
	long double lo = 0, hi = 2e9;
	for (int i = 0; i <= 500; ++i) {
		long double mid = lo + (hi-lo)/2;
		memset(vis, 0, sizeof vis);
		if (dfs(1, mid) == n) hi = mid;
		else lo = mid;
	}
	cout << fixed << setprecision(6) << lo << endl;
	return 0;
}
