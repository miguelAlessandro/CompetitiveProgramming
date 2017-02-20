#include <bits/stdc++.h>
using namespace std;

const int N = 502;
int k, n, m, x;
bool vis[N][N], vis2[N], vis3[N];
int d[N][N], adj[N][N];
vector<int> cycle[N];
vector<int> v;
queue<int> Q;

int main(){

	scanf("%d", &n);
	for(int i = 0 ; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &adj[i][j]);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			d[i][j] = INT_MAX;

	for(int i = 0; i < n; ++i)
		d[i][i] = true;

	for(int i = 0; i < n; ++i){
		Q.push(i); 
		d[i][i] = 0; vis[i][i] = true;
		while(not Q.empty()){
			int q = Q.front(); Q.pop();
			vis[q][q] = true;	
			for(int v = 0; v < n; ++v){
				if(adj[q][v] and not vis[i][v]){
					vis[i][v] = true;
					d[i][v] = d[i][q] + 1;
					Q.push(v);
				}
				if(adj[q][v] and vis[i][v]){
					cycle[q].push_back()
				}	
			}
		}
	}		
	
	scanf("%d", &m);

	while(m--){
		scanf("%d %d", &k, &x);		
		x--;
		v.clear();
		memset(vis2, false, sizeof vis2);		
		memset(vis3, false, sizeof vis3);
		Q.push(x); Q.push(k);
		vis2[x] = true;
		while(not Q.empty()){
			int q = Q.front(); Q.pop();
			int s = Q.front(); Q.pop();
			for(int i = 0; i < n; ++i){
				if(d[q][i] < s and adj[q][q] and not vis3[i])
					vis3[i] = true;	
				if(d[q][i] == s)
					vis3[i] = true;				 
				if(d[q][i] < s and adj[i][i] and not vis2[i]){
					vis2[i] = true;
					Q.push(i);
					Q.push(s-d[q][i]);
				}
			}
		}
		
		for(int i = 0; i < n; ++i) if(vis3[i]) v.push_back(i);
		printf("%d\n", v.size());
		for(int i = 0; i < v.size(); ++i)
			printf("%d%c", v[i]+1, (i+1==v.size())?'\n':' ');			
		if(v.size()==0) puts("-1"); 
	}

	

	return 0;
}
