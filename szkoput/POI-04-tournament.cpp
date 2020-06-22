/**
 * @problem: The Tournament
 * @author: Miguel Mini
 * @tags: greedy, topological sort 
 * @idea:
 *		- let W be the set of possible winners 
 *		and L the set of always losers.
 *		
 * 		- affirmation: for every graph of n nodes, every 
 *		node in W,  has an edge towards every node in L.
 *
 *		- proof:
 *			 for n = 1, the test is trivial. suppose it is 
 *			 true for all n <= k, and be a arbitrary graph with 
 *			 k + 1 nodes, if we take a node v in W, and every 
 *			 other node in W has an edge towards v, then v is in L 
 *			 (easy to prove ), in another case there is a node u in W 
 *			 that does not have an edge towards v, in the same 
 *			 way there is a node in W that does not have an edge to u, 
 *			 and so on, let us denote this path (x_0, x_1,. .., x_k) 
 *			 with x_0 = v, x_1 = u, ... with x_k with edge to every 
 *			 node in W / (x_0, x_1, ..., x_k) and also be a node e in L
 *			 such that there is no edge from v to e then let's do a 
 *			 tournament with the losing nodes first, then the W nodes 
 *			 that are not in the path and finally the inverse path: 
 *		
 *				l_0, l_1, ..., l_p w_0, w_1, ..., w_q,
 *			 	x_k, x_k-1, ..., x_0, e 
 *
 *			 then e is the winner (this is a contradiction). Finally, 
 *			 if u is in L, from the above, every node in w points to u.
 *
 *		- solution: 
 *			 Given the previous test, all dfs-topological-sort considers 
 *			 w <= l for all w in W and l in L (easy to prove). also, 
 *			 as every node w in W has at least one node in W that does 
 *			 not have an edge towards it, therefore, the cardinal of W 
 *			 is the first index such that every node with a smaller or
 *			 equal index has an edge to every node with index higher.
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> order, g[maxn];
bool vis[maxn];
long long cnt[maxn];
int id[maxn];
int n;

void dfs(int x) {
	vis[x] = 1;
	for (int v : g[x]) {
		if (not vis[v]) {
			dfs(v);
		}
	}
	order.push_back(x);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; ++j) {
			int x;
			scanf("%d", &x);
			g[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (not vis[i]) {
			dfs(i);
		}
	}
	reverse(begin(order), end(order));	
	for (int i = 0; i < order.size(); ++i) {
		id[order[i]] = i+1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int v : g[i]) {
			if (id[i] < id[v]) {
				cnt[id[i]] -= 1;
				cnt[id[v]] += 1;
			}
		}
	}
	int ans = n;
	for (int i = n; i >= 2; --i) {
		cnt[i] += cnt[i+1];
		if (cnt[i] == (i-1) *1ll* (n-i+1)) ans = i-1;
	}
	printf("%d", ans);
	for (int i = 1; i <= n; ++i) {
		if (id[i] <= ans) {
			printf(" %d", i);
		}
	}
	puts("");
	return 0;
}
