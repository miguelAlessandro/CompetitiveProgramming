#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
const int mod = 1e9 + 7;
vector<int> g[maxN];
int dis[maxN];
int ways[maxN];
int t, n, m;

int add(int a, int b) {
	return (a+b)%mod;
}

int bfs(int src, int snk) {
	queue<int> Q;
	Q.push(src);
	for (int i = 1; i <= n; ++i) dis[i] = -1, ways[i] = 0;
	dis[src] = 0;
	ways[src] = 1;
	while (not Q.empty()) {
		int q = Q.front(); Q.pop();
		for (int v : g[q]) {
			if (dis[v] < 0) {
				dis[v] = dis[q] + 1;
				ways[v] = add(ways[v], ways[q]);
				Q.push(v);
			} else if (dis[q] + 1 == dis[v]) ways[v] = add(ways[v], ways[q]);
		}
	}
	return ways[snk];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		int src, snk;
		scanf("%d %d %d %d", &n, &m, &src, &snk);
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1; i <= m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		printf("%d\n", bfs(src, snk));
	}
	return 0;
}
