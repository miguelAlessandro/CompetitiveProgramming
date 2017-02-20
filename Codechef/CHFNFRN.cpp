#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int t, n, m;
bool adj[N][N];
int dp[N];

bool dfs(int x, bool P){
	dp[x] = P;
	for(int v = 1; v <= n; ++v) 
		if(adj[x][v])	
			if(dp[v] == -1 and not dfs(v, not P)) return false;
			else if(dp[v] == P)  return false;	

	return true;	
}


int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);

		memset(adj, true, sizeof adj);
		memset(dp, -1, sizeof dp);
		for(int i = 1; i <= n; ++i) adj[i][i] = false;

		for(int x, y, i = 0; i < m; ++i){
			scanf("%d %d", &x, &y);
			adj[x][y] = adj[y][x] = false;
		}			

		bool ok = true;
		for(int i = 1; i <= n and ok; ++i)
			if(dp[i] == -1 and not dfs(i, true)) 
				ok = false;

		puts(ok ? "YES" : "NO");
	}	

	return 0;
}
