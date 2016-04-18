#include <iostream>
#include <cstdio>

using namespace::std;

const int maxV = 1000;

bool adj[maxV][maxV];
bool vis[maxV];
int d[maxV][maxV];
int n, m;

void floyd_warshall(const int n){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dis[i][j] = (adj[i][j] ? 1 : 1<<28);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main(){
    
    scanf("%d %d", &n, &m);
    for(int a, b, i = 0; i < m; ++i){
        scanf("%d %d", &a, &b);
        adj[a][b] = adj[b][a] = true;
    }
    floyd_warshall();
    
    int radio = n*n, diametro = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i; j < n; ++j){
            radio = min(radio, dis[i][j]);
            diametro = max(diametro, dis[i][j]);
        }

    return 0;
}
