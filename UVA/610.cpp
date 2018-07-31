/**
 *	UVA 610
 *	@overview minimum edge of directed graph with strong orientation
 *		
 *	# bridge always has its two directions
 *	# front edge of dfs tree too
 *	# back edge of dfs tree only if its bridge
 *	# in other case front edge not is necesary
 */


#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
bool edge[MAX_N][MAX_N];
bool vis[MAX_N];
int tin[MAX_N], fup[MAX_N];
vector<int> adj[MAX_N];
int n, m, nc=1;
int timer;

void dfs(int x, int p) {
	vis[x] = 1;
	tin[x] = fup[x] = timer++;
	for (int v : adj[x]) {
		if (v == p) continue;
		if (not edge[x][v]) continue;
		if (vis[v])
			fup[x] = min(fup[x], tin[v]), edge[v][x] = 0;
		else {
			dfs(v, x);
			fup[x] = min(fup[x], fup[v]);
			if (fup[v] <= tin[x]) edge[v][x] = 0; 
		}
	}
}

int main () {

	while (scanf ("%d %d", &n, &m), n+m) {
		for (int i = 1; i <= n; ++i) adj[i].clear();
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= m; ++i) {
			int u, v;
			scanf ("%d %d", &u, &v);
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
			edge[u][v] = edge[v][u] = 1;
		}

		dfs(1, 0);
		printf("%d\n\n", nc++);

		for (int i = 1; i <= n; ++i)
			for (int v : adj[i])
				if (edge[i][v]) printf ("%d %d\n", i, v);
		puts("#");
	}
	return 0;
}
