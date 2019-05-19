#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
int dis[maxN];
bool vis[maxN];
int f, s, g, u, d;

int bfs(int src, int snk) {
	queue<int> Q;
	Q.push(src);
	memset(vis, 0, sizeof vis);
	dis[src] = 0;
	vis[src] = 1;
	while (not Q.empty()) {
		int q = Q.front(); Q.pop();
		if (q == snk) return dis[q];
		if (q + u <= f and not vis[q + u]) {
			vis[q + u] = 1;
			dis[q + u] = dis[q] + 1;
			Q.push(q + u);
		}
		if (q - d >= 1 and not vis[q - d]) {
			vis[q - d] = 1;
			dis[q - d] = dis[q] + 1;
			Q.push(q - d);
		}
	}
	return -1;
}

int main() {
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);	
	int ans = bfs(s, g);
	if (~ans) printf("%d\n", ans);
	else puts("use the stairs");
	return 0;
}
