/**
 *	UVA 12363
 *	@overview find if there is a unique simple path between a, b 
 *	# nodes in 2-bridge-conected component they do not connect 
 *	by simple roads
 *	# only its possible if edges are bridges
 */


#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
vector<int> adj[MAX_N];
bool vis[MAX_N];
int tin[MAX_N], fup[MAX_N];
int r, c, q;
int id[MAX_N], sz[MAX_N];
int timer;

int get(int x) {
	return x == id[x] ? x : id[x] = get(id[x]);
}

void Union(int x, int y) {
	x = get(x); 
	y = get(y);
	if (x == y) return;
	if (sz[x] < sz[y]) swap(x, y);
	id[y] = x;
	sz[x] += sz[x] == sz[y]; 
}

void dfs(int x, int p) {
	vis[x] = 1;
	tin[x] = fup[x] = timer++;
	for (int v : adj[x]) {
		if (v == p) continue;
		if (vis[v]) fup[x] = min(fup[x], tin[v]);
		else  {
			dfs(v, x);
			fup[x] = min(fup[x], fup[v]);
			if (tin[x] < fup[v]) Union(x, v);
		}
	}
}

int main () {

	while (scanf("%d %d %d", &r, &c, &q), r+c+q) {
		for (int i = 1; i <= r; ++i) {
			adj[i].clear();
			id[i] = i;
			sz[i] = 0;
			vis[i] = 0;
		}
		for (int i = 0; i < c; ++i) {
			int u, v;
			scanf ("%d %d", &u, &v);
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}

		for (int i = 1; i <= r; ++i)
			if (not vis[i]) dfs(i, 0);

		for (int i = 1; i <= q; ++i) {
			int a, b;
			scanf ("%d %d", &a, &b);
			puts(get(a) == get(b) ? "Y" : "N");
		}
		puts("-");
	}

	return 0;
}
