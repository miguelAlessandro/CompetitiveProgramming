/**
 *	@name POI 2012 Festival
 *	@author Miguel Mini
 *	@tag floyd_warshall, scc
 *	@idea
 *			- we should note that the 
 *			problem is reduced to finding 
 *			the maximum number of positions 
 *			in a strongly connected component,
 *			and add the answer of each one 
 *			of them.
 *
 *			- We must note that the response 
 *			must be reached when the nodes are 
 *			as far apart as possible, therefore 
 *			it is necessary to find the maximum 
 *			distance between each one.
 *
 *			- we can make this with a simple
 *			floyd-warshall algorithm, note that
 *			the answer dont exist if exist a 
 *			positive cycle exist.
 * 
 *			- the answer is the maximum(-distance)
 *			in a scc.
**/
#include <bits/stdc++.h>
#define trav(v, x) for (auto v : x)
#define re(x, y, z) for (int x=y; x<z; ++x)
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;
const int maxn = 610;
int mat[maxn][maxn];
const int inf = 1e5;
bool vis[maxn];
int n, m1, m2;
vi t;

void dfs(int x) {
	vis[x] = 1;
	re(i, 1, n+1)
 		if (not vis[i] and abs(mat[x][i]) < 2) {
			dfs(i);		
		}
	t.push_back(x);
}

void dfsr(int x, vi& v) {
	v.push_back(x);
	vis[x] = 1;
	re(i, 1, n+1) {
		if (not vis[i] and abs(mat[i][x]) < 2) {
			dfsr(i, v);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m1, &m2);
	re(i, 0, n) {
		re(j, 0, n) {
			mat[i+1][j+1] = i==j ? 0 : -inf;
		}
	}
	re(i, 0, m1) {
		int u, v;
		scanf("%d%d", &u, &v);
		mat[u][v] = 1;
		mat[v][u] = -1;
	}
	re(i, 0, m2) {
		int u, v;
		scanf("%d%d", &u, &v);
		mat[u][v] = max(mat[u][v], 0);
	}
	re(i, 1, n+1) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	memset(vis, 0, sizeof vis);
	reverse(all(t));
	int ans = 0;
	trav(v, t) {
		if (!vis[v]) {
			vi ver;
			dfsr(v, ver);
			trav(k, ver) {
				trav(i, ver) {
					trav(j, ver) {
						mat[i][j] = max(mat[i][j], mat[i][k] + mat[k][j]);		
     			}
				}
			}
			trav(i, ver) {
				if (mat[i][i] > 0) {
					cout << "NIE" << endl;
					return 0;
				}
			}
			int len = 0;
			trav(a, ver) {
				trav(b, ver) {
					len = max(len, -mat[a][b] + 1);
				}
			}
			ans += len;
		}
	}
	cout << ans << endl;
	return 0;
}
