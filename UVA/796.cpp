#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5 + 10;
bool vis[MAX_N];
int fup[MAX_N], tin[MAX_N];
vector<int> adj[MAX_N];
vector<pair<int, int>> brid;
int n, timer;

void dfs(int x, int p) {
	vis[x] = 1;
	tin[x] = fup[x] = timer++;
	for (int v : adj[x]) {
		if (v == p) continue;
		if (vis[v]) fup[x] = min(fup[x], tin[v]); 
		else {
			dfs(v, x);
			fup[x] = min(fup[x], fup[v]);
			if (fup[v] > tin[x]) {
				int a = x, b = v;
				if (a > b) swap(a, b);
				brid.push_back({a, b});
			}
		}
	}
}

int main () {

	while (scanf ("%d", &n) == 1) {
		for (int i = 0; i < n; ++i) adj[i].clear();

		for (int i = 1; i <= n; ++i) {
			int u, k;
			scanf ("%d (%d)", &u, &k);
			for (int j = 1; j <= k; ++j) {
				int v; scanf ("%d", &v);
				adj[u].emplace_back(v);
			}
		}

		for (int i = 0; i < n; ++i)
			vis[i] = 0;
		brid.clear();
		for (int i = 0; i < n; ++i) {
			if (not vis[i]) {
				timer = 0;
				dfs(i, -1);
			}
		}
		printf ("%d critical links\n", (int)brid.size());
		sort(brid.begin(), brid.end());
		for (auto e : brid)
			printf ("%d - %d\n", e.first, e.second);
		puts("");
	}

	return 0;
}
