#include <iostream>
#include <vector>
using namespace std;

struct vertex(){
	int x, y;
	vertex(){}
	vertex(int xx, int yy) : x(xx), y(yy) {}
}

const int N = 100000;
vector<int> adj[N];
int dis[N];
bool vis[N];

vertex bfs(const int x){
	memset(vis, false, sizeof vis); vis[x] = true;
	queue<int> Q; Q.push(x); dis[x] = 0;
	int q;
	while(not Q.empty()){
		q = Q.front(); Q.pop();
		for(auto v : adj[q])
			if(not vis[v]){
				vis[v] = true;
				dis[v] = dis[q]+1;
				Q.push(v);
			}	
	}
	return vertex(q, dis[q]);		
}

int diametro(){
	return bfs(bfs(0).x).y;
}

int main(){

	

	return 0;
}
