/**
 * @author Miguel Mini
 * @tag centroid decomposition
 * @idea
 *    - this is an overkill approach O(nlogn)
 *    solve for a especific root and conquer.
**/

#include <bits/stdc++.h>
using namespace std;

struct CentroidDecomposition {
	vector<vector<int>> T;
	vector<int> sz, P;
	vector<bool> block;
	CentroidDecomposition(int n):
		T(n), sz(n), block(n), P(n) {}
	void addEdge(int a, int b) {
		T[a].emplace_back(b);
		T[b].emplace_back(a);
	}
	void dfs(int x, int p=-1) {
		P[x] = p;
		sz[x] = 1;
		for (auto node : T[x]) {
			if (block[node] or node == P[x]) continue;
			dfs(node, x);
			sz[x] += sz[node];
		}
	}
	int find_centroid(int x, int n) {
		int mx = 0, big = -1;
		for (auto node : T[x]) {
			if (block[node] or node == P[x]) continue;
			if (mx < sz[node]) {
				mx = sz[node];
				big = node;
			}
		}
		mx = max(mx, n - sz[x]);
		if (2 * mx <= n) return x;
		return find_centroid(big, n);
	}
	long long decomposition(int x, int n, int k) {
		dfs(x);
		int cen = find_centroid(x, n);
		long long ans = solve(cen, k);
		block[cen] = 1;
		for (auto v : T[cen]) {
			if (block[v]) continue;
			if (v == P[cen]) sz[v] = n - sz[cen];
			ans += decomposition(v, sz[v], k);
		}
		return ans;
	}
	long long memo[510];
	long long _dfs(int x, int k, int nx, int p=-1, int h = 0) {
		if (h > k) return 0;
		long long ans = 0;
		if (nx) ans += memo[k - h];
		else memo[h] += 1;
		for (int v : T[x]) {
			if (block[v] or v == p) continue;
			ans += _dfs(v, k, nx, x, h+1);	
		}
		return ans;
	}
	long long solve(int x, int k) {
		memset(memo, 0, sizeof memo);		
		memo[0] = 1;	
		long long ans = 0;	
		for (int v : T[x]) {
			if (block[v]) continue;
			ans += _dfs(v, k, 1, x, 1);
			_dfs(v, k, 0, x, 1);
		}
		return ans;
	}
};

int main() {	
	int n, k;
	cin >> n >> k;
	CentroidDecomposition solver(n);
	for (int i = 1; i <= n-1; ++i) {
		int a, b;
		cin >> a >> b;
		a -= 1; b -= 1;
		solver.addEdge(a, b);
	}
	cout << solver.decomposition(0, n, k) << endl;
	return 0;
}
