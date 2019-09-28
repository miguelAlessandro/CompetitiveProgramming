/**
 *	@name avici2
 *	@author Miguel Mini
 *	@tag bfs
 *	@idea	
 *		1.- note that we need find 
 *		the x in the range [diameter/4, 
 *		diameter]
 *
 *		2.- every node different has 
 *		excentricity greater than or equal 
 *		to diameter / 2 and less than or 
 *		equal to the diameter. 
 *
 *		3.- run bfs from any node and find
 *		its excentricity
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 21002;
int nxt[maxn<<2], head[maxn<<2], to[maxn<<2];
bool vis[maxn];
int dis[maxn];
int bfs(int src) {
	memset(vis, 0, sizeof vis);
	queue<int> Q; Q.push(src);
	dis[src]=0; vis[src]=1;
	int q;
	while (not Q.empty()) {
		q = Q.front(); Q.pop();
		for (int i = head[q]; ~i; i = nxt[i]) {
			int u = to[i];
			if (not vis[u]) {
				vis[u]=1; dis[u]=dis[q]+1;
				Q.push(u);
			}
		}
	}
	return dis[q];
}
int main() {
	int t, n, m;
	freopen("amici2.in", "r", stdin);
	freopen("amici2.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		memset(head, -1, sizeof head);
		for (int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			to[i<<1] = v; nxt[i<<1] = head[u]; head[u] = i<<1;		
			to[i<<1^1] = u; nxt[i<<1^1] = head[v]; head[v] = i<<1^1;
		}
		printf("%d\n", 32 - __builtin_clz(bfs(1)));
	}
	return 0;
}
