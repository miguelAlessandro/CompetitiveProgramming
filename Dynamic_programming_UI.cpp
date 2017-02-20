#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
const int N = 1005;
const int M = 1005;
vector<int> adj[N];
int S[N];
int min[N][M], dis[N][N];
int v, e, m;

int main(){

	scanf("%d %d %d", &v, &e, &m); 
	for(int x, y, w, i = 0; i < e; ++i){
		scanf("%d %d %d", &x, &y, &w);
		adj[x].push_back(y);
		adj[y].push_back(x);
		dis[x][y] = w; dis[y][x] = w;
	}
	for(int x, wx, i = 0; i < v; ++i){
		scanf("%d %d", &x, &wx);
		S[x] = wx;
	}
		
	for(int i = 1; i <= v; ++i)
		for(int j = 0; j < M; ++j)
			min[i][j] = 1000000000;
	min[1][M] = 0;	
	priority_queue< iii, vector<iii>, greater<iii> > Q;
	Q.push(iii(0, ii(1, M)));
	while(not Q.empty()){
		iii q = Q.top(); Q.pop();
		int k = q.second.first, l = q.second.second;
		for(int p : adj[k]){
			if(l >= S[p] and min[p][l-S[p]] > min[k][l] + dis[k][p])
				min[p][l-s[p]] = min[k][l] + dis[k][p];
				Q.push(iii(min[p][l-s[p]], ii(p, l-s[p])));
			}
	}

	int i = 1;;
	for(; i <= v; ++i)
		if(min[N][i] != 1000000000)
			break;
		
	printf("%d\n", i);		

	return 0;
}
