#include <bits/stdc++.h>

using namespace::std;

const int N = 405;

bool adj[N][N], vis[N];
int dis[N], n, m, d1, d2;


bool bfs(const int x, const bool T, int& d)
{
    queue<int> Q; Q.push(x);

    memset(vis, false, sizeof vis);
    dis[x] = 0; vis[x] = true;
    while(not Q.empty())
    {
        int q = Q.front(); Q.pop();       

        for(int i = 1; i <= n; ++i)
            if(adj[q][i] == T and !vis[i] and q != i)
            {
                vis[i] = true;
                dis[i] = dis[q] + 1;
                Q.push(i);
            }
    }

    d = dis[n];
    return vis[n];
}


int main( void )
{
    scanf("%d %d", &n, &m);
    
    for(int u, v, i = 0; i < m; ++i){
        scanf("%d %d", &u, &v);
        adj[v][u] = adj[u][v] = true;
    }
    
    if(bfs(1, true, d1) and bfs(1, false, d2))
        printf("%d\n", max(d1, d2));
    else
        puts("-1");

    return 0; 
}
