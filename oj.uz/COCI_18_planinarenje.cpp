/**
 *	@name COCI 2018 planinarenje
 *	@author Miguel Miní
 *	@tag bipartite-matching, maxflow-theory
 *	@idea
 *		- affirmation:	if i-th peak is not 
 *		in all maximum matching, then this 
 *		is a win position, in other case is 
 *		a win position.
 *
 *		- proof: suppose a maximum match 
 *		without this peak, then, we take an
 *		arbitrary edge (this edge have a final
 *		endpoint in a match, in other case
 *		we can add this edge to matching). 
 *		any election to the second player 
 *		leave to first player select an edge
 *		with a matching endpoint, in other
 *		case this is a aumenting path and 
 *		flow increasing by one.
 *
 *		in other case, every selection is 
 *		a match and second player have the
 *		the same strategy.
 *		
 *		to accomplish this strategy, we 
 *		can erase current peak if is in a match
 *		and re run maxflow one step.
 *
**/


#include <bits/stdc++.h>
using namespace std;

struct BipartiteMatcher {
	vector<vector<int>> g;
	vector<int> L, R;
	vector<bool> vis;
	BipartiteMatcher(int n, int m):
		g(n), L(n, -1), 
		R(m, -1), vis(n) {} 

	void addEdge(int a, int b) {
		g[a].push_back(b);
	}	

	bool match(int x) {
		if (vis[x]) return 0;
		vis[x] = 1;
		for (int v : g[x])
			if (R[v] == -1) 
				return R[L[x] = v] = x, 1;
		for (int v : g[x])
			if (match(R[v]))
				return R[L[x] = v] = x, 1;
		return 0;
	}

	vector<int> solve() {
		int cnt = 1;
		while (cnt--) {
			fill(vis.begin(), vis.end(), 0);
			for (int i = 0; i < L.size(); ++i)
				cnt |= L[i] == -1 and match(i);
		}
		vector<int> res(L.size());
		for (int i = 0; i < L.size(); ++i) {
			if (L[i] == -1) res[i] = 1;
			else {
				fill(vis.begin(), vis.end(), 0);
				vis[i] = 1;	
				int v= L[i];	
				R[v] = -1; L[i] = -1;
				cnt = 0;
				for (int i = 0; i < L.size(); ++i) {
					cnt |= L[i] == -1 and match(i);
				}
				if (cnt) {
					res[i] = 1;
				} else {
					res[i] = 0;
					R[L[i] = v] = i; 
				}
			}
		}
		return res;
	}
};

int main() {
	int n, m;	
	cin >> n >> m;
	BipartiteMatcher BM(n, n);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		BM.addEdge(a - 1, b - 1);
	}
	vector<int> res = BM.solve();
	for (int v : res) {
		cout << (v ? "Mirko" : "Slavko") << endl;
	}
	return 0;
}
