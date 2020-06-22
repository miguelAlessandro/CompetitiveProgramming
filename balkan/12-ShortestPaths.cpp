/**
 *	@name ShortestPaths
 *	@author Miguel Mini
 *	@tags dijkstra, dfs, lca
 *	@idea:
 *		1.- we must see that all the edges of 
 *		relaxation form a directed acyclic graph.
 *
 *		2.- being the next construction on the 
 *		reverse of the lucky path, we take all the
 * 		nodes that are affected by node k, and we 
 *		make these the subtree of node k, in the 
 *		same way for k-1, k-2, ... , 1, in that order.
 *
 *		3.- Note that with this construction if we
 *		consider the edge path_i, path_{i+1}, the 
 *		minimum path from a to b takes a node from 
 *		the subtree of path_{i+1}, with a node in 
 *		the complement + the edge that connects them.
 *		
 *		4.- Now to have a good time, let's note that 
 *		we discard an edge when the lca is in the 
 *		current subtree. such that we can use a 
 *		multiset of the edges and discard it when its 
 *		lca is in our sub tree.
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10;
const int inf = 2e9;
const int LOG_N = 12;
typedef long long llong;
struct Node {
	int v;
	llong w;
};
vector<Node> g[maxn];
typedef pair<llong, int> plli;
llong sp_length;

void dijkstra(int s, vector<llong>& dist) {
	fill(begin(dist), end(dist), inf);
	priority_queue<plli,
				vector<plli>,
				greater<plli>> Q;
	auto add = [&](int node) {
		Q.push({dist[node], node});
	};
	dist[s] = 0; add(s);
	while (not Q.empty()) {	
		auto [w, v] = Q.top(); Q.pop();
		if (w != dist[v]) {
			continue;
		}
		for (auto node : g[v]) {		
			if (w + node.w < dist[node.v]) {
				dist[node.v] = w + node.w;
				add(node.v);
			}
		}
	}
}

bool vis[maxn];
int sttime[maxn], fttime[maxn];
int st[maxn][12];
int h[maxn];
vector<int> p;
vector<int> T[maxn];
int Time;

void make_tree(int root, int parent, int height, 
				vector<llong> dist[], int pos, 
				vector<int>& path) {
	sttime[root] = Time++;
	h[root] = height;
	vis[root] = 1;
	st[root][0] = parent;
	for (int k = 1; k < LOG_N; ++k) {
		st[root][k] = st[st[root][k-1]][k-1];
	}
	if (pos + 1 < path.size() 
		and path[pos] == root 
		and not vis[path[pos+1]]) {
		T[path[pos]].emplace_back(path[pos+1]);
		make_tree(path[pos+1], root, height+1, dist, pos+1, path);
	}
	for (auto node : g[root]) {
		if (vis[node.v] 
			or dist[0][root] + node.w != dist[0][node.v]) {
			continue;
		}
		T[root].emplace_back(node.v);
		make_tree(node.v, root, height+1, dist, pos, path);
	}
	fttime[root] = Time;
}

int jump(int x, int k) {
	for (int i = 0; i < LOG_N; ++i) {
		if (k & (1<<i)) {
			x = st[x][i];
		}
	}
	return x;
}

int lca(int x, int y) {
	if (h[x] > h[y]) swap(x, y);
	y = jump(y, h[y] - h[x]);
	if (x == y) {
		return x;
	}
	for (int k = LOG_N-1; k >= 0; --k) {
		if (st[x][k] != st[y][k]) {
			x = st[x][k];
			y = st[y][k];
		}		
	}
	return st[x][0];
}

bool is_parent(int x, int y) {
	return sttime[x] <= sttime[y] and fttime[y] <= fttime[x];
}

vector<llong> dist[2];
multiset<llong> candidates;
vector<llong> to_erase[maxn];

void update(int root, int x, int block) {
	vis[x] = 1;
	for (auto v : to_erase[x]) {
		candidates.erase(candidates.lower_bound(v));
	}
	for (auto node : g[x]) {
		if (x == root and node.v == block) { 
			continue;
		}
		if (is_parent(root, node.v)) {
			continue;
		}
		auto temp = dist[1][x] + dist[0][node.v] + node.w;
		to_erase[lca(x, node.v)].push_back(temp);
		candidates.insert(temp); 
	}
	for (int v : T[x]) {
		if (not vis[v]) {
			update(root, v, block);
		}
	}
}

llong solve() {
	if (candidates.empty()) return -1;
	return *candidates.begin();
}

int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	int k;
	cin >> k;
	p.resize(k);
	for (int i = 0; i < k; ++i) {
		cin >> p[i];
	}
	for (int i = 0; i < 2; ++i) {
		dist[i].resize(n+1);
	}
	dijkstra(s, dist[0]);
	dijkstra(t, dist[1]);
	sp_length = dist[0][t];
	make_tree(s, s, 0, dist, 0, p);
	fill(&vis[1], &vis[1]+n, 0);
	vector<llong> res;
	for (int i = k-1; i >= 1; --i) {
		update(p[i], p[i], p[i-1]); //cout << endl;
		res.push_back(solve());
	}
	reverse(begin(res), end(res));
	for (int e : res) cout << e << endl;
	return 0;
}
