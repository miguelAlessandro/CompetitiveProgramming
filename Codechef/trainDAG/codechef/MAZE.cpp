#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int t, n, m, q;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

const int maxN = 5e5 + 10;
int p[maxN];
int rnk[maxN];
pair<int, int> rev[maxN];

int T;
map<pair<int, int>, int> id;
int node(int x, int y) {
	if (id.count({x, y})) return id[{x, y}];
	++T;
	rev[T] = {x, y};
	p[T] = T;
	rnk[T] = 0;
	return id[{x, y}] = T;
}

int get(int x) {return p[x]==x?x:p[x]=get(p[x]);}

void merge(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y); 
	rnk[x] += rnk[x] == rnk[y];
	p[y] = x;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		id.clear();
		T = 0;
		p[0] = 0;
		rnk[0] = 0;
		scanf("%d %d %d", &n, &m, &q);
		if (n == 1 or m == 1) {
			if (n == 1 and m == 1) puts("Chefland is doomed");
			else puts(q?"0":"1");
			for (int i = 0; i < q; ++i) scanf("%*d %*d %*d %*d");
			continue;
		}
		int ans = 2;
		set<pair<int, int>> edges; 
		for (int i = 0; i < q; ++i) {
			int x_1, x_2, y_1, y_2;
			scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
			if (ans == 0) continue;
			if (x_1 == x_2) x_2 -= 1, y_2 = y_1;
			else x_2 = x_1, y_2 -= 1;
			int u = node(x_1, y_1);
			int v = node(x_2, y_2);
			if (x_2 == 0 or y_2 == 0) {
				merge(v, 0);
			}
			if (x_1 == n or y_1 == m) {
				merge(u, 0);
			}
			edges.emplace(u, v);
			if (get(u) == get(v)) ans = 0;
			merge(u, v);
		}
		if (ans == 0) puts("0");
		else {
			for (int i = 1; i <= T; ++i) {
				if (rev[i].first == 0 or rev[i].first == n or rev[i].second == 0 or rev[i].second == m) continue;
				for (int k = 0; k < 4; ++k) {
					int nx = rev[i].first + dx[k];
					int ny = rev[i].second + dy[k];
					if (nx == 0 or nx == n or ny == 0 or ny == m) {
						if (id.count({nx, ny})) {
							int v = node(nx, ny);
							if (edges.count({i, v}) or edges.count({v, i})) continue;
							if (get(i) == get(v)) {
								ans = 1;
								break;
							}
						} else {
							if (get(i) == get(0)) {
								ans = 1;
								break;
							}
						}
					} else {
						if (not id.count({nx, ny})) continue;
						int v = node(nx, ny);
						if (edges.count({i, v}) or edges.count({v, i})) continue;
						if (get(v) == get(i)) {
							ans = 1;
							break;	
						}
					}
				}
				if (ans == 1) break;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
