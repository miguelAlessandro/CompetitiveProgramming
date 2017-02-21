#include <bits/stdc++.h>
using namespace std;

const int N = 102;
vector<int> adj[N];
int F[N][N];
int T[N][N];
int C[N][N];
int p[N];
int M[N];
bool vis[N];
int n, m;
int s, t;

int bfs(int s, int t){

	queue<int> Q; Q.push(s);
	memset(vis, false, sizeof vis);
	vis[s] = true;
	M[s] = INT_MAX;

	while(not Q.empty()){
		int u = Q.front(); Q.pop();
		if(u == t) return M[t];

		for(int v : adj[u])
			if(not vis[v] and T[u][v] > 0){
				vis[v] = true;
				p[v] = u;
				M[v] = min(M[u], C[u][v] - F[u][v]);
				Q.push(v);
			}
	}
	
	return 0;
}



int edmond_karp(int s, int t){

	memcpy(T, C, sizeof C);
	memset(F, 0, sizeof F);
	int ans = 0;
	
	while(true){	
		int fm = bfs(s, t);
		if(fm == 0) break;		
		ans += fm;
		
		int v = t;
		while(v != s){
			int u = p[v];
			F[u][v] += fm;	
			F[v][u] -= fm;
			T[u][v] -= fm;	
			T[v][u] += fm;
			v = u;
		}
	}

	return ans;
}

int main(){

	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int x, y, z, i = 0; i < m; ++i){
		scanf("%d %d %d", &x, &y, &z);
		adj[x].push_back(y);
		adj[y].push_back(x);
		C[x][y] = z;
	}	

	printf("maximum flow : %d\n", edmond_karp(s, t));

	return 0;
}
