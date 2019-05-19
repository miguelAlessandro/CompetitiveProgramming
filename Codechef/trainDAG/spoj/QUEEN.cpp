#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 10;
char mat[maxN][maxN];
int dis[maxN][maxN];
int vis[maxN][maxN];
int n, m, t;
const int dx[] = {-1, -1, 0, -1, 1, 0, 1, 1};
const int dy[] = {-1, 0, -1, 1, -1, 1, 0, 1};
 
bool valid(int x, int y) {
	return x >= 0 and y >= 0 and x < n and y < m and mat[x][y] != 'X'; 
}
 
int bfs(int sx, int sy, int fx, int fy) {
	queue<int> Q;
	memset(vis, 0, sizeof vis);
	memset(dis, 7, sizeof dis);
	vis[sx][sy] = 255;
	dis[sx][sy] = 0;
	Q.push(sx);
	Q.push(sy);
	while (not Q.empty()) {
		int qx = Q.front(); Q.pop();
		int qy = Q.front(); Q.pop();
		for (int k = 0; k < 8; ++k) {
			int nx = qx, ny = qy;
			for (int l = 1; l <= 1e3; ++l) {
				nx += dx[k]; ny += dy[k];
				if (not valid(nx, ny)) break;
				if (vis[nx][ny]&(1<<k)) break;
				vis[nx][ny] |= 1<<k;
				if (dis[nx][ny] > dis[qx][qy] + 1) {
					dis[nx][ny] = dis[qx][qy] + 1;
					Q.push(nx); Q.push(ny);
				}
			}
		}
	}
	int ans = 1e8;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (mat[i][j] == 'F')
				ans = min(ans, dis[i][j]);
	return ans > 1e6 ? -1 : ans;
}
 
int main() {
	scanf("%d", &t); 
	char s[1010];
	while (t--) {
		scanf("%d %d\n", &n, &m);
		int sx, sy, fx, fy;
		for (int i = 0; i < n; ++i) {
			fgets(s, 1010, stdin);
			for (int j = 0; j < m; ++j) {
				mat[i][j] = s[j];
				if (mat[i][j] == 'S') {
					sx = i; sy = j;
				}
			}
		}
		printf("%d\n", bfs(sx, sy, fx, fy));
	}
	return 0;
}
 
