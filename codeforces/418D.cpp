#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 100005;
vector<int> adj[N];
ii d1[N], d2[N]; 
bool vis[N];
int n, m;

int bfs(int x, ii d[N]){
	memset(vis, false, sizeof vis);
	queue<int> Q; Q.push(x);
	vis[x] = true; d[x] = ii(0, x);	
	int q;
	while(not Q.empty()){
		q = Q.front(); Q.pop();
		for(auto v : adj[q])		
			if(not vis[v]){
				vis[v] = true;
				d[v] = ii(d[q].first + 1, v);
				Q.push(v);
			}
	}
	return q;	
}

int main(){

	scanf("%d", &n);
	for(int x, y, i = 0; i < n-1; ++i){
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int q2 = bfs(bfs(1, d1), d2);
	int q1 = bfs(q2, d1);	
	//sort(d1+1, d1+n+1);
	//sort(d2+1, d2+n+1);

	scanf("%d", &m);		
	for(int x, y, i = 0; i < m; ++i){
		scanf("%d %d", &x, &y);
		int l, r;
		if(x == q2 and y == q1 or x == q1 and y == q2) printf("%d\n", (d1[q2].first+1)/2);
		else if(x == q1 or x == q2) printf("%d\n", max(d1[y].first, d2[y].first));
		else if(y == q1 or y == q2) printf("%d\n", max(d1[x].first, d2[x].first));
		else printf("%d\n", max(min(d1[x].first, d2[x].first), min(d1[y].first, d2[y].first))); 
	}

	return 0;
}
