#include <iostream>
using namespace std;

struct vertex{
	int x, w;
	vertex(){}
	vertex(int xx, int ww) : x(xx), w(ww) {}
}

const int N = 10000;
int dis[N];
vector<vertex> adj;


void bfs_01(const int x){

	memset(dis, -1, sizeof dis); dis[x] = 0;
	deque<int> Q; Q.push_front(x);

	while(not Q.empty()){
		int q = Q.front(); Q.pop_front();
		for(auto v : adj[q])
			if(dis[v.x] == -1 or dis[v.x] > dis[q] + v.w){
				dis[v.x] = dis[q]+v.w;
				v.w == 0 ? Q.push_front(v.x) : Q.push_back(v.x);
			} 
	}
}


bool vis[N];

void bfs_01(const int x){

	memset(vis, false, sizeof vis); vis[x] = true;
	deque<int> Q; Q.push_front(x); dis[x] = 0;
	
	while(not Q.empty()){
		int q = Q.front(); Q.pop_front();
		for(auto v : adj[q])
			if(not vis[v.x] or dis[v.x] > dis[q] + v.w){
				vis[v.x] = true;
				dis[v.x] = dis[q] + v.w;
				v.w == 0 ? Q.push_front(v.x) : Q.push_back(v.x);
			}
	}
}


int main(){



	return 0;
}
