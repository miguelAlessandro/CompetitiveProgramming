/**
 *	@name COCI 2016 Mag
 *	@author Miguel Mini
 *	@tag dp, changing-root-trick
 *	@idea
 *			- affirmation: the answer is always 
 *			a node that spans over nodes 1.
 *
 *			- if node has value more than 2, let
 *			x, then this node need x neighbors 
 *			paths to be better, but degree can
 *			be at most 2.
 *
 *			- if a node has value 1, this analysis 
 *			is trivial, and if the value is 2, we
 *			can be better if neighbors paths extends
 *			as much as possible (and values are the same).)
 *
 *			- to design a good algorithm, we can use
 *			the changing root trick, this is similar to
 *			finding diameter of a tree with dp, but after
 *			processing the answer, we can push down 
 *			information from root to the children, be 
 *			careful with to push down the information 
 *			that child gave you. So each child can become 
 *			root and the problem can be solved individually.
 *
 *			complexity: O(n)
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
vector<int> g[maxn], len[maxn];
int a[maxn];
int memo[maxn];
int n;

void add(int x, int t) {
	if (len[x][0] <= t) swap(len[x][0], t);
	len[x][1] = max(len[x][1], t);
}

int get(int x, int t=0) {
	return (a[x] == 1) * (len[x][t] + 1);
}

int dfs(int x, int p = 0) {
	len[x] = {0, 0};
	for (int v : g[x]) {
		if (v == p) continue;
		add(x, dfs(v, x));
	}
	return get(x);
}

int dfs_root(int x, int p = 0) {
	if (p) {
		add(x, (a[p] == 1) *  get(p, len[p][0] == get(x)));
	}
	memo[x] = len[x][0] + len[x][1];
	for (int v : g[x]) {
		if (v == p) continue;
		dfs_root(v, x);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n-1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	dfs(1);
	dfs_root(1);
	int x = -1, y = -1;
	for (int i = 1; i <= n; ++i) {
		if (x == -1 or x *1ll* (memo[i] + 1) > a[i] *1ll* y) {
			x = a[i];
			y = memo[i] + 1;
		}
	}
	int g = __gcd(x, y);
	printf("%d/%d\n", x/g, y/g);
	return 0;
}
