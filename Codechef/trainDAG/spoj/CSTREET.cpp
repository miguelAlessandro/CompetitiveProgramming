#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
struct Node {int v; unsigned w;};
vector<Node> g[maxN];
int t, n, m;
unsigned p;
unsigned dis[maxN];
bool vis[maxN];

unsigned prim(int src) {
	for (int i = 1; i <= n; ++i) {
		dis[i] = UINT_MAX;
		vis[i] = 0;
	}
	dis[src] = 0;
	typedef pair<unsigned, int> ii;
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	Q.push({0, src});
	while (not Q.empty()) {
		auto q = Q.top(); Q.pop();
		int v = q.second;
		unsigned w = q.first;
		if (not vis[v]) {
			vis[v] = 1;
			for (auto node : g[v]) {
				if (not vis[node.v] and node.w < dis[node.v]) {
					dis[node.v] = node.w;
					Q.push({dis[node.v], node.v});
				}
			}
		}
	}
	return accumulate(dis+1, dis+n+1, 0u);
}

int main() {
	cin >> t;
	while (t--) {
		cin >> p >> n >> m;
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1; i <= m; ++i) {
			int a, b; unsigned c;
			cin >> a >> b >> c;
			g[a].push_back({b, c});
			g[b].push_back({a, c});
		}
		cout << p * prim(1) << endl;
	}
	return 0;
}
