#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m;
bool adj[N][N], vis[N];
int dp[1<<N][N];

int backtracking(int bitmask, int x){
	if(bitmask+1 == (1<<n)) return 0;
	if(dp[bitmask][x] != -1) return dp[bitmask][x];
	
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(adj[x][i])
			if(bitmask&(1<<i)) ans += 1; 
			else ans += backtracking(bitmask|(1<<i), i);
	
	return dp[bitmask][x] = ans;
}

int main(){

	scanf("%d %d", &n, &m);
	for(int x, y, i = 1; i <= m; ++i){
		scanf("%d %d", &x, &y);
		adj[x][y] = true; adj[y][x] = true;
	}	
	
	memset(dp, -1, sizeof dp);
	printf("%d\n", backtracking(2, 1));

	return 0;
}
