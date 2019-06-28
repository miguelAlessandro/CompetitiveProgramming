#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
const int mod = 1e9;
int p[maxN], sz[maxN];
int n, m;
struct Edge {
	int a, b, c;
};
vector<Edge> edges;

int mul(long long a, long long b) {
	return (a*b)%mod;
}

int get(int x) {return x==p[x]?x : p[x]=get(p[x]);}

long long ans = 0;
long long add = 0;
int merge(int x, int y, int w) {
	x = get(x);
	y = get(y);
	if (x != y) {
		if (sz[x] < sz[y]) swap(x, y);
		p[y] = x;
		add = (add + mod - (sz[x] *1ll* (sz[x] - 1) / 2) % mod) % mod;
		add = (add + mod - (sz[y] *1ll* (sz[y] - 1) / 2) % mod) % mod;
		sz[x] += sz[y];
		add = (add + (sz[x] *1ll* (sz[x] - 1) / 2) % mod) % mod;
	}
	ans = (ans + mul(w, add)) % mod;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back({a, b, c});
	}
	sort(begin(edges), end(edges), [](Edge p, Edge q) {
		return p.c > q.c;
	});
	for (int i = 1; i <= n; ++i) p[i] = i, sz[i] = 1;
	for (auto e : edges) merge(e.a, e.b, e.c);
	printf("%lld\n", ans);
	return 0;
}
