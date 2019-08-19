/**
 * @name Atcoder 103 ARC F
 * @author Miguel Mini
 * @tag greedy, graph, dp, constructive 
 * @idea:
 *		- note than if we have the values d_1 < d_2 < d_3 < ... < d_n
 *		and suppose 1 is the root of the tree, then if exist a path
 *		from 1 to any leaf, this path is increasing respect to d, 
 *		this is because d_2 = d_1 + n - 2*sz_2, so than sz_2 < n/2
 *		and how sz decrease then d_i increase, and is necesary than 
 *	 	d_n is a leaf. so we proccess big values to small, and finally
 *		check d values. 
 */

#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
long long d[maxN], ans[maxN];
int sz[maxN], sz_2[maxN];
int n;
vector<int> g[maxN];

void dfs(int x, int p = 0) {
	sz[x] = 1;
	ans[x] = 0;
	for (int v : g[x]) {
		if (v == p) continue;
		dfs(v, x);
		sz[x] += sz[v];
		ans[x] += sz[v] + ans[v];
	}
}

void dfs_2(int x, int p = 0) {
	if (p) {
		ans[x] += sz[p] - 2*sz[x] + ans[p] - ans[x];
		sz[x] = sz[p];
	}
	for (int v : g[x]) {
		if (v == p) continue;
		dfs_2(v, x);
	}
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> d[i];
	for (int i = 1; i <= n; ++i) sz_2[i] = 1;
	map<long long, int, greater<long long>> p;
	for (int i = 1; i <= n; ++i) p[d[i]] = i;
	bool fun = 1;
	while (p.size() > 1) {
		auto f = p.begin(); p.erase(f);
		long long d_p = (f->first + 2*sz_2[f->second] - n);
		fun &= p.count(d_p);
		if (not fun) break;
		int r = p[d_p];
		sz_2[r] += sz_2[f->second];
		g[r].push_back(f->second);
		g[f->second].push_back(r);
	}
	dfs(1);
	dfs_2(1);
	for (int i = 1; i <= n; ++i) fun &= d[i] == ans[i];
	if (fun) {
		for (int i = 1; i <= n; ++i) {
			for (int v : g[i])
				if (i < v) cout << i << " " << v << endl;
		}
	} else puts("-1");
	return 0;
}
