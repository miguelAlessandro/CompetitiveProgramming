#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
vector<int> g[maxN];
int dis[maxN];
int t, n, m;

pair<int, int> bfs(int x) {
	queue<int> Q;
	Q.push(x);
	for (int i = 0; i < n; ++i) dis[i] = -1;
	dis[x] = 0;
	int q;
	while (not Q.empty()) {
		q = Q.front(); Q.pop();
		for (int v : g[q]) {
			if (dis[v] < 0) {
				dis[v] = dis[q] + 1;
				Q.push(v);
			}
		}
	}
	return {q, dis[q]};
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		m = n-1;
		for (int i = 0; i < n; ++i) {
			g[i].clear();	
		}
		while (m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		printf("%d\n", (1 + bfs(bfs(0).first).second)/2);
	}
	return 0;
}
