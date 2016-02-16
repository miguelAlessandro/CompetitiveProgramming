#include <bits/stdc++.h>
#define N 405

using namespace::std;

bool G[N][N],
     visit[N];
int d[N],
    n, m, dm;
bool visto;


void bfs(int source)
{
    visit[source] = true;
    d[source] = 0;
    
    queue<int> Q;
    Q.push(source);

    while(not Q.empty())
    {
        int q = Q.front(); Q.pop();       
        
        for(int i = 0; i < n; i++)
        {       
            if(G[q][i] == visto && !visit[i] && i != q)
            {
                visit[i] = true;
                d[i] = d[q] + 1;
                Q.push(i);
            }
        }
    }
}


int main( void )
{
    cin >> n >> m;
    
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[v][u] = G[u][v] = true;
    }
    
    d[n-1] = -1;
    memset(visit, false, sizeof visit);   
    visto = true;
    bfs(0);

    if(d[n-1] != -1)
    {
        dm = d[n-1];
        d[n-1] = -1;

        memset(visit, false, sizeof visit);
        visto = false;
        bfs(0);
    
        if(d[n-1] == -1)
            cout << -1 << endl;
        else
            cout << max(dm, d[n-1]) << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}
