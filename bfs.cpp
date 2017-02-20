#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int N = 10000;


void bfs(int x){
	memset(dis, -1, sizeof dis); dis[x] = 0;
	queue<int> Q; Q.push(x);

	while(not Q.empty()){
		int q = Q.front(); Q.pop();
		for(auto v : adj[q])
			if(dis[v] == -1){
				dis[v] = dis[q]+1;	
				Q.push(v);
			}
	}
}


void bfs01(int x){
	
	memset(dis, -1, sizeof dis); dis[x] = 0;
	deque<int> Q; Q.push_back(x);

	while(not Q.empty()){
		int q = Q.front(); Q.pop_front(); 
		for(auto v : adj[q])
			if(dis[v.first] == -1 or dis[v.first] > dis[q] + v.second){
				dis[v.first] = dis[q]+v.second;
				Q.push_back(v.first);
			}
	}
}

int main(){

		

	return 0;
}
