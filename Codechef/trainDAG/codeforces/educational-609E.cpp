#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
const int LOG = 20;
long long mst;
int mw[maxN][LOG], up[maxN][LOG];
struct Node {
	int v, w;
};
long long ans[maxN];
int h[maxN];
vector<Node> g[maxN];

void dfs(int x, int parent, int height, int weight) {
	mst += weight;
	h[x] = height;
	mw[x][0] = weight;
	up[x][0] = parent;
	for (int k = 1; k < LOG; ++k) {
		mw[x][k] = max(mw[x][k-1], mw[up[x][k-1]][k-1]);
		up[x][k] = up[up[x][k-1]][k-1];
	}
	for (auto node : g[x]) {
		if (node.v == parent) continue;
		dfs(node.v, x, height+1, node.w);
	}
}

struct edge {
	int a, b, w, id;		
};

int id[maxN];
int rnk[maxN];
int get(int x) {return x == id[x] ? x : id[x] = get(id[x]);}

void Union(int x, int y) {
	x = get(x); y = get(y);	
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	id[y] = x;
	rnk[x] += rnk[x] == rnk[y];
}

bool same(int x, int y) {
	return get(x) == get(y);
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

int solve(int x, int l) {
	int ans = 0;
	for (int k = 0; k < LOG; ++k) {
		if (l&(1<<k)) {
			ans = max(ans, mw[x][k]);
			x = up[x][k];
		}
	}
	return ans;
}

int n, m;
bool vis[maxN];
int main() {
	scanf("%d %d", &n, &m);
	vector<edge> E;
	for (int i = 1; i <= n; ++i) id[i] = i;
	for (int i = 1; i <= m; ++i) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		E.push_back({a, b, w, i});
	}
	sort(begin(E), end(E), [](edge p, edge q) {
		return p.w < q.w;
	});
	for (auto e : E) {
		if (not same(e.a, e.b)) {
			Union(e.a, e.b);
			vis[e.id] = 1;
			g[e.a].push_back({e.b, e.w});
			g[e.b].push_back({e.a, e.w});
		}
	}
	dfs(1, 0, 0, 0);
	for (auto e : E) {
		if (vis[e.id]) {
			ans[e.id] = mst;
			continue;
		}
		int a = e.a, b = e.b;
		int anc = lca(a, b);
		ans[e.id] = mst - max(solve(a, h[a] - h[anc]), solve(b, h[b] - h[anc])) + e.w;
	}
	for (int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
	return 0;
}	
