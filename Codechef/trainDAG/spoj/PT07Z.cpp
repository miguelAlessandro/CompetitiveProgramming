#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
vector<int> g[maxN];
int dis[maxN];
bool vis[maxN];
int n;

pair<int, int> bfs(int src) {
	queue<int> Q;
	for (int i = 1; i <= n; ++i) vis[i] = 0;
	dis[src] = 0;
	vis[src] = 1;
	Q.push(src);
	int q;
	while (not Q.empty()) {
		q = Q.front(); Q.pop();
		for (int v : g[q]) {
			if (not vis[v]) {
				vis[v] = 1;
				dis[v] = dis[q] + 1;
				Q.push(v);
			}
		}
	}
	return {q, dis[q]}; 
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	printf("%d\n", bfs(bfs(1).first).second);
	return 0;
}
