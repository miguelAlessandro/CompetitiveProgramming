#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 10;
int n, m, t;
bool table[maxN][maxN], vis[maxN][maxN];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};
int dist[maxN][maxN];

bool valid(int x, int y) {
	return x >= 0 and y >= 0 and x < n and y < m and table[x][y];
}

int dis, ans;
typedef pair<int, int> ii;
pair<ii, int> bfs(ii p) {
	int x = p.first, y = p.second;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			vis[i][j] = 0;
		}
	}
	queue<int> Q;
	Q.push(x); Q.push(y);
	vis[x][y] = 1;
	dist[x][y] = 0;
	int qx, qy;
	while (not Q.empty()) {
		qx = Q.front(); Q.pop();
		qy = Q.front(); Q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = qx + dx[k];
			int ny = qy + dy[k];
			if (not valid(nx, ny)) continue;
			if (not vis[nx][ny]) {
				vis[nx][ny] = 1;
				dist[nx][ny] = dist[qx][qy] + 1;
				Q.push(nx); Q.push(ny);
			}
		}	
	}
	return {{qx, qy}, dist[qx][qy]};
}


int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d\n", &n, &m);
		swap(n, m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				table[i][j] = getchar() != '#';
			}
			getchar();
		}
		ans = 0;
		bool ok = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (table[i][j]) {
					ans = bfs(bfs({i, j}).first).second;
					ok = 1;
					break;
				}
			}
			if (ok) break;
		}
		printf("Maximum rope length is %d.\n", ans);
	}
	return 0;
}
