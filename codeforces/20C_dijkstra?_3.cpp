
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
vector<plli> adj[N];
int p[N];

void dijkstra(int x){

    vector<long long int> d(n, 1000000000000LL); d[x] = 0LL;
    priority_queue<plli, vector<plli>, greater<plli> > Q; Q.push(plli(0LL, x));
    
    while(not Q.empty()){
        plli q = Q.top(); Q.pop();
        if(q.first == d[q.second])
            for(auto it : M[q.second])
                if(d[q.second] + it.first < d[it.second])
                {
                    d[it.second] = d[q.second] + it.first;
                    p[it.second] = q.second;
                    Q.push(plli(d[it.second], is.second));
                }
    }
}


int main( void ){

    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        long long int w;
        scanf("%d %d %I64d", &a, &b, &w);
        adj[a].push_back(plli(w, b));
        adj[b].push_back(plli(w, a));
    }
    
    dijkstra(1);
    
    if(p[n] == 0)
        printf("-1");
    else
    {
        int v = n;
        stack<int> gen;
        while(v != 0){ gen.push(v); v = p[v];}
        while(not gen.empty()){
            printf("%d ", gen.top()); gen.pop();
        }
    }
    
    puts("");

    return 0;  
}
