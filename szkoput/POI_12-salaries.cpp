/**
 * @name SALARIES
 * @author Miguel Mini
 * @tag greedy, dfs
 * @idea
 *		- start with the lowest marked node with at least 
 *		- a not-marked child, if all available values to
 *		- this node is equal to the number of no-marked
 *		- children in its subtree, then use these to mark,
 *		- if these values are greater, every value dont 
 *		- is available now, erase the number of no marked 
 *		- nodes in its subtre and mark how no available
 *		- the others, repeat this process (and in the end,
 *		assign to 0 avery node with z not available).
 *		
 *		- how to mark nodes in a subtree?
 *			this is only possible if the subtree start 
 *			with a path (and apply only to path nodes).
 *			take the largest available z and use this 
 *			to this nodes.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n;
int p[maxn], z[maxn];
bool vis[maxn];
int nxt[maxn];
vector<int> g[maxn];
int deg[maxn];
int sz[maxn];
int c[maxn];

void dfs(int x) {
	sz[x] = z[x] == 0;
	for (int v : g[x]) {
		dfs(v);
		if (z[v] == 0) {
			nxt[x] = v;
			sz[x] += sz[v];
		} else deg[x] -= 1;
	}
	c[z[x]] = x;
}

int main() {
	scanf("%d", &n);
	int root;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", p+i, z+i);
		vis[z[i]] = 1;
		if (p[i] == i) {
			z[root = i] = n;
		} else {
			g[p[i]].push_back(i);
			deg[p[i]] += 1;
		}
	}
	dfs(root);
	deque<int> pending;
	for (int i = 1; i <= n; ++i) {
		if (not vis[i]) {
			pending.push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (c[i] and sz[c[i]] > 0) {
			int u = c[i];
			deque<int> t, s;
			while (deg[u] == 1) {
				t.push_back(nxt[u]);
				u = nxt[u];
			}
			while (not pending.empty() and pending.front() < i) {
				s.push_front(pending.front());
				pending.pop_front();
			}
			if (s.size() <= sz[c[i]]) {
				for (int j = 0; j < min(s.size(), t.size()); ++j) {
					z[t[j]] = s[j];
				}
			} else {
				for (int j = 0; j + sz[c[i]] < s.size(); ++j) {
					pending.push_front(0);
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", z[i]);	
	}
	return 0;
}
