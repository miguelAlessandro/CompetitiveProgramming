/**
 *	UVA 870	
 *	@overview calculate union area o rectangles
 *	
 *	coordinate compression -> grid compression
 * 	all plane in nxn weight grid
 * 	then, only use dfs. 
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 205;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<int> X, Y;
struct data {
	int a, b, c, d;
} p[MAX_N];
long long val[2][MAX_N];
bool G[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int n, t;

bool valid (int x, int y) {
	return x >= 0 and x < X.size() and y >= 0 and y < Y.size();
}

long long dfs (int x, int y) {
	vis[x][y] = 1;
	long long ans = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (not valid(nx, ny)) continue;
		if (not vis[nx][ny] and G[nx][ny]) {
			ans += dfs (nx, ny);
		}	
	}
	return ans + val[0][x] * val[1][y];
}

int main () {

	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		X.clear();
		Y.clear();
		for (int i = 0; i < n; ++i) {
			int Xmin, Ymin, Xmax, Ymax;
			scanf ("%d %d %d %d", &Xmin, &Ymin, &Xmax, &Ymax);
			p[i] = {Xmin, Ymin, Xmax, Ymax};
			X.emplace_back(Xmin); X.emplace_back(Xmax);
			Y.emplace_back(Ymin); Y.emplace_back(Ymax);	
		}
		
		sort(X.begin(), X.end()); 
		X.resize(unique(X.begin(), X.end()) - X.begin());
		sort(Y.begin(), Y.end());
		Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
		
		map<int, int> id[2];
		for (int i = 0; i < X.size(); ++i) {
			id[0][X[i]] = i;
			if (i+1 < X.size()) val[0][i] = X[i+1] - X[i]; 
		}		
		for (int i = 0; i < Y.size(); ++i) {
			id[1][Y[i]] = i;
			if (i+1 < Y.size()) val[1][i] = Y[i+1] - Y[i];
		}

		memset(G, 0, sizeof G);
		for (int i = 0; i < n; ++i) {
			for (int l1 = id[0][p[i].a], l2 = id[0][p[i].c]; l1 < l2; ++l1) {
				for (int r1 = id[1][p[i].b], r2 = id[1][p[i].d]; r1 < r2; ++r1) {
					G[l1][r1] = 1;
				}
			}
		}

		memset(vis, 0, sizeof vis);
		printf ("%lld\n", dfs (id[0][p[0].a], id[1][p[0].b]));
		if (t) puts("");
	}

	return 0;
}
