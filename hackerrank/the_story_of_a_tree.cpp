#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int dp[N], ans[N];
int q, n, g, k;
set< pair<int, int> > A;
vector<int> adj[N];

bool parent(int x, int y){
	return A.find({x, y}) != A.end();
}

void dfs(int x, int p = 0){

	for(int v : adj[x])
		if(v != p){
			dfs(v, x);	
			dp[x] += parent(x, v) + dp[v];		
		}
}

void dfs2(int x, int p = 0){
	if(p) ans[x] = ans[p] + parent(x, p) - parent(p, x);
	else ans[x] = dp[x];

	for(int v : adj[x])
		if(v != p)
			dfs2(v, x);
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){

	scanf("%d", &q);	
	while(q--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) adj[i].clear();
		for(int x, y, i = 1; i < n; ++i){
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		scanf("%d %d", &g, &k);
		A.clear();
		for(int x, y, i = 0; i < g; ++i){
			scanf("%d %d", &x, &y);
			A.insert({x, y});
		}
		
		memset(dp, 0, sizeof dp);
		dfs(1);
		dfs2(1);
		int a = 0, b = n;		
		for(int i = 1; i <= n; ++i)
			a += ans[i] >= k;	

		int gc = gcd(a, b);
		printf("%d/%d\n", a/gc, b/gc);
	}

	return 0;
}
