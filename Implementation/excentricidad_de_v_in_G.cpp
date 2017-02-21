#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxV = 100000;

vector<int> adj[maxV];
bool vis[maxV];
int dis[maxV]; //distancia de v respecto a un x
int n, m, v;

int bfs(int x){
    queue<int> Q; Q.push(x);
    dis[x] = 0; //caso base: distancia de x a x es 0
    while(not Q.empty()){
        int q = Q.front(); Q.pop();
        vis[q] = true;
        for(auto u : adj[q]) //recorrido de la lista de adjacencia de q con c++11
            if(not vis[u]){
                dis[u] = dis[q] + 1;
                Q.push(u);
            }
    }
}


int main(){
    
    scanf("%d %d %d", &n, &m, &v);
    for(int a, b, i = 0; i < m; ++i){
        scanf("%d %d", &a, &b); --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(v-1);   
    int excentricidad = 0;
    for(int i = 0; i < n; ++i)
        excentricidad = max(excentricidad, dis[i]);

    printf("e(%d) = %d\n", v, excentrididad);

    return 0;
}









