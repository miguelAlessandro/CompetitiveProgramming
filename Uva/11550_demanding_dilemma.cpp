#include <iostream>
#include <cstring>
#include <cstdio>

using namespace::std;

int t, n, m,
    inc[10][30];
bool ok, graph[10][10];


int main(){

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        ok = true;
        memset(graph, false, sizeof graph);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                scanf("%d", &inc[i][j]); 
            
        for(int j = 0; j < m; ++j){
            int sum = 0;
            for(int i = 0; i < n; ++i)
                sum += inc[i][j];
            if(sum != 2) ok = false;
        }
        if(ok){
            for(int j = 0; j < m; ++j){
                int incr = 0, a[2];
                for(int i = 0; i < n; ++i)
                    if(inc[i][j] == 1)
                        a[incr++] = i;
                if(!graph[a[0]][a[1]]) graph[a[0]][a[1]] = graph[a[1]][a[0]] = true;
                else ok = false;
            }   
        }

        if(ok) puts("Yes");
        else puts("No");
    }

    return 0;
}
