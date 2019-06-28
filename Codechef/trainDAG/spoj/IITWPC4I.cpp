#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
long long dis[maxN];
bool vis[maxN];
int t, n, m;
vector<pair<int, int>> g[maxN];

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) cin >> vis[i];
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1; i <= m; ++i) {		
			int a, b, c;
			cin >> a >> b >> c;
			g[a].push_back({b, c});
			g[b].push_back({a, c});
		}
		for (int i = 1; i <= n; ++i) dis[i] = 1e18;
		typedef long long ll;
		typedef pair<ll, int> ii;
		priority_queue<ii, vector<ii>, greater<ii>> Q;
		for (int i = 1; i <= n; ++i) {
			if (vis[i]) {
				dis[i] = 0;
				Q.push({0ll, i});
			}
		}
		while (not Q.empty()) {
			auto q = Q.top(); Q.pop();
			int v = q.second;
			ll w = q.first;
			if (vis[v] and dis[v] != 0) continue;
			vis[v] = 1;
			for (auto node : g[v]) {
				if (not vis[node.first] and node.second < dis[node.first]) {
					dis[node.first] = node.second;
					Q.push({dis[node.first], node.first});
				}
			}
		}
		if (accumulate(vis+1, vis+n+1, 0) == n) {
			printf("%lld\n", accumulate(dis+1, dis+n+1, 0ll));
		} else puts("impossible");
	}
	return 0;
}
