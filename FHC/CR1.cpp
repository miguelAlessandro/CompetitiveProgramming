#include <bits/stdc++.h>
using namespace std;

const int N = 102, K = 5002;
bool G[N][N];
bool vis[N], ss[N];
int dis[N][N];
int t, n, m, k, nc=1;
int D[K], S[K];
long long dp[K][K][3][2]; 
bool v[K][K][3][2];

void dfs(int x){
	vis[x] = true;
	for(int i = 1; i <= n; ++i)
		if(G[x][i] and not vis[i])
			dfs(i);
}

long long backtracking(int ent, int rec, int T, int val){

	if(ent == k) return 0;
	if(v[ent][rec][T][val]) return dp[ent][rec][T][val];	
	long long ans = LLONG_MAX;

	if(T == 0){
		if(ent == 0) ans = min(ans, backtracking(ent, rec+1, 1, 1) + dis[1][S[ent]]);
		else ans = min(ans, backtracking(ent, rec+1, 1, 1) + dis[D[ent-1]][S[ent]]);
	}
	if(T == 1){
		if(val == 1){
			ans = min(ans, backtracking(ent, rec+1, 2, 1) + dis[S[rec-1]][S[rec]]);
			ans = min(ans, backtracking(ent+1, rec, 0, 0) + dis[S[rec-1]][D[ent]]);
		}
		else{
			ans = min(ans, backtracking(ent, rec+1, 2, 1) + dis[D[ent-1]][S[rec]]);
			ans = min(ans, backtracking(ent+1, rec, 0, 0) + dis[D[ent-1]][D[ent]]);
		}
	}
	if(T == 2) ans = min(ans, backtracking(ent+1, rec, 1, 0) + dis[S[rec-1]][D[ent]]);
	
	v[ent][rec][T][val] = true;
	return dp[ent][rec][T][val] = ans;
}

int main(){

	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &m, &k);
		
		memset(dis, 1, sizeof dis);
		memset(vis, false, sizeof vis);
		memset(v, false, sizeof v);
		memset(ss, false, sizeof ss);
		memset(G, false, sizeof G);
		for(int i = 1; i <= n; ++i) dis[i][i] = 0;

		for(int x, y, z, i = 0; i < m; ++i){
			scanf("%d %d %d", &x, &y, &z);
			dis[x][y] = dis[y][x] = min(dis[y][x], z);
			G[x][y] = G[y][x] = true;
		}

		for(int i = 0; i < k; ++i){
			scanf("%d %d", S+i, D+i);
			ss[S[i]] = ss[D[i]] = true;
		}

		dfs(1);		
		
		bool ok = true;
		for(int i = 1; i <= n and ok; ++i)
			if(not vis[i] and ss[i])
				ok = false;

		if(not ok){
			printf("Case #%d: -1\n", nc++);
			continue;
		} 

		for(int k = 1; k <= n; ++k)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 

		printf("Case #%d: %lld\n", nc++, backtracking(0, 0, 0, 0));
	}

	return 0;
}
