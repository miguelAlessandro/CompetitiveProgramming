#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
const int LOG = 20;
int h[maxN];
int up[maxN][LOG];
vector<pair<int, int>> g[maxN];
int edge[maxN];
int in[maxN];
int dp[maxN], ans[maxN], out[maxN];
int n, k;

void dfs(int x, int parent, int height, int id) {
	edge[x] = id;
	h[x] = height;
	up[x][0] = parent;
	for (int k = 1; k < LOG; ++k) {	
		up[x][k] = up[up[x][k-1]][k-1];
	}
	for (auto v : g[x]) {
		if (v.first != parent)
		dfs(v.first, x, height+1, v.second);
	}
}

int jump(int x, int l) {
	for (int k = 0; k < LOG; ++k) {
		if (l & (1<<k)) {
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

void dfs_sweep(int x, int p) {
	dp[x] = in[x];
	for (auto node : g[x]) {
		if (node.first == p) continue;
		dfs_sweep(node.first, x);
		dp[x] += dp[node.first];
	}	
	if (~edge[x]) ans[edge[x]] = dp[x];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
	}
	dfs(1, 0, 0, -1);
	scanf("%d", &k);
	while (k--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int anc = lca(a, b);
		in[a] += 1;
		in[b] += 1;
		in[anc] -= 2;
	}
	dfs_sweep(1, 0);
	for (int i = 0; i < n-1; ++i) {
		printf("%d ", ans[i]);
	} puts("");
	return 0;
}
