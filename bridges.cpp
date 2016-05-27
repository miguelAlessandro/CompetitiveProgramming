#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#define N 100005

using namespace::std;

int vis[N], T, low[N];
vector<int> adj[N];
vector<pair<int, int> > bridge;


void dfs_complete(int n){

    memset(visit, -1, sizeof vis);
    bridge.clear();
    T = 0;
    for(int i = 0; i < n; ++i) 
        if(not vis[i])
            dfs(i)
}

void dfs(int x, int P){

    vis[x] = T;
    low[x] = T;
    T = T + 1;
    for(int i = 0; i < int(adj[x].size()); ++i){
        int u = adj[x][i];
        if(u == P) continue;
        if(vis[u] == -1){
            dfs(u, x);
            if(low[u] > vis[x])
                bridge.push_back(make_pair(x, u));
            low[x] = min(low[x], low[u]);
        }
        else low[x] = min(low[x], vis[u]);
    }
}

void dfs(int source){

    stack<pair<int, int> > S; S.push(make_pair(source, -1));
    while(not S.empty()){
        pair<int, int> q = S.top(); S.pop();
        int x = q.first, P = q.second;
        vis[x] = T;
        low[x] = T;
        T = T + 1;
        for(int i = 0; i < int(adj[x].size()); ++i){
            int u = adj[x][i];
            if(u == P) continue;
            if(vis[u] == -1){
                S.push(make_pair(u, x));
                if(low[u] > vis[x]) 
                    bridge.push_back(make_pair(x, u));
                low[x] = min(low[x], low[u]);
           }
           else
                low[x] = min(low[x], vis[u]);
        }
   }
}



int main(){

    return 0;
}
