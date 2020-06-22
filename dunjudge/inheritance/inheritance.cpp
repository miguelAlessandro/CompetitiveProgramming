/**
 * @name dunjudge inheritance
 *	@author Miguel Mini
 *	@tag kruskal, binary search
 *	@idea:
 *		- A edge is added to set 1, if not to set 2, and so
 *		- the admisible set is binary searchable.
 *		- use kruskal with binary search to election
 *		- O(m * (logm + logk * alpha(n)))
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int maxm = 1e7 + 10;
int id[maxm], p[maxm], rnk[maxm];
int ans[maxn];
int n, m, k;
struct Edge {
	int a, b, c, idx;
};
vector<Edge> edges;

int get(int x) {
	return x == p[x] ? x : p[x] = get(p[x]);
}

int cnt = 1;
int val(int x, int t) {
	int res = n*t + x;
	if (not id[res]) {
		p[cnt] = cnt;
		rnk[cnt] = 0;
		id[res] = cnt++;
	}
	return id[res];
}

void merge(int a, int b) {
	a = get(a); b = get(b);
	if (a == b) return;
	if (rnk[a] < rnk[b]) swap(a, b);
	p[b] = a;
	rnk[a] += rnk[a] == rnk[b]; 
}

bool same(int a, int b) {
	return get(a) == get(b);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a -= 1; b -= 1;
		edges.push_back({a, b, c, i});
	}
	sort(begin(edges), end(edges), 
		[](Edge p, Edge q) {
			return p.c > q.c;
		});
	for (auto e : edges) {
		int lo = 0, hi = k-1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (same(val(e.a, mid), val(e.b, mid))) lo = mid+1;
			else hi = mid;
		}
		if (not same(val(e.a, lo), val(e.b, lo))) {
			merge(val(e.a, lo), val(e.b, lo));
			ans[e.idx] = lo + 1;
		} else {
			ans[e.idx] = 0;
		}
	}
	for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
	return 0;	
}
