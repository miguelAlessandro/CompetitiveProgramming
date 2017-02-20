#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n;
vector<int> adj[N];
int d[N];
long long dp[N], dp2[N], ans = LLONG_MIN;

long long dfs(int x, int p){

	dp[x] = d[x];
	dp2[x] = LLONG_MIN;
	for(int v : adj[x])
		if(v != p){
			dfs(v, x);
			dp[x] += dp[v];
			dp2[x] = max(dp2[x], dp2[v]);
		}
	
	dp2[x] = max(dp2[x], dp[x]);
}


long long dfs2(int x, int p, long long e){
	if(e != LLONG_MIN) ans = max(ans, dp[x] + e);

	vector<pair<long long, int>> g;
	for(int v : adj[x])
		if(v != p) g.push_back({dp2[v], v});
	
	g.push_back({LLONG_MIN, -1});
	sort(g.rbegin(), g.rend());
	
	for(int v : adj[x])
		if(v != p){
			long long aux = (g[0].second == v) ? g[1].first : g[0].first;
			dfs2(v, x, max(e, aux));
		} 

}


int main(){

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", d+i);		

	for(int x, y, i = 1; i < n; ++i){
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1, -1);
	dfs2(1, -1, LLONG_MIN);
	puts(ans == LLONG_MIN ? "Impossible" : to_string(ans).c_str());

	return 0;
}
