#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
const int LOG = 20;
vector<int> g[maxN];
vector<int> Set[maxN][LOG], people[maxN];
int up[maxN][LOG];
int h[maxN];
int n, m, q;

vector<int> Merge(vector<int> p, vector<int> q) {
	vector<int> ans;
	int i, j;
	for (i=0, j=0; i<p.size() and j<q.size();) {
		if (p[i] < q[j]) {
			ans.emplace_back(p[i++]);
		} else {
			ans.emplace_back(q[j++]);
		}
	}
	for (; i < p.size(); ++i) ans.emplace_back(p[i]);
	for (; j < q.size(); ++j) ans.emplace_back(q[j]);
	if (ans.size() > 10) {
		ans.resize(10);
	}
	return ans;
}

void dfs(int x, int parent, int height) {
	h[x] = height;
	Set[x][0] = people[x];
	up[x][0] = parent; 
	for (int k = 1; k < LOG; ++k) {
		Set[x][k] = Merge(Set[x][k-1], Set[up[x][k-1]][k-1]);
		up[x][k] = up[up[x][k-1]][k-1];
	}
	for (int v : g[x]) {
		if (v == parent) continue;
		dfs(v, x, height + 1);
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
		if (up[v][k] != up[u][k]) {
			u = up[u][k];
			v = up[v][k];
		}
	}
	return up[u][0];
}

vector<int> find(int u, int l) {
	vector<int> ans;
	for (int k = 0; k < LOG; ++k) {
		if (l&(1<<k)) {
			ans = Merge(ans, Set[u][k]);
			u = up[u][k];
		}
	}
	return ans;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	for (int i = 1; i <= m; ++i) {
		int c;
		scanf("%d", &c);	
		people[c].emplace_back(i);
	}	
	for (int i = 1; i <= n; ++i) {
		sort(begin(people[i]), end(people[i]));
		if (people[i].size() > 10) people[i].resize(10);
	} 
	dfs(1, 0, 0);
	while (q--) {
		int u, v, a;
		scanf("%d %d %d", &u, &v, &a);
		int anc = lca(u, v);
		vector<int> ans = people[anc];
		if (u != anc) ans = Merge(ans, find(u, h[u] - h[anc]));
		if (v != anc) ans = Merge(ans, find(v, h[v] - h[anc]));
		int k = min(a, (int)ans.size());
		printf("%d ", k);
		for (int i = 0; i < k; ++i) printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}
