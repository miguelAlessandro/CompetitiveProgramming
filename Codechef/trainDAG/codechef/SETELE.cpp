#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int id[maxN], sz[maxN];

int get(int x) {return x==id[x]?x:id[x]=get(id[x]);}

void Union(int x, int y, int w) {
	x = get(x);
	y = get(y);
	if (sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	id[y] = x;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		id[i] = i;
		sz[i] = 1;
	}
	vector<pair<int, int>> ed, g;
	long long sum = 0;
	for (int i = 0; i+1 < n; ++i) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		sum += c;
		g.emplace_back(u, v);
		ed.emplace_back(c, i);
	}
	sort(begin(ed), end(ed));
	long long ans = 0;
	for (auto e : ed) {
		int u = g[e.second].first;
		int v = g[e.second].second;
		ans +=  e.first *1ll* sz[get(u)] * sz[get(v)];
		Union(u, v, e.first);
	}
	printf("%Lf\n", sum - (long double) (ans) / (n *1ll* (n - 1) / 2));
	return 0;
}
