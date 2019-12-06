/**
 *	@name infoarena karb
 *	@author Miguel Mini
 *	@tag matroids, mst
 *	@idea
 *		- find a mst, if |mst| == k, 
 *		print this, in other case		
 *		select every 1-weight edge
 *		and make a partial mst with
 *		these.
 *
 *		- add k - |mst| 1-weight edge,
 * 	this is possible because there 
 *		exist that k-spanning tree 
 *		(problem condition) and for 
 *		the exhange principle in matroids 
 *		if I consider partial k-spanning tree 
 *		solution with k edges 1-weight and 
 *		any 0-weight then I can use 
 *		exhange principle between mi partial
 *		mst and this new partial k-spanning 
 *		tree. 
 * 
 *		- add n - k 0-weight edge from
 *		original mst, this is possible 
 *		because I can use exchange principle
 *		and should exist n-k 0-weight edges,
 *		in other case is not possible to make
 *		a tree, because by the way of I build 
 *		a mst, this is connect, and if I dont
 * 	can connect with this edges, then is 
 *		a contradiction.
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int p[maxn], rnk[maxn];
typedef pair<int, int> pii;
int nf[2], ne;
int t[2];
pii f[2][maxn];
pii E[2][maxn];
pii edges[maxn];
int T;

void make(int x) {
	p[x] = x;
	rnk[x] = 0;
}	

int get(int x) {
	return x==p[x] ? x : p[x]=get(p[x]);
}

void merge(int x, int y) {
	x=get(x); y=get(y);
	if (rnk[x]<rnk[y]) swap(x, y);
	rnk[x] += rnk[x]==rnk[y];
	p[y]=x;
}


int main() {
	freopen("karb.in", "r", stdin);
	freopen("karb.out", "w", stdout);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		E[w][t[w]++] = {a, b};
	}
	for (int i = 1; i <= n; ++i) make(i);
	int mst = 0;
	for (int d = 0; d < 2; ++d) {
		for (int i = 0; i < t[d]; ++i) {
			int u = E[d][i].first, v = E[d][i].second;
			if (get(u) != get(v)) {
				merge(u, v);
				mst += d;
				f[d][nf[d]++] = E[d][i];
			}
		}
	}
	for (int i = 1; i <= n; ++i) make(i);
	for (int i = 0; i < nf[1]; ++i) {
		merge(f[1][i].first, f[1][i].second);
		edges[ne++] = f[1][i];
	}
	for (int i = 0; i < t[1]; ++i) {
		if (mst == k) break;
		if (get(E[1][i].first) != get(E[1][i].second)) {
			merge(E[1][i].first, E[1][i].second);
			edges[ne++] = E[1][i];
			mst += 1;
		}
	}
	for (int i = 0; i < nf[0]; ++i) {
		if (get(f[0][i].first) != get(f[0][i].second)) {
			merge(f[0][i].first, f[0][i].second);
			edges[ne++] = f[0][i];
		}
	}
	for (int i = 0; i < ne; ++i) {
		printf("%d %d\n", edges[i].first, edges[i].second);
	}	
	return 0;
}
