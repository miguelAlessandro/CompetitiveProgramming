#include <iostream>
#include <cstdio>
#include <vector>

using namespace::std;
const int N = 1000005;

vector<int> graph[N];
int m, q, x, y;
vector<int> in;

int main(){

    while(scanf("%d %d", &m, &q) != EOF){
        for(int i = 1; i <= m; ++i){
            scanf("%d", &x);
            graph[x].push_back(i);
            in.push_back(x);    
        }
        while(q--){
            scanf("%d %d", &x, &y);
            if(x <= int(graph[y].size()))
                printf("%d\n", graph[y][x-1]);
            else
                puts("0");
        }
        for(int i = 0; i < int(in.size()); ++i)
            if(not graph[in[i]].empty())
                graph[in[i]].clear();
        in.clear();
    }

    return 0;
}
