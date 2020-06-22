/**
 *	@name Plimbare3
 *	@author Miguel Mini
 *	@tag	dp, dfs
 *	@idea
 *		- note that if we relocate 
 *		an edge and putin in other 
 *		place, the best option is 
 *		to join the diameters of 
 *		disconnected components.
 *
 *		- we can use dp in / out.
 *
 *		"in" part: calculate longest 
 *		path from root and diameter 
 *		from children subtrees and 
 *		join with current node.
 *
 *		"out" part: to each node we
 *		 can give the diameter from 
 *		all parents in a merge form, 
 * 	to this if we give this 
 *		information to child i, we 
 *		merge parent path information 
 *		and brother informations to 
 *		this node.
 *
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct Node {
	int v, id;
};
vector<Node> g[maxn];
int n;
struct Data { 
	int l, d; //longest path from root, diameter
};

//merge longest path, and diameters of components
Data merge(Data p, Data q) {
	return {max(p.l, q.l), max({p.d, q.d, p.l + q.l})};
}

vector<Data> in1[maxn], in2[maxn];

//"in" part
void dfs_in(int x, int p = 0) {
	in1[x].push_back({0, 0}); //root node information left to right
	for (auto& node : g[x]) {	
		if (node.v == p) { //traslate parent to final
			swap(node, g[x].back());
			if (node.v == p) continue;
		}
		dfs_in(node.v, x);
		auto q = in2[node.v][0];
		q.l += 1; //add edge from current node to child
		in1[x].push_back(q);
		in2[x].push_back(q);
	}	
	in2[x].push_back({0, 0}); //root node information right to left
	if (p) g[x].pop_back(); //erase parent 
	for (int i = 1; i < in1[x].size(); ++i) {	
		in1[x][i] = merge(in1[x][i], in1[x][i-1]); //merge left to right
	}
	for (int i = (int)in2[x].size() - 2; i >= 0; --i) {
		in2[x][i] = merge(in2[x][i], in2[x][i+1]); //merge right to left
	}
	//cerr << x << ": " << in2[x][0].l << " " << in2[x][0].d << endl;
}

int ans[maxn];
void dfs_out(int x, int p = 0, int id = 0, Data out = {-100000, -100000}) {
	//cerr << x << " " << out.l << " " << out.d << endl;
	if (p) { //get answet sum of diameters to a edge
		ans[id] = out.d + 1 + in2[x][0].d;
	}
	out.l += 1; //add erased edge
	out.d = max(out.d, out.l); //recalculate answer with new l 
	for (int i = 0; i < g[x].size(); ++i) {
		auto node = g[x][i];
		dfs_out(node.v, x, node.id, 
			merge(out, merge(in1[x][i], in2[x][i+1])) 
			/**parent path information and brother informations**/);
	}
}

int main() {
	freopen("plimbare3.in", "r", stdin);
	freopen("plimbare3.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n-1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back({v, i});	
		g[v].push_back({u, i});
	}
	dfs_in(1);
	dfs_out(1);
	for (int i = 1; i <= n-1; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
