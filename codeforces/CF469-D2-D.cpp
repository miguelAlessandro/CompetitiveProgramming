/**
 *  codeforces 469-D2-D
 *  @overview find a partition array such that x in A then a-x is in A and if x in B then b-x is also in B
 *  - 2sat representation
 *  - if x isnt in A then force to B and visceverse
 */

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
bool vis[MAX_N];
int color[MAX_N], val[MAX_N];
vector<int> order, g[MAX_N], gt[MAX_N];
bool ass[MAX_N];
int n, a, b;

void dfs(int x) {
	vis[x] = 1;
	for (int v : g[x])
		if (not vis[v])
			dfs(v);
	order.emplace_back(x);
}

void dfsT(int x, int c) {
	color[x] = c;
	for (int v : gt[x])
		if (not color[v])
			dfsT(v, c);
}

bool solve() {
	for (int i = 0; i < n; ++i)
		if (not vis[i])
			dfs(i);
	reverse(order.begin(), order.end());
	int T = 1;
	for (int i = 0; i < n; ++i)
		if (not color[order[i]])
			dfsT(order[i], T++);
	for (int i = 0; i <  n; i += 2) {
		if (color[i] == color[i|1]) return false;
		ass[i>>1] = color[i] > color[i|1];
	}
	return true;
}

void addEdge(int u, int v) {
    g[u].emplace_back(v);
    gt[v].emplace_back(u);
}

int main () {

	scanf ("%d %d %d", &n, &a, &b);
	map<int, int> id;
	for (int i = 0; i < n; ++i) {
		scanf("%d", val+i);
		id[val[i]] = 2*i;
	}

	for (auto x : id) {
	    int u = x.second;
		if (id.count(a-x.first)) {
		    int v = id[a-x.first];
			addEdge(u, v);
			addEdge(v^1, u^1);
		} else addEdge(u, u^1);
	
		if (id.count(b-x.first)) {
		    int v = id[b-x.first];
		    addEdge(u^1, v^1);
			addEdge(v, u);
		} else addEdge(u^1, u);
	}
	n <<= 1;
	if(solve()) {
		    puts("YES");
		    for (int i = 0; i < n/2; ++i) {
			    printf("%d ", ass[i]^1);
		    }
		    puts("");
	} else puts("NO");
	
	return 0;
}
