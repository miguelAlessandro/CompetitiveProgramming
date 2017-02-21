#include <iostream>
#include <utility>
#define N 100005

using namespace::std;

int vis[N], T, low[N];
vector<int> adj[N];
vector<int> cut_point;


void dfs_complete(int n){

    memset(visit, -1, sizeof vis);
    cut_point.clear();
    T = 0;
    for(int i = 0; i < n; ++i) 
        if(not vis[i])
            dfs(i)
}

void dfs(int x, int P){
    vis[x] = T;
    low[x] = T++;
    int children = 0;
    for(int u : adj[x]){
        if(u == P) continue;
        if(vis[u] == -1){
            dfs(u, x);
            low[x] = min(low[x], low[u]);
            
            if(low[u] >= vis[x] and p != -1) cut_point.push_back(x);
            ++children;
        }
        else low[x] = min(low[x], vis[u]);
    }
    if(p == -1 and children > 1)
        cut_point.push_back(x);
}

int main(){

    return 0;
}
