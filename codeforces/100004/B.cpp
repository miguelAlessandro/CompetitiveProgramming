#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector< pair<int, int> > G[N];
long long c[N];
long long dp[N];
long long ans = LLONG_MAX;
int n;


long long dfs(int x, int p){

	for(auto v : G[x])
		if(v.first != p)
			dp[x] += dfs(v.first, x) + 2*v.second;
	
	return dp[x];
}

void dfs2(int x, int p, long long acum){
	
	ans = min(ans, acum + dp[x] + c[x]);
		
	for(auto v : G[x])
		if(v.first != p)
			dfs2(v.first, x, acum + dp[x] - dp[v.first] - v.second);
}


int main(){

	scanf("%d", &n);
	for(int i = 0; i <= n; ++i)
		scanf("%I64d", c+i);
	
	for(int x, y, z, i = 0; i < n; ++i){
		scanf("%d %d %d", &x, &y, &z);

		G[x].push_back({y, z});
		G[y].push_back({x, z});
	}

	dfs(0, -1);
	dfs2(0, -1, 0);

	printf("%I64d\n", ans);

	return 0;
}
