/**
 * @name POI 2004 East-West
 * @author Miguel Mini
 * @tag bfs, dfs, dp, greedy
 * @idea
 *	- the big problem is to find the cut east/west edge.
 *	
 *	1.- I can send a dfs from node n (in west), and look 
 *	the first vertex with w trucks starting positions in its subtree
 *	
 *	or
 *
 *	2.- I can send a multisource bfs if the set of z-vertex are	 
 *	every west-leaf-edge (that approach is stack-memory friendly)
 *
 *	- in the west, I just need the k first paths to z-nodes
 *
 *	- in the east, if I avoid the restrictions, I can consider greedily
 *	the next strict increasing lexicografic array of distances. 
 *
 *	- I can merge these with a simple greedy, the greatest with the lowest.
 *
**/

#include <bits/stdc++.h>
#pragma comment(linker, "/STACK: 30000000")
#define re(x, y, z) for (int x=y; x<z; ++x)
#define trav(v, x) for (int v : x)
#define eb emplace_back
#define all(v) v.begin(), v.end()
using namespace std;
using vi = vector<int>;
const int maxn = 1e6 + 2;
int n, w, z, p;
int r, s;
int min_dist[maxn], truck[maxn];
bitset<maxn> init;
int nxt[maxn<<1], to[maxn<<1], head[maxn];
int d[maxn], st[maxn];
int h = -1;

void get_dist(int x, int p) {
	int len = 0;
	memset(d, 1, sizeof d);	
	st[len++] = x;
	st[len++] = p;	
	d[p] = 0; d[x] = 0;
	while (len!=0) {
		int q = st[--len];
		if (init[q]) truck[s++] = d[q];
		if (q > n-z) min_dist[r++] = d[q];
		for (int e = head[q]; ~e; e = nxt[e]) {
			if (d[q] + 1 < d[to[e]]) {
				d[to[e]] = d[q] + 1;
				st[len++] = to[e];
			}
		}
	}
}

int x=-1, y=-1;
int dfs(int v, int p) {
	if (~x) return 0;
	int res = v <= w;
	for (int e = head[v]; ~e; e = nxt[e]) {
		if (to[e] == p) continue;
		res += dfs(to[e], v);
	}
	if (res == w and x==-1) {
		x = v;
		y = p;
	}
	return res;
}

int main() {
	scanf("%d%d%d", &n, &w, &z);
	memset(head, -1, sizeof head);
	re(i, 1, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		nxt[i<<1] = head[a]; head[a] = i<<1; to[i<<1] = b;		
		nxt[i<<1|1] = head[b]; head[b] = i<<1|1; to[i<<1|1] = a;
	}
	bool fun = 1;
	for (int i = n; i > n-z; --i) fun &= nxt[head[i]] == -1;
	scanf("%d", &p);
	re(i, 0, p) {
		int x;
		scanf("%d", &x);
		init[x] = 1;
	}
	if (not fun) {
		dfs(n, 0);
	} else {
		queue<int> Q;
		for (int i = 1; i <= n; ++i) {
			for (int e = head[i]; ~e; e = nxt[e]) {
				truck[i] += 1;
			}
		}
		for (int i = n; i > n-z; --i) {		
			min_dist[i] = 1;
			truck[i] = 1;
			Q.push(i);
		}
		while (not Q.empty()) {
			int q = Q.front(); Q.pop();
			if (min_dist[q] == z) {
				y = q;
				for (int e = head[q]; ~e; e = nxt[e]) {
					if (truck[to[e]] > 1) {
						x = to[e];
						break;
					}
				}	
				break;
			}
			for (int e = head[q]; ~e; e = nxt[e]) {
				if (truck[to[e]] <= 1) continue;
				min_dist[to[e]] += min_dist[q];
				truck[to[e]] -= 1;
				if (truck[to[e]] == 1) {
					Q.push(to[e]);
				}	
			}
		}
	}
	get_dist(x, y);
	sort(min_dist, min_dist+r);	
	sort(truck, truck+s);
	int temp = -1;
	for (int& tr : truck) {
		tr = max(tr, temp+1);
		temp = tr;
	}
	int res = 0;
	reverse(truck, truck+s);
	for (int i = 0; i < s; ++i) {
		res = max(res, truck[i] + 1 + min_dist[i]);
	}
	printf("%d\n", res);
	return 0;
}
