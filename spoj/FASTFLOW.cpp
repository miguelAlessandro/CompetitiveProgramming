/**
 *	@name SPOJ - FASTFLOW
 *	@author Miguel Mini
 *	@tag dinic, network-flow
 *	@idea
 *			- using my dinic library
**/
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define trav(i, x) for (auto i : x)
#define re(x, y, z) for (int x=y; x<z; ++x)
#define eb emplace_back
#define fillall(x, v) fill(all(x), v)
using namespace std;
using ll = long long;
using vi = vector<int>;
const int inf = 1e9;
struct Dinic {
	struct Edge {
		int to, cap, flow, link;
		Edge() {}
		Edge(int to, int cap, int link, int flow=0):
			to(to), cap(cap), link(link), flow(flow) {}
	};
	vector<vector<Edge>> g;
	vi d, pt;
	
	Dinic(int n): g(n), d(n), pt(n) {}

	void addEdge(int a, int b, int cap) {
		if (a == b) return;
	  int pa = sz(g[a]), pb = sz(g[b]);
		g[a].eb(b, cap, pb); g[b].eb(a, 0, pa);
	}

	bool bfs(int src, int snk) {
		queue<int> q({src});
		fillall(d, inf);
		d[src] = 0;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			if (v == snk) return true;
			trav(e, g[v]) {
				if (e.flow >= e.cap) continue;
				if (d[e.to] > d[v] + 1) {
					d[e.to] = d[v] + 1;
					q.emplace(e.to);
				}
			}
		}
		return false;
	}

	int dfs(int x, int snk, int flow=inf) {
		if (x == snk || !flow) return flow;
		for (; pt[x] < sz(g[x]); ++pt[x]) {
			auto& e = g[x][pt[x]];
			if (d[e.to] == d[x] + 1) {
				int res = min(e.cap - e.flow, flow);
				if (int push = dfs(e.to, snk, res)) {
					e.flow += push;
					g[e.to][e.link].flow -= push;
					return push;
				}
			}
		}
		return 0;
	}

	ll solve(int s, int t) {
		ll res = 0;
		while (bfs(s, t)) {
			fillall(pt, 0);
			while (int flow = dfs(s, t)) {
				res += flow;
			}
		}
		return res;
	}
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Dinic solver(n);
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		solver.addEdge(a-1, b-1, c);
		solver.addEdge(b-1, a-1, c);
	}
	printf("%lld\n", solver.solve(0, n-1));
	return 0;	
}
