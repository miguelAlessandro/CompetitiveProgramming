#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N];
bool color[N];
bool vis[N];
int nc[2]; 
int n;

void dfs(int x){

	vis[x] = true;
	for(auto v : adj[x])
		if(not vis[v] and color[v] == color[x])
			dfs(v);
}


int main(){

	scanf("%d", &n);
	for(int x, i = 1; i <= n; ++i){
		scanf("%d", &x);
		color[i] = x == 1;
	}

	for(int x, y, i = 0; i < n-1; ++i){
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for(int i = 1; i <= n; ++i)
		if(not vis[i]){
			nc[color[i]]++;
			dfs(i);
		}

	printf("%d\n", min(nc[0], nc[1]));


	return 0;
}
