/**
 *  SPOJ - TREEISO
 *  @overview given two trees T1 and T2, put YES if T1 is isomorphic to T2 and NO in other case. 
 *  hints:
 *      - if two rooted trees are isomorphic, then its possible traverse in same way the trees.
 *      - if consider string traverse: "a" when a edge is traverse from root to leaf and "b" (b != a)
 *      in opposite case, then it's possible build similar string traverse to trees.
 *      - build similar string traverse: hash(root) = [a, concatenate hash(son) to all sons in order, b].  
 *      - how to find root in a tree? theorem: a tree has 1 or 2 centers, then compare a center of one and centers in other.
 *      - find a center its possible if know diameter, this is in mid of that.
 *      - find diameter: bfs from a vertex and find farthest vertex, bfs from this farthest vertex and find farthest.
 *      They vertex are diametrically opposed.
 */


#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int p = 257;
const int MAXN = 2e5+20;
vector<int> g[2][MAXN];
int P[MAXN];
bool vis[MAXN];
int sz[MAXN];
int phi[2][MAXN];
int t, n;

int add(int a, int b) {
	return (a+b)%mod;
}

int mul(long long a, long long b) {
	return a*b%mod;
}

int bfs(int k, int src) {
	for (int i = 1; i <= n; ++i)
		vis[i] = 0;
	queue<int> Q;
	Q.push(src);
	vis[src] = 1;
	while (not Q.empty()) {
		int q = Q.front(); Q.pop();
		for (int v : g[k][q]) {
			if (not vis[v]) {
				vis[v] = 1;
				phi[k][v] = q;
				Q.push(v);
			}
		}
		
		if (Q.empty()) return q;
	}
}

int dfsHash(int k, int x, int p) {

	vector<pair<int, int>> hashSon;
	sz[x] = 1;
	
	for (int v : g[k][x]) {
		if (v == p) continue;
		hashSon.push_back({dfsHash(k, v, x), v});
		sz[x] += sz[v];
	}
	
	sort(hashSon.begin(), hashSon.end());
	
	int _hash = 5, pot = 1;
	for (auto hs : hashSon) {
		_hash = add(_hash, mul(hs.first, P[pot]));
		pot += 2*sz[hs.second];
	}
	return _hash = add(_hash, mul(11, P[pot]));
}

int main() {
	
	P[0] = 1;
	for (int i = 1; i <= 200010; ++i)
		P[i] = mul(P[i-1], p);
	
	scanf ("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<int> c[2];
		int d[2][2];
		for (int k = 0; k < 2; ++k) {
			c[k].clear();
			for (int i = 1; i <= n; ++i)
				g[k][i].clear();
			for (int i = 1; i < n; ++i) {
				int a, b;
				scanf("%d %d", &a, &b);
				g[k][a].emplace_back(b);
				g[k][b].emplace_back(a);
			}
			d[k][0] = bfs(k, 1);
			d[k][1] = bfs(k, d[k][0]);
		
			vector<int> diam;
			while (1) {
				diam.emplace_back(d[k][1]);
				if (d[k][1] == d[k][0]) break;
				d[k][1] = phi[k][d[k][1]];
			}
			int len = diam.size();
			c[k].emplace_back(diam[len/2]);
			if (len%2 == 0) c[k].emplace_back(diam[len/2-1]);
		}
		
		if (c[0].size() != c[1].size()) {
			puts("NO");
		} else {
			vector<int> deg[2];
			for (int k = 0; k < 2; ++k) {
				for (int i = 1; i <= n; ++i)
					deg[k].push_back(g[k][i].size());
				sort(deg[k].begin(), deg[k].end());
			}
			
			if (deg[0] != deg[1]) {
				puts("NO");
			} else {
				vector<int> h[2];
				
				h[1].push_back(dfsHash(1, c[1][0], 0));
				bool ok = 0;
				for (int k = 0; k < c[0].size(); ++k) {
					h[0].push_back(dfsHash(0, c[0][k], 0));
					ok |= h[1][0] == h[0][k];
				}
				
				puts(ok ? "YES" : "NO");
			}
		}	
	}
	return 0;
}
