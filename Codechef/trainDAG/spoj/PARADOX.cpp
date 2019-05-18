#include <bits/stdc++.h>
using namespace std;
const int maxN = 110;
bool val[maxN], dis[maxN];
int vis[maxN];
int nxt[maxN];
int n;

bool dfs(int x, int d) {
	vis[x] = 1;
	dis[x] = d;
	bool ok = 1;
	if (vis[nxt[x]] == 1) ok &= (d ^ dis[nxt[x]] ^ val[x] ^ 1); 
	else if (vis[nxt[x]] == 0) ok &= dfs(nxt[x], d ^ val[x]);
	vis[x] = 2;
	return ok;
}

int main() {
	while (scanf("%d", &n), n) {
		for (int i = 1; i <= n; ++i) {
			vis[i] = 0;
			char s[10];
			scanf("%d %s\n", nxt+i, s);
			val[i] = s[0] == 'f';
		}
		bool ans = 1;
		for (int i = 1; i <= n; ++i) {
			if (not vis[i]) {
				ans &= dfs(i, 0);
			}
		}
		puts(ans ? "NOT PARADOX" : "PARADOX");
	}
	return 0;
}
