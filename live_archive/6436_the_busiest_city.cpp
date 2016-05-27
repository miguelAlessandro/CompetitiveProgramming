#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int aux = 3;
const int N = 20000;

bool vis[N + aux];
vector<int> adj[N + aux], high[N + aux];
queue<int> Q;
int dis[N + aux], wei[N + aux];
int n, t;

int bfs(const int x){
    for(int i = 1; i <= n; ++i) high[i].clear(); 
    memset(vis, false, sizeof vis);
    Q.push(x); dis[x] = 1; high[1].push_back(x);
    int maxHigh = 1;
    while(not Q.empty()){
        int q = Q.front(); Q.pop();
        vis[q] = true; maxHigh = dis[q];
        for(auto v : adj[q])
            if(not vis[v]){
                dis[v] = dis[q] + 1;
                high[dis[v]].push_back(v);
                Q.push(v);
            }
    }
    return maxHigh;
}

void weidth(const int maxHigh){
    
    for(int i = 1; i <= n; ++i) wei[i] = 1;
    for(int i = maxHigh; i >= 1; --i)
        for(auto u : high[i])
            for(auto v : adj[u])           
                if(dis[u] < dis[v])
                    wei[u] += wei[v];
}

int maxFlow(){
    
    int maxflow = 0;
    for(int i = 1; i <= n; ++i){
        int flow = 0, sum = n - 1;
        for(auto u : adj[i])
            if(dis[i] < dis[u]){
                sum -= wei[u];
                flow += wei[u]*sum;      
            }

        maxflow = max(maxflow, flow);
    }
    return maxflow;
}

int main(){

    scanf("%d", &t);
    for(int k = 1; k <= t; ++k){
        
        for(int i = 1; i <= n; ++i) adj[i].clear();
        scanf("%d", &n);
        for(int a, b, i = 1; i < n; ++i){
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        weidth(bfs(1));
        printf("Case #%d: %d\n", k, maxFlow());
    }

    return 0;
}
