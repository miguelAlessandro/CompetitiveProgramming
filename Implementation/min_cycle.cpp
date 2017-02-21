#include <iostream>
using namespace std;

const int N = 1000;
vector<int> adj[N];
bool vis[N];
int dis[N], pi[N];

int bfs(int x){
	queue<int> Q; Q.push(x);
	memset(vis, false, sizeof vis); vis[x] = true;
	dis[x] = 0; 
	pi[x] = x;
	while(not Q.empty()){
		int q = Q.front(); Q.pop();
		for(auto v : adj[q])
			if(not vis[v]){
				vis[v] = true;
				dis[v] = dis[q]+1;
				pi[v] = q;
				Q.push(v);
			}
			else if(v != pi[q])
				return dis[v] + dis[q] + 1;
	}
}

int min_cycle(){
	int mini = 2000000000;
	for(int i = 0; i < n; ++i)
		mini = min(mini, bfs(i));
	return mini;
}

int main(){

		

	return 0;
}
