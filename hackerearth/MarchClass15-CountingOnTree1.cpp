/**
 * @author Miguel Mini
 * @tag dp on trees, connect component approach
 * @idea
 *    - connect component approach aplication
**/

#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
const int N = 50002;
const int K = 101;
int test_cases, n, k;
int dp_root[N][K], val[N];
int buffer_dp[K];
vector<int> Graph[N];
 
int add(int a, int b){
	return (a+b)%mod;
}
 
int mul(long long a, long long b){
	return a*b%mod;
}
 
void dfs(int x, int parent){
 
	for(int v : Graph[x])
		if(v != parent)
			dfs(v, x);
 
	for(int i = 0; i <= k; ++i)
		dp_root[x][i] = 0;
 
	if(val[x] <= k)
		dp_root[x][val[x]] = 1;
 
	for(int i = 0; i <= k; ++i)
		buffer_dp[i] = dp_root[x][i];
 
	for(int v : Graph[x])
		if(v != parent){
			for(int i = 0; i <= k; ++i)
				for(int j = 0; j <= i; ++j)
					buffer_dp[i] = add(buffer_dp[i], mul(dp_root[x][j], dp_root[v][i-j]));
	
			for(int i = 0; i <= k; ++i)
				dp_root[x][i] = buffer_dp[i];
		}
}
 
 
void input(){
	scanf("%d %d", &n, &k);
 
	for(int i = 1; i <= n; ++i)
		Graph[i].clear();
 
	for(int i = 1; i <= n; ++i)
		scanf("%d", val+i);
 
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}
}
 
int solve(){
	dfs(1, 0);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = add(ans, dp_root[i][k]);
	return ans;
}
 
int main(){
 
	scanf("%d", &test_cases);
 
	while(test_cases--){
		input();
		printf("%d\n", solve());
	}
 
 
	return 0;
}
