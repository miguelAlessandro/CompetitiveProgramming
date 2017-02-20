#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int t, n, m, nc=1;
int C[N][N];
long long dp[N][N];
bool vis[N][N];

long long backtracking(int pos, int res){
	
	if(pos == n or res > n-pos) return 0;
	if(vis[pos][res]) return dp[pos][res];
	long long ans = LLONG_MAX;

	if(res > 0) ans = min(ans, backtracking(pos+1, res-1)); 
	for(int i = 0; i < m; ++i)
		ans = min(ans, C[pos][i] + (i+1)*(i+1) + backtracking(pos+1, res + i));

	vis[pos][res] = true;
	return dp[pos][res] = ans;
}


int main(){
	
	scanf("%d", &t);
	while(t--){

		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j)
				scanf("%d", &C[i][j]);
			sort(C[i], C[i]+m);
			for(int j = 1; j < m; ++j)
				C[i][j] += C[i][j-1];
		}
	
		m = min(n, m);
		memset(vis, false, sizeof vis);
		printf("Case #%d: %lld\n", nc++, backtracking(0, 0));
	}

	return 0;
}
