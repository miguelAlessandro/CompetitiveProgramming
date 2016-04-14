#include <iostream>
#include <cstdio>

using namespace::std;
const int N = 1<<6;
bool adj[N][N], vis[N];
int n, m, x, y, T;

void dfs(const int x){
    vis[x] = true;
    for(int i = 1; i <= n; ++i) 
        if(adj[x][i] and not vis[i])
            dfs(i);
}

int main(){
    
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i){
        scanf("%d %d", &x, &y);
        adj[x][y] = true;
        adj[y][x] = true;
    }

    for(int i = 1; i <= n; ++i)
        if(not vis[i]){
            dfs(i);
            T = T + 1; 
        }

    printf("%I64d\n", 1LL<<(n - T));

    return 0;
}
