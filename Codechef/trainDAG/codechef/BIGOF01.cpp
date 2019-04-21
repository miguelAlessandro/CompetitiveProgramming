#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
int id[maxN];
int rnk[maxN];

int get(int x) {return id[x]==x?x:id[x]=get(id[x]);}

void Union(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	id[y] = x;
	rnk[x] += rnk[x] == rnk[y];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			id[i] = i;
			rnk[i] = 0;
		}
		for (int i = 1; i <= m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			Union(a, b);
		}
		int q;
		scanf("%d", &q);
		while (q--) {
			int u, v;
			scanf("%d %d", &u, &v);
			puts(get(u)==get(v)?"Yes":"No");
		}
	}
	return 0;
}
