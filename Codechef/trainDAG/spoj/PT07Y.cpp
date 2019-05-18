#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e4 + 10;
bool vis[maxN];
vector<int> g[maxN];
int n, m;

void dfs(int x, int p=0) {
	vis[x] = 1;
	for (int v : g[x]) {
		if (v == p) continue;
		if (not vis[v]) dfs(v, x);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	if (m != n-1) return puts("NO"), 0;
	for (int i = 1; i <= m; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int c = 0;
	for (int i = 1; i <= n; ++i) if (not vis[i]) {
		c += 1;
		dfs(i);
	}
	puts(c==1?"YES":"NO");
	return 0;
}
