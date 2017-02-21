#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> ii;


const int N = 100000;
int dis[N];
vector<int> adj[N];

ii bfs(const int x){
    
    queue<int> Q; Q.push(x); dis[x] = 0;
    int q;
    while(not Q.empty()){
        q = Q.front(); Q.pop();
        vis[q] = true;
        for(auto v : adj[q])
            if(not vis[v]){
                dis[v] = dis[q] + 1;
                Q.push(v);
            }
    }
    return ii(q, dis[q]);
}

int diamTree(){
    return bfs(bfs(1).first).second;
}
