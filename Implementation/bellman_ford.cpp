#include <iostream>
#include <cstdio>

using namespace::std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
const int maxV = 1000;
const int maxE = 1000;

int S[maxE], E[maxE], W[maxE];
int dis[maxV];

bool bellman_ford(int x){
    memset(dis, 0x3f, sizeof dis);
    dis[x] = 0;
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            dis[E[j]] = min(dis[E[j]], dis[S[j]] + W[j]);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(dis[E[j]] > dis[S[j]] + W[j])
                return true;
    return false;
}

int main(){

    return 0;
}
