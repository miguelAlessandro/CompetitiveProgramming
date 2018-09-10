/**
 *  spoj buglife
 *  @overview: given a graph, solve if there exist odd cycle.
 *  - first method: bicoloring
 *  - second and current method: if p has some color and there exist p-q interaction, then:
 *  - p<->!q and !p<->q, solve if p and !p are in different component.
 */


#include <bits/stdc++.h>
using namespace std;
class Graph {
	vector<vector<int>> adj;
	vector<bool> vis;
	vector<int> color;
	int n;
	public:
		Graph(int n) {
			init(n);
		}
	
		void init(int n) {
			this->n = n;
			adj.resize(n, vector<int>());
			vis.resize(n, 0);
			color.resize(n);
		}
		void addEdge(int a, int b) {
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		void dfs(int x, int c) {
			vis[x] = 1;
			color[x] = c;
			for (int v : adj[x])
				if (not vis[v])
					dfs(v, c);			
		}
		bool solve() {
			int T = 0;
			for (int i = 0; i < n; ++i) {
				if (not vis[i]) {
					dfs(i, T++);
				}
			}
			for (int i = 0; i < n; i += 2) {
				if (color[i] == color[i|1]) {
					return false;
				}
			}
			return true;
		}
};


int main () {
	
	int testCases, nBug, interactions, nc = 1;
	scanf("%d", &testCases);
	while (testCases--) {
		scanf("%d %d", &nBug, &interactions);
		Graph G(nBug<<1);
		for (int i = 1; i <= interactions; ++i) {
			int bug1, bug2;
			scanf("%d %d", &bug1, &bug2);
			bug1--; bug2--;
      //trick p is 2*p and p+1 is 2*p+1, then check is value(p)^1.
			G.addEdge(bug1<<1, bug2<<1|1);
			G.addEdge(bug1<<1|1, bug2<<1);
		}
		printf ("Scenario #%d:\n", nc++);
		puts( not G.solve() ? "Suspicious bugs found!" : "No suspicious bugs found!");
	}
	
	return 0;
}
