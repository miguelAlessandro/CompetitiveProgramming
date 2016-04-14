#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1040

using namespace::std;

int t, n, m, x;
bool v[N];


int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m); memset(v, true, sizeof v);
        for(int i = 0; i < m; ++i) {scanf("%d", &x); v[x-1] = false;}
        int tournament = (1 << (n-1)), solve = 0;
        while(tournament){
            for(int i = 0; i < tournament; ++i){
                if(v[i<<1]^v[(i<<1) + 1]) ++solve;
                v[i] = v[i<<1] || v[(i<<1) + 1];
            }
            tournament >>= 1;
        }
        printf("%d\n", solve);
    }

    return 0;
}
