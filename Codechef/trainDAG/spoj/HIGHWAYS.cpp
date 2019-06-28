#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int dis[maxN];
struct Edge {int v, w;};
vector<Edge> g[maxN];
int t, n, m, s, f;

void dijkstra(int src, int snk) {
	for (int i = 1; i <= n; ++i) dis[i] = 2e9;
	dis[src] = 0;
	typedef pair<int, int> ii;
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	Q.push({0, src}); 
	while (not Q.empty()) {
		auto q = Q.top(); Q.pop();
		int v = q.second;
		int w = q.first;
		if (v == snk) return void(cout << dis[v] << endl);
		if (w != dis[v]) continue;
		for (auto node : g[v]) {
			if (w + node.w < dis[node.v]) {
				dis[node.v] = w + node.w;
				Q.push({dis[node.v], node.v});
			}
		}
	}
	puts("NONE");
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m >> s >> f;
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1; i <= m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a].push_back({b, c});
			g[b].push_back({a, c});
		}
		dijkstra(s, f);
	}
	return 0;
}
