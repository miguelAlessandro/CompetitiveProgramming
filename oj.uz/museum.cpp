/**
 *	@name museum
 *	@author Miguel Mini
 *	@tag dp, trees
 *	@idea 
 *		- considere knapsack solution to 
 *		every node.
 *
 *		- this has the form:	
 *			dp[x][i] = min(dp[x][j] + dp[v][i-j])
 *		with v in child(x).
 *
 *		- suppose we have processed k child 
 *		trees with number of nodes s and we 
 * 		process k+1 child tree, with m nodes.
 *		then (i, j) has only s * m states, 
 *		note that these are the number of paths
 *		from the current child tree to those 
 *		already processed, as all pass through 
 *		x, this is the number of lca between 
 *		those two sets.
 *		
 *		Since each pair of nodes has a unique 
 *		lca, the number of states reviewed by 
 *		all nodes is O(n^2).
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 2;
int n, k, x;
int sz[maxn];
int memo[maxn][maxn][2];
int nxt[maxn<<1], head[maxn];
int to[maxn<<1], value[maxn<<1];

void dfs(int x, int p) {
	sz[x] = 1;
	memo[x][1][0] = memo[x][1][1] = 0;
	for (int e = head[x]; ~e; e = nxt[e]) {
		int v = to[e], w = value[e];
		if (v == p) continue;
		dfs(v, x);
		for (int i = min(sz[x] + sz[v], k); i >= 2; --i) {
			for (int j = min(sz[v], i-1); j >= max(1, i - sz[x]); --j) {
				memo[x][i][1] = min(memo[x][i][1],
					min(
						memo[x][i-j][1] + memo[v][j][0] + (w<<1),
						memo[x][i-j][0] + memo[v][j][1] + w
					));
				memo[x][i][0] = min(memo[x][i][0], 
					memo[x][i-j][0] + memo[v][j][0] + (w<<1));
			}
		}	
		sz[x] += sz[v];
	}
}

int main() {
	scanf("%d %d %d", &n, &k, &x);
	memset(head, -1, sizeof head);
	for (int i = 1; i <= n-1; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		to[i<<1] = b; 
		value[i<<1] = c; nxt[i<<1] = head[a]; head[a] = i<<1;
		to[i<<1|1] = a; 
		value[i<<1|1] = c; nxt[i<<1|1] = head[b]; head[b] = i<<1|1;
	}
	memset(memo, 63, sizeof memo);
	dfs(x, 0);
	printf("%d\n", memo[x][k][1]);	
	return 0;
}
