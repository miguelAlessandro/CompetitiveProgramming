#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
bool vis[maxN];
vector<int> g[maxN];
int t, n, m;

void dfs(int x) {
	vis[x] = 1;
	for (int v : g[x]) {
		if (not vis[v]) {
			dfs(v);
		}	
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			vis[i] = 0;
			g[i].clear();	
		}
		while (m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (not vis[i]) {
				ans += 1;	
				dfs(i);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
