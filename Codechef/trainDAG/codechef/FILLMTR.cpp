#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int t, n, q;
int id[maxN], rnk[maxN];
vector<int> in[maxN];
bool c[maxN];

int get(int x) {return x==id[x]?x:id[x]=get(id[x]);}

bool Union(int u, int v, int d) {
	int x = get(u);
	int y = get(v);
	bool f = (c[u] ^ c[v]) == d;
	if (x == y) {
		return f;
	}
	if (rnk[x] < rnk[y]) swap(x, y);
	for (int e : in[y]) {
		in[x].push_back(e);
		c[e] ^= !f;
	}
	id[y] = x;
	rnk[x] += rnk[x] == rnk[y];
	return 1;
}


int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; ++i) {
			id[i] = i;
			rnk[i] = 0;
			in[i].clear();
			in[i].emplace_back(i);
		}
		bool ok = 1;
		for (int i = 1; i <= q; ++i) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			ok &= Union(a, b, c);
		}
		puts(ok ? "yes" : "no");
	}
	return 0;
}
