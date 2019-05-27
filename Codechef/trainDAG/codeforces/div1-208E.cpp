/**
 *	@author Miguel Mini
 *	@tag LCA, OFFLINE, DSU
 *	@idea
 *			- el problema se traduce a encontrar los descendientes de un nodo a una distancia k
 *			- esto se puede procesar con un array y una construccion de dsu desde las hojas
 */

#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
const int LOG = 19;
int up[maxN][20];
int h[maxN], sz[maxN];
int ver[maxN], big[maxN];
int lo[maxN], hi[maxN];
int ans[maxN], r[maxN];
vector<int> g[maxN];
vector<pair<int, int>> qry[maxN];
int T, n, m;

void dfs(int x, int p) {
	up[x][0] = p==-1 ? x : p;
	for (int k = 1; k < LOG; ++k) {
		up[x][k] = up[up[x][k-1]][k-1];
	}
	h[x] = p==-1 ? 0 : h[p] + 1;
	sz[x] = 1;
	lo[x] = T++;
	ver[lo[x]] = x;
	big[x] = -1;
	for (int v : g[x]) {
		dfs(v, x);
		sz[x] += sz[v];
		if (big[x] == -1 or sz[big[x]] < sz[v]) {
			big[x] = v;
		}
	}
	hi[x] = T;
}

int jump(int x, int l) {
	for (int k = 0; k < LOG; ++k) {
		if (l & (1<<k)) {
			x = up[x][k];
		}
	}
	return x;
}

deque<int> cnt;
int dsu(int x, bool keep) {
	for (int v : g[x]) {
		if (v != big[x]) {
			dsu(v, 0);
		}
	}
	if (~big[x]) dsu(big[x], 1);
	cnt.resize(sz[x] - 1);
	cnt.emplace_front(1);
	for (int v : g[x]) {
		if (v != big[x]) {
			for (int p = lo[v]; p < hi[v]; ++p) {
				cnt[h[ver[p]]-h[x]] += 1;
			}
		}
	}
	for (auto q : qry[x]) {
		ans[q.second] = cnt[q.first]-1;
	}
	if (keep == 0) {
		cnt.clear();
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", r+i);
		g[r[i]].emplace_back(i);
	}
	dfs(0, -1);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {	
		int v, p;
		scanf("%d %d", &v, &p);
		if (h[v] <= p) ans[i] = 0;
		else {
			qry[jump(v, p)].emplace_back(p, i);
		}
	}
	dsu(0, 0);
	for (int i = 1; i <= m; ++i) {
		printf("%d ", ans[i]);
	} puts("");
	return 0;
}
