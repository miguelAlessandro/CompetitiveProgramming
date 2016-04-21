#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <stack>

using namespace::std;
typedef pair<long long, int> plli; 

const int N = 100005;

int n, m;
map<int, long long int> M[N];
int p[N];

void dijkstra(int source){

    memset(p, -1, sizeof p);
    vector<long long int> d(n, 1000000000000LL); d[source] = 0LL;
    priority_queue<plli, vector<plli>, greater<plli> > Q; Q.push(plli(0LL, source));
    
    while(not Q.empty()){
        plli q = Q.top(); Q.pop();
        long long int w = q.first; int u = q.second;
        
        if(w == d[u])
            for(auto it : M[u])
                if(d[u] + it.second < d[it.first])
                {
                    d[v] = d[u] + wv;
                    p[v] = u;
                    Q.push(plli(d[v], v));
                }
    }
}


int main( void ){

    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        long long int w;
        scanf("%d %d %I64d", &a, &b, &w);
        --a, --b;
        if(M[a].find(b) != M[a].end())
        {
            M[b][a] = min(M[b][a], w),
            M[a][b] = min(M[a][b], w);
        }
        else
            M[b][a] = w, M[a][b] = w;
    }
    
    dijkstra(0);
    
    if(p[n-1] == -1)
        printf("-1");
    else
    {
        int v = n-1;
        stack<int> gen;
        while(v != -1){ gen.push(v); v = p[v];}
        while(not gen.empty()){
            printf("%d ", gen.top() + 1); gen.pop();
        }
    }
    
    puts("");

    return 0;  
}
