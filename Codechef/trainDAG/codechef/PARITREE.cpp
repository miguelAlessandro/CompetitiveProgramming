#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
const int mod = 1e9 + 7;
int id[maxN];
int rnk[maxN];
bool c[maxN];
int components;
vector<int> in[maxN];

int get(int x) {return x==id[x]?x:id[x]=get(id[x]);}

bool merge(int u, int v, int d) {
	int x = get(u);
	int y = get(v);
	bool f = (c[u]^c[v])!=d;
	if (x == y) {
		if (f) return 0;
		return 1;
	}
	if (rnk[x] < rnk[y]) swap(x, y);
	for (int e : in[y]) {
		in[x].emplace_back(e);
		c[e] ^= f;
	}
	id[y] = x;
	rnk[x] += rnk[x] == rnk[y];
	components -= 1;
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, q;
		scanf("%d %d", &n, &q);
		for (int i = 1; i < n; ++i) {
			scanf("%*d %*d");	
		}
		components = n;
		for (int i = 1; i <= n; ++i) {
			id[i] = i;
			rnk[i] = 0;
			c[i] = 0;
			in[i].clear();
			in[i].emplace_back(i);
		}
		bool ok = 1;
		for (int i = 1; i <= q; ++i) {
			int u, v, x;
			scanf("%d %d %d", &u, &v, &x);
			ok &= merge(u, v, x);
		}
		if (ok) {
			int ans = 1;
			for (int i = 0; i < components - 1; ++i) {	
				ans *= 2;
				if (ans >= mod) ans -= mod;
			}
			printf("%d\n", ans);
		} else puts("0");
	}
	return 0;
}
