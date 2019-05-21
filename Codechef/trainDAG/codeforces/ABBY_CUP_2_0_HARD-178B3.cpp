#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
const int LOG = 20;
bool vis[maxN] ;
int tin[maxN], low[maxN];
struct Node {int v, id;};
vector<Node> g[maxN];
bool bridge[maxN];
int c[maxN];
int timer;
int n, m, k;

void dfs_bridge(int x, int parent) {
	vis[x] = 1;
	tin[x] = low[x] = timer++;
	for (auto node : g[x]) {
		if (node.v == parent) continue;
		if (vis[node.v]) {
			low[x] = min(low[x], tin[node.v]);
		} else {
			dfs_bridge(node.v, x);
			low[x] = min(low[x], low[node.v]);
			if (low[node.v] > tin[x]) {
				bridge[node.id] = 1;
			}
		}
	}
}

void dfs_color(int x, int parent, int color) {
	vis[x] = 1;
	c[x] = color;
	for (auto node : g[x]) {
		if (node.v == parent) continue;
		if (vis[node.v]) continue;
		if (bridge[node.id]) continue;
		dfs_color(node.v, x, color);
	}
}

int h[maxN];
int up[maxN][LOG];
bool vist[maxN];
void dfs_build(int x, int parent, int height, int parent_color) {
	if (not vist[c[x]]) {
		up[c[x]][0] = parent_color;	
		h[c[x]] = height;
		for (int k = 1; k < LOG; ++k) {
			up[c[x]][k] = up[up[c[x]][k-1]][k-1];
		}
	}
	vis[x] = 1;
	vist[c[x]] = 1; 
	for (auto node : g[x]) {
		if (node.v == parent) continue;
		if (c[node.v] == parent_color) continue;
		if (not vist[c[node.v]]) {
			dfs_build(node.v, x, height+1, c[x]);
		} else {
			if (not vis[node.v]) {
				dfs_build(node.v, x, height, parent_color);
			}
		}
	}
}

int jump(int x, int l) {
	for (int k = 0; k < LOG; ++k) {
		if (l&(1<<k)) {
			x = up[x][k];
		}
	}
	return x;
}

int lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	v = jump(v, h[v] - h[u]);
	if (u == v) return u;
	for (int k = LOG-1; k >= 0; --k) {
		if (up[u][k] != up[v][k]) {
			u = up[u][k];
			v = up[v][k];	
		}
	}
	return up[u][0];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	dfs_bridge(1, 0);
	int d = 1;
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; ++i) {
		if (not vis[i]) {
			dfs_color(i, 0, d++);
		}
	}
	memset(vis, 0, sizeof vis);
	dfs_build(1, 0, 0, 0);
	scanf("%d", &k);
	while (k--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a = c[a]; b = c[b];
		int anc = lca(a, b);
		printf("%d\n", h[a] + h[b] - 2*h[anc]);
	}
	return 0;
}
