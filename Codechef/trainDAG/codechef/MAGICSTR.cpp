#include <bits/stdc++.h>
using namespace std;
int t, n, m;
const int maxN = 2e3 + 10;
const int mod = 1e9 + 7;
bool vis[maxN][maxN];
int id[maxN], rnk[maxN];

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
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d\n", &n, &m);
		for (int i = 1; i <= n; ++i) {
			id[i] = i;
			rnk[i] = 0;
		}
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= m; ++i) {
			int l, r;
			scanf("%d %d", &l, &r);
			for (int j = 1; j <= n; ++j) {
				if (r <= l) break;
				if (vis[l][r]) break;
				Union(l, r);
				vis[l][r] = 1;
				l += 1;
				r -= 1;
			}
		}
		int ans = 1;
		for (int i = 1; i <= n; ++i) {
			if (id[i] == i) {
				ans = ans*1ll*26%mod;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
