/**
 *	@name POI 2005 Double-Row
 *	@author Miguel Mini
 *	@tag bipartite-coloring
 *	@idea:
 *		- as there is always an answer, 
 *		an element cannot be repeated 
 *		more than twice.
 *
 *		- if the same elements are in 
 *		the same row, we can put an edge
 *		with weight 1 between these,
 * 	and if elements are in distinct
 *		rows an edge with weight 0.
 *
 *		- these edges define a bipartite
 *		graph (1-edge separate nodes into
 *		different sets and 0-edge in the same)
 *
 *		- it is clear that we need to keep
 *		 the minimum size set, these are the
 *		elements that we must change. (for
 *		each component)
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
vector<pair<int, int>> g[maxn];
int x[maxn], y[maxn];
int sz[maxn<<1];
bool vis[maxn];

void add(int x, int y, int e) {
	g[x].push_back({y, e});
	g[y].push_back({x, e});
}

void dfs(int x, int c) {
	sz[c] += 1;
	vis[x] = 1;
	for (auto v : g[x]) {
		if (vis[v.first]) continue;	
		dfs(v.first, c ^ v.second);
	}
}

int is_in[maxn << 1];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i];
	for (int i = 0; i < n; ++i) cin >> y[i];
	for (int i = 0; i < n; ++i) {
		if (is_in[x[i]] != 0) {
			add(i, abs(is_in[x[i]]) - 1, is_in[x[i]] > 0);
		}
		if (is_in[y[i]] != 0) {
			add(i, abs(is_in[y[i]]) - 1, is_in[y[i]] < 0);
		}
		is_in[x[i]] = i + 1;
		is_in[y[i]] = -(i + 1);
	}
	int c = 0, t = 0;
	for (int i = 0; i < n; ++i) {
		if (not vis[i]) {
			dfs(i, c);
			t += min(sz[c], sz[c+1]);
			c += 2;
		}
	}
	cout << t << endl;
	return 0;
}
