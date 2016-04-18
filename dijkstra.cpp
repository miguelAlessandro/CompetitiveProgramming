#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace::std;

int maxV = 100000;

typedef pair<int, int> ii;

vector<ii> graph[maxV];
int dis[maxV];
int n, m;

void dijkstra(int x){
    memset(dis, 0x3f, sizeof dis);
    priority_queue<ii, vector<ii>, greater<ii>> Q; 
    Q.push(ii(0, x)); dis[x] = 0;
    while(not Q.empty()){
        ii q = Q.top(); Q.pop();
        int w = q.first, u = q.second;
        if(w == dis[u])
            for(auto v : graph[u])
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                    Q.push(ii(dis[v], v));
                }
    }
}

int main(){

    scanf("%d %d", &n, &m);
    for(int u, v, w, i = 0; i < m; ++i){
        scanf("%d %d %d", &u, &v, &w);
        --u, --v;
        adj[u].push_back(ii(w, v));
        adj[v].push_back(ii(w, u));
    }
    dijkstra(0);      

    return 0;
}
