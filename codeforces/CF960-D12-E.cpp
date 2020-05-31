/**
 * @author Miguel Mini
 * @tag dp on trees, rerooting, combinatorics
 * @idea
 *      - dp on tree aplication.
**/


#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int ans[N];
vector<int> adj[N];
int sumi[N], ci[N];
int sump[N], cp[N];
int n, V[N];

int add(int a, int b){
	return (a+b)%mod;
}

int mul(long long a, long long b){
	return a*b%mod;
}


void dfs(int x, int p){

	for(int v : adj[x])
		if(v != p)
			dfs(v, x);
	
	ans[x] = 0;
	int sum_i = 0, sum_p = 0;
	int c_i = 0, c_p = 0;

	for(int v : adj[x])
		if(v != p){
			ans[x] = add(ans[x], ans[v]);	

			int t1 = 0;
			t1 = add(t1, mul(sum_i, ci[v]));
			t1 = add(t1, mul(c_i, sumi[v]));
			t1 = add(t1, mod - mul(mul(c_i, ci[v]), V[x]));

			ans[x] = add(ans[x], add(t1, t1));

			int t2 = 0;
			t2 = add(t2, mul(sum_p, cp[v]));
			t2 = add(t2, mul(c_p, sump[v]));
			t2 = add(t2, mul(mul(c_p, cp[v]), V[x]));

			ans[x] = add(ans[x], add(t2, t2));

			sum_p = add(sum_p, sump[v]);
			sum_i = add(sum_i, sumi[v]);
			c_i = add(c_i, ci[v]);
			c_p = add(c_p, cp[v]);
		}
		
	sumi[x] = 0;
	ci[x] = 1;
	cp[x] = 0;
	sump[x] = 0;

	for(int v : adj[x])
		if(v != p){
			ci[x] = add(ci[x], cp[v]);
			cp[x] = add(cp[x], ci[v]);
			sumi[x] = add(sumi[x], add(sump[v], mul(V[x], cp[v])));
			sump[x] = add(sump[x], add(sumi[v], mul(mod - V[x], ci[v])));
		}

	ans[x] = add(ans[x], add(sumi[x], sumi[x]));
	ans[x] = add(ans[x], V[x]);
	sumi[x] = add(sumi[x], V[x]);
}

int main(){

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		scanf("%d", V+i);
		V[i] = (mod + V[i])%mod;
	}

	for(int i = 1; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	printf("%d\n", ans[1]);

	return 0;
}
