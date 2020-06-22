/**
 *  @author Miguel Mini
 *  @tag constructive, greedy
 *  @idea
 *      - Affirmation: If we answer yes, only when this is the 
 *      last edge that joins two components, then we can achieve 
 *      our goal.
 *
 *      proof: in this way we will only have n-1 edges and the 
 *      union of the last two components will only be known when 
 *      the last edge appears.
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1510 + 10;
int rnk[maxn];
int link[maxn];
int cnt[maxn][maxn];
int n;

int get(int x) {
	if (x == link[x]) {
		return x;
	}
	return link[x] = get(link[x]);
}

void initialize(int n) {
	::n = n;
	for (int i = 1; i <= n; ++i) {
		link[i] = i;
		rnk[i] = 1;
	}
}

int hasEdge(int u, int v) {
  u += 1; v += 1;
  u = get(u); v = get(v);
  if (u == v) return 1;
  cnt[u][v] +=1;
  cnt[v][u] += 1;
  if (cnt[u][v] < rnk[u] * rnk[v]) return 0;
  if (rnk[u] < rnk[v]) swap(u, v);
  rnk[u] += rnk[v];
  link[v] = u;
  for (int i = 1; i <= n; ++i) {
    cnt[i][u] += cnt[i][v];
    cnt[u][i] += cnt[v][i];
  }
  return 1;
}
