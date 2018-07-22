#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e3 + 10;
int a[MAX_N], b[MAX_N];
bool vis[MAX_N];
vector<int> pos, pre;
int k, n, t;
int inv[MAX_N], p[MAX_N];
int LV[MAX_N];

void dfsPre (int x) {
	pre.emplace_back(x);
	if (a[x]) dfsPre(a[x]);
	if (b[x]) dfsPre(b[x]);
}

void dfsPos (int x) {
	if (a[x]) dfsPos(a[x]);
	if (b[x]) dfsPos(b[x]);
	pos.emplace_back(x);
}

int main () {
	
	scanf ("%d", &t);
	int nc = 1;
	while (t --) {
		scanf ("%d %d", &n, &k);
		for (int i = 1; i <= n; ++i)
			scanf ("%d %d", a+i, b+i);

		pre.clear(); dfsPre(1);
		pos.clear(); dfsPos(1);

		memset(vis, 0, sizeof vis);
	
		int id = 1;
		for (int v : pre) {
			inv[id] = v;
			p[v] = id++;
		}
		for (int& v : pos) {
			v = p[v];
		}
		int lv = 0;
		for (int i = 1; i <= n; ++i) {
			if (not vis[i]) {
				int x = i;
				lv = min(k, lv+1);

				while (not vis[x]) {
					vis[x] = 1;
					LV[inv[x]] = lv;
					x = pos[x-1];
				}
			}
		}

		if (lv < k) {
			printf ("Case #%d: Impossible\n", nc++);
		} else {
			printf ("Case #%d:", nc++);
			for (int i = 1; i <= n; ++i)
				printf (" %d", LV[i]);
			puts ("");
		}
	}
	return 0;
}
