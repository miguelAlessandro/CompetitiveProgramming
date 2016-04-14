#include <iostream>
#include <cstdio>
#include <cstring>

using namespace::std;

const int N = 20;

int t, n, st[N + 2], m;
long long dp[(1<<N) + 5];

long long backtracking(int bitmask, int T){
    if(dp[bitmask] != -1) return dp[bitmask];
    if(T == n) return 1LL;
    int p = st[T]&~bitmask, lsone;
    long long r = 0LL;
    while(p){
        lsone = p&-p;
        if(bitmask & lsone) continue;
        r += backtracking(bitmask|lsone, T+1);
        p -= lsone;
    }
    return dp[bitmask] = r;
}


int main(){

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            st[i] = 0;
            for(int j = 0; j < n; ++j){
                scanf("%d", &m);
                if(m) st[i] |= (1 << j);
            }
        }
        memset(solve, -1, sizeof dp);
        printf("%lld\n", backtracking(0, 0));
    }

    return 0;
}
