/**
 * @name IOI 2011 garden
 *	@author Miguel Mini
 *	@tag bfs, functional_graph, number_theory
 * @idea
 *		- if we consider that a node can
 * 	only go through the smallest or 
 *		the second smallest edge, and 
 *		divide each node into those two
 *		possibilities, we will have a 
 *		functional graph with at most 
 *		a cycle by component.
 *
 *		- we can send a bfs by the two
 *		final nodes (p, p), and consider   
 *		two types of response depending
 *		on p is or not in a cycle. 
 *
 *		- if p is not in a cycle, we 
 *		only consider distance to the 	
 *		other nodes in the transposed
 *		graph.
 *
 *		- in other case, we consider 
 *		distance plus a multiple of the
 *		cycle size. To optimize we 
 *		consider distance + k * len_cycle < 2*n.
 *		2*n-1 is the largest distance with bfs
 *		and substract len_cycle from the query 
 *		to do query - k * len_cycle < 2*n.
 */

#include <bits/stdc++.h>
#include "gardenlib.h"
using namespace std;

int _left(int x) {
	return x<<1;
}

int _right(int x) {
	return x<<1|1;
}

bool is_left(int x) {
	return _left(x/2) == x;
}

vector<int> make_functional_graph(int n, int E[][2], int m) {
	vector<int> F(2 * n);
	vector<vector<int>> best(n);
	for (int i = 0; i < m; ++i) {
		int u = E[i][0], v = E[i][1];
		best[u].emplace_back(v);
		best[v].emplace_back(u);
	}
	for (int i = 0; i < n; ++i) {
		if (best[i].size() == 1) {
			best[i].emplace_back(best[i][0]);
		}
	}
	for (int i = 0; i < n; ++i) {
		int a = best[i][0], b = best[i][1];
		F[_left(i)] = best[a][0] == i ? (best[a][0] == best[a][1] ? _left(a) : _right(a)) : _left(a);
		F[_right(i)] = best[b][0] == i ? (best[b][0] == best[b][1] ? _left(b) : _right(b)) : _left(b);
	}
	return F;
}

vector<vector<int>> make_reverse_functional(vector<int> F) {
	vector<vector<int>> Gt(F.size());
	for (int i = 0; i < F.size(); ++i) {	
		Gt[F[i]].emplace_back(i);
	}
	return Gt;
}

const int inf = 1e9;
vector<int> bfs(vector<vector<int>> G, int src) {
	vector<int> dis(G.size(), inf);
	dis[src] = 0;
	queue<int> Q;
	Q.push(src);
	while (not Q.empty()) {
		int q = Q.front(); Q.pop();
		for (int v : G[q]) {
			if (dis[q] + 1 < dis[v]) {
				dis[v] = dis[q] + 1;
				Q.push(v);
			}
		}
	}
	return dis;
}

vector<int> get_cycle_from_functional(vector<int> F, int x) {
	vector<int> cycle;
	vector<bool> vis(F.size());
	while (not vis[x]) {
		vis[x] = 1;
		x = F[x];
	}
	int t = x;
	do {
		cycle.emplace_back(x);
		x = F[x];
	} while (x != t);
	return cycle;
}

bool is_in(int t, vector<int> v) {
	for (int e : v) {
		if (e == t) {
			return 1;
		}
	}
	return 0;
}

vector<int> solve(vector<int> F, int x) {
	auto dis = bfs(make_reverse_functional(F), x);
	auto cycle = get_cycle_from_functional(F, x);
	int cycle_len = cycle.size();
	int n = F.size();
	vector<int> ans(n);
	if (is_in(x, cycle)) {
		for (int i = 0; i < n; ++i) {
			if (dis[i] >= inf) continue;
			if (not is_left(i)) continue; 
			ans[dis[i]] += 1;
		}
		for (int i = 0; i + cycle_len < n; ++i) {
			ans[i + cycle_len] += ans[i];
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if (dis[i] >= inf) continue;
			if (not is_left(i)) continue;
			ans[dis[i]] += 1;
		}
	}
	return ans;
}

void count_routes(int n, int m, int p, int R[][2], int q, int Q[]) {
	auto G = make_functional_graph(n, R, m);
	auto ans1 = solve(G, _left(p));
	auto ans2 = solve(G, _right(p));
	auto cycle_l = get_cycle_from_functional(G, _left(p));
	auto cycle_r = get_cycle_from_functional(G, _right(p));
	bool o1 = is_in(_left(p), cycle_l);
	bool o2 = is_in(_right(p), cycle_r);
	int c_l_len = cycle_l.size();
	int c_r_len = cycle_r.size();
	for (int i = 0; i < q; ++i) {
		int temp = 0;
		if (o1) {
			if (Q[i] < 2*n) temp += ans1[Q[i]];
			else temp += ans1[Q[i] - ((Q[i] - 2 * n) / c_l_len + 1) * c_l_len];
		} else {
			temp += (Q[i] >= 2*n ? 0 : ans1[Q[i]]);
		}
		//if (G[_left(p)] != G[_right(p)]) {
		if (o2) {
			if (Q[i] < 2*n) temp += ans2[Q[i]];
			else temp += ans2[Q[i] - ((Q[i] - 2 * n) / c_r_len + 1) * c_r_len];
		} else {
			temp += (Q[i] >= 2*n ? 0 : ans2[Q[i]]);
		}
		//}
		answer(temp);
	}
}

