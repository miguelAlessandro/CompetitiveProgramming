#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
const int mod = 1e9 + 7;
int id[maxN], rnk[maxN];
int components;

int get(int x) {return x==id[x]?x:id[x]=get(id[x]);}

void Union(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	id[y] = x;
	rnk[x] += rnk[y];
	components -= 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		components = n;
		for (int i = 1; i <= n; ++i) {
			id[i] = i;
			rnk[i] = 1;
		}
		for (int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			Union(u, v);
		}
		int ans = 1;
		for (int i = 1; i <= n; ++i) {
			if (id[i] == i) {
				ans = ans*1ll*rnk[i] % mod;
			}
		}
		printf("%d %d\n", components, ans);
	}
	return 0;
}
