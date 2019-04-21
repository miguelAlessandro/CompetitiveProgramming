#include <bits/stdc++.h>
using namespace std;
int t, n, m, q;
const int maxN = 1e6 + 2;
int id[maxN];
int sz[maxN];
int Q[maxN][3];
int ans[maxN];
int cnt[1010][1010][2];
char vis[1010][1010];
int best;
int dx[] = {0, 1};
int dy[] = {1, 0};

int value(int x, int y) {return x * m + y;}

int get(int x) {return x==id[x]?x:id[x]=get(id[x]);}

void Union(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) {
		return;
	}
	if (sz[x] < sz[y]) swap(x, y);
	id[y] = x;
	sz[x] += sz[y];
	best = max(best, sz[x]);
}


int main() {
	scanf("%d", &t);
	while (t--) {
		best = 1;
		scanf("%d %d %d", &n, &m, &q);
		for (int i = 0; i < n*m; ++i) {
			id[i] = i;
			sz[i] = 1;
		}
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < q; ++i) {
			int type;
			scanf("%d", &type);
			if (type <= 2) {
				int x, y;
				scanf("%d %d", &x, &y);
				x -= 1;
				y -= 1;
				Q[i][0] = type;
				Q[i][1] = x;
				Q[i][2] = y;
				cnt[x][y][type-1] += 1;
				vis[x][y] |= (1<<type-1);
			} else if (type == 3) {
				int x_1, x_2, y_1, y_2;
				scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
				x_1 -= 1;
				x_2 -= 1;
				y_1 -= 1;
				y_2 -= 1;
				Q[i][0] = type;
				Q[i][1] = value(x_1, y_1);
				Q[i][2] = value(x_2, y_2);
			} else if (type == 4) {
				Q[i][0] = type;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < 2; ++k) {
					if ((~vis[i][j])&(1<<k)) {
						if (i + dx[k] >= n) continue;
						if (j + dy[k] >= m) continue;
						Union(value(i, j), value(i+dx[k], j+dy[k]));	
					}
				}
			}
		} 
		long long sum = 0;
		for (int i = q-1; i >= 0; --i) {
			if (Q[i][0] <= 2) {
				int x = Q[i][1];
				int y = Q[i][2];
				int d = Q[i][0] - 1;
				cnt[x][y][d] -= 1;
				if (cnt[x][y][d] == 0) {
					Union(value(x, y), value(x + dx[d], y + dy[d]));
				}
			} else if (Q[i][0] == 3) {
				sum += get(Q[i][1]) == get(Q[i][2]);
			} else {
				sum += best;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
