#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
const int LOG = 20;
int h[maxN], sz[maxN], up[maxN][LOG];
vector<int> g[maxN];

void dfs(int x, int parent, int height) {
	h[x] = height;
	sz[x] = 1;
	up[x][0] = parent;
	for (int k = 1; k < LOG; ++k) {
		up[x][k] = up[up[x][k-1]][k-1];
	}
	for (int v : g[x]) {
		if (v == parent) continue;
		dfs(v, x, height+1);
		sz[x] += sz[v];
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

int n, m;
int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0, 0);
	scanf("%d", &m);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		if ((h[u] ^ h[v]) & 1) {
			puts("0");
			continue;
		}
		int anc = lca(u, v);
		int dist = h[u] + h[v] - 2*h[anc];
		int mid = dist / 2;
		if (mid == 0) {
			printf("%d\n", n);
			continue;
		}
		if (h[u] < h[v]) swap(u, v);
		int meet = jump(u, mid);
		if (meet != anc) {
			int child = jump(u, mid-1);
			printf("%d\n", sz[meet] - sz[child]);
		} else {
			int child1 = jump(u, mid-1);
			int child2 = jump(v, mid-1);
			printf("%d\n", n - sz[child1] - sz[child2]);
		}
	}
	return 0;
}
