/**
 * @name Baltic 2019 valley
 * @author Miguel Mini
 * @tag dfs, binary_lifting, timestamp
 * @idea
 *			- we make e the root, and we 
 *			calculate for each node, what 
 *			is the distance to the nearest 
 *			store in its subtree.
 *
 *			- be a query q_i = (a, b), and
 *			we do that h[a] < h[b]. 
 *	
 *			1.- if b is not ancestor of R, the
 *			answer is "espace".
 *	
 *			2.- if b dont have a shop in its
 *			subtree, the answer is "oo".
 *	
 *			3.- otherwise, the response takes 
 *			a root how lca in the path from R 
 *			to b. if that root is x, the answer
 *			is distance from x to nearest root
 *			in its subtree + distance from x
 *			to R, that answer is:
 *
 *				- dist_to_shop[x] + height[R] - height[x]
 *
 *			= (dist_to_shop[x] - height[x]) + height[R]		
 *
 *			This means that we must find the minimum
 *			value of this in the path from R to x.
 *	
 *			- we can make this with a simple binary 
 *			lifting.
**/

#include <bits/stdc++.h>
#define re(x, y, z) for (int x=y; x<z; ++x)
#define trav(v, x) for (int v : x)
#define eb emplace_back
using namespace std;
const int maxn = 1e5 + 10;
long long h[maxn];
int lo[maxn], hi[maxn];
long long down[maxn];
using ii = pair<int, int>;
vector<ii> g[maxn];
int n, s, q, e;
ii edges[maxn];
bool shop[maxn];
const int LOG = 18;
int up[maxn][LOG];
long long st[maxn][LOG];
using lli = pair<long long, int>;
const long long inf = 1e18;
int T = 0;
int step[maxn];

void dfs(int x, int p, long long he) {
	h[x] = he;
	step[x] = step[p]+1;
	lo[x] = T++;
	down[x] = shop[x] ? 0 : inf;
	for (auto node : g[x]) {
		if (node.first == p) continue;
		dfs(node.first, x, he + node.second);
		down[x] = min(down[x], down[node.first] + node.second);
	}
	hi[x] = T++;
}

void dfs2(int x, int p) {
	st[x][0] = down[x] - h[x];
	up[x][0] = p==0?x:p;
	for (int k = 1; k < LOG; ++k) {
			st[x][k] = min(st[x][k-1], st[up[x][k-1]][k-1]);
			up[x][k] = up[up[x][k-1]][k-1];
	}
	for (auto node : g[x]) {
		if (node.first == p) continue;
		dfs2(node.first, x);
	}
}

bool isParent(int x, int y) {
	return lo[x] <= lo[y] and hi[y] <= hi[x];
}

long long query(int x, int y) {
	int len = step[x] - step[y] + 1;
	long long ans = inf;
	for (int k = 0; k < LOG; ++k) {
		if (len & (1<<k)) {
			ans = min(ans, st[x][k]);
			x = up[x][k];
		}
	}
	return ans;
}

int main() {
	scanf("%d%d%d%d", &n, &s, &q, &e);
	re(i, 1, n) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		g[a].eb(b, w);
		g[b].eb(a, w);
		edges[i] = {a, b};
	}
	re(i, 0, s) {
		int c;
		scanf("%d", &c);
		shop[c] = 1;
	}
	dfs(e, 0, 0);
	dfs2(e, 0);
	re(i, 0, q) {
		int I, R;
		scanf("%d%d", &I, &R);
		int a = edges[I].first, b = edges[I].second;
		if (h[a] > h[b]) swap(a, b);
		if (isParent(b, R)) {
			if (down[b] == inf) puts("oo");
			else {
				long long res = query(R, b) + h[R];
				if (res >= inf) puts("oo");
				else printf("%lld\n", res);
			}
		} else puts("escaped");
	}
	return 0;
}
