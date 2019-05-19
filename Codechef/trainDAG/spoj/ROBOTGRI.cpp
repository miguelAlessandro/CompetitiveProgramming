#include <bits/stdc++.h>
using namespace std;
const int maxN = 1010;
long long dp[maxN][maxN];
int mat[maxN][maxN];
int n;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
bool vis[maxN][maxN][5];
 
bool valid(int x, int y) {
	return x >= 1 and y >= 1 and x <= n and y <= n;
}
 
void dfs(int x, int y, int t) {
	vis[x][y][t] = 1;
	for (int k = 0; k < t; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (not valid(nx, ny)) continue;
		if (not mat[nx][ny]) continue;
		if (not vis[nx][ny][t]) {
			dfs(nx, ny, t);
		}
	}
}
 
long long add(long long a, long long b) {
	return (a+b)%((1ll<<31)-1);
}
 
int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; ++i) {	
		for (int j = 1; j <= n; ++j) {
			mat[i][j] = getchar() == '.';
		}
		getchar();
	}
	dp[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == 1 and j == 1) continue;
			if (mat[i][j]) {
				dp[i][j] = add(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	dfs(1, 1, 2);
	if (vis[n][n][2]) {
		printf("%lld\n", dp[n][n]);
	} else {
		dfs(1, 1, 4);
		if (vis[n][n][4]) puts("THE GAME IS A LIE");
		else puts("INCONCEIVABLE");
	}
	return 0;
}
